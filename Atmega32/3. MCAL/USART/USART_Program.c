/*
 * USART_Program.c
 *
 *  Created on: 8 May 2024
 */
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "USART_Register.h"
#include "USART_Private.h"
#include "USART_Interface.h"

void USART_void_Init()
{
	//set baud rate
	UBRRL = UBRRL_BAUD_RATE_VAL;

	//set frame format
	UCSRC = FRAME_FORMAT;

	//enable Tx & Rx
	SET_BIT(UCSRB, UCSRB_TXEN);
	SET_BIT(UCSRB, UCSRB_RXEN);
}

void USART_void_Send_Data(u8 Copy_u8_Data)
{
	//waiting for UDR0 to be ready to transmit
	while( GET_BIT(UCSRA, UCSRA_UDRE) == 0 );

	//put data in UDR0
	UDR = Copy_u8_Data;
}

//polling
u8 USART_u8_Receive_Data()
{
	//waiting for UDR0 to be ready to receive
	while( GET_BIT(UCSRA, UCSRA_RXC) == 0 );

	return UDR;
}

void USART_void_Send_Number(u32 Copy_u32_Number)
{
	//'0' is to convert from decimal to char val 'ASCII'
	if(Copy_u32_Number == 0)
		USART_void_Send_Data(Copy_u32_Number + '0');
	else
	{
		while(Copy_u32_Number != 0)
		{
			USART_void_Send_Data((Copy_u32_Number % 10) + '0');	//send digit by digit
			Copy_u32_Number /= 10;
		}
	}
	USART_void_Send_Data('\e');	//'\e' as an indication for the end of number
}

u32 USART_32_Receive_Number()
{
	u32 Local_u32_Number = 0;
	u8 Local_u8_Counter = 0;
	u8 Local_u8_N_Length = 0;
	u8 Local_u8_Number_Digits[8];

	Local_u8_Number_Digits[Local_u8_Counter] = USART_u8_Receive_Data();
	while(Local_u8_Number_Digits[Local_u8_Counter] != '\e')
	{
		Local_u8_Counter++;
		Local_u8_Number_Digits[Local_u8_Counter] = USART_u8_Receive_Data();
		Local_u8_N_Length++;
	}

	for(u8 Local_u8_Iterator=(Local_u8_N_Length); Local_u8_Iterator>0; Local_u8_Iterator--)
	{
		Local_u32_Number = (Local_u32_Number*10)+(Local_u8_Number_Digits[Local_u8_Iterator-1]-48);
	}
	return Local_u32_Number;
}

void USART_void_Send_String(u8* Copy_pU8_String)
{
	while(*Copy_pU8_String != '\0')
	{
		USART_void_Send_Data(*Copy_pU8_String);
		Copy_pU8_String++;
	}
	USART_void_Send_Data('\0');
}

void USART_void_Receive_String(u8* Return_pu8_String)
{
	*Return_pu8_String = USART_u8_Receive_Data();
	while(*Return_pu8_String != '\0')
	{
		Return_pu8_String++;
		*Return_pu8_String = USART_u8_Receive_Data();
	}
}
//INT

void USART_void_Enable_Int_Rx()
{
	SET_BIT(UCSRB, UCSRB_RXCIE);
}

void USART_void_Disable_Int_Rx()
{
	CLR_BIT(UCSRB, UCSRB_RXCIE);
}

/*	declear and initialize Rx_Val in main.c
 * 	this global variable will carry the val. of UDR0
*/
/*
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	extern u8 Rx_Val;
	Rx_Val = UDR;
}
*/

