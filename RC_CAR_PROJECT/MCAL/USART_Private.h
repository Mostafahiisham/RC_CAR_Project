/*
 * USART_Private.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : USART - PRIVATE
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define UCSRB_RXCIE			7	//RX interrupt enable
#define UCSRB_TXCIE			6	//TX interrupt enable
#define	UCSRB_UDRIE			5	//DATA REGISTER EMPTY INTERRUPT ENABLE
#define UCSRB_RXEN			4	//RX ENABLE
#define	UCSRB_TXEN			3	//TX ENABLE
#define UCSRB_UCSZ2			2	//CHARACTER SIZE
#define	UCSRB_RXB8			1	//RECEIVE 8 BIT DATA
#define	UCSRB_TXB8			0	//TRANSIMIT 8 BIT DATA

#define UCSRC_URSEL			7	//register select
#define UCSRC_UMSEL			6	//UART MODE SELECT
#define UCSRC_UPM1			5	//PARITY MODE
#define UCSRC_UPM0			4	//PARITY MODE
#define UCSRC_USBS			3	//STOP BIT
#define UCSRC_UCSZ1			2	//CHARACTER SIZE
#define UCSRC_UCSZ0			1   //CHARACTER SIZE
#define UCSRC_UPCOL			0	//CLOCK PARITY

#define UDRE	5
#define RXC		7


#endif /* USART_PRIVATE_H_ */
