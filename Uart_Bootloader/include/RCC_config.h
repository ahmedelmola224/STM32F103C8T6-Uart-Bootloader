/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: RCC_config.h		                                */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*Choose Clock Type: -RCC_HSE_CRYSTAL
					 -RCC_HSE_RC
					 -RCC_HSI_RC
					 -RCC_PLL
					 */

#define RCC_CLOCK_TYPE  RCC_HSI_RC

/*Choose AHB Prescaler: -RCC_SYSCLK_NOT_DIV
					 	-RCC_SYSCLK_DIV_2
						-RCC_SYSCLK_DIV_4
						-RCC_SYSCLK_DIV_8
						-RCC_SYSCLK_DIV_16
						-RCC_SYSCLK_DIV_64
						-RCC_SYSCLK_DIV_128
						-RCC_SYSCLK_DIV_256
						-RCC_SYSCLK_DIV_512
					 	*/

#define RCC_AHB_PRESCAlER  RCC_SYSCLK_NOT_DIV

/*Choose APB1 & APB2 Prescaler:-RCC_HCLK_NOT_DIV
					 		   -RCC_HCLK_DIV_2
							   -RCC_HCLK_DIV_4
							   -RCC_HCLK_DIV_8
							   -RCC_HCLK_DIV_16
					 	*/

#define RCC_APB1_PRESCAlER  RCC_HCLK_NOT_DIV
#define RCC_APB2_PRESCAlER  RCC_HCLK_DIV_8


/*You can choose only if Clock Type is RCC_PLL */
#if RCC_CLOCK_TYPE == RCC_PLL

/*Choose PLL INPUT: -RCC_PLL_HSE_DIV_2
					-RCC_PLL_HSE
					-RCC_PLL_HSI_DIV_2
					 */
#define RCC_PLL_INPUT RCC_PLL_HSE_DIV_2

/*Choose PLL MULTIPLY FACTOR: RCC_PLL_MUL_2 ..  RCC_PLL_MUL_16*/
#define RCC_PLL_MUL_FACTOR   RCC_PLL_MUL_2

#endif

#endif
