/*
 * LM35_Prog.c
 *
 *  Created on: Sep 20, 2022
 *      Author: malak
 */

#include "LM35_Interface.h"

void H_LM35_Void_LM35Init(void)
{
	M_ADC_Void_ADCInit();
}

u16 H_LM35_U16_LM35Read(void)
{
	u16 Local_U16_AddValue = M_ADC_U16_ADCRead(LM25_PIN);
    u16 Local_U16_Temp     = ((u32)Local_U16_AddValue * 500) / 1023;
    return Local_U16_Temp;
}
