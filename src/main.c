#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "clock.h"
#include "globals.h"
#include "uart.h"
#include "timer.h"
#include "sevseg_display.h"
#include "io_manager.h"



static FILE mystdout = FDEV_SETUP_STREAM(usart_putchar_printf, NULL, 0x0003);

int main(void) {
    stdout = &mystdout;

    init_uart(UBRR);
    clock_init_time();
    // tmpsensor_init();
    sevseg_init_display();
    hwtimers_init();

    sei();
    while (1) {
        io_sync_io();
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