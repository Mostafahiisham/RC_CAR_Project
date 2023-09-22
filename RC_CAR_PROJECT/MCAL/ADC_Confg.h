/*
 * ADC_Confg.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : ADC - CONFIGURATION
 */

#ifndef MCAL_ADC_CONFG_H_
#define MCAL_ADC_CONFG_H_


								/* OPTIONS */
 /*
	ADC_REF_AREF,
	ADC_REF_AVCC,
	ADC_REF_INT
				*/

#define REFERNCE_TYPE 	ADC_REF_AREF
							/* OPTIONS */

  /*  ADC_PRESCALER_2 = 1,
      ADC_PRESCALER_4,
      ADC_PRESCALER_8,
      ADC_PRESCALER_16,
      ADC_PRESCALER_32,
      ADC_PRESCALER_64,
      ADC_PRESCALER_128
					 */

#define PRESCALER_TYPE	ADC_PRESCALER_128
							/* OPTIONS */
/*	ADC_RIGHT_ADJUST,
	ADC_LEFT_ADJUST
					*/

#define ADJUST_TYPE		ADC_RIGHT_ADJUST
							/* OPTIONS */
/*	TRIGGER_ENABLE,
	TRIGGER_DISABLE
					*/
#define TRIGGER_TYPE	TRIGGER_DISABLE

#define ADC_INTERRUPT_MODE ADC_INTERRUPT_ENABLE

#define ADC_TIMEOUT		200000

#endif /* MCAL_ADC_CONFG_H_ */
