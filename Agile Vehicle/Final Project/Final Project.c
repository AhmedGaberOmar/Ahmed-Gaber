/*
 * Final_Project.c
 *
 * Created: 2/10/2019 10:29:10 PM
 *  Author: tasneem samy
 */


#include "motor.h"
#include "Ultra.h"
#include "Bluetooth.h"
#include "Stepper.h"
#include "LED_Matrix.h"
#include "WiFi.h"

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "event_groups.h"


 u8 left_flg =0;
 u8 right_flag=0;
 u8 normal_flag=1;

volatile u8 flag = 0;
void LED_Matrix_Task (void);
void Blind_Spot_Task(void);
void Avoidance_Task(void);

/*light control with steering right and left*/
int main(void)
{
	int control;
	Stepper_Init();
	Bluetooth_Init();
	Ultra_Init();
	DDRA |= 0X03;
	
 	motor_init();
 	Bluetooth_Init();
 	xTaskCreate(LED_Matrix_Task,NULL,50,NULL,2,NULL);
 	xTaskCreate(Blind_Spot_Task,NULL,50,NULL,1,NULL);
 	xTaskCreate(Avoidance_Task,NULL,200,NULL,3,NULL);
	
	for (u8 i=0;i<5;i++)
	{
		LED_Matrix_init();
	}
	
	setbits(DDRD, 0b11000000);
  	Ultra_Init();
  	Stepper_Init();
	vTaskStartScheduler();

}

void LED_Matrix_Task (void)
{
	while(1)
	{
		Chnage_Led_Matrix_Mode();
		vTaskDelay(100);
	}
}

void Blind_Spot_Task(void)
{

	while (1)
	{
		u8 distance = Ultra_get_blind_distance(BACK_LEFT);
		if( distance <= 6)
		{
			PORTA |= (1<<1);
			if(flag==0)
			{
				flag =1;
				Stepper_forward(LEFT_MIRROR,100);
				
			}
		}
		else if (distance > 6)
		{
			PORTA &= ~(1<<1);
			if(flag == 1)
			{
				flag =0;
				Stepper_backward(LEFT_MIRROR,100);
			}
		}
		vTaskDelay(500);
	}

}

void Avoidance_Task (void)
{
	while(1)
	{
		int DISTANCE = Ultra_get_acc_distance(FRONT);
		motor_normal();
		if ( DISTANCE > 25 )
		{
			vTaskDelay(500);
			motor_forward();
			vTaskDelay(1000);
		}
		else if (DISTANCE < 25)
		{
			motor_stop();
			vTaskDelay(1000);
			motor_right();
			motor_backword();
			vTaskDelay(1000);
			motor_stop();
			motor_normal();
			vTaskDelay(1000);
			motor_left();
			motor_forward();
			vTaskDelay(1000);
			motor_stop();
			vTaskDelay(500);
			motor_normal();
			motor_forward();
			vTaskDelay(1000);
			motor_stop();
			vTaskDelay(1000);
		}
	}
}


