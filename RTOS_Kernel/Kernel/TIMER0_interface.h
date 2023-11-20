/*****************************************************************/
/* Author  : ahmed saeed                                         */
/* Layer   : MCAL                                                */
/* SWC     : TIMER0                                              */
/* Version : 1.0                                                 */
/* Date    : 16 Aug 2023                                         */
/*****************************************************************/
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


#define PRESCALER_1   1
#define PRESCALER_8   2
#define PRESCALER_64  3

void TIM0_voidInit(void);
void TIM0_voidEnable(uint8 u8PreScaler);
void TIM0_voidDisable(void);
void TIM0_voidEnableOvfINt(void);
void TIM0_voidDisableOvfINt(void);
void TIM0_voidEnableComparINt(void);
void TIM0_voidDisableCompareINt(void);
void TIM0_voidSetCallBackOvfInt(pf pfOvfcallBack);
void TIM0_voidSetCallBackCompareInt(pf pfComcallBack);
void TIM0_voidSetTCNTValue(uint8 u8TcntReg);
void TIM0_voidSetOCRValue(uint8 u8OcrReg);
uint8 TIM0_u8ReadTcntReg(void);

void TIM0_voidChangMode(uint8 u8Mode);









#endif
