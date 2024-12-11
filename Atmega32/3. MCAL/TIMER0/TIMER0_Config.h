/*
 * TIMER0_Config.h
 *
 *  Created on: Oct 14, 2023
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/*
 * Select WaveForm Generation Mode from this list:
 * 		- NORMAL
 * 		- PWM_PHASE_CORRECT
 * 		- CTC
 * 		- FAST_PWM
 */
#define WAVE_GENERATION_MODE        CTC


/*
 * Select Clock Source from this list:
 * 		- NO_CLK_SOURCE
 * 		- NO_PRESCALER
 * 		- DIVISION_FACTOR_8
 * 		- DIVISION_FACTOR_64
 * 		- DIVISION_FACTOR_265
 * 		- DIVISION_FACTOR_1024
 * 		- T0_FALLING_EDGE
 * 		- T0_RISING_EDGE
 */
#define CLOCK_SELECT           DIVISION_FACTOR_64


#endif /* TIMER0_CONFIG_H_ */
