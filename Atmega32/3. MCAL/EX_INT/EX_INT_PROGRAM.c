/*
 * EX_INT.C
 *
 *  Created on: 30 Sep 2023
 */

#include"STD_TYPE.h"
#include"BIT_MATH.h"

#include"EX_INT_INTERFACE.h"
#include"EX_INT_REGISTER.h"
#include"DIO_interface.h"
#include"EX_INT_CONFIG.h"
#include <util/delay.h>

//0 not wild, static: (global only here)
static void(*EX_INT_pvCallBackINT0) (void) = 0;
static void(*EX_INT_pvCallBackINT1) (void) = 0;
static void(*EX_INT_pvCallBackINT2) (void) = 0;

void EX_INT_voidEnableINT(u8 Copy_u8_INTNumber, u8 Copy_SenseControl)
{
	switch(Copy_u8_INTNumber)
	{
		case EXINT_INT0:
			switch(Copy_SenseControl)
			{
				case EXINT_LOW_LEVEL:
					CLR_BIT(MCUCR, MCUCR_ISC00);
					CLR_BIT(MCUCR, MCUCR_ISC01);
					SET_BIT(GICR, GICR_INT0);
					break;
				case EXINT_ON_CHANGE:
					SET_BIT(MCUCR, MCUCR_ISC00);
					CLR_BIT(MCUCR, MCUCR_ISC01);
					SET_BIT(GICR, GICR_INT0);
					break;
				case EXINT_FALLING_EDGE:
					CLR_BIT(MCUCR, MCUCR_ISC00);
					SET_BIT(MCUCR, MCUCR_ISC01);
					SET_BIT(GICR, GICR_INT0);
					break;
				case EXINT_RISINGING_EDGE:
					SET_BIT(MCUCR, MCUCR_ISC00);
					SET_BIT(MCUCR, MCUCR_ISC01);
					SET_BIT(GICR, GICR_INT0);
					break;
			}
			break;
		case EXINT_INT1:
			switch(Copy_SenseControl)
			{
				case EXINT_LOW_LEVEL:
					CLR_BIT(MCUCR, MCUCR_ISC10);
					CLR_BIT(MCUCR, MCUCR_ISC11);
					SET_BIT(GICR, GICR_INT1);
					break;
				case EXINT_ON_CHANGE:
					SET_BIT(MCUCR, MCUCR_ISC10);
					CLR_BIT(MCUCR, MCUCR_ISC11);
					SET_BIT(GICR, GICR_INT1);
					break;
				case EXINT_FALLING_EDGE:
					CLR_BIT(MCUCR, MCUCR_ISC10);
					SET_BIT(MCUCR, MCUCR_ISC11);
					SET_BIT(GICR, GICR_INT1);
					break;
				case EXINT_RISINGING_EDGE:
					SET_BIT(MCUCR, MCUCR_ISC10);
					SET_BIT(MCUCR, MCUCR_ISC11);
					SET_BIT(GICR, GICR_INT1);
					break;
			}
			break;
		case EXINT_INT2:
			switch(Copy_SenseControl)
			{
				case EXINT_FALLING_EDGE:
					CLR_BIT(MCUCR, MCUCSR_ISC2);
					SET_BIT(GICR, GICR_INT2);
					break;
				case EXINT_RISINGING_EDGE:
					SET_BIT(MCUCR, MCUCSR_ISC2);
					SET_BIT(GICR, GICR_INT2);
					break;
			}
			break;
	}
}

void EX_INT_voidPinsConfiguration(u8 Copy_u8INTNumber)
{
	switch(Copy_u8INTNumber)
	{
	case EXINT_INT0:
		DIO_Vid_Set_Pin_dir(EXINT_PORT_INT0, EXINT_PIN_INT0, INPUT);
		DIO_Vid_Set_Pin_Val(EXINT_PORT_INT0, EXINT_PIN_INT0, HIGH);
		break;
	case EXINT_INT1:
		DIO_Vid_Set_Pin_dir(EXINT_PORT_INT1, EXINT_PIN_INT1, INPUT);
		DIO_Vid_Set_Pin_Val(EXINT_PORT_INT1, EXINT_PIN_INT1, HIGH);
		break;
	case EXINT_INT2:
		DIO_Vid_Set_Pin_dir(EXINT_PORT_INT2, EXINT_PIN_INT2, INPUT);
		DIO_Vid_Set_Pin_Val(EXINT_PORT_INT2, EXINT_PIN_INT2, HIGH);
		break;
	}

}

void EX_INT_voidCallBackFunction(u8 Copy_u8IntNumber, void (*Copy_pvCallBack) (void))
{
	switch(Copy_u8IntNumber)
	{
	case EXINT_INT0:
		EX_INT_pvCallBackINT0 = Copy_pvCallBack;
		break;
	case EXINT_INT1:
		EX_INT_pvCallBackINT1 = Copy_pvCallBack;
		break;
	case EXINT_INT2:
		EX_INT_pvCallBackINT2 = Copy_pvCallBack;
		break;
	}
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	_delay_ms(500);
	extern u8 IR_Senseor_Value;
	IR_Senseor_Value++;
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	EX_INT_pvCallBackINT1();
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	EX_INT_pvCallBackINT2();
}
