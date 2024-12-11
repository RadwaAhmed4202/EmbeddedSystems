/*
 * TIMER0_Interface.h
 *
 *  Created on: Oct 13, 2023
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit();

void TIMER0_voidSetNormalModeParameters(u8 Copy_u8Preload , u32 Copy_u32OverFlowCounts);

void TIMER0_voidSetCTCModeParameters(u8 Copy_u8CompValue , u32 Copy_u32CompMatchCounts);

void TIMER0_voidCallBack(void (*Copy_pvCallBack) (void));

#endif /* TIMER0_INTERFACE_H_ */
