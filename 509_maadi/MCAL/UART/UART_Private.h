/*
 * UART_Private.h
 *
 *  Created on: Sep 21, 2022
 *      Author: malak
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define       UDR_REG                     *(volatile u8*)0x2C
#define       UCSRA_REG                   *(volatile u8*)0x2B
#define       UCSRB_REG                   *(volatile u8*)0x2A
#define       UCSRC_REG                   *(volatile u8*)0x40
#define       UBRRL_REG                   *(volatile u8*)0x29


#define       POLLING_TIME                2000000
#define       UART_FINISHED_RECIEVING     1
#define       UART_FINISHED_TRANSMITTING  1

//UCSRA BITS
#define       TXC_BIT                     6
#define       RXC_BIT                     7

//UCSRB BITS
#define       UCSZ2_BIT                   2
#define       TXEN_BIT                    3
#define       RXEN_BIT                    4

//UCSRC BITS
#define       UCSZ0_BIT                   1
#define       UCSZ1_BIT                   2
#define       UMSEL_BIT                   6
#define       UMP0_BIT                    4
#define       UMP1_BIT                    5
#define       USBS_BIT                    3

#define       UART_PARITY_DISABLE         1
#define       UART_PARITY_EVEN            2
#define       UART_PARITY_ODD             3

#define       UART_STOP_BITS             UART_1_STOP_BIT
#define       UART_1_STOP_BIT            1
#define       UART_2_STOP_BIT            2

#define       F_OSC                      16000000


#endif /* MCAL_UART_UART_PRIVATE_H_ */
