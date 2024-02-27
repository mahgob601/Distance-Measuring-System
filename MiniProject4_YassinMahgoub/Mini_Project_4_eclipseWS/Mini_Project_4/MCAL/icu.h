/*
 * icu.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Yassin
 */

#ifndef MCAL_ICU_H_
#define MCAL_ICU_H_
#include "../std_types.h"

/*
 * Edge either rising or falling edge
 */
typedef enum{
	FALLING, RISING
} ICU_EdgeSelect;

/*
 * Pre-scaler value
 */
typedef enum{
	NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024
} ICU_ClockSelect;

typedef struct{
	ICU_EdgeSelect edgeSelect;
	ICU_ClockSelect clockSelect;
} ICU_ConfigType;

void ICU_setCallBack(void(*a_ptr)(void));
void ICU_init(const ICU_ConfigType *ICU_configPtr);
void ICU_setEdgeSelect(const ICU_EdgeSelect val);
uint16 ICU_getICRValue(void);
void ICU_clearTimerValue(void);
void ICU_deInit(void);

#endif /* MCAL_ICU_H_ */
