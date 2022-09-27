/*
 * I2C_Private.h
 *
 *  Created on: Sep 23, 2022
 *      Author: malak
 */

#ifndef MCAL_I2C_I2C_PRIVATE_H_
#define MCAL_I2C_I2C_PRIVATE_H_

#define    TWBR_REG         *(volatile u8*)0x20
#define    TWCR_REG         *(volatile u8*)0x56
#define    TWSR_REG         *(volatile u8*)0x21
#define    TWAR_REG         *(volatile u8*)0x22
#define    TWDR_REG         *(volatile u8*)0x23

/*TWCR REGISTER BITS*/
#define    TWSTA_BIT        5
#define    TWSTO_BIT        4
#define    TWEN_BIT         2
#define    TWINT_BIT        7

/*TWSR REGISTER BITS*/
#define    TWPS0_BIT                                     0
#define    TWPS1_BIT                                     1

#define    I2C_MASTER_MODE                               1
#define    I2C_SLAVE_MODE                                2

#define   I2C_STILL_PROCESSING                           0

#define   START_CONDITION_HAS_BEEN_TRANSMITTED           0x08
#define   REPEATED_START_CONDITION_HAS_BEEN_TRANSMITTED  0x10
#define   SLAVE_ADDRESS_W_TRANSMITTED_ACK_RECIEVE        0x18
#define   SLAVE_ADDRESS_R_TRANSMITTED_ACK_RECIEVE        0x40
#define   BYTE_TRANSMITTED_ACK_RECIEVE                   0x28
#define   BYTE_RECIEVE_ACK_TRANSMITTED                   0x50



#endif /* MCAL_I2C_I2C_PRIVATE_H_ */
