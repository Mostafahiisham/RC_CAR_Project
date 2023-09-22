/*
 * ICU.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : ICU - IMPLEMENTATION
 */
#include<Std_Types.h>
#include<Macros.h>
#include<Registers.h>
#include<DIO.h>
#include<ICU.h>
#include<ICU_Private.h>

static void(*ICU_CallBack)(u16 value) = NULL;

/*ICU ISR*/
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	ICU_CallBack(ICR1);
}
void ICU_Init()
{
	/* input capture unit noise canceler */
	SET_BIT(TCCR1B,TCCR1B_ICNC1);
	/*SET ICP Pin Input */
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN6,PIN_INPUT);
}
void ICU_SetEdge(ICU_EdgeType edge)
{
	/* set the trigger edge */
	switch(edge)
	{
	case ICU_EDGE_FALLING :
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	break;
	case ICU_EDGE_RISING :
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	break;
	default:
	break;
	}
}
void ICU_SetCallBack(void (*ICU_PTR)(u16 value))
{
	ICU_CallBack = ICU_PTR;
	/* ICU Interrupt Enable */
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_DisableNotification(void)
{
	/* ICU Interrupt Disable */
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_EnableNotification(void)
{
	/* ICU Interrupt Enable */
	SET_BIT(TIMSK,TIMSK_TICIE1);
}



