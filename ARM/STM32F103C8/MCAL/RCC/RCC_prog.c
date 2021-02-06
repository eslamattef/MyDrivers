/*
 * RCC_prog.c
 *
 *  Created on: Feb 2, 2021
 *      Author: Eslam
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_privet.h"
#include "RCC_config.h"

void RCC_voidInit(void){
	u32 Local_u32TimeOut=0;
#if 	CLOCK_TYPE == RCC_HSI
	SET_BIT(RCC_CR,0);											/*HSI Enable					*/
	while((GET_BIT(RCC_CR,1)==0) && Local_u32TimeOut<10000){  	/*wait for HSI be ready			*/
		Local_u32TimeOut++;
	}
#elif 	CLOCK_TYPE == RCC_HSE

        #if	  RCC_HSE_SOURCE == RCC_CRYSTAL
        	  CLR_BIT(RCC_CR,18);											/*set input of HSE as Crystal	*/
        #elif RCC_HSE_SOURCE == RCC_RC
        	  SET_BIT(RCC_CR,18);											/*set input of HSE as RC		*/
        #endif

	SET_BIT(RCC_CR,16);											/*HSE Enable				    */

	SET_BIT(RCC_CFGR,0);	    								/*Set System clock as HSE		*/
	CLR_BIT(RCC_CFGR,1);

	while((GET_BIT(RCC_CR,17)==0) && Local_u32TimeOut < 10000){ /*wait for HSE be ready			*/
		Local_u32TimeOut++;
	}
	Local_u32TimeOut = 0;

	while((GET_BIT(RCC_CFGR,2)==0) &&(GET_BIT(RCC_CFGR,3)==1) && Local_u32TimeOut < 10000){
		Local_u32TimeOut++;										/*wait for HSE selected as SYS CLK*/
	}
	///////////////////////////////////clock security will be added

#elif	CLOCK_TYPE == RCC_PLL
#if 	PLL_INPUT  == RCC_HSIDIV2
	SET_BIT(RCC_CR,0);											/*HSI Enable					*/
	while((GET_BIT(RCC_CR,1)==0) && Local_u32TimeOut<10000){  	/*wait for HSI be ready			*/
		Local_u32TimeOut++;
	}
	CLR_BIT(RCC_CFGR,16);										/*set input of PLL as HSI/2		*/

#elif	PLL_INPUT  == RCC_HSE

#if	  RCC_HSE_SOURCE == RCC_CRYSTAL
	CLR_BIT(RCC_CR,18);											/*set input of HSE as Crystal	*/
#elif RCC_HSE_SOURCE == RCC_RC
	SET_BIT(RCC_CR,18);											/*set input of HSE as RC		*/
#endif

	SET_BIT(RCC_CR,16);											/*HSE Enable				    */


	while((GET_BIT(RCC_CR,17)==0) && Local_u32TimeOut < 10000){ /*wait for HSE be ready			*/
		Local_u32TimeOut++;
	}
	Local_u32TimeOut = 0;

	while((GET_BIT(RCC_CFGR,2)==0) &&(GET_BIT(RCC_CFGR,3)==1) && Local_u32TimeOut < 10000){
		Local_u32TimeOut++;										/*wait for HSE selected as SYS CLK*/
	}
	///////////////////////////////////clock security will be added
	SET_BIT(RCC_CFGR,16);										/*set input of PLL as HSE or HSE/2*/
	CLR_BIT(RCC_CFGR,17);										/*set input of PLL as HSE 		  */

#elif	PLL_INPUT  == RCC_HSE/2
#if	  RCC_HSE_SOURCE == RCC_CRYSTAL
	CLR_BIT(RCC_CR,18);											/*set input of HSE as Crystal	*/
#elif RCC_HSE_SOURCE == RCC_RC
	SET_BIT(RCC_CR,18);											/*set input of HSE as RC		*/
#endif

	SET_BIT(RCC_CR,16);											/*HSE Enable				    */

	while((GET_BIT(RCC_CR,17)==0) && Local_u32TimeOut < 10000){ /*wait for HSE be ready			*/
		Local_u32TimeOut++;
	}
	Local_u32TimeOut = 0;

	while((GET_BIT(RCC_CFGR,2)==0) &&(GET_BIT(RCC_CFGR,3)==1) && Local_u32TimeOut < 10000){
		Local_u32TimeOut++;										/*wait for HSE selected as SYS CLK*/
	}
	///////////////////////////////////clock security will be added
	SET_BIT(RCC_CFGR,16);										/*set input of PLL as HSE or HSE/2*/
	SET_BIT(RCC_CFGR,17);										/*set input of PLL as HSE 		  */


#endif


#if 	PLL_MUL_FACTOR == 1
#elif	PLL_MUL_FACTOR == 2		RCC_CFGR |=(0x0<<18);
#elif	PLL_MUL_FACTOR == 3		RCC_CFGR |=(0x1<<18);
#elif	PLL_MUL_FACTOR == 4		RCC_CFGR |=(0x2<<18);
#elif	PLL_MUL_FACTOR == 5		RCC_CFGR |=(0x3<<18);
#elif	PLL_MUL_FACTOR == 6		RCC_CFGR |=(0x4<<18);
#elif	PLL_MUL_FACTOR == 7		RCC_CFGR |=(0x5<<18);
#elif	PLL_MUL_FACTOR == 8		RCC_CFGR |=(0x6<<18);
#elif	PLL_MUL_FACTOR == 9		RCC_CFGR |=(0x7<<18);
#elif	PLL_MUL_FACTOR == 10	RCC_CFGR |=(0x8<<18);
#elif	PLL_MUL_FACTOR == 11	RCC_CFGR |=(0x9<<18);
#elif	PLL_MUL_FACTOR == 12	RCC_CFGR |=(0xA<<18);
#elif	PLL_MUL_FACTOR == 13	RCC_CFGR |=(0xB<<18);
#elif	PLL_MUL_FACTOR == 14	RCC_CFGR |=(0xC<<18);
#elif	PLL_MUL_FACTOR == 15	RCC_CFGR |=(0xD<<18);
#elif	PLL_MUL_FACTOR == 16	RCC_CFGR |=(0xE<<18);
	//#else 	#error "Value PLL_MUL_FACTOR is not exist "
#endif


	SET_BIT(RCC_CR,24);											/*PLL Enable				    */
	Local_u32TimeOut = 0;
	while((GET_BIT(RCC_CR,25)==0) && Local_u32TimeOut < 10000){ /*wait for PLL be ready			*/
		Local_u32TimeOut++;
	}

	CLR_BIT(RCC_CFGR,0);										/*Set System clock as PLL		*/
	SET_BIT(RCC_CFGR,1);

#endif


}
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PreipheralID)
{
	/***************Range Check*************************/
	if(Copy_u8PreipheralID >=0 && Copy_u8PreipheralID <32)
	{
		switch (Copy_u8BusID) {
		case RCC_AHB:
			SET_BIT(RCC_AHBENR,Copy_u8PreipheralID);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR,Copy_u8PreipheralID);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR,Copy_u8PreipheralID);
			break;
		default:
			break;
		}
	}
	else
	{
		/* Retern Error */
	}

}
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PreipheralID)
{
	/***************Range Check*************************/
	if(Copy_u8PreipheralID >=0 && Copy_u8PreipheralID <32)
	{
		switch (Copy_u8BusID) {
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR,Copy_u8PreipheralID);
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR,Copy_u8PreipheralID);
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR,Copy_u8PreipheralID);
			break;
		default:
			break;
		}
	}
	else
	{
		/* Retern Error */
	}
}





