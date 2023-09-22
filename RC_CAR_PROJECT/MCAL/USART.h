/*
 * USART.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : USART - PROTOTYPE
 */

#ifndef USART_H_
#define USART_H_

void USART_Init();
void USART_Transmit(u8 data);
u8 USART_Receive(void);
void USART_SendString(u8 *str);
void USART_ReceiveString(u8 *str);
void USART_SendNumber(s64 s_number);
void USART_txISR(void(*TX_PTR)(void));
void USART_rxISR(void(*RX_PTR)(u8 data));
void USART_txEMPTYISR(void(*TX_EMPTYPTR)(void));
#endif /* USART_H_ */
