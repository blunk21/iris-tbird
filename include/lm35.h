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



#endif