#include "lm35.h"
#include "uart.h"
#include "inttypes.h"
#include "stdio.h"
#include <avr/io.h>

static  int adcval = 0;


char debugstring[100];

void initLM35()
{
    ADMUX |= _BV(REFS0);                            // select voltage reference Vcc 2.65V
    ADCSRA |= _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // prescaler 128	-> 125kHz
    // ADCSRA |= _BV(ADIE);                            // adc interrupt enable

    ADCSRA |= _BV(ADEN); // enable adc
    // ADCSRA |= _BV(ADSC); //first conv lasts longer

    // do a quick measurement so that we have a current_temp at the beginning
    taskPollTemp();
}

void taskPollTemp()
{
    ADCSRA |= _BV(ADSC);
    loop_until_bit_is_set(ADCSRA, ADIF);
    adcval = ADC;
}