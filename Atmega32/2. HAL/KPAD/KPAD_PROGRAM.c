/*
 * KPAD_PROGRAM.c
 *
 *  Created on: 22 Sep 2023
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_Interface.h"

#include"KPAD_CONFIG.h"
#include"KPAD_INTERFACE.h"

u8 KPAD_u8GetPressedKey()
{
	u8 Local_u8KPADValues[KPAD_ROW_NUMBER][KPAD_COL_NUMBER] = KPAD_VALUES;
	u8 Local_u8ReturnValue = KPAD_NO_PRESSED_KEY;
	u8 Local_u8ColPins[KPAD_COL_NUMBER] = KPAD_COL_PINS;
	u8 Local_u8RowPins[KPAD_ROW_NUMBER] = KPAD_ROW_PINS;

	for(u8 Local_u8ColCounter=0 ; Local_u8ColCounter<KPAD_COL_NUMBER ; Local_u8ColCounter++)
	{
		DIO_voidSetPinValue(KPAD_PORT, Local_u8ColPins[Local_u8ColCounter], DIO_LOW);
		for(u8 Local_u8RowCounter = 0; Local_u8RowCounter<KPAD_ROW_NUMBER; Local_u8RowCounter++)
		{
			if(DIO_u8GetPinValue(KPAD_PORT, Local_u8RowPins[Local_u8RowCounter]) == DIO_LOW)
			{
				Local_u8ReturnValue = Local_u8KPADValues[Local_u8RowCounter][Local_u8ColCounter];

				while(DIO_u8GetPinValue(KPAD_PORT, Local_u8RowPins[Local_u8RowCounter]) == DIO_LOW)
				{

				}

				return Local_u8ReturnValue;
			}
		}
		// Get to its ground state high -> next col
		DIO_voidSetPinValue(KPAD_PORT, Local_u8ColPins[Local_u8ColCounter], DIO_HIGH);

	}

	return Local_u8ReturnValue;
}

void KPAD_voidPinConfiguration()
{
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_COL0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_COL1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_COL2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_COL3, DIO_PIN_OUTPUT);

	DIO_voidSetPinDirection(KPAD_PORT, KPAD_ROW0, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_ROW1, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_ROW2, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_ROW3, DIO_PIN_INPUT);
	//pull up
	DIO_voidSetPinValue(KPAD_PORT, KPAD_ROW0, DIO_HIGH);
	DIO_voidSetPinValue(KPAD_PORT, KPAD_ROW1, DIO_HIGH);
	DIO_voidSetPinValue(KPAD_PORT, KPAD_ROW2, DIO_HIGH);
	DIO_voidSetPinValue(KPAD_PORT, KPAD_ROW3, DIO_HIGH);

}

