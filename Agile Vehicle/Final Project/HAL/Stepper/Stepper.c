/*
 * Stepper.c
 *
 * Created: 2/4/2019 9:27:49 PM
 *  Author: tasneem samy
 */ 

#include "Stepper.h"

void Stepper_Init(void)
{
	CTRL_DDR = 0xFF;
}
void Stepper_forward(u8 mirror, s16 steps){
	int i=0;
	if(mirror == LEFT_MIRROR){
		for(i=0; i<steps; i++){
			writeBits(CTRL_PORT, (1<<0), LEFT_MSK);
			vTaskDelay(5);
			writeBits(CTRL_PORT, (1<<1), LEFT_MSK);
			vTaskDelay(5);
			writeBits(CTRL_PORT, (1<<2), LEFT_MSK);
			vTaskDelay(5);
			writeBits(CTRL_PORT, (1<<3), LEFT_MSK);
			vTaskDelay(5);
		}
	}
	else{
		for(i=0; i<steps; i++){
			writeBits(CTRL_PORT, (1<<4), RIGHT_MSK);
			vTaskDelay(5);
			writeBits(CTRL_PORT, (1<<5), RIGHT_MSK);
			vTaskDelay(5);
			writeBits(CTRL_PORT, (1<<6), RIGHT_MSK);
			vTaskDelay(5);
			writeBits(CTRL_PORT, (1<<7), RIGHT_MSK);
			vTaskDelay(5);
		}
	}
}
void Stepper_backward(u8 mirror, s16 steps){
	int i=0;
	if(mirror == LEFT_MIRROR){
		for(i=0; i<steps; i++){
			writeBits(CTRL_PORT, (1<<3), LEFT_MSK);
			_delay_ms(5);
			writeBits(CTRL_PORT, (1<<2), LEFT_MSK);
			_delay_ms(5);
			writeBits(CTRL_PORT, (1<<1), LEFT_MSK);
			_delay_ms(5);
			writeBits(CTRL_PORT, (1<<0), LEFT_MSK);
			_delay_ms(5);
		}
	}
	else{
		for(i=0; i<steps; i++){
			writeBits(CTRL_PORT, (1<<7), RIGHT_MSK);
			_delay_ms(5);
			writeBits(CTRL_PORT, (1<<6), RIGHT_MSK);
			_delay_ms(5);
			writeBits(CTRL_PORT, (1<<5), RIGHT_MSK);
			_delay_ms(5);
			writeBits(CTRL_PORT, (1<<4), RIGHT_MSK);
			_delay_ms(5);
		}
	}
}