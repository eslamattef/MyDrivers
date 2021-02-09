/*
 * EXTI_interface.h
 *
 *  Created on: Feb 8, 2021
 *      Author: Eslam Attef
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum{

	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
	EXTI_TOTAL_LINES


}EXTI_LineType;



void EXTI_voidInit(void);
void EXTI_voidEnableLine(EXTI_LineType Copy_LineNumber);
void EXTI_voidSetSignalLatch(EXTI_LineType Copy_LineNumber, u8 Copy_u8EdgeMode);
void EXTI_voidDisableLine(EXTI_LineType Copy_LineNumber );

void EXTI_voidSetCallBack(EXTI_LineType Copy_LineNumber,void (*pf) (void));
void EXTI_voidSetSoftwareTrigger(EXTI_LineType Copy_LineNumber);
void EXTI_voidClearIntFlag(EXTI_LineType Copy_LineNumber);

#endif /* EXTI_INTERFACE_H_ */
