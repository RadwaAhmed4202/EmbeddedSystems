/*
 * KPAD_CONFIG.h
 *
 *  Created on: 22 Sep 2023
 */

#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_

#define KPAD_ROW_NUMBER		4
#define KPAD_COL_NUMBER		4

#define KPAD_VALUES			{{7, 8, 9, 99}, {4, 5, 6, 99}, {1, 2, 3, 99}, {99, 0, 99, 99}}

#define KPAD_PORT			DIO_PORTB
#define KPAD_COL0			DIO_PIN0
#define KPAD_COL1			DIO_PIN1
#define KPAD_COL2			DIO_PIN2
#define KPAD_COL3			DIO_PIN3

#define KPAD_ROW0			DIO_PIN4
#define KPAD_ROW1			DIO_PIN5
#define KPAD_ROW2			DIO_PIN6
#define KPAD_ROW3			DIO_PIN7

#define KPAD_COL_PINS		{KPAD_COL0, KPAD_COL1, KPAD_COL2, KPAD_COL3}
#define KPAD_ROW_PINS		{KPAD_ROW0, KPAD_ROW1, KPAD_ROW2, KPAD_ROW3}


#endif /* KPAD_CONFIG_H_ */
