/*****************************************************************/
/* Author  : ahmed saeed                                         */
/* Layer   : MCAL                                                */
/* SWC     : TIMER0                                              */
/* Version : 1.0                                                 */
/* Date    : 16 Aug 2023                                         */
/*****************************************************************/
#include "BIT_Math.h"
#include "STD_Types.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

pf TIM0_pfOVFCallBack;
pf TIM0_pfCmpCallBack;

void TIM0_voidInit(void)
{
	/*selct timer mode*/
#if TIMO_MODE == TIM0_NORMAL
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#elif TIMO_MODE == TIM0_CTC
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#elif TIMO_MODE == TIM0_FAST_PWM
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#elif TIMO_MODE == TIM0_PHASE_PWM
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#else
	/*set normal as default*/
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#endif

	/*selct wave form on oco pin */
#if	TIMO_WAVE == TIM0_TOGL_OC0
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);

#elif TIMO_WAVE == TIM0_SET_OC0
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIMO_WAVE == TIM0_CLR_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIMO_WAVE == TIM0_FAST_INVERT_OC0
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIMO_WAVE == TIM0_FAST_NONINVERT_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIMO_WAVE == TIM0_PHASE_NONINVERT_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIMO_WAVE == TIM0_PHASE_INVERT_OC0
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#else
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
#endif

}


void TIM0_voidEnable(uint8 u8PreScaler)
{

	TCCR0&=0b11111000;
	//& 0b00000111 --> to prevent the user  to entermore than 111 in bits 0,1,2

	TCCR0|= (u8PreScaler & 0b00000111);

}
void TIM0_voidDisable(void)
{
	TCCR0&=0b11111000;
}
void TIM0_voidEnableOvfINt(void)
{
	SET_BIT(TIMSK,0);

}
void TIM0_voidDisableOvfINt(void)
{
	CLR_BIT(TIMSK,0);

}
void TIM0_voidEnableComparINt(void)
{
	SET_BIT(TIMSK,1);

}
void TIM0_voidDisableCompareINt(void)
{
	CLR_BIT(TIMSK,1);
}

void TIM0_voidSetCallBackOvfInt(pf pfOvfcallBack)
{
	TIM0_pfOVFCallBack=pfOvfcallBack;
}
void TIM0_voidSetCallBackCompareInt(pf pfComcallBack)
{
	TIM0_pfCmpCallBack=pfComcallBack;
}

void TIM0_voidSetTCNTValue(uint8 u8TcntReg)
{
	TCNT0 = u8TcntReg;
}
void TIM0_voidSetOCRValue(uint8 u8OcrReg)
{
	OCR0 = u8OcrReg;
}
uint8 TIM0_u8ReadTcntReg(void)
{
	return TCNT0 ;
}

void TIM0_voidChangMode(uint8 u8Mode)
{}

/* ISR OVF*/


void __vector_11  (void)  __attribute__ ((signal,used));

void __vector_11  (void)
{
	TIM0_pfOVFCallBack();
}

/* COM ISR */
void __vector_10  (void)  __attribute__ ((signal,used));

void __vector_10  (void)
{
	TIM0_pfCmpCallBack();
}


