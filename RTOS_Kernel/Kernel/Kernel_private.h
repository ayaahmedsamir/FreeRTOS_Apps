

typedef struct
{
	uint16 periodicity;
	void(*TaskFcn)(void);
	uint8 u8SuspendState;
	uint8 u8ResumeState;
}Task_Type;

#define TASK_SUSPENDED   1
#define TASK_RESUME      1

static void Scheduler(void);

