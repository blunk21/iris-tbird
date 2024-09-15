#include "clock.h"
#include "uart.h"
static struct tm clock_current_tm;


void clock_init_time() {
    clock_current_tm.tm_hour = 6;
    clock_current_tm.tm_min = 59;
    clock_current_tm.tm_sec = 50;
    clock_current_tm.tm_year = 2024 - 1900;
    clock_current_tm.tm_mon = 0;
    clock_current_tm.tm_mday = 1;
    clock_current_tm.tm_wday = 0;
    clock_current_tm.tm_yday = 0;
    mktime(&clock_current_tm);
}

void clock_setTime()
{
}

void clock_tick_clock(void)
{
    clock_current_tm.tm_sec = clock_current_tm.tm_sec + 1;
    mktime(&clock_current_tm);

}

struct tm clock_get_current_time() {
    return clock_current_tm;
}

void clock_inc_min(uint8_t multiplier)
{
    clock_current_tm.tm_min = clock_current_tm.tm_min + multiplier;
    mktime(&clock_current_tm);
}

void clock_inc_hour(uint8_t multiplier)
{
    clock_current_tm.tm_hour = clock_current_tm.tm_hour + multiplier;
    mktime(&clock_current_tm);
}