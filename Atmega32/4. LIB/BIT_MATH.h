/*
 * BIT_MATH.h
 *
 *  Created on: 8 Sep 2023
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define SET_BIT(Reg,Bit_no)   Reg|=(1<<Bit_no)
#define CLR_BIT(Reg,Bit_no)   Reg&=(~(1<<Bit_no))
#define TOG_BIT(Reg,Bit_no)   Reg^=(1<<Bit_no)
#define GET_BIT(Reg,Bit_no)   ((Reg>>Bit_no)&1)


#endif /* BIT_MATH_H_ */
