/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: FPEC_private.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

#define FPEC_BASE  0x40022000 

typedef struct
{
	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_AR;
	volatile u32 FLASH_RESERVED;
	volatile u32 FLASH_OBR;
	volatile u32 FLASH_WRPR;
}FPEC_Registers_t;

#define FPEC  ((volatile FPEC_Registers_t *)FPEC_BASE)



#endif
