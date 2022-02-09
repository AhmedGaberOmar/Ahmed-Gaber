/*
 * spi.h
 *
 * Created: 05/12/2018 01:58:19 م
 *  Author: cisco126
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "datatypes.h"
#include "gpio.h"

#define MASTER_MODE 0
#define SLAVE_MODE  1

#define spi_port      PORTB
#define spi_ddr       DDRB

#define ss            PINB0
#define sck           PINB1
#define mosi          PINB2
#define miso          PINB2



void SPI_Init(u8 spiMode);
u8 SPI_Transcive(u8 data);



#endif /* SPI_H_ */