#include"BIT_Math.h"
#include"STD_Types.h"
#include"TIMER0_interface.h"
#include"Kernel_interface.h"
#include"Kernel_private.h"
#include"Kernel_Config.h"

/*Array to hold the periodcity and the task function name*/
/*priority of the task is the index of the array
 * initialize the array with zero at first
 * */
static Task_Type SystemTasks[TASK_NUM]={{0}};


void RTOS_voidStart(void)
{

	TIM0_voidInit();
	TIM0_voidEnable(64);
	TIM0_voidEnableComparINt();
	TIM0_voidSetOCRValue(250);
	TIM0_voidSetCallBackCompareInt(Scheduler);
}


/*Function to set the periodicity and the function name of the task and make the periodicity
 * is the index of the array to struct
 * */
uint8 RTOS_U8CreateTask(uint8 u8priority,uint16 u16periodicity,void(*Copy_pvTask)(void))
{
	uint8 u8_LocalState=EOK;
	if(Copy_pvTask !=NULL_PTR)
	{
		/*To check if the task is available and will not overwrite on it*/
		if(SystemTasks[u8priority].TaskFcn==NULL_PTR)
		{
			SystemTasks[u8priority].periodicity=u16periodicity;
				SystemTasks[u8priority].TaskFcn=Copy_pvTask;
		}
		else
		{
			/*Do nothing*/
			/*Task is not deleted and can't be overwrite*/
			u8_LocalState=ENOK;
		}

	}
	else
	{
		u8_LocalState=ENOK;
	}

	return u8_LocalState;
}

/*Function to delete the task, indicator is the pointer to function*/
void RTOS_voidDeleteTask(uint8 u8priority)
{
	SystemTasks[u8priority].TaskFcn=NULL_PTR;
}

/*Function to suspend Task*/
void RTOS_voidSuspendTask(uint8 u8priority)
{
	SystemTasks[u8priority].u8SuspendState=TASK_SUSPENDED;
}

/*Function to resume Task*/
void RTOS_voidResumeTask(uint8 u8priority)
{
	SystemTasks[u8priority].u8ResumeState=TASK_RESUME;
}

/* Check for Task periodicity and runs against this task priority
 * depending on the order so the priority is high, according to the comes first.
 * Function that will run every system tick.
*/
static void Scheduler(void)
{
	static uint16 u16_Tickcounter;
	uint8 u8_iterator;

	u16_Tickcounter++;

	for(u8_iterator=0;u8_iterator<TASK_NUM;u8_iterator++)
	{
		/*To check if the task was deleted or not*/
		if(SystemTasks[u8_iterator].TaskFcn!=NULL_PTR)
		{
			/*To check is task is suspended or not*/
			if(SystemTasks[u8_iterator].u8SuspendState==TASK_RESUME)
			{
				if(u16_Tickcounter%SystemTasks[u8_iterator].periodicity==0)
				{
					/*Call the task*/
					SystemTasks[u8_iterator].TaskFcn();
				}
				else
				{
					/*Do nothing*/
				}

			}
			else
			{
				/*Task is suspended*/
			}

		}
		else
		{
			/*Task function is NULL,Task is deleted*/
		}
	}


}
