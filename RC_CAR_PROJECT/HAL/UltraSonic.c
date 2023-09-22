/*
 * UltraSonic.c
 *
 *  Created on: Sep 21, 2023
 *      Author: Mostafa Hisham
 *      Layer : HAL
 *      SWC   : ULTRASONIC SENSOR - IMPLEMENTATION
 */
#include<Std_Types.h>
#include<Registers.h>
#include<DIO.h>
#include<TIMER.h>
#include<ICU.h>
#include<UltraSonic.h>
#include<util/delay.h>

static  volatile u16  READING1 , READING2;
static volatile u8 flag ;

 void ICU_FUNCTION(u16 value);

void ULTRASONIC_Init(void)
{
	TIMER_1Init();
	ICU_Init();
	ICU_EnableNotification();
	ICU_SetCallBack(ICU_FUNCTION);
}


u8 ULTRASONIC_ReadDistance(void)
{
	u8 distance ;
	u16 time = 0;
	 flag = 0;
	TIMER_Preload(0,TIMER1);
	DIO_SetPinLevel(DIO_PORTD,DIO_PIN5,PIN_HIGH);
	_delay_us(10);
	DIO_SetPinLevel(DIO_PORTD,DIO_PIN5,PIN_LOW);
	ICU_SetEdge(ICU_EDGE_RISING);
	ICU_EnableNotification();
	while(flag<2);
	time = READING2 - READING1 ;
	distance =  ((time*34600) /16000000);
	ICU_DisableNotification();
	TIMER1_OVFInterruptDisable();
	return distance;
}
 void ICU_FUNCTION(u16 value)
{
	if(flag == 0)
	{
		READING1 = value;
		flag = 1;
		ICU_SetEdge(ICU_EDGE_FALLING);
	}
	else if(flag == 1)
	{
		READING2 = value;
		flag = 2;
		ICU_SetEdge(ICU_EDGE_RISING);
		ICU_DisableNotification();
	}

}
