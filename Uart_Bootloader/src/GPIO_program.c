#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void MGPIO_voidSetPinMode(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin, GPIO_Mode_t  Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIO_PortA:
			if(Copy_u8Pin <= 7) /*Low REG 0:7*/
			{
				/*Clear nibble of the pin*/
				CLR_NIBBLE(GPIOA_CRL,Copy_u8Pin * 4);
				/*Write to nibble of the pin the specifed mode*/
				WRITE_NIBBLE(GPIOA_CRL,Copy_u8Pin * 4,Copy_u8Mode);
			}
			else if(Copy_u8Pin <= 15) /*High REG 8:15*/
			{
				/*Maping pin to the required bit in the REG*/
				Copy_u8Pin = Copy_u8Pin - 8; 
				/*Clear nibble of the pin*/
				CLR_NIBBLE(GPIOA_CRH,Copy_u8Pin * 4);
				/*Write to nibble of the pin the specifed mode*/
				WRITE_NIBBLE(GPIOA_CRH,Copy_u8Pin * 4,Copy_u8Mode);
			}
			break;

		case GPIO_PortB:
			if(Copy_u8Pin <= 7)/*Low REG 0:7*/
			{
				/*Clear nibble of the pin*/
				CLR_NIBBLE(GPIOB_CRL,Copy_u8Pin * 4);
				/*Write to nibble of the pin the specifed mode*/
				WRITE_NIBBLE(GPIOB_CRL,Copy_u8Pin * 4,Copy_u8Mode);
			}
			else if(Copy_u8Pin <= 15)/*High REG 8:15*/
			{
				/*Maping pin to the required bit in the REG*/
				Copy_u8Pin = Copy_u8Pin - 8;
				/*Clear nibble of the pin*/
				CLR_NIBBLE(GPIOB_CRH,Copy_u8Pin * 4);
				/*Write to nibble of the pin the specifed mode*/
				WRITE_NIBBLE(GPIOB_CRH,Copy_u8Pin * 4,Copy_u8Mode);
			}
			break;

		case GPIO_PortC:
			if(Copy_u8Pin <= 7)/*Low REG 0:7*/
			{
				/*Clear nibble of the pin*/
				CLR_NIBBLE(GPIOC_CRL,Copy_u8Pin * 4);
				/*Write to nibble of the pin the specifed mode*/
				WRITE_NIBBLE(GPIOC_CRL,Copy_u8Pin * 4,Copy_u8Mode);
			}
			else if(Copy_u8Pin <= 15)
			{
				/*Maping pin to the required bit in the REG*/
				Copy_u8Pin = Copy_u8Pin - 8;
				/*Clear nibble of the pin*/
				CLR_NIBBLE(GPIOC_CRH,Copy_u8Pin * 4);
				/*Write to nibble of the pin the specifed mode*/
				WRITE_NIBBLE(GPIOC_CRH,Copy_u8Pin * 4,Copy_u8Mode);
			}
			break;	
		default: break;


	}
}


void MGPIO_voidSetPinValue(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin, GPIO_PinVoltage_t  Copy_u8PinVoltage)
{
	switch(Copy_u8Port)
	{
		case GPIO_PortA:
			if(Copy_u8PinVoltage == GPIO_Low) /*Low voltage*/
			{
				/*BRR(0-16) -> set bit to reset the pin*/ 
				SET_BIT(GPIOA_BRR,Copy_u8Pin); 
			}
			else if(Copy_u8PinVoltage == GPIO_High)/*High voltage*/
			{
				/*BSRR(0-16) -> set bit to set the pin*/
				SET_BIT(GPIOA_BSRR,Copy_u8Pin);
			}
			break;
		case GPIO_PortB:
			if(Copy_u8PinVoltage == GPIO_Low) /*Low voltage*/
			{
				/*BRR(0-16) -> set bit to reset the pin*/ 
				SET_BIT(GPIOB_BRR,Copy_u8Pin);
			}
			else if(Copy_u8PinVoltage == GPIO_High)/*High voltage*/
			{
				/*BSRR(0-16) -> set bit to set the pin*/
				SET_BIT(GPIOB_BSRR,Copy_u8Pin);
			}
			break;
		case GPIO_PortC:
			if(Copy_u8PinVoltage == GPIO_Low) /*Low voltage*/
			{
				/*BRR(0-16) -> set bit to reset the pin*/ 
				SET_BIT(GPIOC_BRR,Copy_u8Pin);
			}
			else if(Copy_u8PinVoltage == GPIO_High)/*High voltage*/
			{
				/*BSRR(0-16) -> set bit to set the pin*/
				SET_BIT(GPIOC_BSRR,Copy_u8Pin);
			}
			break;	
		default: break;		
	}
}


