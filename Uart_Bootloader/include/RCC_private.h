/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: RCC_private.h		                                */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

			/*RCC Register Definations*/
#define RCC_BASE          0x40021000
#define RCC_CR            *((volatile u32 *)(RCC_BASE+0x00))
#define RCC_CFGR          *((volatile u32 *)(RCC_BASE+0x04))
#define RCC_CIR           *((volatile u32 *)(RCC_BASE+0x08))
#define RCC_APB2RSTR      *((volatile u32 *)(RCC_BASE+0x0c))
#define RCC_APB1RSTR      *((volatile u32 *)(RCC_BASE+0x10))
#define RCC_AHBENR        *((volatile u32 *)(RCC_BASE+0x14))/*AHB peripheral clock enable register*/
#define RCC_APB2ENR       *((volatile u32 *)(RCC_BASE+0x18))/*APB2 peripheral clock enable register*/
#define RCC_APB1ENR       *((volatile u32 *)(RCC_BASE+0x1C))/*APB1 peripheral clock enable register*/
#define RCC_BDCR          *((volatile u32 *)(RCC_BASE+0x20))
#define RCC_CSR           *((volatile u32 *)(RCC_BASE+0x24))


			/*Clock Types*/
#define RCC_HSE_CRYSTAL   0
#define RCC_HSE_RC        1
#define RCC_HSI_RC        2
#define RCC_PLL           3



			/*PLL INPUT*/
#define RCC_PLL_HSE_DIV_2  0
#define RCC_PLL_HSE        1   
#define RCC_PLL_HSI_DIV_2  2

			/*PLL MUL*/
#define RCC_PLL_MUL_2       0b0000
#define RCC_PLL_MUL_3       0b0001
#define RCC_PLL_MUL_4       0b0010
#define RCC_PLL_MUL_5       0b0011
#define RCC_PLL_MUL_6       0b0100
#define RCC_PLL_MUL_7       0b0101
#define RCC_PLL_MUL_8       0b0110
#define RCC_PLL_MUL_9       0b0111
#define RCC_PLL_MUL_10      0b1000
#define RCC_PLL_MUL_11      0b1001
#define RCC_PLL_MUL_12      0b1010
#define RCC_PLL_MUL_13      0b1011
#define RCC_PLL_MUL_14      0b1100
#define RCC_PLL_MUL_15      0b1101
#define RCC_PLL_MUL_16      0b1110


	 	/*AHB prescaler*/
#define RCC_SYSCLK_NOT_DIV    0b0000
#define RCC_SYSCLK_DIV_2      0b1000
#define RCC_SYSCLK_DIV_4      0b1001
#define RCC_SYSCLK_DIV_8      0b1010
#define RCC_SYSCLK_DIV_16     0b1011
#define RCC_SYSCLK_DIV_64     0b1100
#define RCC_SYSCLK_DIV_128    0b1101
#define RCC_SYSCLK_DIV_256    0b1110
#define RCC_SYSCLK_DIV_512    0b1111


		/*APB prescaler (APB1)&(APB2)*/	
#define RCC_HCLK_NOT_DIV   	  0b000
#define RCC_HCLK_DIV_2  	  0b100
#define RCC_HCLK_DIV_4   	  0b101
#define RCC_HCLK_DIV_8   	  0b110
#define RCC_HCLK_DIV_16 	  0b111



#endif