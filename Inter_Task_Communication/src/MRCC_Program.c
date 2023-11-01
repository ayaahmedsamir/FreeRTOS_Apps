#include <BIT_Math.h>
#include"../include/STD_Types.h"
#include"../include/MRCC_Private.h"
#include"../include/MRCC_interface.h"
#include"../include/MRCC_Config.h"


void MRCC_Init(void)
{
#if (SYS_CLK==RCC_HSI)
	SET_BIT(RCC->RCC_CR,CR_HSI_ON);

	while(GET_BIT(RCC->RCC_CR,CR_HSI_RDY)==0){}
	RCC->RCC_CFGR = (RCC->RCC_CFGR & 0xFFFFFFFC) | (SWITCH_HSI) ;

#elif (SYS_CLK==RCC_HSE)
	SET_BIT(RCC->RCC_CR,CR_HSE_ON);

	while(GET_BIT(RCC->RCC_CR,CR_HSE_RDY)==0){}
	RCC->RCC_CFGR = (RCC->RCC_CFGR & 0xFFFFFFFC) | (SWITCH_HSE) ;

#elif (SYS_CLK==RCC_PLL)
	SET_BIT(RCC->RCC_CR,CR_PLL_ON);

	while(GET_BIT(RCC->RCC_CR,CR_PLL_RDY)==0){}
	RCC->RCC_CFGR = (RCC->RCC_CFGR & 0xFFFFFFFC) | (SWITCH_PLL) ;

#endif


}
void MRCC_Enable_Peripheral(uint32 Copy_32Address_Bus,uint32 Copy_32Peripheral)
{
	switch (Copy_32Address_Bus)
	{
	case RCC_AHB1:
		SET_BIT(RCC->RCC_AHB1ENR,Copy_32Peripheral);
		break;

	case RCC_AHB2:
		SET_BIT(RCC->RCC_AHB2ENR,Copy_32Peripheral);
			break;

	case RCC_APB1:
		SET_BIT(RCC->RCC_APB1ENR,Copy_32Peripheral);
			break;

	case RCC_APB2:
		SET_BIT(RCC->RCC_APB2ENR,Copy_32Peripheral);
			break;
	default:
		break;

	}

}
void MRCC_Disable_Peripheral(uint32 Copy_32Address_Bus,uint32 Copy_32Peripheral)
{

	switch (Copy_32Address_Bus)
		{
		case RCC_AHB1:
			CLR_BIT(RCC->RCC_AHB1ENR,Copy_32Peripheral);
			break;

		case RCC_AHB2:
			CLR_BIT(RCC->RCC_AHB2ENR,Copy_32Peripheral);
				break;

		case RCC_APB1:
			CLR_BIT(RCC->RCC_APB1ENR,Copy_32Peripheral);
				break;

		case RCC_APB2:
			CLR_BIT(RCC->RCC_APB2ENR,Copy_32Peripheral);
				break;
		default:
			break;

		}
}

