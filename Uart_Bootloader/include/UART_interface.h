/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: UART_interface.h	                                */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

typedef enum 
{
	UART_IDLEI = 4 ,
	UART_RXNEI = 5 , 
	UART_TCI   = 6 , 
	UART_TXEI  = 7 ,  
	UART_PEIE  = 8
}UART_Interrupts_t;

void MUART_voidInit(void);
void MUART_voidDisablePeripheral(void);
void MUART_voidSendSync(u8 Copy_u8DataToTransmit);
void MUART_voidRecieveSync(u8* Copy_pu8DataToRecieve);
u8 MUART_u8RecievePeriodic(u8* Copy_pu8DataToRecieve);
void MUART_voidInterruptEnable(UART_Interrupts_t Copy_u8Int);
void MUART_voidInterruptDisable(UART_Interrupts_t Copy_u8Int);
void MUART_voidRxSetCallBack(void(*Copy_Fptr)(u8));
void MUART_voidTxSetCallBack(void(*Copy_Fptr)(void));

/*used only with tx interrupt*/
void MUART_voidSendNoBlock(u8 Copy_u8DataToTransmit);

#endif
