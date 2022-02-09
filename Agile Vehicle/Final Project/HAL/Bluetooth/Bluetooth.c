/*
 * bluetooth.c
 *
 * Created: 1/31/2019 12:01:13 PM
 *  Author: Mostafa
 */ 
  
#include "Bluetooth.h"


void Bluetooth_Init(){
	USART1_Init(F_CPU/16/9600-1);
}

void Bluetooth_transmit_byte(char data_byte)
{
	USART1_Transmit(data_byte);
}

char Bluetooth_receive_byte(void)
{
	return USART1_Receive();
}
