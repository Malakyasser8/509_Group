/*
 * main.c
 *
 *  Created on: Aug 25, 2022
 *      Author: malak
 */

#include "Projects.h"
#include "EXT_INT_Interface.h"
#include <avr/interrupt.h>

int main()
{
	                      /*========LED=========*/
	//A_LEDProject();

	                      /*=======Buzzer=======*/
	//A_BuzzerProject();

	                      /*=====PushButton=====*/
	//A_PBProject();

	                      /*======7 Segment=====*/
	//A_SSDProject();

	                      /*========LCD=========*/
	//A_LCDProject();

                          /*========EXT_INT=========*/

	/*
	M_EXT_INT_Void_ExtIntInit(EXT_INT_0);
	H_LED_Void_LedInit(LED0);
    while(1)
    {
    	_delay_ms(5000);
    }
    */
                         /*========KEYPAD=========*/
	//A_KeypadProject();
	                     /*=========ADC/LM35==========*/
	//A_ADCProject();
                        /*=========TIMER0==========*/
	//A_Timer0Project();
                        /*=========UART==========*/
	//A_HC05Project();

	u8 x = 0;
	H_AT24C16A_Void_EEPROMInit();
	x = H_AT24C16A_U8_EEPROMRead(1,1);
	H_LCD_Void_LCDInit();

	while(1)
	{
		H_AT24C16A_Void_EEPROMWrite(1,1,x);
		H_LCD_Void_LCDWriteNumber(x);
		_delay_ms(500);
		x++;
		H_LCD_Void_LCDClear();
	}
	return 0;
}


