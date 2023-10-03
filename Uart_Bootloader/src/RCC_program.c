#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"




void MRCC_voidInitClockSystem()
{
	#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL

	/*Bits 1:0 SW[1:0]: System clock Switch
		01: HSE selected as system clock*/
	SET_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);

	/*Bit 16 HSEON: HSE clock enable
		0: HSE oscillator OFF
		1: HSE oscillator ON*/
	SET_BIT(RCC_CR,16);

	/*Bit 18 HSEBYP: External high-speed clock bypass
		0: external 3-25 MHz oscillator not bypassed
		1: external 3-25 MHz oscillator bypassed with external clock*/
	CLR_BIT(RCC_CR,18);

	/*Bit 17 HSERDY: External high-speed clock ready flag
		0: HSE oscillator not ready
		1: HSE oscillator ready*/
	/*wait until the clock is ready*/
	while(!GET_BIT(RCC_CR,17)); 


	#elif 	RCC_CLOCK_TYPE == RCC_HSE_RC

	/*Bits 1:0 SW[1:0]: System clock Switch
		01: HSE selected as system clock*/
	SET_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);

	/*Bit 16 HSEON: HSE clock enable
		0: HSE oscillator OFF
		1: HSE oscillator ON*/
	SET_BIT(RCC_CR,16);

	/*Bit 18 HSEBYP: External high-speed clock bypass
	0: external 3-25 MHz oscillator not bypassed
	1: external 3-25 MHz oscillator bypassed with external clock*/
	SET_BIT(RCC_CR,18);

	/*Bit 17 HSERDY: External high-speed clock ready flag
		0: HSE oscillator not ready
		1: HSE oscillator ready*/
	/*wait until the clock is ready*/
	while(!GET_BIT(RCC_CR,17));


	#elif 	RCC_CLOCK_TYPE == RCC_HSI_RC

	/*Bits 1:0 SW[1:0]: System clock Switch
		00: HSI selected as system clock*/
	CLR_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);

	/*Bit 0 HSION: Internal high-speed clock enable
		0: Internal 8 MHz RC oscillator OFF
		1: Internal 8 MHz RC oscillator ON*/
	SET_BIT(RCC_CR,0);

	/*Bit 1 HSIRDY: Internal high-speed clock ready flag
		0: Internal 8 MHz RC oscillator not ready
		1: Internal 8 MHz RC oscillator ready*/
	/*wait until the clock is ready*/
	while(!GET_BIT(RCC_CR,1));


	#elif 	RCC_CLOCK_TYPE == RCC_PLL
	/*Bits 1:0 SW[1:0]: System clock Switch
		10: PLL selected as system clock*/
	CLR_BIT(RCC_CFGR,0);
	SET_BIT(RCC_CFGR,1);

		#if 	RCC_PLL_INPUT == RCC_PLL_HSE

		/* Bit 17 PLLXTPRE: HSE divider for PLL entry
			0: HSE clock not divided
			1: HSE clock divided by 2*/
		CLR_BIT(RCC_CFGR,17);


		/*Bit 16 PLLSRC: PLL entry clock source
			0: HSI oscillator clock / 2 selected as PLL input clock
			1: HSE oscillator clock selected as PLL input clock*/
		SET_BIT(RCC_CFGR,16);


		#elif 	RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2

		/* Bit 17 PLLXTPRE: HSE divider for PLL entry
			0: HSE clock not divided
			1: HSE clock divided by 2*/
		SET_BIT(RCC_CFGR,17);
		

		/*Bit 16 PLLSRC: PLL entry clock source
			0: HSI oscillator clock / 2 selected as PLL input clock
			1: HSE oscillator clock selected as PLL input clock*/
		SET_BIT(RCC_CFGR,16);


		#elif   RCC_PLL_INPUT == RCC_PLL_HSI_DIV_2

		/*Bit 16 PLLSRC: PLL entry clock source
			0: HSI oscillator clock / 2 selected as PLL input clock
			1: HSE oscillator clock selected as PLL input clock*/
		CLR_BIT(RCC_CFGR,16);
		#else
			#error "Wrong Pll Input"
		#endif  /*PLL INPUT*/
		
		/*Bits 21:18 PLLMUL[3:0]: PLL multiplication facto
			0010: PLL input clock x 4*/
		#if 	RCC_PLL_MUL_FACTOR >= RCC_PLL_MUL_2 && RCC_PLL_MUL_FACTOR <= RCC_PLL_MUL_16
			RCC_CFGR&= (~((0b1111)<<18));
			RCC_CFGR|= RCC_PLL_MUL_FACTOR <<18;

		#else
			#error "Wrong PLL Multiply Factor"
		#endif /*PLL MUL*/


	/*PLLON: PLL enable 
	 0: PLL OFF
	 1: PLL ON*/
	SET_BIT(RCC_CR,24);
	#else
		#error "Wrong Clock Type"
	#endif /*CLOCK TYPE*/

	#if 	RCC_AHB_PRESCAlER >= RCC_SYSCLK_NOT_DIV &&  RCC_AHB_PRESCAlER <= RCC_SYSCLK_DIV_512
	RCC_CFGR&= (~((0b1111)<<4));
	RCC_CFGR|= RCC_AHB_PRESCAlER <<4;
	#else

	#error "Wrong AHB PRESCALER"
	#endif

	#if 	RCC_APB1_PRESCAlER >= RCC_HCLK_NOT_DIV &&  RCC_APB1_PRESCAlER <= RCC_HCLK_DIV_16
	RCC_CFGR&= (~((0b111)<<8));
	RCC_CFGR|= RCC_APB1_PRESCAlER <<8;
	#else

	#error "Wrong APB1 PRESCALER"
	#endif

	#if 	RCC_APB2_PRESCAlER >= RCC_HCLK_NOT_DIV &&  RCC_APB2_PRESCAlER <= RCC_HCLK_DIV_16
	RCC_CFGR&= (~((0b111)<<11));
	RCC_CFGR|= RCC_APB2_PRESCAlER <<11;
	#else

	#error "Wrong APB2 PRESCALER"
	#endif


}


void MRCC_voidEnablePreipheralClock(u8 Copy_u8PreipheralBus,u8 Copy_u8Preipheral)
{
	switch(Copy_u8PreipheralBus)
	{
		case RCC_AHB: SET_BIT(RCC_AHBENR,Copy_u8Preipheral);     break;
		case RCC_APB1: SET_BIT(RCC_APB1ENR,Copy_u8Preipheral);   break;
		case RCC_APB2: SET_BIT(RCC_APB2ENR,Copy_u8Preipheral);   break;
		default:                                                 break;
	}
}


void MRCC_voidDisablePreipheralClock(u8 Copy_u8PreipheralBus,u8 Copy_u8Preipheral)
{
	switch(Copy_u8PreipheralBus)
	{
		case RCC_AHB:  CLR_BIT(RCC_AHBENR,Copy_u8Preipheral);    break;
		case RCC_APB1: CLR_BIT(RCC_APB1ENR,Copy_u8Preipheral);   break;
		case RCC_APB2: CLR_BIT(RCC_APB2ENR,Copy_u8Preipheral);   break;
		default:                                                 break;
	}
}