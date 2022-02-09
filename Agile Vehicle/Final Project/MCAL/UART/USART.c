/*
 * UART.c
 *
 * Created: 1/20/2019 12:27:37 AM
 *  Author: tasneem samy
 */ 
#include "USART.h"

volatile u8 recv_buffer[BUFFER_SIZE];
volatile s32 index = 0;

void USART0_Init(u32 ubrr){
	/*Set baud rate */
	UBRR0H = (u8)(ubrr>>8);
	UBRR0L = (u8)ubrr;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C |= (3<<UCSZ00);
	/* Enable Receiving interrupt*/
	UCSR0B |= (1<<RXCIE0);
	sei();
}
void USART0_Transmit(u8 data){
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)));
	/* Put data into buffer, sends the data */
	UDR0 = data;
}
void USART0_TransmitStr(u8* str){
	int ind = 0;
	while(str[ind]!='\0'){
		if(str[ind]!='\\'){
			USART0_Transmit(str[ind]);
			ind++;
		}
	}
}

u8 USART0_Receive(void){
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}

void USART1_Init(u32 ubrr){
	/*Set baud rate */
	UBRR1H = (u8)(ubrr>>8);
	UBRR1L = (u8)ubrr;
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	/* Set frame format: 8data, 2stop bit */
	UCSR1C |= (3<<UCSZ01);
}
void USART1_Transmit(u8 data){
	/* Wait for empty transmit buffer */
	while (!(UCSR1A & (1<<UDRE1)));
	/* Put data into buffer, sends the data */
	UDR1 = data;
}
u8 USART1_Receive(void){
	/* Wait for data to be received */
	while (!(UCSR1A & (1<<RXC1)));
	/* Get and return received data from buffer */
	return UDR1;
}

void USART1_TransmitStr(u8* str){
	int ind = 0;
	while(str[ind]!='\0'){
		if(str[ind]!='\\'){
			USART1_Transmit(str[ind]);
			ind++;
		}
	}
}

u8* USART0_readResponse(void){
	return recv_buffer;
}

void USART0_clearResponse(void){
	memset(recv_buffer, 0, BUFFER_SIZE);
	index = 0;
}

ISR(USART0_RX_vect){
	if(index < BUFFER_SIZE){
		recv_buffer[index] = UDR0;
		index++;
	}
}