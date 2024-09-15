#ifndef _LM35_H_
#define _LM35_H_
#include "inttypes.h"

/**
 * @brief Initialize ADC peripheral
 *
 */
void initLM35();

/**
 * @brief Initiates a conversion and stores a value in integer and string format.
 *
 */

void taskPollTemp(void);

/**
 * @brief Logs the adc value for debugging purposes
 *
 * @param val
 */
void log_adc_val(uint16_t);

/**
 * @brief Converts the ADC value into temperature and stores it in string and integer format.
 */
void taskRegisterTemp();

/**
 * @brief Get the Temp String
 *
 * @return uint8_t*
 */
uint8_t *getTempString(void);

/**
 * @brief Get the Current Temp
 *
 * @return uint16_t
 */
uint16_t getCurrentTemp(void);

#endif