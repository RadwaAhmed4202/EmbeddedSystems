/*
 * SPI_Program.c
 *
 *  Created on: Nov 11, 2023
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Register.h"
#include "SPI_Interface.h"
#include "DIO_Interface.h"

void SPI_voidMasterInit()
{

	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);

	SET_BIT(SPCR,SPCR_MSTR);

	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);

	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSlaveInit()
{
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT);

	CLR_BIT(SPCR,SPCR_MSTR);

	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;

	while( GET_BIT(SPSR,SPSR_SPIF) == 0 );

	return SPDR;
}
