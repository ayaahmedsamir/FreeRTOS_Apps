/******************************************************************************************************
Name        : Aya Ahmed Samir Abbas Halawa
Date        : 10/31/2023
Description : Application to make the concept of task synchronization where task takes action
             depends on the result of another task.

*******************************************************************************************************/

#include"FreeRTOS.h"
#include"FreeRTOSConfig.h"
#include"STD_Types.h"
#include"BIT_MATH.h"
#include"MGPIO_Private.h"
#include"MGPIO_interface.h"
#include"MGPIO_Config.h"
#include"MRCC_Private.h"
#include"MRCC_Config.h"
#include"MRCC_interface.h"
#include"task.h"
#include"semphr.h"

/**************************To define the semaphore and tasks*******************************************************/
SemaphoreHandle_t xsemaphore=NULL;

TaskHandle_t vtaskLedhanlde = NULL;
TaskHandle_t vtaskbuttonhandle = NULL;
/******************************Task prototypes***********************************************************/
void vLedHanlder(void*x);
void vPushButtonHanlder(void*y);

uint8 u8button_statues_curr=0;
uint8 u8button_statues_prev=0;

int main(void)
{
	MRCC_Init();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MGPIO_SetMode(PORTA,PIN0,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN0,PUSH_PULL,LOW_SPEED);

	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MGPIO_SetMode(PORTA,PIN1,INPUT);
	MGPIO_SetInputPinType(PORTA,PIN1,PULL_DOWN);

	/*********************************Task Creation************************************************/
		xTaskCreate(vLedHanlder,"Task_Blink", 128, NULL, 1, &vtaskLedhanlde);
		xTaskCreate(vPushButtonHanlder,"Task_PB", 128, NULL, 2, &vtaskbuttonhandle);
		xsemaphore=xSemaphoreCreateBinary();

		vTaskStartScheduler();

	while(1)
	{

	}

}


void vLedHanlder(void*y)
{
	while(1)
	{
		//Task to take action corresponds to the statues of the button//
		if( xSemaphoreTake(xsemaphore,(TickType_t) portMAX_DELAY)==pdTRUE)
		{
			if(u8button_statues_curr==1)
			{
			MGPIO_writePin(PORTA,PIN0,HIGH);
			}
			else
			{
				MGPIO_writePin(PORTA,PIN0,LOW);
			}

		}
		vTaskDelay(30);
	}

}


void vPushButtonHanlder(void *x)
{

	while(1)
	{
		//Task to detect the statues of the button, if statues has changed so give the semaphore//
		MGPIO_readPin(PORTA,PIN1,&u8button_statues_curr);
		if(u8button_statues_curr != u8button_statues_prev)
		{
			xSemaphoreGive(xsemaphore);
		}

		u8button_statues_prev=u8button_statues_curr;

		vTaskDelay(25);

	}


}
