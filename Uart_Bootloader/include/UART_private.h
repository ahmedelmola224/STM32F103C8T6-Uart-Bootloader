/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: UART_private.h	                                */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


#define  UART_BASE   0x40013800 

typedef struct 
{
	u32 UART_SR;
	u32 UART_DR;
	u32 UART_BRR;
	u32 UART_CR1;
	u32 UART_CR2;
	u32 UART_CR3;
	u32 UART_GTPR;
}UART_Registers_t;


#define UART  ((volatile UART_Registers_t *)UART_BASE)

/* Word length*/
#define UART_DATA_BITS_8  	0
#define UART_DATA_BITS_9	1

/*Parity control enable*/
#define UART_PARITY_DIS 	0
#define UART_PARITY_EVEN 	1
#define UART_PARITY_ODD 	2 

/*Transmitter enable*/
#define UART_TX_DISABLE 	0
#define UART_TX_ENABLE		1

/*Reciever enable*/
#define UART_RX_DISABLE 	0
#define UART_RX_ENABLE		1

/* STOP bits*/
#define UART_STOP_BITS_1	0
#define UART_STOP_BITS_2 	2





#endif