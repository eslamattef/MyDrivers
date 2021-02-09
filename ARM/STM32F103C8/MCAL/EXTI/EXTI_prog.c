/*
 * EXTI_program.c
 *
 *  Created on: Feb 8, 2021
 *      Author: Eslam Attef
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#ifndef		NULL
#define 	NULL		(void *)0
#endif

static void (*EXTI_pfCallBackArray[EXTI_TOTAL_LINES])(void) = {NULL};



void EXTI_voidInit(void)
{
	/*		Select all Edge Modes for All Lines		*/
#if			EXTI_Edge_LINE0 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR , 0);
#elif		EXTI_Edge_LINE0 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 0);
#elif		EXTI_Edge_LINE0 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 0);
	SET_BIT(EXTI -> FTSR , 0);
#else
#error		"Wrong Choice of edge mode for line0 !"
#endif

#if			EXTI_Edge_LINE1 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR , 1);
#elif		EXTI_Edge_LINE1 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 1);
#elif		EXTI_Edge_LINE1 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 1);
	SET_BIT(EXTI -> FTSR , 1);
#else
#error		"Wrong Choice of edge mode for line1 !"
#endif

#if			EXTI_Edge_LINE2 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR , 2);
#elif		EXTI_Edge_LINE2 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 2);
#elif		EXTI_Edge_LINE2 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 2);
	SET_BIT(EXTI -> FTSR , 2);
#else
#error		"Wrong Choice of edge mode for line2 !"
#endif

#if			EXTI_Edge_LINE3 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR , 3);
#elif		EXTI_Edge_LINE3 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 3);
#elif		EXTI_Edge_LINE3 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 3);
	SET_BIT(EXTI -> FTSR , 3);
#else
#error		"Wrong Choice of edge mode for line3 !"
#endif


#if			EXTI_Edge_LINE4 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR , 4);
#elif		EXTI_Edge_LINE4 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 4);
#elif		EXTI_Edge_LINE4 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 4);
	SET_BIT(EXTI -> FTSR , 4);
#else
#error		"Wrong Choice of edge mode for line4 !"
#endif



#if			EXTI_Edge_LINE5 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,5);
#elif		EXTI_Edge_LINE5 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 5);
#elif		EXTI_Edge_LINE5 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 5);
	SET_BIT(EXTI -> FTSR , 5);
#else
#error		"Wrong Choice of edge mode for line5 !"
#endif

#if			EXTI_Edge_LINE6 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,6);
#elif		EXTI_Edge_LINE6 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 6);
#elif		EXTI_Edge_LINE6 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 6);
	SET_BIT(EXTI -> FTSR , 6);
#else
#error		"Wrong Choice of edge mode for line6 !"
#endif



#if			EXTI_Edge_LINE7 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,7);
#elif		EXTI_Edge_LINE7 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 7);
#elif		EXTI_Edge_LINE7 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 7);
	SET_BIT(EXTI -> FTSR , 7);
#else
#error		"Wrong Choice of edge mode for line7 !"
#endif


#if			EXTI_Edge_LINE8 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,8);
#elif		EXTI_Edge_LINE8 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 8);
#elif		EXTI_Edge_LINE8 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 8);
	SET_BIT(EXTI -> FTSR , 8);
#else
#error		"Wrong Choice of edge mode for line8 !"
#endif


#if			EXTI_Edge_LINE9 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,9);
#elif		EXTI_Edge_LINE9 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 9);
#elif		EXTI_Edge_LINE9 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 9);
	SET_BIT(EXTI -> FTSR , 9);
#else
#error		"Wrong Choice of edge mode for line9 !"
#endif


#if			EXTI_Edge_LINE10 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,10);
#elif		EXTI_Edge_LINE10 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 10);
#elif		EXTI_Edge_LINE10 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 10);
	SET_BIT(EXTI -> FTSR , 10);
#else
#error		"Wrong Choice of edge mode for line10 !"
#endif


#if			EXTI_Edge_LINE11 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,11);
#elif		EXTI_Edge_LINE11 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 11);
#elif		EXTI_Edge_LINE11 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 11);
	SET_BIT(EXTI -> FTSR , 11);
#else
#error		"Wrong Choice of edge mode for line11 !"
#endif


#if			EXTI_Edge_LINE12 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,12);
#elif		EXTI_Edge_LINE12 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 12);
#elif		EXTI_Edge_LINE12 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 12);
	SET_BIT(EXTI -> FTSR , 12);
#else
#error		"Wrong Choice of edge mode for line12 !"
#endif


#if			EXTI_Edge_LINE13 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,13);
#elif		EXTI_Edge_LINE13 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 13);
#elif		EXTI_Edge_LINE13 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 13);
	SET_BIT(EXTI -> FTSR , 13);
#else
#error		"Wrong Choice of edge mode for line13 !"
#endif


#if			EXTI_Edge_LINE14 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,14);
#elif		EXTI_Edge_LINE14 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 14);
#elif		EXTI_Edge_LINE14 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 14);
	SET_BIT(EXTI -> FTSR , 14);
#else
#error		"Wrong Choice of edge mode for line14 !"
#endif


#if			EXTI_Edge_LINE15 == EXTI_FALLING
	SET_BIT(EXTI -> FTSR ,15);
#elif		EXTI_Edge_LINE15 == EXTI_RISING
	SET_BIT(EXTI -> RTSR , 15);
