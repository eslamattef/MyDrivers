/*
 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Eslam Attef
 */



#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



extern const GPIO_u8_PinDirectionType GPIO_PinsDirectionArray[GPIO_TOTAL_PINS];



/*To init one pin*/
void GPIO_voidInitPin(GPIO_u8_PinType Copy_PinNumberType,GPIO_u8_PinDirectionType Copy_PinDirectionType )
{
	GPIO_u8_PinType   Local_PinNumber=Copy_PinNumberType%16; /*To get Number of this Pin in the Port*/
	GPIO_u8_PortType  Local_PortNumber=Copy_PinNumberType/16; /*To get Number of Port*/


	/*Range Check*/
	if(Copy_PinNumberType < GPIO_TOTAL_PINS)
	{
		switch (Local_PortNumber) {
		case GPIO_PORTA:
			/*To Know pin in High or low Register */
			if(Local_PinNumber < 8)
			{
				GPIOA_CRL &= ~((u32)(0b1111)<<(Local_PinNumber * 4));                /* Bit Mask*/
				GPIOA_CRL |=  ((u32)(Copy_PinDirectionType)<<(Local_PinNumber * 4)); /* Bit Set*/
			}
			else
			{
				Local_PinNumber -= 8 ;
				GPIOA_CRH &= ~((u32)(0b1111)<<(Local_PinNumber * 4));                /* Bit Mask*/
				GPIOA_CRH |=  ((u32)(Copy_PinDirectionType)<<(Local_PinNumber * 4)); /* Bit Set*/

			}


			break;

		case GPIO_PORTB:
			if(Local_PinNumber < 8)
			{
				GPIOB_CRL &= ~((u32)(0b1111)<<(Local_PinNumber * 4));
				GPIOB_CRL |=  ((u32)(Copy_PinDirectionType)<<(Local_PinNumber * 4));
			}
			else
			{
				Local_PinNumber -= 8 ;
				GPIOB_CRH &= ~((u32)(0b1111)<<(Local_PinNumber * 4));
				GPIOB_CRH |=  ((u32)(Copy_PinDirectionType)<<(Local_PinNumber * 4));

			}

			break;

		case GPIO_PORTC:
			if(Local_PinNumber < 8)
			{
				GPIOC_CRL &= ~((u32)(0b1111)<<(Local_PinNumber * 4));
				GPIOC_CRL |=  ((u32)(Copy_PinDirectionType)<<(Local_PinNumber * 4));
			}
			else
			{
				Local_PinNumber -= 8 ;
				GPIOC_CRH &= ~((u32)(0b1111)<<(Local_PinNumber * 4));
				GPIOC_CRH |=  ((u32)(Copy_PinDirectionType)<<(Local_PinNumber * 4));

			}


			break;

		default:
			break;
		}

	}
	else
	{
		/*Return Error*/
	}

}

/*		to init one port 										*/
void	GPIO_voidInitPort(GPIO_u8_PortType Copy_PortType,GPIO_u8_PinDirectionType Copy_PinDirectionType)
{
	/*		Range Check							*/
	if( Copy_PortType < GPIO_TOTAL_PORT )
	{
		switch(Copy_PortType)
		{
		case GPIO_PORTA:

			/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/

			GPIOA_CRL &= 0;     /*Clear LOW PORT*/
			GPIOA_CRH &= 0;     /*Clear HIGH PORT*/

			for(u8 i=0;i<8;i++)
			{
				GPIOA_CRL|=((u32)(Copy_PinDirectionType)<<(i * 4));  /* Assign LOW PORT*/
				GPIOA_CRH|=((u32)(Copy_PinDirectionType)<<(i * 4));  /* Assign HIGH PORT*/
			}

			break;
		case GPIO_PORTB:
			/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/

			GPIOB_CRL &= 0;     /*Clear LOW PORT*/
			GPIOB_CRH &= 0;     /*Clear HIGH PORT*/

			for(u8 i=0;i<8;i++)
			{
				GPIOB_CRL|=((u32)(Copy_PinDirectionType)<<(i * 4));  /* Assign LOW PORT*/
				GPIOB_CRH|=((u32)(Copy_PinDirectionType)<<(i * 4));  /* Assign HIGH PORT*/
			}

			break;
		case GPIO_PORTC:
			/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/

			GPIOC_CRL &= 0;     /*Clear LOW PORT*/
			GPIOC_CRH &= 0;     /*Clear HIGH PORT*/

			/*PORTC has 3 Pins Only*/
			for(u8 i=0;i<8;i++)
			{
				GPIOC_CRL|=((u32)(Copy_PinDirectionType)<<(i * 4));  /* Assign LOW PORT*/
				GPIOC_CRH|=((u32)(Copy_PinDirectionType)<<(i * 4));  /* Assign HIGH PORT*/
			}
			break;
		}
	}
	else
	{
		/*	Return ERROR	*/
	}

}

/*To init All pins by using GPIO_Config.c file */
void	GPIO_voidInit(void)
{
	GPIO_u8_PinType i;
	for(i=GPIO_PINA0;i<GPIO_TOTAL_PINS;i++)
	{
		GPIO_voidInitPin(i, GPIO_PinsDirectionArray[i]);

	}

}

