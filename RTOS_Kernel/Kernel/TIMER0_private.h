/*****************************************************************/
/* Author  : ahmed saeed                                         */
/* Layer   : MCAL                                                */
/* SWC     : TIMER0                                              */
/* Version : 1.0                                                 */
/* Date    : 16 Aug 2023                                         */
/*****************************************************************/
#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TIM0_NORMAL       10
#define TIM0_CTC          20
#define TIM0_FAST_PWM     30
#define TIM0_PHASE_PWM    40
/* non pwm modes */
#define TIM0_TOGL_OC0        0
#define TIM0_SET_OC0         1
#define TIM0_CLR_OC0         2

/*  pwm modes */
#define TIM0_FAST_INVERT_OC0           3
#define TIM0_FAST_NONINVERT_OC0        4

#define TIM0_PHASE_INVERT_OC0           5
#define TIM0_PHASE_NONINVERT_OC0        6

#define TIM0_DISCONNECT                 7









#define TCCR0       *((volatile  uint8*) 0x53)
#define TCNT0       *((volatile  uint8*) 0x52)
#define OCR0        *((volatile  uint8*) 0x5C)
#define TIMSK       *((volatile  uint8*) 0x59)
#define TIFR        *((volatile  uint8*) 0x58)




#endif
