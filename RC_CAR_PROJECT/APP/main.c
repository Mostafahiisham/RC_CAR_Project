/*
 * main.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Mostafa Hisham
 *      Layer : APP
 *      SWC   : APP - IMPLEMENTATION
 */
#include<Std_Types.h>
#include<Macros.h>
#include<Registers.h>
#include<DIO.h>
#include<GIE.h>
#include<USART.h>
#include<TIMER.h>
#include<ADC.h>
#include<ICU.h>
#include<UltraSonic.h>
#include<DC_Motor.h>
#include<main.h>
#include<util/delay.h>
u8 i = 0;
u8 distance ;
u16 LDR_READING;

void TOGGLE_LIGHT(void);
void CAR_LIGHT_NOTIFICATION(void);

void main(void)
{
	USART_Init();
	TIMER_2Init();
	//UART RX PIN
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN7,PIN_OUTPUT);
	while(1)
	{
		USART_rxISR(CAR_CONTROL);
		TIMER_SetCTCValue(i,TIMER2);
		CAR_LIGHT();
	}
}
/****************************************************************************/
/****************** car light control with LDR (ADC) function *********************************/
/****************************************************************************/
void CAR_LIGHT(void)
{
	ADC_Init();
	//CAR LIGHT
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN7,PIN_OUTPUT);
	//LDR
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,PIN_INPUT);
	GIE_Enable();
	ADC_AnalogReadASynchronous(ADC_CHANNEL_ADC0,&CAR_LIGHT_NOTIFICATION,&LDR_READING);
}

void CAR_LIGHT_NOTIFICATION(void)
{
	if(LDR_READING > 500)
	{
		DIO_SetPinLevel(DIO_PORTB,DIO_PIN4,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTB,DIO_PIN5,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTB,DIO_PIN6,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTB,DIO_PIN7,PIN_LOW);
	}
	else if(LDR_READING < 500)
	{
		DIO_SetPinLevel(DIO_PORTB,DIO_PIN4,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTB,DIO_PIN5,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTB,DIO_PIN6,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTB,DIO_PIN7,PIN_HIGH);
	}
}
/****************************************************************************/
/****************** obstacle distance from the car function *********************************/
/****************************************************************************/

void OBSTACLE_DETECT(void)
{
	GIE_Enable();
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN5,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN3,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,PIN_OUTPUT);

	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,PIN_OUTPUT);
	ULTRASONIC_Init();
	GIE_Enable();
	distance = ULTRASONIC_ReadDistance();

	if(distance >= 80 )
	{
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN1,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN2,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN3,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN4,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN5,PIN_LOW);
	}
	else if(distance >= 60 && distance < 80)
	{
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN1,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN2,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN3,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN4,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN5,PIN_LOW);
	}
	else if(distance >= 40 && distance < 60)
	{
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN1,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN2,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN3,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN4,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN5,PIN_LOW);
	}
	else if(distance >= 20 && distance < 40)
	{
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN1,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN2,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN3,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN4,PIN_LOW);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN5,PIN_LOW);
	}
	else if(distance < 20)
	{

		DIO_SetPinLevel(DIO_PORTA,DIO_PIN1,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN2,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN3,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN4,PIN_HIGH);
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN5,PIN_HIGH);
	}
}

/****************************************************************************/
/******************************** car direction functions *********************************/
/****************************************************************************/
void MOVE_Forward()
{
	// MOVE THE CAR FORWARD
	DCMOTOR_RotateCounterClockWise(MOTOR1);
	DCMOTOR_RotateCounterClockWise(MOTOR2);
	DCMOTOR_RotateCounterClockWise(MOTOR3);
	DCMOTOR_RotateCounterClockWise(MOTOR4);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN0,PIN_LOW);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN1,PIN_LOW);
	OBSTACLE_DETECT();
}
void MOVE_Backward(void)
{


	/* MOVE THE CAR BACKWARD*/
	DCMOTOR_RotateClockwise(MOTOR1);
	DCMOTOR_RotateClockwise(MOTOR2);
	DCMOTOR_RotateClockwise(MOTOR3);
	DCMOTOR_RotateClockwise(MOTOR4);
	/*STOP BRAKE LIGHTS */
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN0,PIN_LOW);
	/*REVERSE lights */
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,PIN_OUTPUT);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN1,PIN_HIGH);
}

