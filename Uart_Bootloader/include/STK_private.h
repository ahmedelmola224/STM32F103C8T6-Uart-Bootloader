/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: STK_private.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

		/*STK Registers Definations*/
#define STK_BASE   0xE000E010

#define STK_CTRL 	 *((volatile u32 *)(STK_BASE+0x00)) 
#define STK_LOAD  	 *((volatile u32 *)(STK_BASE+0x04)) 
#define STK_VAL  	 *((volatile u32 *)(STK_BASE+0x08)) 
#define STK_CALIB 	 *((volatile u32 *)(STK_BASE+0x0C)) 


#define STK_AHB_CLK_DIV_8    0
#define STK_AHB_CLK 		 1

#define STK_SINGLE_MODE      0
#define STK_PERIODIC_MODE    1





#endif