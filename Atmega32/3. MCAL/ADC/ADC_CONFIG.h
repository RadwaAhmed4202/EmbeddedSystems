/*
 * ADC_CONFIG.h
 *
 *  Created on: 7 Oct 2023
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*Select ADC Reference Selection from this list
 * AREF
 * AVCC
 * INTERNAL_2_56V
 *
 * */
#define ADC_REFERENCE_SELECTION		AVCC
/*Select ADC Adjust from this list
 * LEFT_ADJUST
 * RIGHT_ADJUST
 * */
#define ADC_ADJUST		RIGHT_ADJUST

/*Select ADC Auto Trigger from this list
 * ENABLE_AUTO_TRIGGER
 * DISABLE_AUTO_TRIGGER
 * */
#define ADC_AUTO_TRIGGER	DISABLE_AUTO_TRIGGER

#if ADC_AUTO_TRIGGER
/*Select ADC Auto Trigger Source from this list
 * Free_Running
 * Analog_Comparator
 * INT0
 * TIMER0_COMPARE_MATCH
 * TIMER0_OVERFLOW
 * TIMER0_COMPARE_MATCH_B
 * TIMER1_OVERFLOW
 * Timer1_Capture_Event
 */
#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING
#endif

/*Select ADC Prescaler from this list
 * DIVISION_FACTOR_2
 * DIVISION_FACTOR_4
 * DIVISION_FACTOR_8
 * DIVISION_FACTOR_16
 * DIVISION_FACTOR_32
 * DIVISION_FACTOR_64
 * DIVISION_FACTOR_128
 * */
#define ADC_PRESCALER		DIVISION_FACTOR_16

#endif /* ADC_CONFIG_H_*/`
