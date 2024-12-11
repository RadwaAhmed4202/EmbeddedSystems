/*
 * USART_Register.h
 *
 *  Created on: 8 May 2024
 */

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

#define UDR        *((volatile u8*)0x2c)

#define UCSRA		*((volatile u8*)0x2b)
#define UCSRA_RXC   7
#define UCSRA_UDRE  5

#define UCSRB		*((volatile u8*)0x2a)
#define UCSRB_RXCIE  7
#define UCSRB_RXEN  4
#define UCSRB_TXEN  3

#define UCSRC		   *((volatile u8*)0x40)

#define UBRRL		*((volatile u8*)0x29)

#endif /* USART_REGISTER_H_ */