void MOVE_Right(void)
{
	/* MOVE THE CAR RIGHT */
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,PIN_INPUT);
	DCMOTOR_Stop(MOTOR1);
	DCMOTOR_Stop(MOTOR2);
	DCMOTOR_RotateCounterClockWise(MOTOR3);
	DCMOTOR_RotateCounterClockWise(MOTOR4);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN0,PIN_LOW);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN1,PIN_LOW);
}
void MOVE_Left(void)
{
	/* MOVE THE CAR LEFT */
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,PIN_INPUT);
	DCMOTOR_RotateCounterClockWise(MOTOR1);
	DCMOTOR_RotateCounterClockWise(MOTOR2);
	DCMOTOR_Stop(MOTOR3);
	DCMOTOR_Stop(MOTOR4);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN0,PIN_LOW);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN1,PIN_LOW);
}
void CAR_Brake(void)
{
	/* brake lights */
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN0,PIN_OUTPUT);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN0,PIN_HIGH);
	/* stop the car motors */
	DCMOTOR_Stop(MOTOR1);
	DCMOTOR_Stop(MOTOR2);
	DCMOTOR_Stop(MOTOR3);
	DCMOTOR_Stop(MOTOR4);
	DIO_SetPinLevel(DIO_PORTB,DIO_PIN1,PIN_LOW);
}
/****************************************************************************/
/**************************** car speed control functions *********************************/
/****************************************************************************/
void SPEED_Increase(void)
{
	// INCREASE THE CAR SPEED
		i += 40;
}
void SPEED_Decrease(void)
{
	// DECREASE THE CAR SPEED
		i -= 40;
}
/****************************************************************************/
/****************************** car park lights functions *********************************/
/****************************************************************************/
void TOGGLE_LIGHT(void)
{
		DIO_TogglePinLevel(DIO_PORTB,DIO_PIN2);
		DIO_TogglePinLevel(DIO_PORTB,DIO_PIN3);
}
void WAIT_Lights(void)
{
	//PARKING LIGHTS
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,PIN_OUTPUT);
	TIMER_0Init();
	TIMER_Preload(94,TIMER0);
	TIMER0_SetInterval(391,TOGGLE_LIGHT);
	GIE_Enable();
}
void WAIT_LightsTurnOff(void)
{
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,PIN_INPUT);
}
void RIGHT_Sign(void)
{
	// RIGHT SIGN LIGHTS
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,PIN_INPUT);
	TIMER_0Init();
	TIMER_Preload(94,TIMER0);
	TIMER0_SetInterval(391,TOGGLE_LIGHT);
	GIE_Enable();
}
void LEFT_Sign(void)
{
	//LEFT SIGN LIGHTS
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,PIN_INPUT);
	TIMER_0Init();
	TIMER_Preload(94,TIMER0);
	TIMER0_SetInterval(391,TOGGLE_LIGHT);
	GIE_Enable();
}
/****************************************************************************/
/****************** car control function *********************************/
/****************************************************************************/
void CAR_CONTROL(u8 data)
{
	switch(data)
		{
	case '0':
		CAR_Brake();
		break;
	case '+' :
		SPEED_Increase();
		break;
	case '-' :
		SPEED_Decrease();
		break;
	case 'W' :
		MOVE_Forward();
		break;
	case 'S' :
		MOVE_Backward();
		break;
	case 'D' :
		MOVE_Right();
		break;
	case 'A' :
		MOVE_Left();
		break;
	case 'P' :
		WAIT_Lights();
		break;
	case 'O' :
		WAIT_LightsTurnOff();
		break;
	case 'R' :
		RIGHT_Sign();
		break;
	case 'L' :
		LEFT_Sign();
		break;
	}
}
