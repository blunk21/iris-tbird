#include <avr/io.h>
#include "sevseg_display.h"
#include <stdio.h>
#include "uart.h"
#include "clock.h"


sevseg_display_t* sevseg_get_display(void)
{
    static sevseg_display_t instance;
    return  &instance;
}

void sevseg_init_display(void)
{
    DDRA = 0xFF; // sevseg display
    sevseg_display_t* pdisplay = sevseg_get_display();
    pdisplay->current_page = TIME;
}

void sevseg_set_page(Page page)
{
    sevseg_get_display()->current_page = page;
}

void sevseg_print_num(uint8_t num, uint8_t dig)
{
    if (num > 9)
        return;
    else if (dig > 4)
        return;
    else if (dig == 4)
    {
        PORTA = 0xC0;
        return;
    }
    PORTA = (1 << PINA7) | (dig << 4) | num;
    return;
}

void sevseg_refresh_display(void)
{
    static uint8_t digit = 0;
    if (digit > 4)
        digit = 0;
    if (sevseg_get_display()->current_page == TIME)
    {
        struct tm curr = clock_get_current_time();
        switch (digit)
        {
        case 0:
            sevseg_print_num(curr.tm_min % 10, digit);
            break;
        case 1:
            sevseg_print_num((curr.tm_min / 10) % 10, digit);
            break;
        case 2:
            sevseg_print_num(curr.tm_hour % 10, digit);
            break;
        case 3:
            sevseg_print_num((curr.tm_hour / 10) % 10, digit);
            break;
        case 4:
            if (curr.tm_sec % 2 == 0)
                sevseg_print_num(0, digit);
            break;
        default:
            break;
        }
    }
    else if (sevseg_get_display()->current_page == TEMP)
    {
    }
    digit++;
}
