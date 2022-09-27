/*
 * LM35_Interface.h
 *
 *  Created on: Sep 20, 2022
 *      Author: malak
 */


/*=============TEMP SENSOR APPLICATION OF ADC==========*/
#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_

/******************************Includes**************************/
#include "LM35_Config.h"
#include "ADC_Interface.h"
#include "STD.h"

/******************************Function prototypes***************************/

void H_LM35_Void_LM35Init(void);
u16 H_LM35_U16_LM35Read(void);


#endif /* HAL_LM35_LM35_INTERFACE_H_ */
