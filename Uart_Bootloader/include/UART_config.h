/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: UART_config.h		                                */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define F_CPU				8000000
#define UART1_BAUD_RATE		9600

/*Choose one of the following : -UART_DATA_BITS_8
								-UART_DATA_BITS_9 */
#define UART1_DATA_SIZE   	UART_DATA_BITS_8

/*Choose one of the following : -UART_PARITY_DIS
								-UART_PARITY_EVEN
								-UART_PARITY_ODD */
#define UART1_PARITY_BIT	UART_PARITY_DIS

/*Choose one of the following : -UART_TX_DISABLE
								-UART_TX_ENABLE */
#define UART1_TRANSMITTER	UART_TX_ENABLE

/*Choose one of the following : -UART_RX_DISABLE
								-UART_RX_ENABLE */
#define UART1_RECEIVER		UART_RX_ENABLE

/*Choose one of the following : -UART_STOP_BITS_1
								-UART_STOP_BITS_2 */
#define	UART1_STOP_BITS  	UART_STOP_BITS_1
 
#endif