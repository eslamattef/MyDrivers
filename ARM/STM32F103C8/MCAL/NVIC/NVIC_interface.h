/*
 * NVIC_interface.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Eslam Attef
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum{
	NVIC_WWDG             ,
	NVIC_PVD              ,
	NVIC_TAMPER           ,
	NVIC_RTC              ,
	NVIC_FLASH            ,
	NVIC_RCC              ,
	NVIC_EXTI0            ,
	NVIC_EXTI1            ,
	NVIC_EXTI2            ,
	NVIC_EXTI3            ,
	NVIC_EXTI4            ,
	NVIC_DMA1_Channel1    ,
	NVIC_DMA1_Channel2    ,
	NVIC_DMA1_Channel3    ,
	NVIC_DMA1_Channel4    ,
	NVIC_DMA1_Channel5    ,
	NVIC_DMA1_Channel6    ,
	NVIC_DMA1_Channel7    ,
	NVIC_ADC1_2           ,
	NVIC_USB_HP_CAN_TX    ,
	NVIC_USB_LP_CAN_RX0   ,
	NVIC_CAN1_RX1         ,
	NVIC_CAN1_SCE         ,
	NVIC_EXTI9_5          ,
	NVIC_TIM1_BRK         ,
	NVIC_TIM1_UP          ,
	NVIC_TIM1_TRG_COM     ,
	NVIC_TIM1_CC          ,
	NVIC_TIM2             ,
	NVIC_TIM3             ,
	NVIC_TIM4             ,
	NVIC_I2C1_EV          ,
	NVIC_I2C1_ER          ,
	NVIC_I2C2_EV          ,
	NVIC_I2C2_ER          ,
	NVIC_SPI1             ,
	NVIC_SPI2             ,
	NVIC_USART1           ,
	NVIC_USART2           ,
	NVIC_USART3           ,
	NVIC_EXTI15_10        ,
	NVIC_RTCAlarm         ,
	NVIC_USBWakeup        ,
	NVIC_TIM8_BRK         ,
	NVIC_TIM8_UP          ,
	NVIC_TIM8_TRG_COM     ,
	NVIC_TIM8_CC          ,
	NVIC_ADC3             ,
	NVIC_FSMC             ,
	NVIC_SDIO             ,
	NVIC_TIM5             ,
	NVIC_SPI3             ,
	NVIC_UART4            ,
	NVIC_UART5            ,
	NVIC_TIM6             ,
	NVIC_TIM7             ,
	NVIC_DMA2_Channel1    ,
	NVIC_DMA2_Channel2    ,
	NVIC_DMA2_Channel3    ,
	NVIC_DMA2_Channel4_5

}INTERRUPT_Type;

typedef enum{
	NVIC_GROUP0,
	NVIC_GROUP1,
	NVIC_GROUP2,
	NVIC_GROUP3,
	NVIC_GROUP4,
	NVIC_GROUP5,
	NVIC_GROUP6,
	NVIC_GROUP7,
	NVIC_GROUP8,
	NVIC_GROUP9,
	NVIC_GROUP10,
	NVIC_GROUP11,
	NVIC_GROUP12,
	NVIC_GROUP13,
	NVIC_GROUP14,
	NVIC_GROUP15,
	NVIC_GROUP_NONE

}NVIC_GroupNumberType;

typedef enum{
	NVIC_SUBGROUP0,
    NVIC_SUBGROUP1,
    NVIC_SUBGROUP2,
    NVIC_SUBGROUP3,
    NVIC_SUBGROUP4,
    NVIC_SUBGROUP5,
    NVIC_SUBGROUP6,
    NVIC_SUBGROUP7,
    NVIC_SUBGROUP8,
    NVIC_SUBGROUP9,
    NVIC_SUBGROUP10,
    NVIC_SUBGROUP11,
    NVIC_SUBGROUP12,
    NVIC_SUBGROUP13,
    NVIC_SUBGROUP14,
    NVIC_SUBGROUP15,
    NVIC_SUBGROUP_NONE

}NVIC_SubGroupNumberType;






void NVIC_voidInit(void);

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNum);
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNum);

void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNum);
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptNum);

u8	 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptNum);

void NVIC_voidSetPriority(INTERRUPT_Type Copy_InterruptType , NVIC_GroupNumberType Copy_GroupNumber,NVIC_SubGroupNumberType Copy_SubGroupNumber);

#endif /* NVIC_INTERFACE_H_ */
