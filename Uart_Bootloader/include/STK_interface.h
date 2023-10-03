/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: STK_interface.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H



void MSTK_voidInit();
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,void(*Copy_ptrFunc)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void(*Copy_ptrFunc)(void));
void MSTK_voidSetIntervalStop(void);
u32 MSTK_u32GetElapsedTicks(void);
u32 MSTK_u32GetRemainningTicks(void);

#endif