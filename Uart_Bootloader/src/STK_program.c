#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

static u8 STK_u8RunningMode = STK_PERIODIC_MODE;
static void(*STK_ptrFunc)(void)=NULL;

void MSTK_voidInit()
{
	/*Set Systick Clock Source*/
	WRITE_BIT(STK_CTRL,2,STK_CLK_SRC);
	/*Disable Peripheral*/
	CLR_BIT(STK_CTRL,0);
	/*Disable Interrupt*/
	CLR_BIT(STK_CTRL,1);
}


void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	STK_LOAD = Copy_u32Ticks;
	STK_VAL = 0;
	/*Disable Interrupts*/
	CLR_BIT(STK_CTRL,1);
	/*Enable Peripheral*/
	SET_BIT(STK_CTRL,0);
	/*Polling*/
	while((GET_BIT(STK_CTRL,16)) == 0);
	/*Reset Load & Value Registers*/
	STK_LOAD  = 0;
	STK_VAL = 0;
	/*Disable Peripherl*/
	CLR_BIT(STK_CTRL,0);
}



void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,void(*Copy_ptrFunc)(void))
{
	STK_LOAD = Copy_u32Ticks;
	/*Write to ST_VALUE to load the new value*/
	STK_VAL = 0;
	/*function to be called after the ticks had been ellapsed*/
	STK_ptrFunc = Copy_ptrFunc;
	/*Set the Running Mode */
	STK_u8RunningMode = STK_SINGLE_MODE;
	/*Enable Peripheral*/
	SET_BIT(STK_CTRL,0);
	/*Enable Interrupts*/
	SET_BIT(STK_CTRL,1);
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void(*Copy_ptrFunc)(void))
{
	STK_LOAD = Copy_u32Ticks;
	/*Write to ST_VALUE to load the new value*/
	STK_VAL = 0;
	STK_ptrFunc = Copy_ptrFunc;
	/*Set the Running Mode */
	STK_u8RunningMode = STK_PERIODIC_MODE;	
	/*Enable Peripheral*/
	SET_BIT(STK_CTRL,0);
	/*Enable Interrupts*/
	SET_BIT(STK_CTRL,1);

}

void MSTK_voidSetIntervalStop(void)
{
	/*Reset Load & Value Registers*/
	STK_LOAD  = 0;
	STK_VAL = 0;
	/*Disable Peripheral*/
	CLR_BIT(STK_CTRL,0);
	/*Disable Interrupt*/
	CLR_BIT(STK_CTRL,1);
}

u32 MSTK_u32GetElapsedTicks(void)
{
	return STK_LOAD - STK_VAL ;
}


u32 MSTK_u32GetRemainningTicks(void)
{
	return STK_VAL ;
}

void SysTick_Handler(void)
{
	STK_ptrFunc();
	/*Flag Clearence*/
	GET_BIT(STK_CTRL,16);
	if(STK_u8RunningMode == STK_SINGLE_MODE)
	{
		/*Reset Load & Value Registers*/
		STK_VAL = 0;
		STK_LOAD  = 0;
		/*Disabl Peripheral*/
		CLR_BIT(STK_CTRL,0);
		/*Disable Interrupts*/
		CLR_BIT(STK_CTRL,1);

	}
}
