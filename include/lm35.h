#ifndef _LM35_H_
#define _LM35_H_
#include "inttypes.h"

/**
 * @brief Initialize ADC peripheral
 *
 */
void tmpsensor_init();

/**
 * @brief Initiates a conversion and stores a value in integer and string format.
 *
 */

void tmpsensor_measure_temp(void);



#endif