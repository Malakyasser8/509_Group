/*
 * Buzzer_Prog.c
 *
 *  Created on: Aug 27, 2022
 *      Author: malak
 */

#include "Buzzer_Interface.h"

void H_Buzzer_Void_BuzzerInit(void)
{
	M_DIO_Void_SetPinDirection(Buzzer_PIN,OUTPUT);
}

void H_Buzzer_Void_BuzzerSetOn(void)
{
	M_DIO_Void_SetPinValue(Buzzer_PIN,HIGH);
}

void H_Buzzer_Void_BuzzerSetOff(void)
{
	M_DIO_Void_SetPinValue(Buzzer_PIN,LOW);
}

void H_Buzzer_Void_BuzzerOnce(void)
{
	M_DIO_Void_SetPinValue(Buzzer_PIN,HIGH);
	_delay_ms(BUZZER_TIME_ON);
	M_DIO_Void_SetPinValue(Buzzer_PIN,LOW);
}
