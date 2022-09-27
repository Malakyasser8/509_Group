/*
 * SPI_Interface.h
 *
 *  Created on: Sep 22, 2022
 *      Author: malak
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

/***********************************Includes*********************************/
#include "STD.h"
#include "BitMath.h"
#include "SPI_Config.h"
#include "DIO_Interface.h"

/************************************Macros**********************************/


/******************************Function prototypes***************************/
void M_SPI_Void_SPIInit(void);
u8   M_SPI_U8_SPITransive(u8);


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