GPIO_PinVoltage_t MGPIO_u8GetPinValue(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin)
{
	GPIO_PinVoltage_t LOC_u8Result=0;
	switch(Copy_u8Port)
	{
		case GPIO_PortA:
			/* get the pin value from IDR of specified port */
			LOC_u8Result = GET_BIT(GPIOA_IDR,Copy_u8Pin);
			break;
		case GPIO_PortB:
			/* get the pin value from IDR of specified port */			
			LOC_u8Result = GET_BIT(GPIOB_IDR,Copy_u8Pin);
			break;
		case GPIO_PortC:
			/* get the pin value from IDR of specified port */
			LOC_u8Result = GET_BIT(GPIOC_IDR,Copy_u8Pin);
			break;	
		default: break;		
	}
	return LOC_u8Result;

}

void MGPIO_voidLockPinMode(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIO_PortA:
			/*Config the pin in the port to lock*/
			SET_BIT(GPIOA_LCKR,Copy_u8Pin);
			break;
		case GPIO_PortB:
			/*Config the pin in the port to lock*/
			SET_BIT(GPIOB_LCKR,Copy_u8Pin);
			break;
		case GPIO_PortC:
			/*Config the pin in the port to lock*/
			SET_BIT(GPIOC_LCKR,Copy_u8Pin);
			break;	
		default: break;		
	}
}

void MGPIO_voidConfirmLock(GPIO_Port_t Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case GPIO_PortA:
			/*Confirm the lock of pins of the specified port by writing a specifed sequence*/
			SET_BIT(GPIOA_LCKR,16);
			CLR_BIT(GPIOA_LCKR,16);
			SET_BIT(GPIOA_LCKR,16);
			CLR_BIT(GPIOA_LCKR,16);
			SET_BIT(GPIOA_LCKR,16);			
			break;
		case GPIO_PortB:
			/*Confirm the lock of pins of the specified port by writing a specifed sequence*/
			SET_BIT(GPIOB_LCKR,16);
			CLR_BIT(GPIOB_LCKR,16);
			SET_BIT(GPIOB_LCKR,16);
			CLR_BIT(GPIOB_LCKR,16);
			SET_BIT(GPIOB_LCKR,16);	
			break;
		case GPIO_PortC:
			/*Confirm the lock of pins of the specified port by writing a specifed sequence*/
			SET_BIT(GPIOC_LCKR,16);
			CLR_BIT(GPIOC_LCKR,16);
			SET_BIT(GPIOC_LCKR,16);
			CLR_BIT(GPIOC_LCKR,16);
			SET_BIT(GPIOC_LCKR,16);	
			break;	
		default: break;		
	}

}




 void MGPIO_voidSetByteMode(GPIO_Port_t Copy_u8Port, GPIO_Byte_t Copy_u8Byte,GPIO_Mode_t  Copy_u8Mode)
{
	u8 LOC_u8Iterator = 0;
	GPIO_Pin_t LOC_u8StartPin;
	if(Copy_u8Byte == GPIO_Lower_Byte)
	{
		/*Lower byte starts from pin 0 to 7 */
		LOC_u8StartPin = GPIO_Pin0;
	}
	else 
	{
		/*Higher byte starts from pin 8 to 15 */
		LOC_u8StartPin = GPIO_Pin8;
	}
	/*loop to intialize the specified byte of the port*/
	for( ; LOC_u8Iterator < 8 ; LOC_u8Iterator++ )
		MGPIO_voidSetPinMode(Copy_u8Port,LOC_u8StartPin + LOC_u8Iterator,Copy_u8Mode);	
}


 void MGPIO_voidSetByteValue(GPIO_Port_t Copy_u8Port, GPIO_Byte_t Copy_u8Byte,u8  Copy_u8ByteValue)
{
	u8 LOC_u8Bit;
	u8 LOC_u8Iterator = 0;
	GPIO_Pin_t LOC_u8StartPin;
	if(Copy_u8Byte == GPIO_Lower_Byte)
	{
		/*Lower byte starts from pin 0 to 7 */
		LOC_u8StartPin = GPIO_Pin0;
	}
	else 
	{
		/*Higher byte starts from pin 8 to 15 */
		LOC_u8StartPin = GPIO_Pin8;
	}

	/*loop to write to the specified byte of the port*/
	for( ; LOC_u8Iterator < 8 ; LOC_u8Iterator++ )
	{
		LOC_u8Bit=GET_BIT(Copy_u8ByteValue,LOC_u8Iterator);
		MGPIO_voidSetPinValue(Copy_u8Port,LOC_u8StartPin + LOC_u8Iterator,LOC_u8Bit);
	}
}
