/*
 * ULTRASONIC.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Yassin
 *      Description
 */

#ifndef HAL_ULTRASONIC_H_
#define HAL_ULTRASONIC_H_
#include "../MCAL/gpio.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/****************************************
 *  The defines
 ****************************************/
#define ULTRASONIC_TRIGGER_PIN PIN5_ID
#define ULTRASONIC_TRIGGER_PORT PORTB_ID


/****************************************
 *  Non-static functions prototypes
 ****************************************/
void Ultrasonic_init(void);
uint16 Ultrasonic_readDistance(void);
#endif /* HAL_ULTRASONIC_H_ */
