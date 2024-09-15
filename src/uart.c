#include "uart.h"
#include "avr/io.h"


int usart_putchar_printf(char var, FILE* stream) {
	// if (var == '\n') uartTransmitChar('\r');
	uart_transmit_char(var);
	return 0;
}
void init_uart(uint8_t ubrr)
{

	// Set Baud Rate
	UBRR0H = (UBRR >> 8);
	UBRR0L = UBRR;
	// Enable receiving and transmitting + interrupts
	UCSR0A |= _BV(U2X0); // double the uart speed

	UCSR0B |= _BV(RXEN0) | _BV(TXEN0);

	// Set up frame format
	UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00);
}

void uart_transmit_char(uint8_t cp)

{
	if (bit_is_set(UCSR0A, UDRE0))
		UDR0 = cp;
}

void uart_transmit_str(char* str)
{
	char* cp;
	cp = str;
	while (*cp)
	{
		while (bit_is_clear(UCSR0A, UDRE0))
			;
		uart_transmit_char(*cp);
		cp++;
	}
}

void check_uart_error()
{
	if (bit_is_set(UCSR0A, FE0))
		uart_transmit_str("Frame receive error\n");
	else if (bit_is_set(UCSR0A, DOR0))
		uart_transmit_str("Data overrun errori\n");
	else if (bit_is_set(UCSR0A, UPE0))
		uart_transmit_str("Parity error\n");
}