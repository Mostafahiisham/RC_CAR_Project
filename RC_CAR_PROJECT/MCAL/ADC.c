/*
 * ADC.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : ADC - IMPLEMENTATION
 */
#include<Std_Types.h>
#include<Macros.h>
#include<Registers.h>
#include<ADC.h>
#include<ADC_Private.h>
#include<ADC_Confg.h>

static void(*ADCAsynch_CallBack)(void) = NULL;
static u16* ADC_G_Reading = NULL;
u8 ADC_State = IDLE;

void ADC_Init(void)
{
	/*choose reference type */
#if REFERNCE_TYPE == ADC_REF_AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif REFERNCE_TYPE == ADC_REF_AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif REFERNCE_TYPE == ADC_REF_INT
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
	#error "Unknown Reference Type"
#endif
	/* choose adjust type */
#if ADJUST_TYPE == ADC_LEFT_ADJUST
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADJUST_TYPE ==ADC_RIGHT_ADJUST
	 CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
	#error"Unknown adjust type"
#endif
#if TRIGGER_TYPE == TRIGGER_ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADATE);
#elif TRIGGER_TYPE == TRIGGER_DISABLE
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#endif

	/* ADC interrupt status */

#if ADC_INTERRUPT_MODE  == ADC_INTERRUPT_ENABLE
		SET_BIT(ADCSRA,ADCSRA_ADIE);
#elif ADC_INTERRUPT_MODE == ADC_INTERRUPT_DISABLE
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
#else
	#error"Undefined interrupt mode"
#endif

		ADCSRA = (ADCSRA & ADC_PRESCALER_MASK) | (PRESCALER_TYPE);
	/*ADC Peripheral Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
u8 ADC_AnalogReadSynchronous(ADC_ChannelType channel, u16 *ADC_Reading)
{
	// variable for timeout protection mechanism
	u32 Local_counter = 0;
	u8 	Local_ErrorState = OK;
	u16 READING;
	if(ADC_State == IDLE)
	{
		/* ADC is now busy */
		ADC_State = BUSY;

		ADMUX =(ADMUX & 0XE0) |(channel & 0x07);
		/* Start Conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		/* Polling (busy waiting) until the conversion flag is set or conter reaching timeout value */
		while((GET_BIT(ADCSRA,ADCSRA_ADIF)== 0)&& (Local_counter != ADC_TIMEOUT));
		{
		Local_counter++;
		}
		if(Local_counter == ADC_TIMEOUT)
		{
		// LOOP IS BROKEN (TIME OUT IS REACHED)
		Local_ErrorState = NOK;
		}
		else
		{ /* Loop is Broken (FLAG IS RISED)*/
			/*CLEAR THE CONVERSION FLAG */
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			/* select the ADC adjust type */
		#if ADJUST_TYPE == ADC_RIGHT_ADJUST
			READING = ADC;
		#elif ADJUST_TYPE == ADC_LEFT_ADJUST
			READING = ADCH;
		#endif
			/* return ADC reading */
			*ADC_Reading = READING;
			/*ADC is finished return it to IDLE */
			ADC_State = IDLE;
		}
	}
	return Local_ErrorState;
}

u8 ADC_AnalogReadASynchronous(ADC_ChannelType channel,void(*ADC_PTR)(void),u16 *ADC_Reading)
{
	u8 Local_ErrorState = OK;
	if(ADC_State ==  IDLE)
	{

		if(ADC_Reading != NULL || ADC_PTR != NULL)
		{
			/*make adc busy not to work until being idle*/
			ADC_State = BUSY;

			/*Initialize the reading variable globally */
			ADC_G_Reading = ADC_Reading;

			/* Initialize the call back notification function*/
			ADCAsynch_CallBack = ADC_PTR;

			/*SET THE REQUIED CHANNEL INTO THE MUX BITS*/
			ADMUX =(ADMUX & 0XE0) |(channel & 0x07);

			/* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/* ADC Interrupt Enable */
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}


	return Local_ErrorState;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	u16 READING;
		#if ADJUST_TYPE == ADC_RIGHT_ADJUST
			READING = ADC;
		#elif ADJUST_TYPE == ADC_LEFT_ADJUST
			READING = ADCH;
		#endif

	/*read ADC result */
	*ADC_G_Reading = READING;

	/*make ADC state IDLE  */
	ADC_State = IDLE;
	/*iNVOKE CALLBACK NOTIFICATION FUNCTION*/
	ADCAsynch_CallBack();

	/*Disable ADC Conversion complete interrupt */
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}

