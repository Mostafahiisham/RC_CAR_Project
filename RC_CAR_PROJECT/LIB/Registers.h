/*
 * Registers.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Mostafa Hisham
 *      Layer: LIB
 */

#ifndef INCLUDE_REGISTERS_H_
#define INCLUDE_REGISTERS_H_

					/*****DIO Registers******/

#define DDRA 			*((volatile u8*)0x3A)
#define DDRB            *((volatile u8*)0x37)
#define DDRC            *((volatile u8*)0x34)
#define DDRD			*((volatile u8*)0x31)

#define PORTA           *((volatile u8*)0x3B)
#define PORTB           *((volatile u8*)0x38)
#define PORTC           *((volatile u8*)0x35)
#define PORTD           *((volatile u8*)0x32)

#define PINA            *((volatile u8*)0x39)
#define PINB            *((volatile u8*)0x36)
#define PINC            *((volatile u8*)0x33)
#define PIND            *((volatile u8*)0x30)

				/***** External Interrupt Registers *****/
#define GICR 			*((volatile u8*)0x5B)
#define GIFR			*((volatile u8*)0x5A)
#define MCUCR			*((volatile u8*)0x55)
#define MCUCSR			*((volatile u8*)0x54)
				/***** Global Interrupt Registers *****/
#define SREG            *((volatile u8*)0x5F)
					/***** ADC Registers *****/
#define ADMUX 			*((volatile u8*)0x27)	/*ADC MULTIPLEXER SELECTION*/
#define ADCSRA			*((volatile u8*)0x26)
#define ADCH 			*((volatile u8*)0x25) 	/*ADC HIGH REGISTER*/
#define ADCL			*((volatile u8*)0x24) 	/*ADC LOW REGISTER*/
#define ADC 			*((volatile u16*)0x24)

					/***** TIMERS Registers *****/
#define TCCR0			*((volatile u8*)0x53)	/* TIMER 0 CONTROL REGISTER */
#define TCNT0 			*((volatile u8*)0x52)
#define OCR0			*((volatile u8*)0x5C)

#define TCCR1A			*((volatile u8*)0x4F)	/* TIMER 1A CONTROL REGISTTER */
#define TCCR1B			*((volatile u8*)0x4E)	/* TIMER 1B CONTROL REGISTER */
#define TCNT1H			*((volatile u8*)0x4D)
#define TCNT1L			*((volatile u8*)0x4C)
#define TCNT1	        *((volatile u16*)0x4C)
#define OCR1AH			*((volatile u8*)0x4B)
#define OCR1AL			*((volatile u8*)0x4A)
#define OCR1A			*((volatile u16*)0x4A)
#define OCR1BH			*((volatile u8*)0x49)
#define OCR1BL			*((volatile u8*)0x48)
#define OCR1B			*((volatile u16*)0x48)
#define ICR1H			*((volatile u8*)0x47)
#define ICR1L			*((volatile u8*)0x46)
#define ICR1 			*((volatile u16*)0x46)


#define TCCR2 			*((volatile u8*)0x45)	/* TIMER 2 CONTROL  REGISTER */
#define TCNT2			*((volatile u8*)0x44)
#define OCR2			*((volatile u8*)0x43)


#define TIMSK			*((volatile u8*)0x59)

				/*****WATCH DOG TIMER REGISTER *****/
#define WDTCR 			*((volatile u8*)0x41)
					/***** USART REGISTERS *****/
#define	UDR				*((volatile u8*)0x2C)
#define UCSRA			*((volatile u8*)0x2B)
#define UCSRB			*((volatile u8*)0x2A)
#define	UBRRL			*((volatile u8*)0x29)
#define UBBRH			*((volatile u8*)0x40)
#define UCSRC			*((volatile u8*)0x40)
						/***** SPI REGISTERS *****/
#define SPCR			*((volatile u8*)0x2D)
#define SPSR			*((volatile u8*)0x2E)
#define	SPDR			*((volatile u8*)0x2F)
#endif /* INCLUDE_REGISTERS_H_ */
