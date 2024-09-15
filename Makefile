BAUD       = 115200
F_CPU = 16000000UL
#8Mhz tbird3-nal
MCU        = atmega128
PORT       = /dev/tty.usbserial-A6029IMX
PROGRAMMER = jtag1
#jtag2 at64-en

LIBDIR   = vendor

#INCLUDES = -I. -I$(LIBDIR) -isystem"/usr/local/include/simavr"

ifeq ($(DEBUG),1)
    CFLAGS += -DDEBUG
endif


########################################################
#  nothing below this point should have to be changed  #
########################################################

AVRDUDE = avrdude
AVRSIZE = avr-size
CC      = avr-gcc
CXX     =
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIMAVR  = simavr

TARGET = $(lastword $(subst /, ,$(CURDIR)))

# preprocessor flags:
CPPFLAGS = -Iinclude -MMD -MP -D F_CPU=$(F_CPU) -DTARGET_ATMEGA_128 -D BAUD=$(BAUD) -D MCU=\"$(MCU)\" $(INCLUDES)
#  -D       define macro

# c compiler flags:
CFLAGS = -Os -mmcu=$(MCU)
CFLAGS += -Wall
CFLAGS += -g3
#  -Os      optimize for size
#  -mmcu    set Model MicroControlller Unit
#  -g3      add debug symbols
#  -Wall    enable all errors
#  -Werror  warnings are errors

# linker flags:
LDFLAGS = -Os -mmcu=$(MCU)

# c++ compiler flags:
CXXFLAGS =

# add all directories with code to the wildcard:
SOURCES = $(wildcard *.c src/*.c)
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(SOURCES:.c=.h)

all: $(TARGET).hex

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@ --save-temps

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@ --save-temps

$(TARGET).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

# targets that don't correspond to a file
.PHONY: all clean size flash simavr upload-trace \
	get-flash get-eeprom get-info dependency-graph

clean:
	rm -f *.elf *.hex *.vcd *.i *.s *.o *.d dependency-graph.pdf
	rm -f src/*.elf src/*.hex src/*.vcd src/*.i src/*.s src/*.o src/*.d dependency-graph.pdf

size: $(TARGET).elf
	$(AVRSIZE) -C --mcu=$(MCU) $(TARGET).elf

flash: $(TARGET).hex
	$(AVRDUDE) -P $(PORT) -b $(BAUD) -p $(MCU) -c $(PROGRAMMER) \
		-U flash:w:$(TARGET).hex

simavr: $(TARGET).elf
	$(SIMAVR) $(TARGET).elf

# upload Value Change Dumps to debian VM for GTKWave.
upload-trace:
	scp *.vcd debian:Desktop

get-flash:
	$(AVRDUDE) -P $(PORT) -b $(BAUD) -p $(MCU) -c $(PROGRAMMER) \
		-U flash:r:flash.hex:i

# i don't think this works with arduino!
get-eeprom:
	$(AVRDUDE) -P $(PORT) -b $(BAUD) -p $(MCU) -c $(PROGRAMMER) \
		-U eeprom:r:eeprom.hex:i

get-info:
	$(AVRDUDE) -P $(PORT) -b $(BAUD) -p $(MCU) -c $(PROGRAMMER) -v 2>&1

dependency-graph:
	make all -Bnd | make2graph | dot -Tpdf -o dependency-graph.pdf

