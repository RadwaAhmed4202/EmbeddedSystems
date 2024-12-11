/*
 * TIMER0_Private.h
 *
 *  Created on: Oct 14, 2023
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define NORMAL                 0
#define PWM_PHASE_CORRECT      1
#define CTC                    2
#define FAST_PWM               3


#define NO_CLK_SOURCE            0
#define NO_PRESCALER             1
#define DIVISION_FACTOR_8        2
#define DIVISION_FACTOR_64       3
#define DIVISION_FACTOR_265      4
#define DIVISION_FACTOR_1024     5
#define T0_FALLING_EDGE          6
#define T0_RISING_EDGE           7

#endif /* TIMER0_PRIVATE_H_ */
