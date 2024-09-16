#include <avr/io.h>
#include <inttypes.h>
#include "timer.h"


void hwtimers_init_clock_tick_timer(void)
{


    TCCR1B |= _BV(CS12) | _BV(WGM12); // 256 prescaler and CTC mode
    OCR1A = CLOCK_TICK_OCR_VAL;

    TIMSK |= _BV(OCIE1A);
}

void hwtimers_init_io_refresh_timer(void)
{
    TCCR2 |= _BV(CS22); //1 msec
    TIMSK |= _BV(TOIE2);
}

void hwtimers_init()
{
    hwtimers_init_clock_tick_timer();
    hwtimers_init_io_refresh_timer();
}