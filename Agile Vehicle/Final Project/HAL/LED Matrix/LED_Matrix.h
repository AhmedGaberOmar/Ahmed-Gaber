/*
 * LED_Matrix.h
 *
 * Created: 30/01/2019 11:30:56 ص
 *  Author: cisco126
 */ 


#ifndef LED_MATRIX_H_
#define LED_MATRIX_H_
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "datatypes.h"
#include "GPIO.h"
#include "spi.h"
#define SCK PB1
#define MOSI PB2
#define SS2 PB4
#define SS4 PB5
#define SS1 PB6
#define SS3 PC0
#define SSPB PORTB
#define SSPC PORTC
#define SSPM 0xF0

// slave select
#define load_end_1 setbit(SSPB,SS1)
#define load_end_2 setbit(SSPB,SS2)
#define load_end_3 setbit(SSPC,SS3)
#define load_end_4 setbit(SSPB,SS4)

#define load_start_1 clearbit(SSPB,SS1)
#define load_start_2 clearbit(SSPB,SS2)
#define load_start_3 clearbit(SSPC,SS3)
#define load_start_4 clearbit(SSPB,SS4)
//Control registers
#define Decode_Mode  0x09
#define Intensity    0x0A
#define scan_limit   0x0B
#define Shutdown	 0x0C
#define Display_test 0x0F
//column select
#define D0 0x01
#define D1 0x02
#define D2 0x03
#define D3 0x04
#define D4 0x05
#define D5 0x06
#define D6 0x07
#define D7 0x08
// power status
#define ON  0x01
#define OFF 0x00

void LED_Matrix_init(void);
void LED_Matrix_write(u8 Matrix_sel, u8 Add, u8 Data);
void LED_Matrix_UP(u8 Matrix_sel, u8 Data);
void LED_Matrix_half_UP(u8 Matrix_sel, u8 Data);
void LED_Matrix_normal(u8 Matrix_sel, u8 Data);
void LED_Matrix_half_DOWN(u8 Matrix_sel, u8 Data);
void LED_Matrix_DOWN(u8 Matrix_sel, u8 Data);
void LED_Matrix_ClearAll(u8 Matrix_sel);


void Normal_Middle_Led_Matrix(void);
void UP_Middle_Led_Matrix(void);
void Down_Middle_Led_Matrix(void);


/****************************** right **************************/
void Normal_Right_Led_Matrix(void);
void DOWN_Right_Led_Matrix(void);
void UP_Rigt_Led_Matrix(void);


/****************************** LEFT ************************************/

void UP_Left_Led_Matrix(void);
void DOWN_Left_Led_Matrix(void);
void Normal_Left_Led_Matrix(void);

void Chnage_Led_Matrix_Mode(void);




#endif /* LED_MATRIX_H_ */