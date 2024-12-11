/*
 * ADC_PROGRAM.c
 *
 *  Created on: 7 Oct 2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_REGISTER.h"
#include "ADC_PRIVATE.h"
#include "ADC_CONFIG.h"
#include "ADC_INTERFACE.h"


static u16 ADC_u16Reading = 0;

void ADC_voidInit()
{
	ADMUX &= CLEAR;
	ADCSRA &= CLEAR;
    SFIOR &= SFIOR_MASK;

	ADMUX |= (ADC_REFERENCE_SELECTION<<ADMUX_REFS0);

	ADMUX |= (ADC_ADJUST<<ADMUX_ADLAR);

	ADCSRA |= (ADC_AUTO_TRIGGER<<ADCSRA_ADATE);

#if	ADC_AUTO_TRIGGER
	SFIOR |= (ADC_AUTO_TRIGGER_SOURCE<<SFIOR_ADTS0);
#endif
	ADCSRA |= ADC_PRESCALER;

	SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u16 ADC_u16StartConversionPolling(u8 Copy_u8Channel)
{
	ADMUX &= ADMUX_MASK;
	ADMUX |= Copy_u8Channel;

	SET_BIT(ADCSRA, ADCSRA_ADSC);//start conversion

	//read flag XX get out after
	while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);

	return ADC;//data in 10 bit
}

void ADC_voidStartConversionInterrupt(u8 Copy_u8Channel)
{
	ADMUX &= ADMUX_MASK;
	ADMUX |= Copy_u8Channel;
	//enable INT first
	SET_BIT(ADCSRA, ADCSRA_ADIF);
	SET_BIT(ADCSRA, ADCSRA_ADSC);//start conversion
}

u16 ADC_u16SendingData()
{
	return ADC_u16Reading;
}

void __vector_16 (void)__attribute__((signal));
void __vector_16 (void)
{
	ADC_u16Reading = ADC;
#if ADC_AUTO_TRIGGER == 0
	CLR_BIT(ADCSRA, ADCSRA_ADIF);
#endif
}
