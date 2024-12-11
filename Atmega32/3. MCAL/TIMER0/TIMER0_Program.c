/*
 * TIMER0_Program.c
 *
 *  Created on: Oct 13, 2023
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_Register.h"
#include "TIMER0_Private.h"
#include "TIMER0_Config.h"
#include "TIMER0_Interface.h"

static u8 TIMER0_u8Preload = 0;
static u32 TIMER0_u32OverFlowCounts = 0;

static void (*TIMER0_pvCallBackFunction) (void) =0;

static u8 TIMER0_u8CompValue = 0;
static u32 TIMER0_u32CompMatchCounts = 0;

void TIMER0_voidInit()
{
#if WAVE_GENERATION_MODE == NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	TCCR0 |= CLOCK_SELECT;

	TCNT0 = TIMER0_u8Preload;

	SET_BIT(TIMSK,TIMSK_TOIE0);

#elif WAVE_GENERATION_MODE == CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	TCCR0 |= CLOCK_SELECT;

	OCR0 = TIMER0_u8CompValue;

	SET_BIT(TIMSK,TIMSK_OCIE0);

#endif
}

void TIMER0_voidSetNormalModeParameters(u8 Copy_u8Preload , u32 Copy_u32OverFlowCounts)
{
	TIMER0_u8Preload = Copy_u8Preload;
	TIMER0_u32OverFlowCounts = Copy_u32OverFlowCounts;
}

void TIMER0_voidSetCTCModeParameters(u8 Copy_u8CompValue , u32 Copy_u32CompMatchCounts)
{
	TIMER0_u8CompValue = Copy_u8CompValue;
	TIMER0_u32CompMatchCounts = Copy_u32CompMatchCounts;
}

void TIMER0_voidCallBack(void (*Copy_pvCallBack) (void))
{
	TIMER0_pvCallBackFunction = Copy_pvCallBack;
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u32 counter=0;
	counter++;
	if(counter == TIMER0_u32OverFlowCounts)
	{
		TIMER0_pvCallBackFunction();
		counter=0;
		TCNT0 = TIMER0_u8Preload;
	}
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	static u32 counter=0;
	counter++;
	if(counter == TIMER0_u32CompMatchCounts)
	{
		TIMER0_pvCallBackFunction();
		counter=0;
	}
}
