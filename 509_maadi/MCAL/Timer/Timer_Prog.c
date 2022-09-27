/*
 * Timer_Prog.c
 *
 *  Created on: Sep 20, 2022
 *      Author: malak
 */

#include "Timer_Interface.h"
#include "LED_Interface.h"
#include <avr/interrupt.h>

void (*Timer0_CallBack) (void);
void (*Timer1_CallBack) (void);
void (*Timer2_CallBack) (void);

u32 Timer_U32_NumOfOverflows = 0;

#define        TCCR0_REG      *(volatile u8*)0x53
#define        SREG_REG       *(volatile u8*)0x5F
#define        TIMSK_REG      *(volatile u8*)0x59

#define        WGM00         6
#define        WGM01         3
#define        CS00          0
#define        CS01          1
#define        CS02          2
#define        I_BIT         7
#define        TOIE0_BIT     0

void M_Timer_Void_TimerInit(void)
{
	//TO SELECT NORMAL MODE
	CLR_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);

	//TO SELECT DIVISON FACTOR IN PRESCALER -> 1024
	SET_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);

	//To enable Global Interrupt
	SET_BIT(SREG_REG,I_BIT);

	//To enable Local Interrupt
	SET_BIT(TIMSK_REG,TOIE0_BIT);
    /*u8 Copy_U8_TimerChannel=0;
	switch(Copy_U8_TimerChannel)
	{
	case TIMER0_CHANNEL:
		break;
	case TIMER1_CHANNEL:
		break;
	case TIMER2_CHANNEL:
		break;
	default:
		break;
	}*/
}

void M_Timer_Void_TimerSetTime(u32 Copy_U32_DesiredTime)
{
	u32 Local_U32_TickTime   = 1024 / 16;//result in microsecond
	u32 Local_U32_TotalTicks = (Copy_U32_DesiredTime * 1000) / Local_U32_TickTime;
	Timer_U32_NumOfOverflows = Local_U32_TotalTicks / 256;

}

void M_Timer_Void_SetCallBack(u8 Copy_U8_TimerChannel,void(*Copy_ptr)(void))
{
	switch(Copy_U8_TimerChannel)
	{
	case TIMER0_CHANNEL:
		Timer0_CallBack = Copy_ptr;
		break;
	case TIMER1_CHANNEL:
		Timer1_CallBack = Copy_ptr;
		break;
	case TIMER2_CHANNEL:
		Timer2_CallBack = Copy_ptr;
		break;
	default:
		break;
	}
}

ISR(TIMER0_OVF_vect)
{
	static u32 Local_U32_Counter = 0;
	Local_U32_Counter++;
	if(Local_U32_Counter == Timer_U32_NumOfOverflows)
	{
		H_LED_Void_LedSetOn(LED2);
		H_LED_Void_LedSetOff(LED2);

		Local_U32_Counter=0;
	}
}