#elif		EXTI_Edge_LINE15 == EXTI_IOC
	SET_BIT(EXTI -> RTSR , 15);
	SET_BIT(EXTI -> FTSR , 15);
#else
#error		"Wrong Choice of edge mode for line15 !"
#endif


	/*		Disable all EXTI lines		 			*/
	EXTI -> IMR = 0;
	/*		Clear All Pending BITs					*/
	EXTI -> PR 	= 0xFFFFFFFF;
}

void EXTI_voidEnableLine(EXTI_LineType Copy_LineNumber)
{
	/*Range Check*/
	if(Copy_LineNumber<EXTI_TOTAL_LINES)
	{
		SET_BIT(EXTI -> IMR , Copy_LineNumber);
	}
	else
	{
		/*Return Error*/
	}
}

void EXTI_voidSetSignalLatch(EXTI_LineType Copy_LineNumber, u8 Copy_u8EdgeMode)
{
	/*Range Check*/

	if(Copy_LineNumber < EXTI_TOTAL_LINES)
	{
		CLR_BIT(EXTI -> FTSR , Copy_LineNumber );
		CLR_BIT(EXTI -> RTSR , Copy_LineNumber );
		switch(Copy_u8EdgeMode)
		{
		case EXTI_RISING 	: 	SET_BIT(EXTI -> RTSR , Copy_LineNumber ); 	break;
		case EXTI_FALLING 	:	SET_BIT(EXTI -> FTSR , Copy_LineNumber ); 	break;
		case EXTI_IOC 		: 	SET_BIT(EXTI -> RTSR , Copy_LineNumber );
		SET_BIT(EXTI -> FTSR , Copy_LineNumber );	break;
		}
	}
	else
	{
		/*Return Error*/
	}
}
void EXTI_voidDisableLine(EXTI_LineType Copy_LineNumber )
{
	/*Range Check*/
	if(Copy_LineNumber<EXTI_TOTAL_LINES)
	{
		CLR_BIT(EXTI -> IMR , Copy_LineNumber);
	}
	else
	{
		/*Return Error*/
	}
}

void EXTI_voidSetCallBack(EXTI_LineType Copy_LineNumber,void (*pf) (void)) // address ahmed Function
{

	/*Range Check*/
	if(Copy_LineNumber<EXTI_TOTAL_LINES)
	{
		if(pf != NULL)
		{
			/*EXTI_pfCallBack = pf = address Function*/
			EXTI_pfCallBackArray[Copy_LineNumber] = pf ;
		}
	}
	else
	{
		/*Return Error*/
	}
}

void EXTI_voidSetSoftwareTrigger(EXTI_LineType Copy_LineNumber)
{
	/*Range Check*/
	if(Copy_LineNumber<EXTI_TOTAL_LINES)
	{
		SET_BIT(EXTI -> SWIER,Copy_LineNumber);
	}
	else
	{
		/*Return Error*/
	}
}
void EXTI_voidClearIntFlag(EXTI_LineType Copy_LineNumber)
{
	/*Range Check*/
	if(Copy_LineNumber<EXTI_TOTAL_LINES)
	{
		SET_BIT(EXTI ->PR ,Copy_LineNumber);
	}
	else
	{
		/*Return Error*/
	}
}


/* 			External Interrupt  									*/

void EXTI0_IRQHandler(void)
{
	EXTI_pfCallBackArray[EXTI_LINE0]();

	/*CLEAR interrupt flag */
	SET_BIT(EXTI ->PR ,0);
}

void EXTI1_IRQHandler(void)
{
	EXTI_pfCallBackArray[EXTI_LINE1]();

	/*CLEAR interrupt flag */
	SET_BIT(EXTI ->PR ,1);
}
void EXTI2_IRQHandler(void)
{
	EXTI_pfCallBackArray[EXTI_LINE2]();

	/*CLEAR interrupt flag  Clear*/
	SET_BIT(EXTI ->PR ,2);
}
void EXTI3_IRQHandler(void)
{
	EXTI_pfCallBackArray[EXTI_LINE3]();

	/*CLEAR interrupt flag */
	SET_BIT(EXTI ->PR ,3);
}
void EXTI4_IRQHandler(void)
{
	EXTI_pfCallBackArray[EXTI_LINE4]();

	/*CLEAR interrupt flag */
	SET_BIT(EXTI ->PR ,4);
}
void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(EXTI ->PR ,5)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE5]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,5);
	}
	if(GET_BIT(EXTI ->PR ,6)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE6]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,6);
	}
	if(GET_BIT(EXTI ->PR ,7)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE7]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,7);
	}
	if(GET_BIT(EXTI ->PR ,8)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE8]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,8);
	}
	if(GET_BIT(EXTI ->PR ,9)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE9]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,9);
	}

}
void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(EXTI ->PR ,10)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE10]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,10);
	}
	if(GET_BIT(EXTI ->PR ,11)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE11]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,11);
	}
	if(GET_BIT(EXTI ->PR ,12)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE12]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,12);
	}
	if(GET_BIT(EXTI ->PR ,13)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE13]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,13);
	}
	if(GET_BIT(EXTI ->PR ,14)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE14]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,14);
	}
	if(GET_BIT(EXTI ->PR ,15)==1)
	{
		EXTI_pfCallBackArray[EXTI_LINE15]();

		/*CLEAR interrupt flag */
		SET_BIT(EXTI ->PR ,15);
	}

}




