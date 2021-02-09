/*
 * NVIC_program.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Boon
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidInit(void)
{
	/*		Number of Groups and Sub Groups	SCB			*/
#ifndef			SCB_AIRCR
#define 	SCB_AIRCR 			*((u32 *)(0xE000ED00 + 0x0C))
#endif
	/*	2 G and 2 sub				*/
	SCB_AIRCR = NUM_GROUPS_AND_SUB;
}
void NVIC_voidEnableInterrupt(INTERRUPT_Type Copy_InterruptType)
{
	if(Copy_InterruptType < 32)
	{
		NVIC_ISER0 = ( 1 << Copy_InterruptType );
	}
	else if (Copy_InterruptType < 60)
	{
		Copy_InterruptType -= 32;
		NVIC_ISER1 = ( 1 << Copy_InterruptType );
	}
	else{/*					Return ERROR						*/}
}
void NVIC_voidDisableInterrupt(INTERRUPT_Type Copy_InterruptType)
{
	if(Copy_InterruptType < 32)
	{
		NVIC_ICER0 = ( 1 << Copy_InterruptType );
	}
	else if (Copy_InterruptType < 60)
	{
		Copy_InterruptType -= 32;
		NVIC_ICER1 = ( 1 << Copy_InterruptType );
	}
	else{/*					Return ERROR						*/}
}
void NVIC_voidSetPendingFlag(INTERRUPT_Type Copy_InterruptType)
{
	if(Copy_InterruptType < 32)
	{
		NVIC_ISPR0 = ( 1 << Copy_InterruptType );
	}
	else if (Copy_InterruptType < 60)
	{
		Copy_InterruptType -= 32;
		NVIC_ISPR1 = ( 1 << Copy_InterruptType );
	}
	else{/*					Return ERROR						*/}
}
void NVIC_voidClearPendingFlag(INTERRUPT_Type Copy_InterruptType)
{
	if(Copy_InterruptType < 32)
	{
		NVIC_ICPR0 = ( 1 << Copy_InterruptType );
	}
	else if (Copy_InterruptType < 60)
	{
		Copy_InterruptType -= 32;
		NVIC_ICPR1 = ( 1 << Copy_InterruptType );
	}
	else{/*					Return ERROR						*/}
}
u8	 NVIC_u8GetActiveFlag(INTERRUPT_Type Copy_InterruptType)
{
	u8 Local_u8Active = 0xFF;
	if(Copy_InterruptType < 32)
	{
		Local_u8Active = GET_BIT(NVIC_IABR0,Copy_InterruptType);
	}
	else if (Copy_InterruptType < 60)
	{
		Copy_InterruptType -= 32;
		Local_u8Active = GET_BIT(NVIC_IABR1,Copy_InterruptType);
	}
	else{/*					Return ERROR						*/}
	return Local_u8Active;
}

void NVIC_voidSetPriority(INTERRUPT_Type Copy_InterruptType , NVIC_GroupNumberType Copy_GroupNumber,NVIC_SubGroupNumberType Copy_SubGroupNumber)
{
	u8	Local_u8PerPriority;

#if   NUM_GROUPS_AND_SUB == GROUPS_16_SUB_0

	Local_u8PerPriority=Copy_GroupNumber;
	if(Copy_GroupNumber < NVIC_GROUP_NONE && Copy_SubGroupNumber == NVIC_SUBGROUP_NONE)
	{
		NVIC_IPR[Copy_InterruptType] = (Local_u8PerPriority<<4);

	}
#elif NUM_GROUPS_AND_SUB == GROUPS_8_SUB_2

	Local_u8PerPriority=((Copy_GroupNumber<<1)|Copy_SubGroupNumber);
	if(Copy_GroupNumber < NVIC_GROUP8 && Copy_SubGroupNumber < NVIC_SUBGROUP2)
	{
		NVIC_IPR[Copy_InterruptType] = (Local_u8PerPriority<<4);

	}
#elif NUM_GROUPS_AND_SUB == GROUPS_4_SUB_4

	Local_u8PerPriority=((Copy_GroupNumber<<2)|Copy_SubGroupNumber);
	if(Copy_GroupNumber < NVIC_GROUP4 && Copy_SubGroupNumber < NVIC_SUBGROUP4)
	{
		NVIC_IPR[Copy_InterruptType] = (Local_u8PerPriority<<4);

	}
#elif NUM_GROUPS_AND_SUB == GROUPS_2_SUB_8

	Local_u8PerPriority=((Copy_GroupNumber<<3)|Copy_SubGroupNumber);
	if(Copy_GroupNumber < NVIC_GROUP2 && Copy_SubGroupNumber < NVIC_SUBGROUP8)
	{
		NVIC_IPR[Copy_InterruptType] = (Local_u8PerPriority<<4);

	}

#elif NUM_GROUPS_AND_SUB == GROUPS_0_SUB_16
	Local_u8PerPriority=Copy_SubGroupNumber;
	if(Copy_GroupNumber == NVIC_GROUP_NONE && Copy_SubGroupNumber < NVIC_SUBGROUP_NONE)
	{
		NVIC_IPR[Copy_InterruptType] = (Local_u8PerPriority<<4);

	}
#endif

}