/*		if Pin is Output (High or Low)	*/
void	GPIO_voidSetPinValue(GPIO_u8_PinType Copy_PinNumberType,GPIO_u8_VoltageType Copy_VoltageType)
{

	GPIO_u8_PinType   Local_PinNumber=Copy_PinNumberType%16; /*To get Number of this Pin in the Port*/
	GPIO_u8_PortType  Local_PortNumber=Copy_PinNumberType/16; /*To get Number of Port*/
	/*		Range Check							*/
	if( Copy_PinNumberType < GPIO_TOTAL_PINS )
	{
		switch(Local_PortNumber)
		{
		case GPIO_PORTA:
			switch(Copy_VoltageType)
			{
			case GPIO_HIGH   :	GPIOA_BSR=(1<<Local_PinNumber);	break;
			case GPIO_LOW	:	GPIOA_BRR=(1<<Local_PinNumber);	break;
			default:;	/*		Return ERROR		*/
			}

			break;
			case GPIO_PORTB:
				switch(Copy_VoltageType)
				{
				case GPIO_HIGH   :	GPIOB_BSR=(1<<Local_PinNumber);	break;
				case GPIO_LOW	:	GPIOB_BRR=(1<<Local_PinNumber);	break;
				default:;	/*		Return ERROR		*/
				}
				break;
				case GPIO_PORTC:
					switch(Copy_VoltageType)
					{
					case GPIO_HIGH   :	GPIOC_BSR=(1<<Local_PinNumber);	break;
					case GPIO_LOW	:	GPIOC_BRR=(1<<Local_PinNumber);	break;
					default:;	/*		Return ERROR		*/
					}
					break;
		}

	}
	else
	{
		/*	Return ERROR	*/
	}
}
/*		SET PORT VALUE												*/
void	GPIO_voidSetPortValue(GPIO_u8_PortType Copy_PortType,u16 Copy_u16PortValue)
{
	/*		Range Check							*/
	if(Copy_PortType < GPIO_TOTAL_PORT)
	{
		switch(Copy_PortType)
		{
		case GPIO_PORTA:

			GPIOA_ODR &=0;
			GPIOA_ODR  = (u16)Copy_u16PortValue;

		case GPIO_PORTB:

			GPIOB_ODR &=0;
			GPIOB_ODR  = (u16)Copy_u16PortValue;
		case GPIO_PORTC:

			GPIOC_ODR &=0;
			GPIOC_ODR  = (u16)Copy_u16PortValue;
		}
	}
	else
	{
		/*	Return ERROR	*/
	}


}

/*		SET PORT NIPLE VALUE												*/

void	GPIO_voidSetPortNipleValue(GPIO_u8_PortType Copy_PortType,u8 Copy_u8Niple ,u8 Copy_u8NipleValue)
{
	/*		Range Check							*/
	if(Copy_PortType < GPIO_TOTAL_PORT)
	{
		switch(Copy_PortType)
		{
		case GPIO_PORTA:
			if(Copy_u8Niple==LOW_NIPLE)
			{
				GPIOA_ODR &=0xFF00;
				GPIOA_ODR  = (u8)Copy_u8NipleValue;
			}
			else if(Copy_u8Niple==HIGH_NIPLE)
			{
				GPIOA_ODR &=0x00FF;
				GPIOA_ODR  = ((u8)Copy_u8NipleValue<<8);
			}

		case GPIO_PORTB:

			if(Copy_u8Niple==LOW_NIPLE)
			{
				GPIOB_ODR &=0xFF00;
				GPIOB_ODR  = (u8)Copy_u8NipleValue;
			}
			else if(Copy_u8Niple==HIGH_NIPLE)
			{
				GPIOB_ODR &=0x00FF;
				GPIOB_ODR  = ((u8)Copy_u8NipleValue<<8);
			}

		case GPIO_PORTC:

			if(Copy_u8Niple==LOW_NIPLE)
			{
				GPIOC_ODR &=0xFF00;
				GPIOC_ODR  = (u8)Copy_u8NipleValue;
			}
			else if(Copy_u8Niple==HIGH_NIPLE)
			{
				GPIOC_ODR &=0x00FF;
				GPIOC_ODR  = ((u8)Copy_u8NipleValue<<8);
			}

		}
	}
	else
	{
		/*	Return ERROR	*/
	}


}

/*		if Pin is Input (Return High or Low)	*/

GPIO_u8_VoltageType		GPIO_voltGetPinValue(GPIO_u8_PinType Copy_PinNumberType)
{
	GPIO_u8_PinType     Local_PinNumber=Copy_PinNumberType%16;  /*To get Number of this Pin in the Port*/
	GPIO_u8_PortType    Local_PortNumber=Copy_PinNumberType/16; /*To get Number of Port*/
	GPIO_u8_VoltageType Local_Value = GPIO_LOW;

	/*		Range Check							*/
	if( Copy_PinNumberType < GPIO_TOTAL_PINS )
	{

		switch(Local_PortNumber)
		{
		case GPIO_PORTA:	Local_Value = GET_BIT(GPIOA_IDR , Local_PinNumber);	break;
		case GPIO_PORTB:	Local_Value = GET_BIT(GPIOB_IDR , Local_PinNumber);	break;
		case GPIO_PORTC:	Local_Value = GET_BIT(GPIOC_IDR , Local_PinNumber);	break;

		}
	}
	else
	{
		/*	Return ERROR	*/
	}

	return Local_Value;
}

void Delay_ms(u32 Copy_u32Time)
{
	for(u32 i = 0 ; i < Copy_u32Time ; i++)
	{
		for(u16 j = 0 ; j < 565 ; j++)
		{
			asm("NOP");
		}
	}

}


