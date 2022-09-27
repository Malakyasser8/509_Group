/*
 * PB_Interface.h
 *
 *  Created on: Aug 27, 2022
 *      Author: malak
 */

#ifndef HAL_PB_PB_INTERFACE_H_
#define HAL_PB_PB_INTERFACE_H_

/***********************************Includes*********************************/

#include "DIO_Interface.h"
#include "STD.h"
#include <util/delay.h>
#include "PB_Config.h"

/***********************************Macros*********************************/

#define       PB0         0
#define       PB1         1
#define       PB2         2

#define       ACTIVE_HIGH 1
#define       ACTIVE_LOW  2

#if           PB_MODE ==  ACTIVE_HIGH
#define       RELEASED    0
#define       PRESSED     1
#elif         PB_MODE ==  ACTIVE_LOW
#define       RELEASED    1
#define       PRESSED     0
#endif


/******************************Function prototypes***************************/

void H_PB_Void_PBInit(u8);
u8   H_PB_U8_PBRead(u8);//If pressed,return 1 if not, return 0

#endif /* HAL_PB_PB_INTERFACE_H_ */
