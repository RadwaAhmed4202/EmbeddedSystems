/*
 * TIMER0_Register.h
 *
 *  Created on: Oct 13, 2023
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

#define TCCR0            *((volatile u8*)0x53)
#define TCCR0_WGM00      6
#define TCCR0_WGM01      3
#define TCCR0_COM00      4

#define TCNT0            *((volatile u8*)0x52)

#define OCR0             *((volatile u8*)0x5c)

#define TIMSK            *((volatile u8*)0x59)
#define TIMSK_TOIE0      0
#define TIMSK_OCIE0      1

#define TIFR             *((volatile u8*)0x58)

#endif /* TIMER0_REGISTER_H_ */
