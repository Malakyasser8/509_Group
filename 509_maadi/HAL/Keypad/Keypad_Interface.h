/*
 * Keypad_Interface.h
 *
 *  Created on: Sep 19, 2022
 *      Author: malak
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

/***********************************Includes*********************************/
#include "DIO_Interface.h"
#include "Keypad_Config.h"
#include <util/delay.h>

/***********************************Macros**********************************/

#define     KEYPAD_PRESSED                    0
#define     KEYPAD_RELEASED                   1

#define     TYPE_1                            1
#define     TYPE_2                            2

/******************************Function prototypes***************************/

void H_Keypad_Void_KeypadInit(void);
u8   H_Keypad_U8_KeypadRead(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
