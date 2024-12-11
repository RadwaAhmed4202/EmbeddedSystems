/*
 * ADC_PRIVATE.h
 *
 *  Created on: 7 Oct 2023
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define AREF	0
#define AVCC	1
#define INTERNAL_2_56V	3

#define CLEAR		0
#define SFIOR_MASK 0b00011111;
#define ADMUX_MASK 0b11100000;

#define LIFT_ADJUST		1
#define RIGHT_ADJUST	0

#define ENABLE_AUTO_TRIGGER		1
#define DISABLE_AUTO_TRIGGER	0

#define FREE_RUNNING			0
#define	ANALOG_COMPARATOR		1
#define	INT0					2
#define TIMER0_COMPARE_MATCH	3
#define TIMER0_OVERFLOW			4
#define TIMER0_COMPARE_MATCH_B	5
#define TIMER1_OVERFLOW			6
#define TIMER1_CAPTURE_EVENT	7

#define DIVISION_FACTOR_2		1
#define DIVISION_FACTOR_4		2
#define DIVISION_FACTOR_8		3
#define DIVISION_FACTOR_16		4
#define DIVISION_FACTOR_32		5
#define DIVISION_FACTOR_64		6
#define DIVISION_FACTOR_128		7


#endif /* ADC_PRIVATE_H_ */
