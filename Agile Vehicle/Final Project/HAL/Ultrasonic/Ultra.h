/*
 * Ultra.h
 *
 * Created: 1/20/2019 2:59:40 PM
 *  Author: tasneem samy
 */ 

#ifndef ULTRA_H_
#define ULTRA_H_

#include <avr/io.h>
#define F_CPU 8000000
#include <avr/interrupt.h>
#include <util/delay.h>
#include "datatypes.h"
#include "gpio.h"

#define UNKNOWN -1

enum SENSOR{
	FRONT,
	LEFT,
	RIGHT,
	BACK_LEFT,
	BACK_RIGHT
};

void Ultra_Init(void);
uint16_t Ultra_get_acc_distance(u8 sensor);
uint16_t Ultra_get_blind_distance(u8 sensor);


#endif /* ULTRA_H_ */