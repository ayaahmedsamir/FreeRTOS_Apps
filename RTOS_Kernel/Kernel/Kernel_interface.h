

void RTOS_voidStart(void);
uint8 RTOS_U8CreateTask(uint8 u8priority,uint16 u16periodicity,void(*Copy_pvTask)(void));
void RTOS_voidDeleteTask(uint8 u8priority);
void RTOS_voidSuspendTask(uint8 u8priority);
void RTOS_voidResumeTask(uint8 u8priority);
