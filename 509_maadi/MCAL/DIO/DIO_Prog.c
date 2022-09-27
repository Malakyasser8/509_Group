/*
 * DIO_Prog.c
 *
 *  Created on: Aug 26, 2022
 *      Author: malak
 */

#include "DIO_Interface.h"
#include "DIO_Private.h"

void M_DIO_Void_SetPinDirection(u8 Copy_U8_Num, u8 Copy_U8_State)
{
	u8 Local_U8_Pin = Copy_U8_Num % 10;
	u8 Local_U8_Port = Copy_U8_Num / 10;

	switch (Copy_U8_State)
	{
	case INPUT:
		switch (Local_U8_Port)
		{
		case PORTA:     CLR_BIT(DDRA_REG, Local_U8_Pin);    break;
		case PORTB:		CLR_BIT(DDRB_REG, Local_U8_Pin);    break;
		case PORTC:     CLR_BIT(DDRC_REG, Local_U8_Pin);    break;
		case PORTD:     CLR_BIT(DDRD_REG, Local_U8_Pin);    break;
		default:        break;
		}
		break;
	case OUTPUT:
		switch (Local_U8_Port)
		{
		case PORTA:	   SET_BIT(DDRA_REG, Local_U8_Pin);	    break;
		case PORTB:    SET_BIT(DDRB_REG, Local_U8_Pin);  	break;
		case PORTC:    SET_BIT(DDRC_REG, Local_U8_Pin); 	break;
		case PORTD:    SET_BIT(DDRD_REG, Local_U8_Pin); 	break;
		default:       break;
		}
		break;
	default:
		break;
	}
}

void M_DIO_Void_SetPinValue(u8 Copy_U8_Num, u8 Copy_U8_State)
{
	u8 Local_U8_Pin = Copy_U8_Num % 10;
	u8 Local_U8_Port = Copy_U8_Num / 10;

	switch (Copy_U8_State) {
	case LOW:
		switch (Local_U8_Port) {
		case PORTA:     CLR_BIT(PORTA_REG, Local_U8_Pin);    break;
		case PORTB:		CLR_BIT(PORTB_REG, Local_U8_Pin);    break;
		case PORTC:     CLR_BIT(PORTC_REG, Local_U8_Pin);    break;
		case PORTD:     CLR_BIT(PORTD_REG, Local_U8_Pin);    break;
		default:        break;
		}
		break;
	case HIGH:
		switch (Local_U8_Port) {
		case PORTA:	   SET_BIT(PORTA_REG, Local_U8_Pin);    break;
		case PORTB:    SET_BIT(PORTB_REG, Local_U8_Pin);  	break;
		case PORTC:    SET_BIT(PORTC_REG, Local_U8_Pin); 	break;
		case PORTD:    SET_BIT(PORTD_REG, Local_U8_Pin); 	break;
		default:       break;
		}
		break;
	default:
		break;
	}
}

void M_DIO_Void_SetPinPullUpResistor(u8 Copy_U8_Num, u8 Copy_U8_State)
{
	u8 Local_U8_Pin = Copy_U8_Num % 10;
	u8 Local_U8_Port = Copy_U8_Num / 10;

	switch (Copy_U8_State)
	{
	case DISABLE:
		switch (Local_U8_Port)
		{
		case PORTA:     CLR_BIT(PORTA_REG, Local_U8_Pin);    break;
		case PORTB:		CLR_BIT(PORTB_REG, Local_U8_Pin);    break;
		case PORTC:     CLR_BIT(PORTC_REG, Local_U8_Pin);    break;
		case PORTD:     CLR_BIT(PORTD_REG, Local_U8_Pin);    break;
		default:        break;
		}
		break;
	case ENABLE:
		switch (Local_U8_Port)
		{
		case PORTA:	   SET_BIT(PORTA_REG, Local_U8_Pin);    break;
		case PORTB:    SET_BIT(PORTB_REG, Local_U8_Pin);  	break;
		case PORTC:    SET_BIT(PORTC_REG, Local_U8_Pin); 	break;
		case PORTD:    SET_BIT(PORTD_REG, Local_U8_Pin); 	break;
		default:       break;
		}
		break;
	default:
		break;
	}
}

void M_DIO_Void_TogPin(u8 Copy_U8_Num)
{
	u8 Local_U8_Pin = Copy_U8_Num % 10;
	u8 Local_U8_Port = Copy_U8_Num / 10;

		switch (Local_U8_Port)
		{
			case PORTA:     TOG_BIT(PORTA_REG, Local_U8_Pin);    break;
			case PORTB:		TOG_BIT(PORTB_REG, Local_U8_Pin);    break;
			case PORTC:     TOG_BIT(PORTC_REG, Local_U8_Pin);    break;
			case PORTD:     TOG_BIT(PORTD_REG, Local_U8_Pin);    break;
			default:                                             break;
        }
}

u8   M_DIO_U8_GetPinValue(u8 Copy_U8_Num)
{
	u8 Local_U8_Pin = Copy_U8_Num % 10;
	u8 Local_U8_Port = Copy_U8_Num / 10;
	u8 Local_U8_Reading=0;
	switch (Local_U8_Port)
	{
		case PORTA:   Local_U8_Reading = GET_BIT(PINA_REG, Local_U8_Pin);    break;
		case PORTB:   Local_U8_Reading = GET_BIT(PINB_REG, Local_U8_Pin);    break;
		case PORTC:   Local_U8_Reading = GET_BIT(PINC_REG, Local_U8_Pin);    break;
		case PORTD:   Local_U8_Reading = GET_BIT(PIND_REG, Local_U8_Pin);    break;
		default:                                                             break;
	}
	return Local_U8_Reading;
}

