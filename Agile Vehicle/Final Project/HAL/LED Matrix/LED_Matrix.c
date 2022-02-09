/*
 * LED_Matrix.c
 *
 * Created: 30/01/2019 11:30:33 ص
 *  Author: cisco126
 */ 
#include "LED_Matrix.h"

extern   u8 left_flg ;
extern   u8 right_flag;
extern   u8 normal_flag;



void LED_Matrix_init(void){
 	SPI_Init(MASTER_MODE);
	setbits (DDRB,SSPM);
	setbit (DDRC,PC0);
	setbits (SSPB,SSPM);
	setbit(SSPC,PC0);
	DDRC &=~ ((1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6));
	for (u8 i=1;i<5;i++)
	{
		LED_Matrix_write(i,Decode_Mode,0x00);
		LED_Matrix_write(i,Intensity,0x08);
		LED_Matrix_write(i,Shutdown,ON);
		LED_Matrix_write(i,scan_limit,0x07);	
	}
	
}
void LED_Matrix_write(u8 Matrix_sel, u8 Add, u8 Data){

	if(Matrix_sel==1){
		load_start_1;
 		SPI_Transcive(Add);
 		SPI_Transcive(Data);
 		load_end_1;
	}

	else if(Matrix_sel==2){
		load_start_2;
		SPI_Transcive(Add);
		SPI_Transcive(Data);
		load_end_2;
	}
	else if(Matrix_sel==3){
		load_start_3;
		SPI_Transcive(Add);
		SPI_Transcive(Data);
		load_end_3;
	}
	else if(Matrix_sel==4){
		load_start_4;
		SPI_Transcive(Add);
		SPI_Transcive(Data);
		load_end_4;
	}
	_delay_ms(1);
}
void LED_Matrix_UP(u8 Matrix_sel, u8 Data){
	LED_Matrix_write(Matrix_sel,D0,Data);
	LED_Matrix_write(Matrix_sel,D1,Data);
	LED_Matrix_write(Matrix_sel,D2,Data);
	LED_Matrix_write(Matrix_sel,D3,Data);
	LED_Matrix_write(Matrix_sel,D4,Data);
	LED_Matrix_write(Matrix_sel,D5,Data);
	LED_Matrix_write(Matrix_sel,D6,0);
	LED_Matrix_write(Matrix_sel,D7,0);
}
void LED_Matrix_half_UP(u8 Matrix_sel, u8 Data){
	LED_Matrix_write(Matrix_sel,D0,0);
	LED_Matrix_write(Matrix_sel,D1,Data);
	LED_Matrix_write(Matrix_sel,D2,Data);
	LED_Matrix_write(Matrix_sel,D3,Data);
	LED_Matrix_write(Matrix_sel,D4,Data);
	LED_Matrix_write(Matrix_sel,D5,Data);
	LED_Matrix_write(Matrix_sel,D6,0);
	LED_Matrix_write(Matrix_sel,D7,0);
}
void LED_Matrix_normal(u8 Matrix_sel, u8 Data){
	LED_Matrix_write(Matrix_sel,D0,0);
	LED_Matrix_write(Matrix_sel,D1,0);
	LED_Matrix_write(Matrix_sel,D2,Data);
	LED_Matrix_write(Matrix_sel,D3,Data);
	LED_Matrix_write(Matrix_sel,D4,Data);
	LED_Matrix_write(Matrix_sel,D5,Data);
	LED_Matrix_write(Matrix_sel,D6,0);
	LED_Matrix_write(Matrix_sel,D7,0);
}
void LED_Matrix_half_DOWN(u8 Matrix_sel, u8 Data){
	LED_Matrix_write(Matrix_sel,D0,0);
	LED_Matrix_write(Matrix_sel,D1,0);
	LED_Matrix_write(Matrix_sel,D2,Data);
	LED_Matrix_write(Matrix_sel,D3,Data);
	LED_Matrix_write(Matrix_sel,D4,Data);
	LED_Matrix_write(Matrix_sel,D5,Data);
	LED_Matrix_write(Matrix_sel,D6,Data);
	LED_Matrix_write(Matrix_sel,D7,0);
}
void LED_Matrix_DOWN(u8 Matrix_sel, u8 Data){
	LED_Matrix_write(Matrix_sel,D0,0);
	LED_Matrix_write(Matrix_sel,D1,0);
	LED_Matrix_write(Matrix_sel,D2,Data);
	LED_Matrix_write(Matrix_sel,D3,Data);
	LED_Matrix_write(Matrix_sel,D4,Data);
	LED_Matrix_write(Matrix_sel,D5,Data);
	LED_Matrix_write(Matrix_sel,D6,Data);
	LED_Matrix_write(Matrix_sel,D7,Data);
}
void LED_Matrix_ClearAll(u8 Matrix_sel){
	LED_Matrix_write(Matrix_sel,Shutdown, OFF);
}

