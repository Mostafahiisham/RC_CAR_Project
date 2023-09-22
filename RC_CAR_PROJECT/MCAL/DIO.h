/*
 * DIO.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : DIO - PROTOYPE
 */

#ifndef INCLUDE_DIO_H_
#define INCLUDE_DIO_H_

/*port type */
typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC ,
	DIO_PORTD
}PORT_TYPE;
/* pin Direction */
typedef enum{
	PIN_INPUT,
	PIN_OUTPUT,
	PIN_INPUT_PULLUP
}PIN_DIRECTION;


/*pin value */
typedef enum {
	PIN_LOW,
	PIN_HIGH
}PIN_LEVEL;

/* port direction */
typedef enum{
	PORT_MODE_OUTPUT = 0XFF,
	PORT_MODE_INPUT = 0
}PORT_DIRECTION;
/* port level*/
typedef enum{
	PORT_LEVEL_LOW = 0,
	PORT_LEVEL_HIGH = 0XFF
}PORT_LEVEL;



/* pin type*/
typedef enum {
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
} PIN_TYPE;

void DIO_SetPinDirection(PORT_TYPE Port ,PIN_TYPE Pin,PIN_DIRECTION Direction);//1
void DIO_SetPinLevel(PORT_TYPE Port,PIN_TYPE Pin,PIN_LEVEL Level);//2
void DIO_SetPortDirection(PORT_TYPE Port,PORT_DIRECTION Direction);//3
void DIO_SetPortLevel(PORT_TYPE Port,PORT_LEVEL Level);//4
u8 DIO_TogglePinLevel (PORT_TYPE Port,PIN_TYPE Pin);//5
u8 DIO_ReadPinLevel (PORT_TYPE Port,PIN_TYPE Pin);//6
u8 DIO_ReadPortlevel(PORT_TYPE Port,PORT_LEVEL Level);//7


#endif /* INCLUDE_DIO_H_ */
