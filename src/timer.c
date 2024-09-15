#include <avr/io.h>
#include <inttypes.h>
#include "timer.h"


void init_clock_tick_timer(void)
{


    TCCR1B |= _BV(CS12) | _BV(WGM12); // 256 prescaler and CTC mode
    OCR1AH = (0xF424>>8);
    OCR1AL = 0xF424; // 1 sec 

    TIMSK |= _BV(OCIE1A);
}

void init_refresh_timer(void)
{
    TCCR2 |= _BV(CS22);
    TIMSK |= _BV(TOIE2);
}

void init_timers()
{
    init_clock_tick_timer();
    init_refresh_timer();
}