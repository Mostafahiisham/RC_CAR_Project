/*
 * USART.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : USART - IMPLEMENTATION
 */

#include<Std_Types.h>
#include<Macros.h>
#include<Registers.h>
#include<USART.h>
#include<USART_Private.h>

static void(*RX_CALLBACK)(u8 data) = NULL;
static void(*TX_CALLBACK)(void) = NULL;
static void(*TX_EmptyCALLBACK)(void) = NULL;
void __vector_13(void) 	__attribute__((signal));
void __vector_13(void)
{
	RX_CALLBACK(UDR);
	CLR_BIT(UCSRB,UCSRB_RXCIE);
}
void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	TX_EmptyCALLBACK();
	CLR_BIT(UCSRB,UCSRB_UDRIE);
}
void __vector_15(void) 	__attribute__((signal));
void __vector_15(void)
{

	TX_CALLBACK();
	CLR_BIT(UCSRB,UCSRB_TXCIE);
}

void USART_Init()
{		u8 Local_UCSRC;

	SET_BIT(Local_UCSRC,UCSRC_URSEL);
	SET_BIT(Local_UCSRC,UCSRC_UCSZ1);
	SET_BIT(Local_UCSRC,UCSRC_UCSZ0);
	Local_UCSRC =UCSRC;
	//UCSRB = 0b00011000;
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXCIE);
	//UCSRC = 0B10000110;
	UBRRL = 51;		//baud rate 9600 bit/sec.
}
void USART_Transmit(u8 data)
{
	while(!( UCSRA& (1<<UDRE)))		//wait until transmit buffer is empty
	/*put data into the buffer , sends the data */
		UDR = data;
}
u8 USART_Receive(void)
{
	/* wait for the received data (busy waiting)*/
	while(!(UCSRA & (1<<RXC)));
	/*get received data from the buffer */
	return UDR;
}
void USART_SendString(u8 *str)
{
	u8 i;
		/*ARRAY OF CHARACTER*/
		while( str[i] != '\0')
		{
			USART_Transmit(*str);
			str++;
		}
}
void USART_ReceiveString(u8 *str)
{
	u8 i= 0 ;
	str[i]= USART_Receive();
	while(str[i] != '#')
	{
		i++;
		str[i]= USART_Receive();
	}
	str[i] = '\0';
}
void USART_SendNumber(s64 s_number)
{
	u64 u_number = 1;
		if(s_number == 0 )
		{
			USART_Transmit('0');
		}
		if(s_number < 0)
		{
			USART_Transmit('-');
			s_number *= -1;
		}
		while(s_number != 0)
		{
			u_number = ((u_number*10)+(s_number % 10));
			s_number = s_number / 10;
		}
		while(u_number != 1)
		{
			USART_Transmit((u_number%10)+48);
			u_number = u_number /10;
		}
}
void USART_txISR(void(*TX_PTR)(void))
{
	TX_CALLBACK = TX_PTR;

	/* TX INTERRUPT ENABLE */
	SET_BIT(UCSRB,UCSRB_TXCIE);

}
void USART_rxISR(void(*RX_PTR)(u8 data))
{

	RX_CALLBACK = RX_PTR;
	/*RX Interrupt Enable */
	SET_BIT(UCSRB,UCSRB_RXCIE);
}
void USART_txEMPTYISR(void(*TX_EMPTYPTR)(void))
{
	TX_EmptyCALLBACK = TX_EMPTYPTR;
	/* TX EMPTY interrupt Enable */
	SET_BIT(UCSRB,UCSRB_UDRIE);
}

