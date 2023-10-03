/********************************************************************/
/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: GPIO_interface.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


typedef enum 
{
	GPIO_PortA=0  	,
	GPIO_PortB  	,
	GPIO_PortC
}GPIO_Port_t;

typedef enum 
{
	GPIO_Pin0=0 	,
	GPIO_Pin1  		,
	GPIO_Pin2 		,
	GPIO_Pin3 		,
	GPIO_Pin4 		,
	GPIO_Pin5 		,
	GPIO_Pin6 		,
	GPIO_Pin7 		,
	GPIO_Pin8 		,
	GPIO_Pin9 		,
	GPIO_Pin10 		,
	GPIO_Pin11 		,
	GPIO_Pin12 		,
	GPIO_Pin13 		,
	GPIO_Pin14 		,
	GPIO_Pin15
}GPIO_Pin_t;

typedef enum 
{
	GPIO_Output_PP_2MHz 	=0b0010		,
	GPIO_Output_OD_2MHz 	=0b0110		,
	GPIO_Output_AF_PP_2MHz 	=0b1010		,
	GPIO_Output_AF_OD_2MHz 	=0b1110		,	
	GPIO_Output_PP_10MHz 	=0b0001		,
	GPIO_Output_OD_10MHz 	=0b0101 	,
	GPIO_Output_AF_PP_10MHz =0b1001		,
	GPIO_Output_AF_OD_10MHz =0b1101		,
	GPIO_Output_PP_50MHz    =0b0011		,
	GPIO_Output_OD_50MHz 	=0b0111		,
	GPIO_Output_AF_PP_50MHz =0b1011		,
	GPIO_Output_AF_OD_50MHz =0b1111		,
	GPIO_INPUT_AN 			=0b0000		,
	GPIO_INPUT_FL  			=0b0100		,
	GPIO_INPUT_PUD  		=0b1000
}GPIO_Mode_t;

typedef enum 
{
	GPIO_Low=0,
	GPIO_High
}GPIO_PinVoltage_t;

typedef enum 
{
	GPIO_Lower_Byte=0,
	GPIO_Higher_Byte
}GPIO_Byte_t;

void MGPIO_voidSetPinMode(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin, GPIO_Mode_t  Copy_u8Mode);
void MGPIO_voidSetPinValue(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin, GPIO_PinVoltage_t  Copy_u8PinVoltage);
GPIO_PinVoltage_t MGPIO_u8GetPinValue(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin);
void MGPIO_voidLockPinMode(GPIO_Port_t Copy_u8Port, GPIO_Pin_t Copy_u8Pin);

/*After determining what pins you need to lock you need to lock the port ,only specified pins will be locked in the port*/
void MGPIO_voidConfirmLock(GPIO_Port_t Copy_u8Port);
void MGPIO_voidSetByteMode(GPIO_Port_t Copy_u8Port, GPIO_Byte_t Copy_u8Byte,GPIO_Mode_t  Copy_u8Mode);
void MGPIO_voidSetByteValue(GPIO_Port_t Copy_u8Port, GPIO_Byte_t Copy_u8Byte,u8  Copy_u8ByteValue);





#endif