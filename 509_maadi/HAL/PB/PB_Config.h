/*
 * PB_Config.h
 *
 *  Created on: Aug 27, 2022
 *      Author: malak
 */

#ifndef HAL_PB_PB_CONFIG_H_
#define HAL_PB_PB_CONFIG_H_

//Mode that the Push Button works on from hardware: ACTIVE_HIGH or ACTIVE_LOW
#define       PB_MODE     ACTIVE_HIGH

//Select Pin of Push Button
#define       PUSH_BUTTON0_PIN      PB0_PIN
#define       PUSH_BUTTON1_PIN      PD6_PIN
#define       PUSH_BUTTON2_PIN      PD2_PIN

//Debouncing Time of hardware
#define       PB_DEBOUNCING_TIME    130
#endif /* HAL_PB_PB_CONFIG_H_ */
