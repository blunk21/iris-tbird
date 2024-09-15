#ifndef _TIMER_H_
#define _TIMER_H_

/**
 * @brief Value needed in OCR1 to tick the clock at 1 sec
 *
 */
#define CLOCK_TICK_OCR_VAL 62500


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
void init_timers(void);

#endif