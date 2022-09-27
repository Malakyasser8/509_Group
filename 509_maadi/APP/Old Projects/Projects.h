/*
 * Projects.h
 *
 *  Created on: Sep 2, 2022
 *      Author: malak
 */

#ifndef APP_OLD_PROJECTS_PROJECTS_H_
#define APP_OLD_PROJECTS_PROJECTS_H_

#include "STD.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "Buzzer_Interface.h"
#include "PB_Interface.h"
#include "SSD_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "ADC_Interface.h"
#include "LM35_Interface.h"
#include "Timer_Interface.h"
#include "HC05_Interface.h"
#include "AT24C16A_Interface.h"
#include <util/delay.h>

void A_SSDProject(void);
void A_LEDProject(void);
void A_BuzzerProject(void);
void A_PBProject(void);
void A_LCDProject(void);
void A_EXT_INT_Project(void);
void A_KeypadProject(void);
void A_ADCProject(void);
void A_Timer0Project(void);
void A_HC05Project(void);

#endif /* APP_OLD_PROJECTS_PROJECTS_H_ */
