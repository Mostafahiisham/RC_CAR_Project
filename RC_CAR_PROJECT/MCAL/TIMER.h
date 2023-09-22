/*
 * TIMER.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : TIMER - PROTOTYPE
 */

#ifndef MCAL_TIMER_H_
#define MCAL_TIMER_H_
/***TIMER STATE ***/
#define TIMER_OFF				0
#define TIMER_ON				1
/**** timer number ****/
#define TIMER0					1
#define TIMER1					2
#define TIMER2					3
/**** wave form generation mode options ****/
#define	TIMER_OVF				1
#define	TIMER_CTC				2
#define	TIMER_PHASE_PWM 		3
#define	TIMER_FAST_PWM			4
#define TIMER_CTC_OCR1A			5
#define TIMER_CTC_ICR1			6
#define TIMER_FAST_PWM_ICR1 	7
#define TIMER_FAST_PWM_OCR1A	8
/**** NON PWM MODE OPTIONS ****/
#define OC_DISCONNECTED	1
#define OC_TOGGLE			2
#define OC_CLEAR			3
#define OC_SET				4
/**** PHASE CORRECT PWM MODE ****/
#define  OC_PHASE_DISCONNECTED		1
#define  OC_CLR_CTCUP_SET_CTCDOWN	2
#define  OC_SET_CTCUP_CLR_CTCDOWN	3
/**** FAST PWM MODE *****************/
#define OC_FAST_DISCONNECTED		1
#define OC_CLR_CTC_SET_TOP			2
#define OC_SET_CTC_CLR_TOP			3
/*****PRESCALER CLOCK TYPES *********/
#define NO_CLK_SOURCE				0
#define NO_PRESCALING				1
#define	PRESCALER_8					2
#define	PRESCALER_64				3
#define PRESCALER_256				4
#define PRESCALER_1024				5
#define PRESCALER_FALLING_EDGE		6
#define PRESCALER_RISING_EDGE		7

#define	RISING_EDGE				1
#define	FALLING_EDGE			2


void TIMER_0Init(void);//1
void TIMER0_OVFInterruptDisable(void);//2
void TIMER_Preload(u16 preload, u8 number);//3
void TIMER0_SetInterval(u16 interval, void (*ovf_ptr)(void));//4
void TIMER_SetCTCValue(u16 CTC_Value,u8 number);//5
void TIMER0_CTCInterruptDisable(void);//6
void TIMER_CTC0SetCallBack(void(*CTC0_PTR)(void));//7
void TIMER_2Init(void);//8
void TIMER2_SetInterval(u16 interval, void(*ovf2_ptr)(void));
void TIMER_CTC2SetCallBack(void(*CTC2_PTR)(void));
void TIMER_1Init(void);
void TIMER1_SetInterval(u16 interval ,void(*ovf1_ptr)(void));
void TIMER_CTC1ASetCallBack(void(*CTC1A_PTR)(void));
void TIMER_CTC1BSetCallBack(void(*CTC1B_PTR)(void));
void TIMER1_SetTopValue(u16 Top_Value);
void TIMER2_CTCInterruptDisable(void);
void TIMER2_OVFInterruptDisable(void);
void TIMER1_OVFInterruptDisable(void);
void TIMER1_CTC1AInterruptDisable(void);
void TIMER1_CTC1BInterruptDisable(void);
u16 TIMER1_GetValue(void);
#endif /* MCAL_TIMER_H_ */
