/*
 * ADC_Private.h
 *
 *  Created on: Sep 20, 2022
 *      Author: malak
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define      ADMUX_REG           *(volatile u8*)0x27
#define      ADCSRA_REG          *(volatile u8*)0x26
#define      ADCL_REG            *(volatile u16*)0x24//b2ra el etnen registers el High wel Low f nafs el step

//ADMUX REGISTER BITS
#define      MUX0_BIT            0
#define      MUX1_BIT            1
#define      MUX2_BIT            2
#define      MUX3_BIT            3
#define      MUX4_BIT            4
#define      ADLAR_BIT           5
#define      REFS0_BIT           6
#define      REFS1_BIT           7

//ADCSRA REGISTER BITS
#define      ADPS0_BIT            0
#define      ADPS1_BIT            1
#define      ADPS2_BIT            2
#define      ADIF_BIT             4
#define      ADATE_PIN            5
#define      ADSC_BIT             6
#define      ADEN_BIT             7

#define       AVCC                1
#define       AREF_PIN            2
#define       _2V5                3

#define       ADC_DELAY           0

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
