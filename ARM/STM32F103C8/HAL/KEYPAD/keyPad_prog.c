/*
 * keyPad.c
 *
 * Created: 12/6/2020 11:57:39 PM
 *  Author: Eslam
 */
#include "KeyPad_interface.h"

static const u8 keys[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}}; 
	
	
	
	
u8 Keypad_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	
	GPIO_voidSetPinValue(FIRST_OUTPUT,GPIO_HIGH);
	GPIO_voidSetPinValue(FIRST_OUTPUT+1,GPIO_HIGH);
	GPIO_voidSetPinValue(FIRST_OUTPUT+2,GPIO_HIGH);
	GPIO_voidSetPinValue(FIRST_OUTPUT+3,GPIO_HIGH);
	for(r=0;r<4;r++)
	{
		GPIO_voidSetPinValue(FIRST_OUTPUT+r,GPIO_LOW);
		for(c=0;c<4;c++)
		{
			if(!GPIO_voltGetPinValue(FIRST_INPUT+c))
			{
				key=keys[r][c];
				while(!GPIO_voltGetPinValue(FIRST_INPUT+c));
			}
			
		}
		GPIO_voidSetPinValue(FIRST_OUTPUT+r,GPIO_HIGH);
	}
	return key;

}
