/*
 * ADC_Interface.h
 *
 *  Created on: Sep 20, 2022
 *      Author: malak
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

/******************************Includes**************************/
#include "ADC_Config.h"
#include "BitMath.h"
#include "STD.h"
#include <util/delay.h>

/******************************MACROS***************************/

#define     ADC_CHANNEL_0       0
#define     ADC_CHANNEL_1       1
#define     ADC_CHANNEL_2       2
#define     ADC_CHANNEL_3       3
#define     ADC_CHANNEL_4       4
#define     ADC_CHANNEL_5       5
#define     ADC_CHANNEL_6       6
#define     ADC_CHANNEL_7       7

/******************************Function prototypes***************************/

void M_ADC_Void_ADCInit(void);
u16 M_ADC_U16_ADCRead(u8);//u16 ashan barga3 ala 2 registers (10 bits)

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
