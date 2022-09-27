/*
 * SSD_Interface.h
 *
 *  Created on: Aug 30, 2022
 *      Author: malak
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

/***********************************Includes*********************************/
#include "DIO_Interface.h"
#include "SSD_Config.h"
#include "STD.h"
#include <util/delay.h>

/***********************************Macros*********************************/

/******************************Function prototypes***************************/
void H_SSD_Void_SSDInit(void);
//static void H_SSD_Void_SSDDigitDisplay(u8);
void H_SSD_Void_SSDWriteNumber(u8);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
