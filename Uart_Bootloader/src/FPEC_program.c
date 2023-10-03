#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FPEC_private.h"
#include "FPEC_config.h"
#include "FPEC_interface.h"

void MFPEC_voidEraseAppArea(void)
{
	u8 i;
	for(i=4;i<64;i++)
	{
		MFPEC_voidEraseFlashPage(i);
	}
}

void MFPEC_voidEraseFlashPage(u8 Copy_u8PageNumber)
{
	/*wait if there is process of flashing running*/
	while((GET_BIT(FPEC -> FLASH_SR,0))==1);

	/* Check if locked or not */
	if ((GET_BIT(FPEC -> FLASH_CR,7)) == 1)
	{
		FPEC -> FLASH_KEYR = 0x45670123;
		FPEC -> FLASH_KEYR = 0xCDEF89AB;
	}

	/*erase mode*/
	SET_BIT(FPEC ->FLASH_CR , 1);

	/*set page address*/
	FPEC -> FLASH_AR = (u32)(Copy_u8PageNumber * 1024) + 0x08000000;

	/*start erasing*/
	SET_BIT(FPEC ->FLASH_CR , 6);	

	/*wait until flashing done*/
	while((GET_BIT(FPEC -> FLASH_SR , 0))==1);

	/*EOP*/
	SET_BIT(FPEC -> FLASH_SR , 5);
	CLR_BIT(FPEC -> FLASH_CR , 1);

}
void MFPEC_voidWriteToFlash(u32 Copy_u32Address,u16 *Copy_pu16Data,u8 Copy_u8Length)
{
	u8 i;
	volatile u16 temp;
	/*wait if there is process of flashing running*/
	while((GET_BIT(FPEC -> FLASH_SR,0))==1);

	/* Check if locked or not */
	if ((GET_BIT(FPEC -> FLASH_CR,7)) == 1)
	{
		FPEC -> FLASH_KEYR = 0x45670123;
		FPEC -> FLASH_KEYR = 0xCDEF89AB;
	}

	for(i = 0;i<Copy_u8Length;i++)
	{
		/*write mode*/
		SET_BIT(FPEC ->FLASH_CR , 1);

		/*Half Word*/
		temp=Copy_pu16Data[i];
		*((volatile u16*)Copy_u32Address)=temp;

		/*16 bit is written so move to next address*/
		Copy_u32Address += 2;

		/*wait until flashing done*/
		while((GET_BIT(FPEC -> FLASH_SR,0))==1);

		/*EOP*/
		SET_BIT(FPEC -> FLASH_SR , 5);
		CLR_BIT(FPEC -> FLASH_CR , 0);

	}

}
