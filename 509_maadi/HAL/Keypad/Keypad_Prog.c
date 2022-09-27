/*
 * Keypad_Prog.c
 *
 *  Created on: Sep 19, 2022
 *      Author: malak
 */


#include "Keypad_Interface.h"

void H_Keypad_Void_KeypadInit(void)
{
	M_DIO_Void_SetPinDirection(KEYPAD_R0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R3_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(KEYPAD_R0_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R1_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R2_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R3_PIN,HIGH);

	M_DIO_Void_SetPinDirection(KEYPAD_C0_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C1_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C2_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C3_PIN,INPUT);

	M_DIO_Void_SetPinPullUpResistor(KEYPAD_C0_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpResistor(KEYPAD_C1_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpResistor(KEYPAD_C2_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpResistor(KEYPAD_C3_PIN,ENABLE);
}

u8   H_Keypad_U8_KeypadRead(void)
{
#if   KEYPAD_MODE     ==    TYPE_1
	u8 Local_U8_Arr[4][4] = {{ '1' , '2' , '3' , 'A' },
			                 { '4' , '5' , '6' , 'B' },
			                 { '7' , '8' , '9' , 'C' },
			                 { '*' , '0' , '#' , 'D' }};
#elif KEYPAD_MODE     ==    TYPE_2
	u8 Local_U8_Arr[4][4] = {{ '7' , '8' , '9' , '/' },
				             { '4' , '5' , '6' , '*' },
				             { '1' , '2' , '3' , '-' },
				             { 'C' , '0' , '=' , '+' }};
#endif

	u8 Local_U8_Reading = 0;//m3naha eno madassh,law b2et 0 yb2a howa das
	u8 Local_U8_Col = 0;
	u8 Local_U8_Row = 0;
	for (Local_U8_Row = KEYPAD_R0_PIN; Local_U8_Row <= KEYPAD_R3_PIN; Local_U8_Row++)
	{
		M_DIO_Void_SetPinValue(Local_U8_Row, LOW);
		for (Local_U8_Col = KEYPAD_C0_PIN; Local_U8_Col <= KEYPAD_C3_PIN; Local_U8_Col++)
		{
			if (M_DIO_U8_GetPinValue(Local_U8_Col) == KEYPAD_PRESSED)
			{
				_delay_ms(KEYPAD_BOUNCING_TIME);
				if( M_DIO_U8_GetPinValue(Local_U8_Col) == KEYPAD_PRESSED)
				{
					while(M_DIO_U8_GetPinValue(Local_U8_Col) == KEYPAD_PRESSED);
					Local_U8_Reading = Local_U8_Arr[Local_U8_Row - KEYPAD_R0_PIN][Local_U8_Col - KEYPAD_C0_PIN] ;
                    break;
				}
			}
		}
		M_DIO_Void_SetPinValue(Local_U8_Row, HIGH);
	}
	return Local_U8_Reading;
}
