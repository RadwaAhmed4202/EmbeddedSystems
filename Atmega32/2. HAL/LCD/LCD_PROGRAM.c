/*
 * LCD_PROGRAM.c
 *
 *  Created on: 15 Sep 2023
 */
#include"STD_TYPES.H"
#include"BIT_MATH.H"
#include"DIO_Interface.H"
#include"LCD_CONFG.H"
#include"LCD_INTERFACE.H"
#include<util/delay.h>

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW);

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_LOW);

}

void LCD_voidSendData(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH);

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Data);

	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_LOW);

}

void LCD_voidInit()
{
	_delay_ms(40);
	LCD_voidSendCommand(0b00111000);
	_delay_ms(1);
	LCD_voidSendCommand(0b00001100);
	_delay_ms(1);
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);

}

void LCD_voidConfiguration()
{
	DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_OUTPUT);

}

void LCD_voidSendString(u8 * Copy_pu8String)
{
	u8 Local_u8Itrator=0;
	while(Copy_pu8String[Local_u8Itrator] != '\0')
	{
		LCD_voidSendData(Copy_pu8String[Local_u8Itrator]);
		Local_u8Itrator++;
	}

}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
	if(Copy_u32Number/10 != 0)
	{
		LCD_voidSendNumber(Copy_u32Number/10);
	}
	LCD_voidSendData(Copy_u32Number%10+48);
}

void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 Local_u8DDRAMAddress;
	if(Copy_u8Y == 0)
	{
		Local_u8DDRAMAddress = Copy_u8X;
	}

	else if(Copy_u8Y == 1)
	{
		Local_u8DDRAMAddress = Copy_u8X + 0x40;
	}

	LCD_voidSendCommand(Local_u8DDRAMAddress + 128);
}

void LCD_voidSendSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 Local_u8CGRAMAddress = Copy_u8PatternNumber*8;
	LCD_voidSendCommand(Local_u8CGRAMAddress + 64);
	for(u8 Local_u8Itrator = 0;Local_u8Itrator<8; Local_u8Itrator++)
	{
		LCD_voidSendData(Copy_pu8Pattern[Local_u8Itrator]);
	}
	LCD_voidGoToXY(Copy_u8X, Copy_u8Y);
	LCD_voidSendData(Copy_u8PatternNumber);
}