void Normal_Middle_Led_Matrix(void)
{
	LED_Matrix_write(1,D0,0);
	LED_Matrix_write(1,D1,0);
	LED_Matrix_write(1,D2,0);
	LED_Matrix_write(1,D3,0);
	LED_Matrix_write(1,D4,0);
	LED_Matrix_write(1,D5,0);
	LED_Matrix_write(1,D6,0);
	LED_Matrix_write(1,D7,0);
	
	LED_Matrix_write(2,D0,0);
	LED_Matrix_write(2,D1,0);
	LED_Matrix_write(2,D2,0);
	LED_Matrix_write(2,D3,0xff);
	LED_Matrix_write(2,D4,0xff);
	LED_Matrix_write(2,D5,0);
	LED_Matrix_write(2,D6,0);
	LED_Matrix_write(2,D7,0);
	
	LED_Matrix_write(3,D0,0);
	LED_Matrix_write(3,D1,0);
	LED_Matrix_write(3,D2,0);
	LED_Matrix_write(3,D3,0xff);
	LED_Matrix_write(3,D4,0xff);
	LED_Matrix_write(3,D5,0);
	LED_Matrix_write(3,D6,0);
	LED_Matrix_write(3,D7,0);
	
	LED_Matrix_write(4,D0,0);
	LED_Matrix_write(4,D1,0);
	LED_Matrix_write(4,D2,0);
	LED_Matrix_write(4,D3,0);
	LED_Matrix_write(4,D4,0);
	LED_Matrix_write(4,D5,0);
	LED_Matrix_write(4,D6,0);
	LED_Matrix_write(4,D7,0);
}
void UP_Middle_Led_Matrix(void)
{
	LED_Matrix_write(1,D0,0);
	LED_Matrix_write(1,D1,0);
	LED_Matrix_write(1,D2,0);
	LED_Matrix_write(1,D3,0);
	LED_Matrix_write(1,D4,0);
	LED_Matrix_write(1,D5,0);
	LED_Matrix_write(1,D6,0);
	LED_Matrix_write(1,D7,0);
	
	LED_Matrix_write(2,D0,0);
	LED_Matrix_write(2,D1,0);
	LED_Matrix_write(2,D2,0);
	LED_Matrix_write(2,D3,0);
	LED_Matrix_write(2,D4,0);
	LED_Matrix_write(2,D5,0XFF);
	LED_Matrix_write(2,D6,0XFF);
	LED_Matrix_write(2,D7,0XFF);
	
	LED_Matrix_write(3,D0,0);
	LED_Matrix_write(3,D1,0);
	LED_Matrix_write(3,D2,0);
	LED_Matrix_write(3,D3,0);
	LED_Matrix_write(3,D4,0);
	LED_Matrix_write(3,D5,0XFF);
	LED_Matrix_write(3,D6,0XFF);
	LED_Matrix_write(3,D7,0XFF);
	
	LED_Matrix_write(4,D0,0);
	LED_Matrix_write(4,D1,0);
	LED_Matrix_write(4,D2,0);
	LED_Matrix_write(4,D3,0);
	LED_Matrix_write(4,D4,0);
	LED_Matrix_write(4,D5,0);
	LED_Matrix_write(4,D6,0);
	LED_Matrix_write(4,D7,0);
}
void Down_Middle_Led_Matrix(void)
{
	LED_Matrix_write(1,D0,0);
	LED_Matrix_write(1,D1,0);
	LED_Matrix_write(1,D2,0);
	LED_Matrix_write(1,D3,0);
	LED_Matrix_write(1,D4,0);
	LED_Matrix_write(1,D5,0);
	LED_Matrix_write(1,D6,0);
	LED_Matrix_write(1,D7,0);
	
	LED_Matrix_write(2,D0,0xff);
	LED_Matrix_write(2,D1,0xff);
	LED_Matrix_write(2,D2,0xff);
	LED_Matrix_write(2,D3,0);
	LED_Matrix_write(2,D4,0);
	LED_Matrix_write(2,D5,0);
	LED_Matrix_write(2,D6,0);
	LED_Matrix_write(2,D7,0);
	
	LED_Matrix_write(3,D0,0xff);
	LED_Matrix_write(3,D1,0xff);
	LED_Matrix_write(3,D2,0xff);
	LED_Matrix_write(3,D3,0);
	LED_Matrix_write(3,D4,0);
	LED_Matrix_write(3,D5,0);
	LED_Matrix_write(3,D6,0);
	LED_Matrix_write(3,D7,0);
	
	LED_Matrix_write(4,D0,0);
	LED_Matrix_write(4,D1,0);
	LED_Matrix_write(4,D2,0);
	LED_Matrix_write(4,D3,0);
	LED_Matrix_write(4,D4,0);
	LED_Matrix_write(4,D5,0);
	LED_Matrix_write(4,D6,0);
	LED_Matrix_write(4,D7,0);
}
/****************************** right **************************/
void Normal_Right_Led_Matrix(void)
{

	LED_Matrix_write(1,D0,0);
	LED_Matrix_write(1,D1,0);
	LED_Matrix_write(1,D2,0);
	LED_Matrix_write(1,D3,0);
	LED_Matrix_write(1,D4,0);
	LED_Matrix_write(1,D5,0);
	LED_Matrix_write(1,D6,0);
	LED_Matrix_write(1,D7,0);
	
	LED_Matrix_write(2,D0,0);
	LED_Matrix_write(2,D1,0);
	LED_Matrix_write(2,D2,0);
	LED_Matrix_write(2,D3,0);
	LED_Matrix_write(2,D4,0);
	LED_Matrix_write(2,D5,0);
	LED_Matrix_write(2,D6,0);
	LED_Matrix_write(2,D7,0);
	
	LED_Matrix_write(3,D0,0);
	LED_Matrix_write(3,D1,0);
	LED_Matrix_write(3,D2,0);
	LED_Matrix_write(3,D3,0XFF);
	LED_Matrix_write(3,D4,0XFF);
	LED_Matrix_write(3,D5,0);
	LED_Matrix_write(3,D6,0);
	LED_Matrix_write(3,D7,0);
	
	LED_Matrix_write(4,D0,0);
	LED_Matrix_write(4,D1,0);
	LED_Matrix_write(4,D2,0);
	LED_Matrix_write(4,D3,0XFF);
	LED_Matrix_write(4,D4,0XFF);
	LED_Matrix_write(4,D5,0);
	LED_Matrix_write(4,D6,0);
	LED_Matrix_write(4,D7,0);

}
void DOWN_Right_Led_Matrix(void)
{

	LED_Matrix_write(1,D0,0);
	LED_Matrix_write(1,D1,0);
	LED_Matrix_write(1,D2,0);
	LED_Matrix_write(1,D3,0);
	LED_Matrix_write(1,D4,0);
	LED_Matrix_write(1,D5,0);
	LED_Matrix_write(1,D6,0);
	LED_Matrix_write(1,D7,0);
	
	LED_Matrix_write(2,D0,0);
	LED_Matrix_write(2,D1,0);
	LED_Matrix_write(2,D2,0);
	LED_Matrix_write(2,D3,0);
	LED_Matrix_write(2,D4,0);
	LED_Matrix_write(2,D5,0);
	LED_Matrix_write(2,D6,0);
	LED_Matrix_write(2,D7,0);
	
	LED_Matrix_write(3,D0,0XFF);
	LED_Matrix_write(3,D1,0XFF);
	LED_Matrix_write(3,D2,0XFF);
	LED_Matrix_write(3,D3,0);
	LED_Matrix_write(3,D4,0);
	LED_Matrix_write(3,D5,0);
	LED_Matrix_write(3,D6,0);
	LED_Matrix_write(3,D7,0);
	
	LED_Matrix_write(4,D0,0XFF);
	LED_Matrix_write(4,D1,0XFF);
	LED_Matrix_write(4,D2,0XFF);
	LED_Matrix_write(4,D3,0);
	LED_Matrix_write(4,D4,0);
	LED_Matrix_write(4,D5,0);
	LED_Matrix_write(4,D6,0);
	LED_Matrix_write(4,D7,0);

}
void UP_Rigt_Led_Matrix(void)
{

	LED_Matrix_write(1,D0,0);
	LED_Matrix_write(1,D1,0);
	LED_Matrix_write(1,D2,0);
	LED_Matrix_write(1,D3,0);
	LED_Matrix_write(1,D4,0);
	LED_Matrix_write(1,D5,0);
	LED_Matrix_write(1,D6,0);
	LED_Matrix_write(1,D7,0);
	
	LED_Matrix_write(2,D0,0);
	LED_Matrix_write(2,D1,0);
	LED_Matrix_write(2,D2,0);
	LED_Matrix_write(2,D3,0);
	LED_Matrix_write(2,D4,0);
	LED_Matrix_write(2,D5,0);
	LED_Matrix_write(2,D6,0);
	LED_Matrix_write(2,D7,0);
	
	LED_Matrix_write(3,D0,0);
	LED_Matrix_write(3,D1,0);
	LED_Matrix_write(3,D2,0);
	LED_Matrix_write(3,D3,0);
	LED_Matrix_write(3,D4,0);
	LED_Matrix_write(3,D5,0XFF);
	LED_Matrix_write(3,D6,0XFF);
	LED_Matrix_write(3,D7,0XFF);
	
	LED_Matrix_write(4,D0,0);
	LED_Matrix_write(4,D1,0);
	LED_Matrix_write(4,D2,0);
	LED_Matrix_write(4,D3,0);
	LED_Matrix_write(4,D4,0);
	LED_Matrix_write(4,D5,0XFF);
	LED_Matrix_write(4,D6,0XFF);
	LED_Matrix_write(4,D7,0XFF);

}

