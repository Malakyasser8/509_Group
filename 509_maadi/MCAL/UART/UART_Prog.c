/*
 * UART_Prog.c
 *
 *  Created on: Sep 21, 2022
 *      Author: malak
 */

#include "UART_Interface.h"
#include "UART_Private.h"


void M_UART_Void_UARTInit(void)
{
	//MAKE TRANSMITTER OUTPUT AS IT IS DEFAULT INPUT
	M_DIO_Void_SetPinDirection(PD0_PIN,INPUT);
	M_DIO_Void_SetPinDirection(PD1_PIN,OUTPUT);

	//TO TALK TO UCSRC WE MUST WRITE 1 IN BIT 15
	u8 Local_U8_UCSRCValue = 0b10000000;

	//TO SELECT CHARACTER SIZE -> 8 BIT
	CLR_BIT(UCSRB_REG,UCSZ2_BIT);
	SET_BIT(Local_U8_UCSRCValue,UCSZ1_BIT);
	SET_BIT(Local_U8_UCSRCValue,UCSZ0_BIT);

	//TO SELECT ASYNCHRONOUS MODE
	CLR_BIT(Local_U8_UCSRCValue,UMSEL_BIT);

#if UART_PARITY_MODE   ==   UART_PARITY_DISABLE
	CLR_BIT(Local_U8_UCSRCValue,UMP0_BIT);
	CLR_BIT(Local_U8_UCSRCValue,UMP1_BIT);

#elif UART_PARITY_MODE   ==   UART_PARITY_EVEN
	CLR_BIT(Local_U8_UCSRCValue,UMP0_BIT);
	SET_BIT(Local_U8_UCSRCValue,UMP1_BIT);

#elif UART_PARITY_MODE   ==   UART_PARITY_ODD
	SET_BIT(Local_U8_UCSRCValue,UMP0_BIT);
	SET_BIT(Local_U8_UCSRCValue,UMP1_BIT);

#endif

#if  UART_STOP_BITS   ==   UART_1_STOP_BIT
	CLR_BIT(Local_U8_UCSRCValue,USBS_BIT);
#elif  UART_STOP_BITS   ==   UART_2_STOP_BIT
	SET_BIT(Local_U8_UCSRCValue,USBS_BIT);
#endif

	//TO SELECT BAUD RATE -> 9600
	UBRRL_REG = ((u32)F_OSC / (u32)(16 * (u32)UART_BAUD_RATE )) - 1;

	//TO WRITE ONLY ONCE IN THE REGISTER
	UCSRC_REG = Local_U8_UCSRCValue;

	//ENABLE TRANSMITTER AND RECIEVER
	SET_BIT(UCSRB_REG,RXEN_BIT);
	SET_BIT(UCSRB_REG,TXEN_BIT);

}

void M_UART_Void_UARTSend(u8 Copy_U8_Data)
{
   UDR_REG = Copy_U8_Data;
   u32 Local_U32_Counter = 0;
   //Check flag first before exiting the function
   while(Local_U32_Counter < POLLING_TIME)
   {
  	 Local_U32_Counter++;
   	 if(GET_BIT(UCSRA_REG,RXC_BIT) == UART_FINISHED_TRANSMITTING)
 	 {
   			break;
     }
   	}
}

u8   M_UART_U8_UARTReceive(void)
{
	//Check flag first, then return
	u32 Local_U32_Counter = 0;
	while(Local_U32_Counter < POLLING_TIME)
	{
		Local_U32_Counter++;
		if(GET_BIT(UCSRA_REG,RXC_BIT) == UART_FINISHED_RECIEVING)
		{
			break;
		}
	}
	return UDR_REG;
}
