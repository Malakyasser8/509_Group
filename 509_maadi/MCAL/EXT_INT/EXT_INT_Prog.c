/*
 * EXT_INT_Prog.c
 *
 *  Created on: Sep 9, 2022
 *      Author: malak
 */

#include "EXT_INT_Interface.h"
#include "EXT_INT_Private.h"

//MicroController Unit Control Register
void M_EXT_INT_Void_ExtIntInit(u8 Copy_U8_Num)
{
	switch(Copy_U8_Num)
	{
	case EXT_INT_0:
#if SENSE_CONTROL_0  ==  RISING_EDGE
	//To select -> Rising Edge -> Generate INT
	SET_BIT(MCUCR_REG,ISC00_BIT);//Interrupt Sense Control 0
	SET_BIT(MCUCR_REG,ISC01_BIT);

#elif SENSE_CONTROL_0  ==  FALLING_EDGE

	CLR_BIT(MCUCR_REG,ISC00_BIT);
	SET_BIT(MCUCR_REG,ISC01_BIT);

#elif SENSE_CONTROL_0  ==  LOW_LEVEL

	CLR_BIT(MCUCR_REG,ISC00_BIT);
	CLR_BIT(MCUCR_REG,ISC01_BIT);

#elif SENSE_CONTROL_0  ==  ANY_LOGICAL_CHANGE

	SET_BIT(MCUCR_REG,ISC00_BIT);
	CLR_BIT(MCUCR_REG,ISC01_BIT);

#endif

	//To enable local INT
	SET_BIT(GICR_REG,INT0_BIT);
	break;
	case EXT_INT_1:
#if SENSE_CONTROL_1  ==  RISING_EDGE
	//To select -> Rising Edge -> Generate INT
	SET_BIT(MCUCR_REG,ISC10_BIT);//Interrupt Sense Control 0
	SET_BIT(MCUCR_REG,ISC11_BIT);

#elif SENSE_CONTROL_1  ==  FALLING_EDGE

	CLR_BIT(MCUCR_REG,ISC10_BIT);
	SET_BIT(MCUCR_REG,ISC11_BIT);

#elif SENSE_CONTROL_1  ==  LOW_LEVEL

	CLR_BIT(MCUCR_REG,ISC10_BIT);
	CLR_BIT(MCUCR_REG,ISC11_BIT);

#elif SENSE_CONTROL_1  ==  ANY_LOGICAL_CHANGE

	SET_BIT(MCUCR_REG,ISC10_BIT);
	CLR_BIT(MCUCR_REG,ISC11_BIT);

#endif
		//To enable local INT
		SET_BIT(GICR_REG,INT1_BIT);
		break;
	case EXT_INT_2:
#if SENSE_CONTROL_2  ==  RISING_EDGE
	//To select -> Rising Edge -> Generate INT
	SET_BIT(MCUCSR_REG,ISC2_BIT);//Interrupt Sense Control 0

#elif SENSE_CONTROL_2  ==  FALLING_EDGE

	CLR_BIT(MCUCSR_REG,ISC2_BIT);

#endif
		//To enable local INT
		SET_BIT(GICR_REG,INT2_BIT);
		break;
	default:
		break;
}
	//To enable global INT
	SET_BIT(SREG_REG,I_BIT);

}
