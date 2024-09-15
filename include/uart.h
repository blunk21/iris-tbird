#ifndef _UART_H_
#define _UART_H_

#include <inttypes.h>
#include <stdio.h>
#include "globals.h"



#define BAUD_RATE 115200
#define UBRR ((F_CPU / 8 / BAUD_RATE) - 1)
#define UART_BUFFER_SIZE 160


int usart_putchar_printf(char var, FILE* stream);

/**
 * @brief Initialize UART interface
 *
 * @param ubrr
 */

void init_uart(uint8_t);

/**
 * @brief Transmits a character via UART
 *
 * @param cp
 */
void uart_transmit_char(uint8_t);
void uartReceive(void);

/**
 * @brief Trnsmits a string via UART
 *
 * @param str
 */
void uart_transmit_str(char *);

/**
 * @brief Checks the UART error registers
 *
 */
void check_uart_error(void);

#endif
