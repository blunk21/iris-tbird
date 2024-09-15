#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifdef DEBUG
    #define debug_printf(...) printf(__VA_ARGS__)
#else
    #define debug_printf(...) // Empty definition, no printing
#endif

#include <inttypes.h>

volatile static uint8_t push_button_pressed = 0;

#endif