/*
 * ADC_Private.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC	  : ADC - PRIVATE
 */

#ifndef MCAL_ADC_PRIVATE_H_
#define MCAL_ADC_PRIVATE_H_

//REFERNCE SELECTION BITS
#define ADMUX_REFS1			7
#define ADMUX_REFS0			6
//ADC LEFT ADJUST
#define ADMUX_ADLAR			5

#define ADCSRA_ADEN			7		//ADC ENABLE
#define ADCSRA_ADSC			6		//START CONVERSION
#define ADCSRA_ADATE		5		//AUTO TRIGGER ENABLE
#define ADCSRA_ADIF			4		//INTERRUPT FLAG
#define ADCSRA_ADIE			3		//INTERRUPT ENABLE
#define ADCSRA_ADPS2		2		//PRESCALER BIT2
#define ADCSRA_ADPS1		1		//PRESCALER BIT1
#define ADCSRA_ADPS0		0		//PRESCALER BIT0

#define ADC_PRESCALER_MASK 0XF8

#define IDLE 				1
#define BUSY				2



#endif /* MCAL_ADC_PRIVATE_H_ */
