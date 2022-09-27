/*
 * Timer_Interface.h
 *
 *  Created on: Sep 20, 2022
 *      Author: malak
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_
/******************************Includes**************************/

#include "STD.h"
#include "BitMath.h"

/******************************MACROS***************************/

#define    TIMER0_CHANNEL      0
#define    TIMER1_CHANNEL      1
#define    TIMER2_CHANNEL      2

/******************************Function prototypes***************************/

void M_Timer_Void_TimerInit(void);
void M_Timer_Void_TimerSetTime(u32);
void M_Timer_Void_SetCallBack(u8,void(*)(void));


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
