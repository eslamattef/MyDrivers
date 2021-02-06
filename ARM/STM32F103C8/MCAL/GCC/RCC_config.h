/*
 * RCC_config.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Eslam
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*  CLOCK_TYPE can be:
 *    1-RCC_HSI
 *    2-RCC_HSE
 *    3-RCC_PLL
 */
#define CLOCK_TYPE  RCC_HSE
#if     CLOCK_TYPE == RCC_HSE
/* can be RCC_CRYSTAL or RCC_RC*/

#define RCC_HSE_SOURCE  RCC_CRYSTAL
#endif

#if  CLOCK_TYPE==RCC_PLL
/*******PLL Multiplication factor 1:16 ******************/
#define RCC_PLL_MUL RCC_HSE 1
/*******PLL Source (HSE/HSI)*****************/
#define RCC_PLL_SOURCE     RCC_HSI

#endif

#endif /* RCC_CONFIG_H_ */