/****************************** LEFT ************************************/

void UP_Left_Led_Matrix(void)
{

	LED_Matrix_write(1,D0,0);
	LED_Matrix_write(1,D1,0);
	LED_Matrix_write(1,D2,0);
	LED_Matrix_write(1,D3,0);
	LED_Matrix_write(1,D4,0);
	LED_Matrix_write(1,D5,0XFF);
	LED_Matrix_write(1,D6,0XFF);
	LED_Matrix_write(1,D7,0XFF);
	
	LED_Matrix_write(2,D0,0);
	LED_Matrix_write(2,D1,0);
	LED_Matrix_write(2,D2,0);
	LED_Matrix_write(2,D3,0);
	LED_Matrix_write(2,D4,0);
	LED_Matrix_write(2,D5,0XFF);
	LED_Matrix_write(2,D6,0XFF);
	LED_Matrix_write(2,D7,0XFF);
	
	LED_Matrix_write(3,D0,0);
	LED_Matrix_write(3,D1,0);
	LED_Matrix_write(3,D2,0);
	LED_Matrix_write(3,D3,0);
	LED_Matrix_write(3,D4,0);
	LED_Matrix_write(3,D5,0);
	LED_Matrix_write(3,D6,0);
	LED_Matrix_write(3,D7,0);
	
	LED_Matrix_write(4,D0,0);
	LED_Matrix_write(4,D1,0);
	LED_Matrix_write(4,D2,0);
	LED_Matrix_write(4,D3,0);
	LED_Matrix_write(4,D4,0);
	LED_Matrix_write(4,D5,0);
	LED_Matrix_write(4,D6,0);
	LED_Matrix_write(4,D7,0);

}
void DOWN_Left_Led_Matrix(void)
{

	LED_Matrix_write(1,D0,0XFF);
	LED_Matrix_write(1,D1,0XFF);
	LED_Matrix_write(1,D2,0XFF);
	LED_Matrix_write(1,D3,0);
	LED_Matrix_write(1,D4,0);
	LED_Matrix_write(1,D5,0);
	LED_Matrix_write(1,D6,0);
	LED_Matrix_write(1,D7,0);
	
	LED_Matrix_write(2,D0,0XFF);
	LED_Matrix_write(2,D1,0XFF);
	LED_Matrix_write(2,D2,0XFF);
	LED_Matrix_write(2,D3,0);
	LED_Matrix_write(2,D4,0);
	LED_Matrix_write(2,D5,0);
	LED_Matrix_write(2,D6,0);
	LED_Matrix_write(2,D7,0);
	
	LED_Matrix_write(3,D0,0);
	LED_Matrix_write(3,D1,0);
	LED_Matrix_write(3,D2,0);
	LED_Matrix_write(3,D3,0);
	LED_Matrix_write(3,D4,0);
	LED_Matrix_write(3,D5,0);
	LED_Matrix_write(3,D6,0);
	LED_Matrix_write(3,D7,0);
	
	LED_Matrix_write(4,D0,0);
	LED_Matrix_write(4,D1,0);
	LED_Matrix_write(4,D2,0);
	LED_Matrix_write(4,D3,0);
	LED_Matrix_write(4,D4,0);
	LED_Matrix_write(4,D5,0);
	LED_Matrix_write(4,D6,0);
	LED_Matrix_write(4,D7,0);

}
void Normal_Left_Led_Matrix(void)
{

	LED_Matrix_write(1,D0,0);
	LED_Matrix_write(1,D1,0);
	LED_Matrix_write(1,D2,0);
	LED_Matrix_write(1,D3,0XFF);
	LED_Matrix_write(1,D4,0XFF);
	LED_Matrix_write(1,D5,0);
	LED_Matrix_write(1,D6,0);
	LED_Matrix_write(1,D7,0);
	
	LED_Matrix_write(2,D0,0);
	LED_Matrix_write(2,D1,0);
	LED_Matrix_write(2,D2,0);
	LED_Matrix_write(2,D3,0XFF);
	LED_Matrix_write(2,D4,0XFF);
	LED_Matrix_write(2,D5,0);
	LED_Matrix_write(2,D6,0);
	LED_Matrix_write(2,D7,0);
	
	LED_Matrix_write(3,D0,0);
	LED_Matrix_write(3,D1,0);
	LED_Matrix_write(3,D2,0);
	LED_Matrix_write(3,D3,0);
	LED_Matrix_write(3,D4,0);
	LED_Matrix_write(3,D5,0);
	LED_Matrix_write(3,D6,0);
	LED_Matrix_write(3,D7,0);
	
	LED_Matrix_write(4,D0,0);
	LED_Matrix_write(4,D1,0);
	LED_Matrix_write(4,D2,0);
	LED_Matrix_write(4,D3,0);
	LED_Matrix_write(4,D4,0);
	LED_Matrix_write(4,D5,0);
	LED_Matrix_write(4,D6,0);
	LED_Matrix_write(4,D7,0);

}
void Chnage_Led_Matrix_Mode(void)
{

	if (((PINC & (1<<PD1))==(1<<PD1)) && normal_flag == 1)
	{
		Normal_Middle_Led_Matrix();
	}
	if((((PINC&(1<<PD5))== (1<<PD5)) || ((PINC&(1<<PD6))== (1<<PD6))) && normal_flag == 1)
	{
		Down_Middle_Led_Matrix();
	}
	else if((((PINC&(1<<PD2))== (1<<PD2)) || ((PINC&(1<<PD3))== (1<<PD3))) && normal_flag == 1)
	{
		UP_Middle_Led_Matrix();
	}
// 	/****************************************** right ******************************************/
	
	
	if (((PINC & (1<<PD1))==(1<<PD1)) && right_flag == 1)
	{
		Normal_Right_Led_Matrix();
	}
	if((((PINC&(1<<PD5))== (1<<PD5)) || ((PINC&(1<<PD6))== (1<<PD6))) && right_flag == 1)
	{
		DOWN_Right_Led_Matrix();
	}
	else if((((PINC&(1<<PD2))== (1<<PD2)) || ((PINC&(1<<PD3))== (1<<PD3))) && right_flag == 1)
	{
		UP_Rigt_Led_Matrix();
	}
	/************************************* LEFT *******************************************/
	if (((PINC & (1<<PD1))==(1<<PD1)) && left_flg == 1)
	{
		Normal_Left_Led_Matrix();
	}
	if((((PINC&(1<<PD5))== (1<<PD5)) || ((PINC&(1<<PD6))== (1<<PD6))) && left_flg == 1)
	{
		UP_Left_Led_Matrix();
	}
	else if((((PINC&(1<<PD2))== (1<<PD2)) || ((PINC&(1<<PD3))== (1<<PD3))) && left_flg == 1)
	{
		DOWN_Left_Led_Matrix();
	}
	vTaskDelay(100);	



}