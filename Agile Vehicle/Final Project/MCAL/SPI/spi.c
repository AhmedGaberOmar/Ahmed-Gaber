/*
 * spi.c
 *
 * Created: 05/12/2018 01:58:36 م
 *  Author: cisco126
 */ 
#include "spi.h"

void SPI_Init(u8 spiMode){
	if (spiMode == MASTER_MODE)
	{
		/* Set MOSI and SCK output, all others input */
		spi_ddr |= ((1<<mosi)|(1<<sck)|(1<<ss));
		/* Enable SPI, Master, set clock rate fck/16 */
		SPCR |= ((1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<CPOL));
	}
	else if (spiMode == SLAVE_MODE)
	 {
		spi_ddr |= (1<<miso);
		
		SPCR |= (1<<SPE);
	}
	
}
u8 SPI_Transcive(u8 data){
	SPDR = data;
	while((SPSR&(1<<SPIF))==0);
	PORTD|=(1<<4);
	return SPDR;
}
