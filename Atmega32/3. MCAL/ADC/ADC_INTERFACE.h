/*
 * ADC_INTERFACE.h
 *
 *  Created on: 7 Oct 2023
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CHANNEL0	0
#define ADC_CHANNEL1	1
#define ADC_CHANNEL2	2
#define ADC_CHANNEL3	3
#define ADC_CHANNEL4	4
#define ADC_CHANNEL5	5
#define ADC_CHANNEL6	6
#define ADC_CHANNEL7	7

void ADC_voidInit();
u16 ADC_u16StartConversionPolling(u8 Copy_u8Channel);
void ADC_voidStartConversionInterrupt(u8 Copy_u8Channel);
u16 ADC_u16SendingData();


#endif /* ADC_INTERFACE_H_ */
