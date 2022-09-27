/*
 * LCD_Prog.c
 *
 *  Created on: Sep 2, 2022
 *      Author: malak
 */

#include "LCD_Interface.h"
#include "LCD_Private.h"

void H_LCD_Void_LCDInit(void)
{
#if     LCD_MODE     ==     _8_BIT_MODE

	M_DIO_Void_SetPinDirection(LCD_D0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D3_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);

	M_DIO_Void_SetPinDirection(LCD_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RW_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(LCD_RW_PIN,LOW);

	H_LCD_Void_LCDWriteCommand(LCD_8_BIT_MODE);
	H_LCD_Void_LCDWriteCommand(LCD_8_DISPLAY_ON_CURSOR_OFF);
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR);
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME);

#elif     LCD_MODE     ==     _4_BIT_MODE

	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);

	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RW_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(LCD_RW_PIN,LOW);

	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_1);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_2);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_3);

	H_LCD_Void_LCDWriteCommand(LCD_8_DISPLAY_ON_CURSOR_OFF);
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR);
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME);

#endif

}

void H_LCD_Void_LCDWriteCharacter(u8 Copy_U8_Character)
{
	M_DIO_Void_SetPinValue(LCD_RS_PIN,HIGH);
#if     LCD_MODE     ==     _8_BIT_MODE
	//PORTA_REG = Copy_U8_Character;//Da ghalat
	//Hanktb badalo dool
	H_LCD_Void_LCDSetPins(Copy_U8_Character);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
#elif     LCD_MODE     ==     _4_BIT_MODE
	// Ab3at el 4 el fl awel mslan (1010)0010 fa b3ml shift 4 fa ytb3et 00001010
	H_LCD_Void_LCDSetPins(Copy_U8_Character >> 4);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(1);

	// Ab3at el 4 el fl akher baa 1010(0010) fa bab3t el rqam zay ma howa w howa haylhod awel 4 bas
	H_LCD_Void_LCDSetPins(Copy_U8_Character);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);

#endif
	_delay_ms(1);
}

void H_LCD_Void_LCDWriteString(u8* Copy_U8_String)
{
	u8 Local_U8_Counter = 0;
    while(Copy_U8_String[Local_U8_Counter] != '\0')
    {
    	H_LCD_Void_LCDWriteCharacter(Copy_U8_String[Local_U8_Counter]);
    	Local_U8_Counter++;
    }

}

void H_LCD_Void_LCDWriteCommand(u8 Copy_U8_Command)
{
	M_DIO_Void_SetPinValue(LCD_RS_PIN,LOW);
#if     LCD_MODE     ==     _8_BIT_MODE
	//PORTA_REG = Copy_U8_Command;//Da ghalat
	//Hanktb badalo dool
	H_LCD_Void_LCDSetPins(Copy_U8_Command);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
#elif     LCD_MODE     ==     _4_BIT_MODE
	// Ab3at el 4 el fl awel mslan (1010)0010 fa b3ml shift 4 fa ytb3et 00001010
	H_LCD_Void_LCDSetPins(Copy_U8_Command >> 4);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(1);

	// Ab3at el 4 el fl akher baa 1010(0010) fa bab3t el rqam zay ma howa w howa haylhod awel 4 bas
	H_LCD_Void_LCDSetPins(Copy_U8_Command);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);

#endif
	_delay_ms(1);
}

void H_LCD_Void_LCDWriteNumber(s32 Copy_S32_Num)	//128
{
	s8 Local_S8_Counter = -1;	//Ashan m3mlsh -- lel counter b3d el while loop
	u8 Local_U8_Array[16];	    //max 16 digit 3ala el screen

	if (Copy_S32_Num < 0) //ashan law el num negative
	{
		Copy_S32_Num = Copy_S32_Num * -1;
		H_LCD_Void_LCDWriteCharacter('-');
	}

	do	//ashan ytba3 el zero
	{
		Local_S8_Counter++;	//1 -> 2 -> 3
		Local_U8_Array[Local_S8_Counter] = Copy_S32_Num % 10; //8 -> 2 -> 1
		Copy_S32_Num = Copy_S32_Num / 10; //12 -> 1 -> 0
		//el array =[8,2,1]
	} while (Copy_S32_Num != 0);

	while (Local_S8_Counter >= 0) {
		H_LCD_Void_LCDWriteCharacter(Local_U8_Array[Local_S8_Counter] + 48);
		Local_S8_Counter--;
	}
}

void H_LCD_Void_LCDGoTo(u8 Copy_U8_Row,u8 Copy_U8_Column)//Row:0-1 Column:0 -> 15
{
	u8 Local_U8_Array[2]={0x08 , 0xC0};/******VERY GOOD IDEA*****/
	 H_LCD_Void_LCDWriteCommand(Local_U8_Array[Copy_U8_Row] + Copy_U8_Column);
}

void H_LCD_Void_LCDClear(void)
{
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR);
}

static void H_LCD_Void_LCDSetPins(u8 Copy_U8_Num)
{
#if     LCD_MODE     ==     _8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_D0_PIN,Copy_U8_Num & 0x01);
	M_DIO_Void_SetPinValue(LCD_D1_PIN,Copy_U8_Num >>1 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D2_PIN,Copy_U8_Num >>2 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D3_PIN,Copy_U8_Num >>3 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D4_PIN,Copy_U8_Num >>4 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D5_PIN,Copy_U8_Num >>5 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D6_PIN,Copy_U8_Num >>6 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D7_PIN,Copy_U8_Num >>7 & 0x01);

#elif     LCD_MODE     ==     _4_BIT_MODE

	M_DIO_Void_SetPinValue(LCD_D4_PIN,Copy_U8_Num >>0 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D5_PIN,Copy_U8_Num >>1 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D6_PIN,Copy_U8_Num >>2 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D7_PIN,Copy_U8_Num >>3 & 0x01);

#endif
}
