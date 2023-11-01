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
#include"queue.h"
#include"semphr.h"

/**************************To define the semaphore and tasks*********************************************/
TaskHandle_t vtaskMasterHanlde = NULL;
TaskHandle_t vtaskSlaveHandle = NULL;
QueueHandle_t xQueueHandel=NULL;
/******************************Task prototypes***********************************************************/
void vMasterHandler(void*x);
void vSlaveHanlder(void*y);


int main(void)
{

	MRCC_Init();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);

	MGPIO_SetMode(PORTA,PIN0,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN0,PUSH_PULL,LOW_SPEED);

	MGPIO_SetMode(PORTA,PIN1,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN1,PUSH_PULL,LOW_SPEED);


	/*********************************Task Creation************************************************/
	xTaskCreate(vMasterHandler,"Master send commands", 128, NULL, 1, &vtaskMasterHanlde);
	xTaskCreate(vSlaveHanlder,"Slave execute commands", 128, NULL, 2, &vtaskSlaveHandle);

	xQueueHandel = xQueueCreate(10,sizeof(int));

	vTaskStartScheduler();

	while(1)
	{


	}

}
void vMasterHandler(void*x)
{
	uint8 u8ONCommand=1;
	uint8 u8OFFCommand=0;


	while(1)
	{
		/* First argument is queue handel and second is the data and the third is The maximum
		 * amount of time the task should block waiting for space to become available on the queue
		 */
		xQueueSend(xQueueHandel,&u8OFFCommand,(TickType_t)5);
		vTaskDelay(15);
		xQueueSend(xQueueHandel,&u8ONCommand,(TickType_t)5);
		vTaskDelay(10);
	}

}

void vSlaveHanlder(void*y)
{
	uint8 u8CommandReceive=0;
	while(1)
	{
		/*Slave receives the command where the off command or on command and store it in
		 * command receive, if the received command is off so the led will be low
		 * if on so the led will be high*/
		xQueueReceive(xQueueHandel,&u8CommandReceive,(TickType_t)5);
		if(u8CommandReceive==0)
		{
			MGPIO_writePin(PORTA,PIN0,LOW);
		}
		else if(u8CommandReceive==1)
		{

			MGPIO_writePin(PORTA,PIN0,HIGH);
		}
		vTaskDelay(10);
	}


}

