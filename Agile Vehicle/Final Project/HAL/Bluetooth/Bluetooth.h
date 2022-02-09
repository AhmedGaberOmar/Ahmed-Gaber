/*
 * Bluetooth.h
 *
 * Created: 1/31/2019 12:07:18 PM
 *  Author: Mostafa
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "Bluetooth.h"
#include "USART.h"

void Bluetooth_Init();
void Bluetooth_transmit_byte(char data_byte);
char Bluetooth_receive_byte(void);

#endif /* BLUETOOTH_H_ */