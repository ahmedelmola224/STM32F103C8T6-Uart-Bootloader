#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "STK_interface.h"
#include "FPEC_interface.h"
#include "parse.h"


 u8 GLO_u8TimeoutFlag =0 	;
 u8 GLO_u8BlBuffer[100]		;
 u8 GLO_u8BufferCounter=0 	;
 u8 GLO_u8FirstRecord = 1;

typedef void (*Function_t)(void);
Function_t addr_to_call = 0;


void BL_JmupToApplicaation()
{
	/*IVT Address*/
	#define SCB_VTOR   *((volatile u32*)0xE000ED08)
	SCB_VTOR = 0x08001000;

	/*jump to IVT & Skip sp*/
	addr_to_call = *(Function_t*)(0x08001004);
	addr_to_call();

}

void main(void)
{
	u8 LOC_u8RecState = 0;
	/*HSI*/
	MRCC_voidInitClockSystem(); 
	/*Peripherrals clock Init*/
	MRCC_voidEnablePreipheralClock(RCC_APB2,RCC_IOPA);/*GPIO*/
	MRCC_voidEnablePreipheralClock(RCC_APB2,RCC_USART1);/*UART*/
	MRCC_voidEnablePreipheralClock(RCC_AHB,RCC_FLITF);/*FPEC*/

	/*UART PINS*/
	MGPIO_voidSetPinMode(GPIO_PortA,GPIO_Pin9,GPIO_Output_AF_PP_2MHz);/*TX*/
	MGPIO_voidSetPinMode(GPIO_PortA,GPIO_Pin10,GPIO_INPUT_FL);/*RX*/

	/*UART Init*/
	MUART_voidInit();/*baud rate 9600*/

	/*STK Init*/
	MSTK_voidInit();
	MSTK_voidSetIntervalSingle(15000000,BL_JmupToApplicaation);/*15 sec*/

	while(GLO_u8TimeoutFlag == 0)
	{
		LOC_u8RecState =MUART_u8RecievePeriodic(&(GLO_u8BlBuffer[GLO_u8BufferCounter]));
		if(LOC_u8RecState==1)
		{
			MSTK_voidSetIntervalStop();
			if(GLO_u8BlBuffer[GLO_u8BufferCounter]=='\n')
			{
				if(GLO_u8FirstRecord == 1)
				{
					MFPEC_voidEraseAppArea();
					GLO_u8FirstRecord = 0;
				}


				Parser_voidParseRecord(GLO_u8BlBuffer);
				MUART_voidSendSync('o');
				MUART_voidSendSync('k');
				GLO_u8BufferCounter = 0;
			}
			else
			{
				GLO_u8BufferCounter++;
			}

			MSTK_voidSetIntervalSingle(15000000,BL_JmupToApplicaation);/*15 sec*/
		}
		else
		{
			/*nothing to receieve*/
		}
	}


	

}

