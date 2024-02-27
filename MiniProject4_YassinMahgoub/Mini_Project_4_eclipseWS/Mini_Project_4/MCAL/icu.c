/*
 * icu.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Yassin
 *      Description: ICU file
 */
#include "../std_types.h"
#include "icu.h"
#include <avr/io.h>
#include <avr/interrupt.h>

static volatile void (*g_callBackPtr) (void) = NULL_PTR;

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}

void ICU_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;

}

void ICU_init(const ICU_ConfigType *ICU_configPtr)
{
	// configuring w
	DDRD &= ~(1<<PD6);
	// not pwm mode
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B);
	// choose trigger on rising edge or falling edge
	TCCR1B = (TCCR1B & 0xBF) | ((ICU_configPtr->edgeSelect)<<ICES1);
	/*
	 * Setting the passed pre-scaler value
	 */
	TCCR1B = (TCCR1B & 0xF8) | (ICU_configPtr->clockSelect);
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK |= (1<<TICIE1);
}

/*
 * Description
 * select edge capture rising or falling
 */
void ICU_setEdgeSelect(const ICU_EdgeSelect val)
{
	TCCR1B = (TCCR1B & 0xBF) | (val<<ICES1);

}
uint16 ICU_getICRValue(void)
{
	return ICR1;
}
void ICU_clearTimerValue(void)
{
	TCNT1 = 0;
}

void ICU_deInit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK &= ~(1<<TICIE1);
	g_callBackPtr = NULL_PTR;

}
