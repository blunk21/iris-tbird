#ifndef _DISPLAY_MANAGER_H_
#define _DISPLAY_MANAGER_H_
#include <inttypes.h>



typedef enum 
{
    TIME,
    TEMP
} Page;


typedef struct sevseg_display {
    Page current_page;
    uint8_t digits[5];
}sevseg_display_t;

/**
 * @brief Initialize the display manager
 *
 */
void initDisplayManager(void);

/**
 * @brief Set the Current Page
 *
 * @param page
 */
void setPage(Page page);

uint8_t getCurrentPage();

void printNum(uint8_t num, uint8_t dig);

void sevseg_refresh_display(void);

#endif