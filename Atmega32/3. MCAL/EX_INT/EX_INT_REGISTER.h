/*
 * EX_INT_REGISTER.h
 *
 *  Created on: 30 Sep 2023
 */

#ifndef EX_INT_REGISTER_H_
#define EX_INT_REGISTER_H_

#define MCUCR		*((volatile u8*)0x55) 	//casting it is a pointer (u8*)-------volatile (do not delete while unusage)
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

#define MCUCSR		*((volatile u8*)0x54)
#define MCUCSR_ISC2		6

#define GICR		*((volatile u8*)0x5B)
#define GICR_INT2		5
#define GICR_INT0		6
#define GICR_INT1		7

#endif /* EX_INT_REGISTER_H_ */
