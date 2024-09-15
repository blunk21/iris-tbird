#ifndef _IO_MANAGER_H_
#define _IO_MANAGER_H_
#include <inttypes.h>





#define DEBOUNCE_CYCLE 5
/**
 * @brief Initialize the module
 *
 */
void io_init_io_manager(void);

/**
 * @brief Initialize the LEDs
 *
 */
void io_init_leds(void);

void io_check_buttons();

uint8_t io_getLastButtonPress();

void io_clearButtonPress();

void io_syncIO();

/**
 * @brief Task to check for a button press
 *
 */
void taskButtonCheck(void);

/**
 * @brief Task to control the actuators
 *
 */
void taskManageActuators(void);

#endif