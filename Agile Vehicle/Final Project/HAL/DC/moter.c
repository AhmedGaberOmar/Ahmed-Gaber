/*
 * moter.c
 *
 * Created: 10/02/2019 09:30:31 ص
 *  Author: cisco126
 */ 
#include "motor.h"


volatile extern left_flg;
volatile extern right_flag;
volatile extern normal_flag;

void motor_init(void){
	setbits(control_DDR,0b11000000);
	clearbits(PORTD,0b11000000);
	/* timer 1 for the servo */
	setbits(TCCR3A,0b10000010);			 //NON Inverted Fast PWM                  com1A=10  -  WGM1n=10
	setbits(TCCR3B,0b00011011);			 //PRESCALER=64 MODE 14(FAST PWM)         CS=011    -  WGM1n=11
	ICR3=2499;							 //servo frequency=50Hz (time for  complete cycle = 20ms)
	setbit(DDRE,PINE3);					 //set the OC1A as an output
	OCR3A=195;
	
	/* timer 2 for the dc motor*/
// 	setbits(TCCR2,0b01101010);           //NON Inverted Fast _ PWM PRESCALER 8 
// 	setbit(DDRB,pwm_DC);
// 	OCR2=235;
	PORTB|=(1<<7);
}
/* dc motor */

void motor_forward(void){
	setbit(control_port,control_DC1);
	clearbit(control_port,control_DC2);
}
void motor_backword(void){
	setbit(control_port,control_DC2);
	clearbit(control_port,control_DC1);
}
void motor_stop(void){
	setbit(control_port,control_DC1);
	setbit(control_port,control_DC2);
}


/* servo moter */
void motor_right(void)
{
	left_flg =0;
	right_flag=1;
	normal_flag=0;
	OCR3A=325;
}
void motor_left(void)
{
	normal_flag=0;
	left_flg =1;
	right_flag=0;
	
	OCR3A=150;

}
void motor_normal(void){
	left_flg =0;
	right_flag=0;
	normal_flag=1;
	OCR3A=225;
}

/*
void motor_halfRight(void){
	OCR3A = 220;
}
void motor_halfLeft(void){
	OCR3A = 170;
}*/