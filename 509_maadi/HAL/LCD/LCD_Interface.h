/*
 * LCD_Interface.h
 *
 *  Created on: Sep 2, 2022
 *      Author: malak
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/***********************************Includes*********************************/

#include "DIO_Interface.h"
#include "LCD_Config.h"
#include <util/delay.h>

/************************************Macros**********************************/




/******************************Function prototypes***************************/

void H_LCD_Void_LCDInit(void);
void H_LCD_Void_LCDWriteCharacter(u8);
void H_LCD_Void_LCDWriteString(u8*);
void H_LCD_Void_LCDWriteCommand(u8);
void H_LCD_Void_LCDWriteNumber(s32);
void H_LCD_Void_LCDGoTo(u8,u8);
void H_LCD_Void_LCDClear(void);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
