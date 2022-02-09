/*
 * motor.h
 *
 * Created: 10/02/2019 09:30:41 ص
 *  Author: cisco126
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "gpio.h"
#include "datatypes.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "avr/io.h"
#include "stdio.h"
#include "stdlib.h"

#define control_DC1  PIND6
#define control_DC2  PIND7
#define control_DDR  DDRD
#define control_port PORTD

#define pwm_DC PINB7

void motor_init(void);

/* dc motor */
void motor_forward(void);
void motor_backword(void);
void motor_stop(void);

/* servo moter */
void motor_right(void);
void motor_left(void);
void motor_normal(void);
void motor_halfRight(void);
void motor_halfLeft(void);


#endif /* MOTOR_H_ */