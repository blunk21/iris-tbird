#include <avr/io.h>
#include "sevseg_display.h"
#include <stdio.h>
#include "uart.h"
#include "clock.h"

static uint8_t current_page = TIME;

void initDisplayManager(void)
{
    DDRA = 0xFF; // sevseg display
}

void setPage(Page page)
{
    switch (page)
    {
    case TIME:
        /* code */
        break;

    case TEMP:
        break;
    default:
        break;
    }
    current_page = page;
}

uint8_t getCurrentPage()
{
    return current_page;
}

void printNum(uint8_t num, uint8_t dig)
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
    if (getCurrentPage() == TIME)
    {
        struct tm curr = clock_get_current_time();
        switch (digit)
        {
        case 0:
            printNum(curr.tm_min % 10, digit);
            break;
        case 1:
            printNum((curr.tm_min / 10) % 10, digit);
            break;
        case 2:
            printNum(curr.tm_hour % 10, digit);
            break;
        case 3:
            printNum((curr.tm_hour / 10) % 10, digit);
            break;
        case 4:
            if (curr.tm_sec % 2 == 0)
                printNum(0, digit);
            break;
        default:
            break;
        }
    }
    else if (getCurrentPage() == TEMP)
    {
    }
    digit++;
}
