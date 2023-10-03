#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"



static void (*Fptr_Rx)(u8)=NULL;
static void (*Fptr_Tx)(void)=NULL;


void MUART_voidInit(void)
{
	/*Baud Rate Calculations*/
	u16 LOC_u16BaudRateMantissa = (F_CPU) / (16 * UART1_BAUD_RATE) ;
	u16 LOC_u8BaudRateFraction   = ((((u32)F_CPU * 100) / (16 * (u32)UART1_BAUD_RATE)) % 100) * 16 ;

	if(LOC_u8BaudRateFraction > 1500)
	{
		LOC_u16BaudRateMantissa++;
		LOC_u8BaudRateFraction = 0 ;
	}
	u16 LOC_u16BaudRate = (LOC_u16BaudRateMantissa << 4) | (LOC_u8BaudRateFraction/100) ;
	UART->UART_BRR = LOC_u16BaudRate ;

	/*Data Size*/
	WRITE_BIT(UART->UART_CR1 ,12,UART1_DATA_SIZE);

	/*Parity bit*/
	#if UART1_PARITY_BIT == UART_PARITY_DIS
		CLR_BIT(UART->UART_CR1,10);
	#else
		SET_BIT(UART->UART_CR1,10);
		WRITE_BIT(UART->UART_CR1,9,(UART1_PARITY_BIT-1)) ;
	#endif	
		/*TX & Rx*/
	WRITE_BIT(UART->UART_CR1,3,UART1_TRANSMITTER);	
	WRITE_BIT(UART->UART_CR1,2,UART1_RECEIVER);	
	
	/*Stop Bits*/
	UART->UART_CR2 = UART1_STOP_BITS << 12 ;

	/*Enable Uart*/
	SET_BIT(UART->UART_CR1,13);
}


void MUART_voidDisablePeripheral(void)
{
	UART->UART_SR = 0x00;

	/*Disable Uart*/
	CLR_BIT(UART->UART_CR1,13);
}


void MUART_voidSendSync(u8 Copy_u8DataToTransmit)
{
	/*wait to transmit*/
	while((GET_BIT(UART->UART_SR,6)) == 0);

	/*clear the flag*/
	CLR_BIT(UART->UART_SR,6);

	UART->UART_DR = Copy_u8DataToTransmit;
}

void MUART_voidRecieveSync(u8* Copy_pu8DataToRecieve)
{
	/*wait until data is received*/
	while((GET_BIT(UART->UART_SR,5)) == 0);

	*Copy_pu8DataToRecieve = UART->UART_DR ;

	/*clear the flag*/
	CLR_BIT(UART->UART_SR,5);
}

u8 MUART_u8RecievePeriodic(u8* Copy_pu8DataToRecieve)
{
	u8 LOC_u8Result =0;
	if((GET_BIT(UART->UART_SR,5)) == 1)
	{
		*Copy_pu8DataToRecieve = UART->UART_DR ;

		/*clear the flag*/
		CLR_BIT(UART->UART_SR,5);

		LOC_u8Result = 1 ;
	}
	return LOC_u8Result;
}



void MUART_voidInterruptEnable(UART_Interrupts_t Copy_u8Int)
{
	SET_BIT(UART->UART_CR1 ,Copy_u8Int);
}

void MUART_voidInterruptDisable(UART_Interrupts_t Copy_u8Int)
{
	CLR_BIT(UART->UART_CR1 ,Copy_u8Int);
}

void MUART_voidRxSetCallBack(void(*Copy_Fptr)(u8))
{
	if(Copy_Fptr !=NULL)
	{
		Fptr_Rx = Copy_Fptr;
	}
}

void MUART_voidTxSetCallBack(void(*Copy_Fptr)(void))
{
	if(Copy_Fptr !=NULL)
	{
		Fptr_Tx = Copy_Fptr;
	}

}

/*used only with tx interrupt*/
void MUART_voidSendNoBlock(u8 Copy_u8DataToTransmit)
{
	UART->UART_DR = Copy_u8DataToTransmit;
}

void USART1_IRQHandler(void)
{
	/*Rx interrupt*/
	if((GET_BIT(UART->UART_SR,5)))
	{
		if(Fptr_Rx != NULL)
		{
			Fptr_Rx(UART->UART_DR);
		}

	/*clear the flag*/
	CLR_BIT(UART->UART_SR,5);
	}

	/*Tx interrupt*/
	if((GET_BIT(UART->UART_SR,6)))
	{
		if(Fptr_Tx != NULL)
		{
			Fptr_Tx();
		}

	/*clear the flag*/
	CLR_BIT(UART->UART_SR,6);
	}

}
