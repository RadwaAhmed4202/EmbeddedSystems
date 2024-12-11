/*
 * EX_INT_INTERFACE.h
 *
 *  Created on: 30 Sep 2023
 */

#ifndef EX_INT_INTERFACE_H_
#define EX_INT_INTERFACE_H_

#define EXINT_INT0		0
#define EXINT_INT1		1
#define EXINT_INT2		2

#define EXINT_LOW_LEVEL		0
#define EXINT_ON_CHANGE		1
#define EXINT_FALLING_EDGE		2
#define EXINT_RISINGING_EDGE	3

void EX_INT_voidEnableINT(u8 Copy_u8_INTNumber, u8 Copy_SenseControl);

void EX_INT_voidPinsConfiguration(u8 Copy_u8INTNumber);

void EX_INT_voidCallBackFunction(u8 Copy_u8IntNumber, void (*Copy_pvCallBack) (void));

#endif /* EX_INT_INTERFACE_H_ */
