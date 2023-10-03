/* Author       : Ahmed Essam                                       */
/* Date         :                                                   */
/* File Name	: FPEC_interface.h		                            */
/* Type      	: Header File	                                    */
/* Version      : V01                                               */
/********************************************************************/

#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

void MFPEC_voidEraseAppArea(void);
void MFPEC_voidEraseFlashPage(u8 Copy_u8PageNumber);
void MFPEC_voidWriteToFlash(u32 Copy_u32Address,u16 *Copy_pu16Data,u8 Copy_u8Length);



#endif
