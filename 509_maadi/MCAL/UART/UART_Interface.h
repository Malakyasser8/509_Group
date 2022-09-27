/*
 * UART_Interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: malak
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

/******************************Includes**************************/
#include "BitMath.h"
#include "STD.h"
#include "UART_Config.h"
#include "DIO_Interface.h"

/******************************MACROS***************************/


/******************************Function prototypes***************************/

void M_UART_Void_UARTInit(void);
void M_UART_Void_UARTSend(u8);
u8   M_UART_U8_UARTReceive(void);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
