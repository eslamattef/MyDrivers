/*
 * GPIO_interface.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Eslam Attef
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

typedef enum{

/*				INPUT Options					*/
		GPIO_INPUT_ANALOG		=0b0000  ,
		GPIO_INPUT_FLOATING		=0b0100  ,
		GPIO_INPUT_PULL_UP_DOWN	=0b1000  ,

/*				OUTPUT 2 MHz Options			*/
		GPIO_OUTPUT_2MHZ_PP		= 0b0010  ,
		GPIO_OUTPUT_2MHZ_OD		= 0b0110  ,
		GPIO_OUTPUT_2MHZ_AF_PP	= 0b1010  ,
		GPIO_OUTPUT_2MHZ_AF_OD	= 0b1110  ,

/*				OUTPUT 10 MHz Options			*/
		GPIO_OUTPUT_10MHZ_PP	=  0b0001 ,
		GPIO_OUTPUT_10MHZ_OD	=  0b0101 ,
		GPIO_OUTPUT_10MHZ_AF_PP	=  0b1001 ,
		GPIO_OUTPUT_10MHZ_AF_OD	=  0b1101 ,

/*				OUTPUT 50 MHz Options			*/
		GPIO_OUTPUT_50MHZ_PP	=  0b0011 ,
		GPIO_OUTPUT_50MHZ_OD	=  0b0111 ,
		GPIO_OUTPUT_50MHZ_AF_PP	=  0b1011 ,
		GPIO_OUTPUT_50MHZ_AF_OD	=  0b1111

}GPIO_u8_PinDirectionType;

typedef enum{

	GPIO_PINA0  ,
	GPIO_PINA1  ,
	GPIO_PINA2  ,
	GPIO_PINA3  ,
	GPIO_PINA4  ,
	GPIO_PINA5  ,
	GPIO_PINA6  ,
	GPIO_PINA7  ,
	GPIO_PINA8  ,
	GPIO_PINA9  ,
	GPIO_PINA10 ,
	GPIO_PINA11 ,
	GPIO_PINA12 ,
	GPIO_PINA13 ,
	GPIO_PINA14 ,
	GPIO_PINA15 ,
	GPIO_PINB0  ,
	GPIO_PINB1  ,
	GPIO_PINB2  ,
	GPIO_PINB3  ,
	GPIO_PINB4  ,
	GPIO_PINB5  ,
	GPIO_PINB6  ,
	GPIO_PINB7  ,
	GPIO_PINB8  ,
	GPIO_PINB9  ,
	GPIO_PINB10 ,
	GPIO_PINB11 ,
	GPIO_PINB12 ,
	GPIO_PINB13 ,
	GPIO_PINB14 ,
	GPIO_PINB15 ,
	GPIO_PINC0  ,
	GPIO_PINC1  ,
	GPIO_PINC2  ,

	GPIO_TOTAL_PINS


}GPIO_u8_PinType;

typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_TOTAL_PORT

}GPIO_u8_PortType;
typedef enum
{
	GPIO_LOW,
	GPIO_HIGH
}GPIO_u8_VoltageType;

#define LOW_NIPLE    0
#define HIGH_NIPLE   1



/*To init one pin*/
void  GPIO_voidInitPin(GPIO_u8_PinType Copy_PinNumberType,GPIO_u8_PinDirectionType Copy_PinDirectionType );
/*to  init one port */
void  GPIO_voidInitPort( GPIO_u8_PortType Copy_PortType,GPIO_u8_PinDirectionType Copy_PinDirectionType);
/*To  init All pins by using GPIO_Config.c file */
void  GPIO_voidInit(void);
/*	 	if Pin is Output (High or Low)	*/
void  GPIO_voidSetPinValue(GPIO_u8_PinType Copy_PinNumberType,GPIO_u8_VoltageType Copy_VoltageType);
/*	 	SET PORT VALUE												*/
void  GPIO_voidSetPortValue(GPIO_u8_PortType Copy_PortType,u16 Copy_u16PortValue);
/*		SET PORT NIPLE VALUE												*/
void  GPIO_voidSetPortNipleValue(GPIO_u8_PortType Copy_PortType,u8 Copy_u8Niple ,u8 Copy_u8NipleValue);
/*      Toggel Pin Value                                             */
void	GPIO_voidTogglelPinValue(GPIO_u8_PinType Copy_PinNumberType);
/*		if Pin is Input (Return High or Low)	*/
GPIO_u8_VoltageType		GPIO_voltGetPinValue(GPIO_u8_PinType Copy_PinNumberType);

void Delay_ms(u32 Copy_u32Time);


#endif /* GPIO_INTERFACE_H_ */
