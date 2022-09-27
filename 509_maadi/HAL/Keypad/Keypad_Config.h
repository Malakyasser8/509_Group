/*
 * Keypad_Config.h
 *
 *  Created on: Sep 19, 2022
 *      Author: malak
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define     KEYPAD_R0_PIN         PC3_PIN
#define     KEYPAD_R1_PIN         PC4_PIN
#define     KEYPAD_R2_PIN         PC5_PIN
#define     KEYPAD_R3_PIN         PC6_PIN

#define     KEYPAD_C0_PIN         PB4_PIN
#define     KEYPAD_C1_PIN         PB5_PIN
#define     KEYPAD_C2_PIN         PB6_PIN
#define     KEYPAD_C3_PIN         PB7_PIN

//SELECT KEYPAD BOUNCING TIME IN MILLISECOND
#define     KEYPAD_BOUNCING_TIME  120

//SELECT KEYPAD MODE -> (TYPE_1  OR TYPE_2)
#define         KEYPAD_MODE           TYPE_1
#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */