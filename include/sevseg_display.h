#ifndef _DISPLAY_MANAGER_H_
#define _DISPLAY_MANAGER_H_
#include <inttypes.h>





typedef enum { TIME, TEMP } Page;

typedef struct sevseg_display {
  Page current_page;
} sevseg_display_t;


/**
 * @brief Get the sevseg display object
 *
 * @return sevseg_display_t*
 */
sevseg_display_t *sevseg_get_display(void);

/**
 * @brief Initialize the display manager
 *
 */
void sevseg_init_display(void);

/**
 * @brief Set the Current Page
 *
 * @param page
 */
void sevseg_set_page(Page page);

/**
 * @brief Prints a number on the given digit of the sevseg display
 * 
 * @param num 
 * @param dig 
 */
void sevseg_print_num(uint8_t num, uint8_t dig);

/**
 * @brief Puts information on the sevseg display depending on current page
 * 
 */
void sevseg_refresh_display(void);

#endif