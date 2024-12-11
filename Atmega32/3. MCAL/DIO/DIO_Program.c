/*
 * DIO_Program.c
 *
 *  Created on: 9 Sep 2023
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"



void DIO_voidSetPinDirection(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Direction)
{
if(copy_u8Direction == DIO_PIN_INPUT)
{
switch(copy_u8Port)
{
case DIO_PORTA:CLR_BIT(DDRA,copy_u8Pin); break;
case DIO_PORTB:CLR_BIT(DDRB,copy_u8Pin); break;
case DIO_PORTC:CLR_BIT(DDRC,copy_u8Pin); break;
case DIO_PORTD:CLR_BIT(DDRD,copy_u8Pin); break;
}
}
else if(copy_u8Direction ==DIO_PIN_OUTPUT)
{
	switch(copy_u8Port)
	{
	case DIO_PORTA:SET_BIT(DDRA,copy_u8Pin); break;
	case DIO_PORTB:SET_BIT(DDRB,copy_u8Pin); break;
	case DIO_PORTC:SET_BIT(DDRC,copy_u8Pin); break;
	case DIO_PORTD:SET_BIT(DDRD,copy_u8Pin); break;
	}
}
}
void DIO_voidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value)
{
if(copy_u8Value==DIO_LOW)
{
	switch(copy_u8Port)
		{
		case DIO_PORTA:CLR_BIT(PORTA,copy_u8Pin); break;
		case DIO_PORTB:CLR_BIT(PORTB,copy_u8Pin); break;
		case DIO_PORTC:CLR_BIT(PORTC,copy_u8Pin); break;
		case DIO_PORTD:CLR_BIT(PORTD,copy_u8Pin); break;
		}
}
else if(copy_u8Value==DIO_HIGH)
{
	switch(copy_u8Port)
			{
			case DIO_PORTA:SET_BIT(PORTA,copy_u8Pin); break;
			case DIO_PORTB:SET_BIT(PORTB,copy_u8Pin); break;
			case DIO_PORTC:SET_BIT(PORTC,copy_u8Pin); break;
			case DIO_PORTD:SET_BIT(PORTD,copy_u8Pin); break;
			}
}
}
void DIO_voidSetPortDirection(u8 copy_u8Port,u8 copy_u8Direction)
{
switch (copy_u8Port)
{
case DIO_PORTA:DDRA=copy_u8Direction; break;
case DIO_PORTB:DDRB=copy_u8Direction; break;
case DIO_PORTC:DDRC=copy_u8Direction; break;
case DIO_PORTD:DDRD=copy_u8Direction; break;
}
}
void DIO_voidSetPortValue(u8 copy_u8Port,u8 copy_u8Value)
{
switch(copy_u8Port)
{
case DIO_PORTA:PORTA=copy_u8Value; break;
case DIO_PORTB:PORTB=copy_u8Value; break;
case DIO_PORTC:PORTC=copy_u8Value; break;
case DIO_PORTD:PORTD=copy_u8Value; break;
}

}
void DIO_voidTogpinValue(u8 copy_u8Port,u8 copy_u8Pin)
{
switch(copy_u8Port)
{
case DIO_PORTA:TOG_BIT(PORTA,copy_u8Pin); break;
case DIO_PORTB:TOG_BIT(PORTB,copy_u8Pin); break;
case DIO_PORTC:TOG_BIT(PORTC,copy_u8Pin); break;
case DIO_PORTD:TOG_BIT(PORTD,copy_u8Pin); break;
}

}
u8 DIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin)
{
u8 Local_u8ReturnValue;
switch(copy_u8Port)
{
case DIO_PORTA:Local_u8ReturnValue=GET_BIT(PINA,copy_u8Pin); break;
case DIO_PORTB:Local_u8ReturnValue=GET_BIT(PINB,copy_u8Pin); break;
case DIO_PORTC:Local_u8ReturnValue=GET_BIT(PINC,copy_u8Pin); break;
case DIO_PORTD:Local_u8ReturnValue=GET_BIT(PIND,copy_u8Pin); break;
}
return Local_u8ReturnValue;
}
