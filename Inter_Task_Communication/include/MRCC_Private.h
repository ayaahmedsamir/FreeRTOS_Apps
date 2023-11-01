
#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_


#define RCC_BASE_ADDRESS   (0x40023800)

/*******************************************************************************************
                              * system clock options *
 *******************************************************************************************/
#define RCC_HSE                0
#define RCC_HSI                1
#define RCC_PLL                2

/*******************************************************************************************
                              * system clock switch *
 *******************************************************************************************/
#define SWITCH_HSE 1
#define SWITCH_HSI 0
#define SWITHC_PLL 2

typedef struct
{

	uint32 RCC_CR;
	uint32 RCC_PLLCFGR;
	uint32 RCC_CFGR;
	uint32 RCC_CIR;
	uint32 RCC_AHB1RSTR;
	uint32 RCC_AHB2RSTR;
	uint32 RESERVED1;
	uint32 RESERVED2;
	uint32 RCC_APB1RSTR;
	uint32 RCC_APB2RSTR;
	uint32 RESERVED3;
	uint32 RESERVED4;
	uint32 RCC_AHB1ENR;
	uint32 RCC_AHB2ENR;
	uint32 RESERVED5;
	uint32 RESERVED6;
	uint32 RCC_APB1ENR;
	uint32 RCC_APB2ENR;
	uint32 RESERVED7;
	uint32 RESERVED8;
	uint32 RCC_AHB1LPENR;
	uint32 RCC_AHB2LPENR;
	uint32 RESERVED9;
	uint32 RESERVED10;
	uint32 RCC_APB1LPENR;
	uint32 RCC_APB2LPENR;
	uint32 RESERVED11;
	uint32 RESERVED12;
	uint32 RCC_BDCR;
	uint32 RCC_CSR;
	uint32 RESERVED13;
	uint32 RESERVED14;
	uint32 RCC_SSCGR;
	uint32 RCC_PLLI2SCFGR;
	uint32 RESERVED15;
	uint32 RCC_DCKCFGR;

}RCC_t;



#define RCC    ((volatile RCC_t*) RCC_BASE_ADDRESS) // To make address struct is the base address //

/*************************************************************************************************************
                                *CR register bits*
 ****************************************************************************************************************/
#define CR_HSE_ON        16
#define CR_HSI_ON        0
#define CR_PLL_ON        24
#define CR_HSE_RDY       17
#define CR_HSI_RDY       1
#define CR_PLL_RDY       25

#endif /* MRCC_PRIVATE_H_ */
