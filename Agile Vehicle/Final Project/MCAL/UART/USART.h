/*
 * UART.h
 *
 * Created: 1/20/2019 12:27:53 AM
 *  Author: tasneem samy
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include "datatypes.h"

#define BUFFER_SIZE 700

void USART0_Init(u32 ubrr);
void USART0_Transmit(u8 data);
u8 USART0_Receive(void);
void USART0_TransmitStr(u8* str);
u8* USART0_readResponse(void);
void USART0_clearResponse(void);

void USART1_Init(u32 ubrr);
void USART1_Transmit(u8 data);
u8 USART1_Receive(void);
void USART1_TransmitStr(u8* str);


#endif /* UART_H_ */