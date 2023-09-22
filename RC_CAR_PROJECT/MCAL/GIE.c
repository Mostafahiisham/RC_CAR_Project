/*
 * GIE.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : GIE - IMPLEMENTATION
 */

#include<Std_types.h>
#include<Macros.h>
#include<Registers.h>
#include<GIE_Private.h>
#include<GIE.h>

void GIE_Enable(void)
{
	SET_BIT(SREG,SREG_INTERRUPT);
}
void GIE_Disable(void)
{
	CLR_BIT(SREG,SREG_INTERRUPT);
}

