#ifndef _CLOCK_H
#define _CLOCK_H
#include "time.h"
#include <inttypes.h>

void clock_init_time();

void clock_tick_clock(void);

struct tm clock_get_current_time();

void clock_inc_min(uint8_t multiplier);

void clock_inc_hour(uint8_t multiplier);

#endif


