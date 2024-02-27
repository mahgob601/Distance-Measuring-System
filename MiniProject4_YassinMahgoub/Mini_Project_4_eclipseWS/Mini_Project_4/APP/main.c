/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Yassin
 *      Description: app layer main source file
 */


#include "../HAL/LCD.h"
#include "../HAL/ULTRASONIC.h"
#include <avr/io.h>
#include <util/delay.h>




int main(void)
{

	uint16 distance = 0;
	SREG |= (1<<7);

	LCD_init();

	Ultrasonic_init();
	LCD_displayString("Distance = ");

	while(1)
	{

		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0,11);
		LCD_integerToString(distance);
		LCD_displayString("cm  ");
	}




}
