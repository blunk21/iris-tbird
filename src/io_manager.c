#include <avr/io.h>
#include "sevseg_display.h"
#include "uart.h"
#include "io_manager.h"
#include "clock.h"
#include "globals.h"


void io_init_io_manager(void)
{
    io_init_leds();
}

void io_init_leds(void)
{
    DDRD |= DDRB |= 0xF0;
}

void io_check_buttons()
{

    static uint8_t pressed = 0, debounce_counter = 0;
    uint8_t state = PING & 0x1F;
    if (state != 0)
    {
        if (debounce_counter < DEBOUNCE_CYCLE)
        {
            debounce_counter++;
        }
        else
        {
            pressed = state;
        }
    }
    else
    {
        if (pressed != 0)
        {
            push_button_pressed = pressed;
            pressed = 0;
            debounce_counter = 0;
        }
        else
        {
            debounce_counter = 0;
        }
    }
}

uint8_t io_get_last_pushbutton_pressed()
{
    return push_button_pressed;
}

void io_clear_button_press()
{
    push_button_pressed = 0;
}

void io_sync_io(){
    uint8_t pressed = io_get_last_pushbutton_pressed();
        if (pressed != 0)
        {
            switch (pressed)
            {
            case 16:
                clock_inc_hour(1);
                break;
            case 8:
                clock_inc_min(1);
                break;
            case 4:
                clock_inc_min(10);
                break;
            case 2:
                clock_inc_min(-5);
                break;
            default:
                break;
            }
            io_clear_button_press();
        }
    return;
}