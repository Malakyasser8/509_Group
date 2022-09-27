/*
 * I2C_Prog.c
 *
 *  Created on: Sep 23, 2022
 *      Author: malak
 */

#include "I2C_Interface.h"
#include "I2C_Private.h"


void M_I2C_Void_I2CInit(void)
{
#if     I2C_MODE       ==         I2C_MASTER_MODE
	/*TO SELECT F_SCL -> 4OO KHZ*/
	TWBR_REG = 12;
#elif     I2C_MODE       ==         I2C_SLAVE_MODE
	TWAR_REG = (SLAVE_ADDRESS << 1) | GENERAL_CALL_RESPONSE;
#endif

	/*TO ENABLE I2C CIRCUIT*/
	SET_BIT(TWCR_REG,TWEN_BIT);
}

void M_I2C_Void_I2CStartCondition(void)
{
	/*TO MAKE A START CONDITION*/
	SET_BIT(TWCR_REG,TWSTA_BIT);

	/*TO CLEAR THE FLAG (MUST BE WRITTEN BEFORE EVERY FUNCTION)*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*TO REMAIN STUCK TILL BYTE FINISHES WRITING*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);

	/*Bat2aked le tany mara hasal start condition ala el bus mn bara wla la*/
	while((TWSR_REG & 0xF8) != START_CONDITION_HAS_BEEN_TRANSMITTED);

}

void M_I2C_Void_I2CStopCondition(void)
{
	/*TO MAKE A STOP CONDITION*/
	SET_BIT(TWCR_REG,TWSTO_BIT);

	/*TO CLEAR THE FLAG (MUST BE WRITTEN BEFORE EVERY FUNCTION)*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*MABKTBSH HENA WHILE ASHAN EL CPU MSH HYKHROG MNHA ASHAN
	 * MSTNY EL CIRCUIT TKTB WAHED BAS EL CLK W2FET FA EL CIRCUIT MSH HATSHTGHAL*/
}

void M_I2C_Void_I2CRepeatedStart(void)
{
	/*TO MAKE A START CONDITION*/
	SET_BIT(TWCR_REG,TWSTA_BIT);

	/*TO CLEAR THE FLAG (MUST BE WRITTEN BEFORE EVERY FUNCTION)*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*TO REMAIN STUCK TILL BYTE FINISHES WRITING*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);

	/*Bat2aked le tany mara hasal repeated start condition ala el bus mn bara wla la*/
	while((TWSR_REG & 0xF8) != REPEATED_START_CONDITION_HAS_BEEN_TRANSMITTED);
}

void M_I2C_Void_I2CSendSlaveAddressWrite(u8 Copy_U8_Address)
{
	TWDR_REG = Copy_U8_Address << 1;//ashan homa 7 bits bas w akher wahda heya el operation

	/*TO CLEAR THE FLAG (MUST BE WRITTEN BEFORE EVERY FUNCTION)*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*TO REMAIN STUCK TILL BYTE FINISHES WRITING*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);

	/*Bat2aked le tany mara hasal send slave address ala el bus mn bara wla la*/
	while((TWSR_REG & 0xF8) != SLAVE_ADDRESS_W_TRANSMITTED_ACK_RECIEVE);
}

void M_I2C_Void_I2CSendSlaveAddressRead(u8 Copy_U8_Address)
{
	TWDR_REG = (Copy_U8_Address << 1) | 1;//to make last bit 1 to read

	/*TO CLEAR THE FLAG (MUST BE WRITTEN BEFORE EVERY FUNCTION)*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*TO REMAIN STUCK TILL BYTE FINISHES WRITING*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);

	/*Bat2aked le tany mara hasal send slave address ala el bus mn bara wla la*/
		while((TWSR_REG & 0xF8) != SLAVE_ADDRESS_R_TRANSMITTED_ACK_RECIEVE);
}

void M_I2C_Void_I2CSendByte(u8 Copy_U8_Data)
{
    TWDR_REG = Copy_U8_Data;

    /*TO CLEAR THE FLAG (MUST BE WRITTEN BEFORE EVERY FUNCTION)*/
    SET_BIT(TWCR_REG,TWINT_BIT);

    /*TO REMAIN STUCK TILL BYTE FINISHES WRITING*/
    while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);

    /*Bat2aked le tany mara hasal send slave address ala el bus mn bara wla la*/
    while((TWSR_REG & 0xF8) != BYTE_TRANSMITTED_ACK_RECIEVE);
}

u8   M_I2C_Void_I2CReadByte(void)
{
	u8 Local_U8_Data = TWDR_REG;

	CLR_BIT(TWCR_REG,TWSTA_BIT);

	/*TO CLEAR THE FLAG (MUST BE WRITTEN BEFORE EVERY FUNCTION)*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*TO REMAIN STUCK TILL BYTE FINISHES WRITING*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);

    /*Bat2aked le tany mara hasal send slave address ala el bus mn bara wla la*/
	while((TWSR_REG & 0xF8) != BYTE_RECIEVE_ACK_TRANSMITTED);

	return Local_U8_Data;
}
