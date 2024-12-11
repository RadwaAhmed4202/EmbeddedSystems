/*
 * GIE_PROGRAM.C
 *
 *  Created on: 30 Sep 2023
 */

#include "STD_TYPE.h"
#include"BIT_MATH.h"

#include"GIE_INTERFACE.h"
#include"GIE_REGISTER.h"

void GIE_voidEnableGlobalInterrupt()
{
	SET_BIT(SREG, SREG_I);
}

void GIE_voidDisableGlobalInterrupt()
{
	CLR_BIT(SREG, SREG_I);
}
