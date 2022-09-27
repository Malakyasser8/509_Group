/*
 * HC05_Interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: malak
 */

/*===============BLUTOOTH APPLICATION OF UART===================*/


/******************************Includes**************************/
#include "UART_Interface.h"

/******************************MACROS***************************/

/**********************Function prototypes**********************/
void H_HC05_Void_HC05Init(void);
void H_HC05_Void_HC05Send(u8);
u8   H_HC05_U8_HC05Receive(void);

#ifndef HAL_HC05_HC05_INTERFACE_H_
#define HAL_HC05_HC05_INTERFACE_H_
#endif /* HAL_HC05_HC05_INTERFACE_H_ */
