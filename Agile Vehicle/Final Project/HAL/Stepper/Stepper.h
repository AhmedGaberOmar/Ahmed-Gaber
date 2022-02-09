/*
 * Stepper.h
 *
 * Created: 2/4/2019 9:28:09 PM
 *  Author: tasneem samy
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "datatypes.h"
#include "gpio.h" 

#define CTRL_PORT PORTF
#define CTRL_DDR DDRF

#define LEFT_MSK 0x0F
#define RIGHT_MSK 0xF0

#define LEFT_MIRROR 0
#define RIGHT_MIRROR 1

void Stepper_Init(void);
void Stepper_forward(u8 mirror, s16 steps);
void Stepper_backward(u8 mirror, s16 steps);


#endif /* STEPPER_H_ */