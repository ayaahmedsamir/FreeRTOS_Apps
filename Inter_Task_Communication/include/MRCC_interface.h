
#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/***************************************************************************************************************
                                           * BUSES *
 ****************************************************************************************************************/
#define RCC_AHB1 0
#define RCC_AHB2 1
#define RCC_APB1 2
#define RCC_APB2 3


/******************************************************************************************************************
                                          * bits in registers *
 *****************************************************************************************************************/
#define RCC_APB1_TIM2       0
#define RCC_APB1_TIM3       1
#define RCC_APB1_TIM4       2
#define RCC_APB1_TIM5       3
#define RCC_APB1_WWDG       11
#define RCC_APB1_SPI2       14
#define RCC_APB1_SPI3       15

#define RCC_APB2_TIM1        0
#define RCC_APB2_USART1      4
#define RCC_APB2_USART6      5
#define RCC_APB2_ADC1        8
#define RCC_APB2_SPI1        12


#define RCC_AHB1_GPIOA       0
#define RCC_AHB1_GPIOB       1
#define RCC_AHB1_GPIOC       2
#define RCC_AHB1_GPIOD       3
#define RCC_AHB1_GPIOE       4
#define RCC_AHB1_GPIOH       7

#define RCC_AHB2_OTGFS       7

/**********************************************************************************************************************
                                                          *function prototypes/
 *********************************************************************************************************************/

void MRCC_Init(void);
void MRCC_Enable_Peripheral(uint32 Copy_32Address_Bus,uint32 Copy_32Peripheral);
void MRCC_Disable_Peripheral(uint32 Copy_32Address_Bus,uint32 Copy_32Peripheral);




#endif /* MRCC_INTERFACE_H_ */
