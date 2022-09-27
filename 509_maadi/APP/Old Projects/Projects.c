/*
 * Projects.c
 *
 *  Created on: Sep 2, 2022
 *      Author: malak
 */

#include "Projects.h"

void A_LEDProject(void)
{
    H_LED_Void_LedInit(LED2);
	H_LED_Void_LedSetOn(LED2);
	_delay_ms(2000);              //we use this function instead of for(i=0;i<1000000;i++);
	H_LED_Void_LedSetOff(LED2);
}

void A_BuzzerProject(void)
{
    H_Buzzer_Void_BuzzerInit();
	H_Buzzer_Void_BuzzerSetOn();
	_delay_ms(1000);
	H_Buzzer_Void_BuzzerSetOff();
}

void A_PBProject(void)
{
H_PB_Void_PBInit(PB0);
	H_Buzzer_Void_BuzzerInit();
	while(1)
	{
		while(H_PB_U8_PBRead(PB0) == PRESSED)
			H_Buzzer_Void_BuzzerSetOn();
		H_Buzzer_Void_BuzzerSetOff();
    }
}

void A_SSDProject(void)
{
	H_SSD_Void_SSDInit();
		int x = 0;
		while(1)
		{
		H_SSD_Void_SSDWriteNumber(x);
		_delay_ms(1000);
		x++;
		}
}

void A_LCDProject(void)
{
	H_LCD_Void_LCDInit();

    while(1)
    {
    	u8 i = 0;
		u8 k = 0;
		for (i=0;i<16;i++)
		{
			H_LCD_Void_LCDClear();
			for (k=0;k<i;k++)
			{
				H_LCD_Void_LCDWriteCharacter(' ');
			}
			//H_LCD_Void_LCDWriteString('m');
			_delay_ms(500);

		}
    }

}

void A_EXT_INT_Project(void)
{

}

void A_KeypadProject(void)
{

	H_LCD_Void_LCDInit();
	H_Keypad_Void_KeypadInit();
	int x=0;
	while(1)
	{
		x=H_Keypad_U8_KeypadRead();
		if (x != 0)
			H_LCD_Void_LCDWriteCharacter(x);
	}
}

void A_ADCProject(void)
{
	H_LCD_Void_LCDInit();
	H_LM35_Void_LM35Init();
	while(1)
	{
		H_LCD_Void_LCDWriteNumber(H_LM35_U16_LM35Read());
		_delay_ms(500);
		H_LCD_Void_LCDClear();
	}
}

void A_Timer0Project()
{
	H_LED_Void_LedInit(LED2);
	M_Timer_Void_TimerInit();
    M_Timer_Void_TimerSetTime(200);
}

void A_HC05Project(void)
{
	H_LCD_Void_LCDInit();
	H_LED_Void_LedInit(LED0);
	H_LED_Void_LedInit(LED1);
	H_LED_Void_LedInit(LED2);
	H_LED_Void_LedSetOff(LED0);
	H_LED_Void_LedSetOff(LED1);
	H_LED_Void_LedSetOff(LED2);
	H_Buzzer_Void_BuzzerInit();
	M_UART_Void_UARTInit();
	u8 x = 0;
	while (1)
	{
		x=H_HC05_U8_HC05Receive();
		if (x != 0)
		{
			if (x == 49)
			{
		    	H_LED_Void_LedSetOn(LED0);
	    		_delay_ms(500);
     			H_LED_Void_LedSetOff(LED0);
			}
			if (x == 50)
			{
				H_LED_Void_LedSetOn(LED1);
				_delay_ms(500);
				H_LED_Void_LedSetOff(LED1);
			}
			if (x == 51)
			{
				H_LED_Void_LedSetOn(LED2);
				_delay_ms(500);
				H_LED_Void_LedSetOff(LED2);
			}
			if (x == 52)
				H_Buzzer_Void_BuzzerOnce();
			if (x == 53)
				H_LCD_Void_LCDWriteString("Hi");
			if (x == 54)
				H_LCD_Void_LCDWriteString("BYE");
			if (x == 55)
				H_LCD_Void_LCDClear();
			if (x == 56)
			{
				for (int i = 0; i < 20; i++)
				{
					H_LED_Void_LedTog(LED0);
					_delay_ms(200);
					H_LED_Void_LedTog(LED1);
					_delay_ms(200);
					H_LED_Void_LedTog(LED2);
					_delay_ms(200);
				}

			}
			if (x == 57)
			{
				for (int i = 0; i < 2; i++)
				{
					u8 i = 0;
					u8 k = 0;
					for (i = 0; i < 16; i++)
					{
						H_LCD_Void_LCDClear();
						for (k = 0; k < i; k++)
						{
							H_LCD_Void_LCDWriteCharacter(' ');
						}
						H_LCD_Void_LCDWriteString("HELLO");
						_delay_ms(500);

					}
				}
			}
		}
	}
}
