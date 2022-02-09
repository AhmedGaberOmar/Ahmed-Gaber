/*
 * Ultra.c
 *
 * Created: 1/20/2019 2:59:21 PM
 *  Author: tasneem samy
 */ 

#include "Ultra.h"

static volatile int pulse_acc = 0;
static volatile int pulse_blind = 0;
static volatile uint16_t timer0_overflows = 0;
static volatile uint16_t timer2_overflows = 0;

void Ultra_Init(void){
	
	
	DDRG |= 0X07;	// Multiplexers selection lines -- PG0 & PG1 for accident avoidance ultras MUX, PG2 for blind spot ultras
		
	DDRD &= ~((1<<0) | (1<<1));		//echo pins(input) -- PD0->accident avoidance ultras & PD1->blind spot ultras
	PORTD |= (1<<0) | (1<<1);			// activate pull up resistance
	
	DDRD |= (1<<4) | (1<<5);		// trigger pins(output) -- PD4->accident avoidance ultras & PD5->blind spot ultras
	
	/* SELECT THE FALLING EDGE TO INTERRUPT BOTH INT0 & INT1 */
	EICRA &= ~((1<<ISC00) | (1<<ISC10));
	EICRA |= (1<<ISC01) | (1<<ISC11);
	
	/* ENABLE INT0 & INT1 -- INT0 FOR ECHO FROM BLIND SPOT SENSORS & INT1 FOR ACCIDENT AVOIDANCE SENSORS */
	EIMSK |= (1<<INT0) | (1<<INT1);
	
	/* ENABLE INTERRUPT ON TIMER0 & TIMER1 OVERFLOWS */
	TIMSK |= (1<<TOIE0) | (1<<TOIE1);
	sei();
}
uint16_t Ultra_get_acc_distance(u8 sensor){
	if (sensor>2)
	{
		return UNKNOWN;
	}
	
	/* SELECT SENSOR */
	writeBits(PORTG, sensor, 0x03);
	//PORTG = sensor;
	
	uint16_t count_a = 0;
	pulse_acc = 0;
	timer2_overflows = 0;
	TCNT2 = 0;
	TIMSK |= (1<<TOIE2);
	/* send 10 micro second pulse on trigger pin*/
	PORTD |= (1<<4);
	_delay_us(10);
	PORTD &= ~(1<<4);
	
	/* start timer1 */
	TCCR2 |= ((1<<CS22)|(1<<CS20));
	/* wait until a falling edge occurs on INT0 as pulse_acc updates only there*/
	while(pulse_acc==0);
	/* calculate no. of pulses counted on timer1 */
	uint32_t number = pulse_acc + (timer2_overflows*256);
	count_a = (2.1952 * number) -10;
	return count_a;
}

uint16_t Ultra_get_blind_distance(u8 sensor){
	/* SELECT SENSOR */
	if (sensor == BACK_LEFT)
	{
		PORTG &= ~(1<<2);
	}
	else if(sensor == BACK_RIGHT){
		PORTG |= (1<<2);
	}
	else
	{
		return UNKNOWN;
	}
	
	uint16_t count_Blind = 0;
	pulse_blind = 0;
	timer0_overflows = 0;
	TCNT0 = 0;
	TIMSK |= (1<<TOIE0);
	/* send 10 micro second pulse on trigger pin*/
	
	PORTD |= (1<<5);
	_delay_us(10);
	PORTD &= ~(1<<5);
	
	TCCR0 |= ((1<<CS00)|(1<<CS02));		//
	while(pulse_blind==0);
	uint16_t number = pulse_blind + (timer0_overflows*256);
	count_Blind = (2.1952 * number) -10;
	return count_Blind/20;
}

ISR(INT1_vect)
{
	/* save count number at the falling edge time*/
	pulse_blind = TCNT0;
	/*  stop timer */
	TCCR0 = 0;
}

ISR(TIMER0_OVF_vect)
{
	timer0_overflows ++;
}




ISR(INT0_vect)
{
	/* save count number at the falling edge time*/
	pulse_acc = TCNT2;
	/*  stop timer */
	TCCR2 = 0;
}

ISR(TIMER2_OVF_vect)
{
	timer2_overflows++;
}