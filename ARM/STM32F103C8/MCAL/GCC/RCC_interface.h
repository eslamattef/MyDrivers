/*
 * RCC_interface.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Eslam
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include <STD_TYPES.h>

void RCC_voidInit(void);
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PreipheralID);
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PreipheralID);

#define 	RCC_AHB				0

#define  RCC_DMA1_ID           0
#define  RCC_DMA2_ID           1
#define  RCC_SRAM_ID           2
#define  RCC_FLITF_ID          4
#define  RCC_CRCE_ID           6
#define  RCC_FSMC_ID           8
#define  RCC_SDIO_ID           10



#define 	RCC_APB1			1

#define  RCC_TIM2_ID           0
#define  RCC_TIM3_ID           1
#define  RCC_TIM4_ID           2
#define  RCC_TIM5_ID           3
#define  RCC_TIM6_ID           4
#define  RCC_TIM7_ID           5
#define  RCC_TIM12_ID          6
#define  RCC_TIM13_ID          7
#define  RCC_TIM14_ID          8
#define  RCC_WWDG_ID           11
#define  RCC_SPI2_ID           14
#define  RCC_SPI3_ID           15
#define  RCC_USART2_ID         17
#define  RCC_USART3_ID         18
#define  RCC_USART4_ID         19
#define  RCC_USART5_ID         20
#define  RCC_I2C1_ID           21
#define  RCC_I2C2_ID           22
#define  RCC_USB_ID            23
#define  RCC_CAN_ID            25
#define  RCC_BKP_ID            27
#define  RCC_PWR_ID            28
#define  RCC_DAC_ID            29





#define 	RCC_APB2			2

#define  RCC_GPIOA_ID           2
#define  RCC_GPIOB_ID           3
#define  RCC_GPIOC_ID           4
#define  RCC_GPIOD_ID           5
#define  RCC_GPIOE_ID           6
#define  RCC_GPIOF_ID           7
#define  RCC_GPIOC_ID           8
#define  RCC_ADC1_ID            9
#define  RCC_ADC2_ID            10
#define  RCC_TIM1_ID            11
#define  RCC_SPI1_ID            12
#define  RCC_TIM8_ID            13
#define  RCC_USART1_ID          14
#define  RCC_ADC3_ID            15
#define  RCC_TIM9_ID            19
#define  RCC_TIM10_ID           20
#define  RCC_RIM11_ID           21






#endif /* RCC_INTERFACE_H_ */
