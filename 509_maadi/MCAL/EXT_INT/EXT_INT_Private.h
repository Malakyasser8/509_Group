/*
 * EXT_INT_Private.h
 *
 *  Created on: Sep 9, 2022
 *      Author: malak
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_EXT_INT_PRIVATE_H_

#define        MCUCR_REG           *(volatile u8*)0x55
#define        MCUCSR_REG          *(volatile u8*)0x55//wrong
#define        SREG_REG            *(volatile u8*)0x5F
#define        GICR_REG            *(volatile u8*)0x5B

//MCUCR BITS
#define        ISC00_BIT           0
#define        ISC01_BIT           1
#define        ISC10_BIT           2
#define        ISC11_BIT           3
#define        ISC2_BIT            3//wrong

//GICR_BITS
#define        INT0_BIT            6
#define        INT1_BIT            7
#define        INT2_BIT            5

//SREG BITS
#define        I_BIT               7


#define        RISING_EDGE         1
#define        FALLING_EDGE        2
#define        LOW_LEVEL           3
#define        ANY_LOGICAL_CHANGE  4

#endif /* MCAL_EXT_INT_EXT_INT_PRIVATE_H_ */
