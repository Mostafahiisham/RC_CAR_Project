/*
 * DIO.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : DIO - IMPLEMENTATION
 */
#include<Std_Types.h>
#include<Macros.h>
#include<Registers.h>
#include<DIO.h>
// FUNCTION TO DETECT WHETHER THE PIN IS INPUT OR OUTPUT OR INPUT PULLUP
/*
 * THE FUNCTION TAKES THE PORT TYPE AND THE PIN WHICH IS REQUIRED FOR THE FUNCTION AND IT'S MODE
 */
void DIO_SetPinDirection(PORT_TYPE Port,PIN_TYPE Pin,PIN_DIRECTION Direction)//1
{
	if(Direction == PIN_INPUT)
	{
	switch(Port)
		{
	case DIO_PORTA:
		CLR_BIT(DDRA,Pin);
		CLR_BIT(PORTA,Pin);
		break;
	case DIO_PORTB:
		CLR_BIT(DDRB,Pin);
		CLR_BIT(PORTB,Pin);
		break;
	case DIO_PORTC:
		CLR_BIT(DDRC,Pin);
		CLR_BIT(PORTC,Pin);
		break;
	case DIO_PORTD:
		CLR_BIT(DDRD,Pin);
		CLR_BIT(PORTD,Pin);
		break;
	default:
		break;
		}
	}
	else if(Direction == PIN_OUTPUT)
	{
		switch(Port)
		{
			case DIO_PORTA:
				SET_BIT(DDRA,Pin);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB,Pin);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC,Pin);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD,Pin);
				break;
			default:
				break;
				}
	}
	else if (Direction == PIN_INPUT_PULLUP)
	{
		switch(Port)
					{
					case DIO_PORTA:
						CLR_BIT(DDRA,Pin);
						SET_BIT(PORTA,Pin);
						break;
					case DIO_PORTB:
						CLR_BIT(DDRB,Pin);
						SET_BIT(PORTB,Pin);
						break;
					case DIO_PORTC:
						CLR_BIT(DDRC,Pin);
						SET_BIT(PORTC,Pin);
						break;
					case DIO_PORTD:
						CLR_BIT(DDRD,Pin);
						SET_BIT(PORTD,Pin);
						break;
					default:
						break;
						}
	}

	}
//A FUNCTION TO DETECT WHETHER THE PIN IS OUTPUT HIGH OR OUTPUT LOW
/*
 * If the previous function detected the pin mode output then we have to choose the pin level in this function
 */
void DIO_SetPinLevel(PORT_TYPE Port,PIN_TYPE Pin,PIN_LEVEL Level)//2
{
	if(Level == PIN_HIGH )
	{
		switch(Port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA,Pin);
			break;

			case DIO_PORTB:
			SET_BIT(PORTB,Pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC,Pin);
			break;
			case DIO_PORTD :
			SET_BIT(PORTD,Pin);
			break;
			default:
				break;
			}
	}
	else if (Level == PIN_LOW)
	{
		switch(Port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA,Pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB,Pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC,Pin);
			break;
			case DIO_PORTD :
			CLR_BIT(PORTD,Pin);
			break;

		default:
			break;
		}
	}

}

// A FUNCTION TO TOGGLE THE PIN LEVEL
/*
 * input the port type then the required pin to be flip it's state
 */
PIN_LEVEL DIO_TogglePinLevel (PORT_TYPE Port, PIN_TYPE Pin)//3
{
	 PIN_LEVEL Level = PIN_HIGH; // declaration and intilization of the level (output)
	switch(Port)
	{
	case DIO_PORTA:
		TOGGLE_BIT(PORTA,Pin);
		Level = GET_BIT(PORTA,Pin);
		break;
	case DIO_PORTB:
		TOGGLE_BIT(PORTB,Pin);
		Level = GET_BIT(PORTB,Pin);
		break;
	case DIO_PORTC:
		TOGGLE_BIT(PORTC,Pin);
		Level = GET_BIT(PORTC,Pin);
		break;
	case DIO_PORTD:
		TOGGLE_BIT(PORTD,Pin);
		Level = GET_BIT(PORTD,Pin);
		break;
	default:
		break;
	}
	return Level;
}
//A FUNCTION TO RETURN THE PIN LEVEL
/*
 *  so you have to input the port type then the required pin and return it through then pin level.
 */
PIN_LEVEL DIO_ReadPinLevel (PORT_TYPE Port,PIN_TYPE Pin)//4
{	PIN_LEVEL Level = PIN_LOW;
	switch(Port)
		{
		case DIO_PORTA:
			Level=GET_BIT(PINA,Pin);
			break;
		case DIO_PORTB:
			Level=GET_BIT(PINB,Pin);
			break;
		case DIO_PORTC:
			Level=GET_BIT(PINC,Pin);
			break;
		case DIO_PORTD:
			Level=GET_BIT(PIND,Pin);
			break;
		default:
			break;
		}
	return Level;
}
// A FUNCTION TO DETECT WHETHER THE DIRECTION OF THE WHOLE PORT IS INPUT OR OUTPUT
/*
 * the inputs of the function will be the port type  then whether it's input or output mode
 */
void DIO_SetPortDirection(PORT_TYPE Port,PORT_DIRECTION Direction )//5
{
	switch(Port)
	{
	case DIO_PORTA:
		DDRA = Direction;
		break;
	case DIO_PORTB:
		DDRB =  Direction;
		break;
	case DIO_PORTC:
		DDRC =  Direction;
		break;
	case DIO_PORTD:
		DDRD =  Direction;
		break;
	default:
		break;
	}

}
//  A FUNCTION TO DETECT WHETHER THE PORT IS HIGH OR LOW
/* The inputs of the function is the port type and it's level whether high or low after choosing it's mode in the previous function
 *
 */
void DIO_SetPortLevel(PORT_TYPE Port,PORT_LEVEL Level)//6
{
	switch(Port)
	{
	case DIO_PORTA:
		PORTA = Level;
	break;
	case DIO_PORTB:
		PORTB = Level;
	break;
	case DIO_PORTC:
		PORTC = Level;
	break;
	case DIO_PORTD:
		PORTD = Level;
	break;
	default:
		break;
	}
}
PORT_LEVEL DIO_ReadPortLevel(PORT_TYPE Port)//7
{
	PORT_LEVEL Level = PORT_LEVEL_LOW;
	    switch (Port)
	    {
	    case DIO_PORTA:
	        Level = PINA;
	        break;
	    case DIO_PORTB:
	        Level = PINB;
	        break;
	    case DIO_PORTC:
	        Level = PINC;
	        break;
	    case DIO_PORTD:
	        Level = PIND;
	        break;
	    default:
	        break;
	    }
	    return Level;
}
