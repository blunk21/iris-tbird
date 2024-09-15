#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "globals.h"
#include "uart.h"
#include "timer.h"



static FILE mystdout = FDEV_SETUP_STREAM(usart_putchar_printf, NULL, 0x0003);

int main(void) {
    stdout = &mystdout;
    DDRD |= _BV(0x80);
    init_uart(UBRR);
    clock_init_time();
    // initLM35();
    initDisplayManager();
    init_timers();
    sei();
    // debug_printf("Sending this with debufprintf\r\n");
    while (1) {
        io_syncIO();
    }
    return 0;
}


ISR(TIMER2_OVF_vect)
{
    sevseg_refresh_display();
    io_check_buttons();
}

ISR(TIMER1_COMPA_vect)
{
    clock_tick_clock();
}

ISR(USART0_RX_vect)
{
    uint8_t data = UDR0;
    write_buffer(data);
    check_uart_error();
}