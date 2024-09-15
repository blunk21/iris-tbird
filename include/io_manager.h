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

uint8_t io_get_last_pushbutton_pressed();

void io_clear_button_press();

void io_sync_io();

#endif