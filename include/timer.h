#ifndef _TIMER_H_
#define _TIMER_H_

/**
 * @brief Creates ticks to measure time
 *
 */
void init_clock_tick_timer(void);

/**
 * @brief Periodically refresh display
 * 
 */
void init_refresh_timer(void);

/**
 * @brief Initialise timers
 * 
 */
void init_timers();

#endif