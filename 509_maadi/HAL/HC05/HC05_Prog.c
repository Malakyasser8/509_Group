/*
 * HC05_Prog.c
 *
 *  Created on: Sep 21, 2022
 *      Author: malak
 */

#include "HC05_Interface.h"

void H_HC05_Void_HC05Init(void)
{
	M_UART_Void_UARTInit();
}

void H_HC05_Void_HC05Send(u8 Copy_U8_Data)
{
	M_UART_Void_UARTSend(Copy_U8_Data);
}

u8   H_HC05_U8_HC05Receive(void)
{
	return M_UART_U8_UARTReceive();
}
