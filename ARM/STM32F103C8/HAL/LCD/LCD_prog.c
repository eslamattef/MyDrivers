/*
 * LCD.c
 *
 * Created: 12/3/2020 12:12:44 AM
 *  Author: Eslam
 */ 
#include "LCD_interface.h"


#if (LCD_MODE==_8_BIT)

void LCD_WriteData(u8 data)
{
	
	GPIO_voidSetPinValue(RS,HIGH);
	GPIO_voidSetPortValue(LCD_PORT,data);
	GPIO_voidSetPinValue(EN,HIGH);
	Delay_ms(1);
	GPIO_voidSetPinValue(EN,LOW);
	Delay_ms(1);
}

void LCD_WriteCommand(u8 command)
{
	GPIO_voidSetPinValue(RS,LOW);
	GPIO_voidSetPortValue(LCD_PORT,command);
	GPIO_voidSetPinValue(EN,HIGH);
	Delay_ms(1);
	GPIO_voidSetPinValue(EN,LOW);
	Delay_ms(1);
	
}

void LCD_Init(void)
{
	Delay_ms(50);
	LCD_WriteCommand(0x38);//8 bit mode ,font 5*7 , 2 line
	Delay_ms(1);
	LCD_WriteCommand(0x0c);//0x0f ,0x0e display ,cursor
	Delay_ms(1);
	LCD_WriteCommand(0x01);//Clear screen
	Delay_ms(2);
	LCD_WriteCommand(0x06);//increas ddram address no 
	Delay_ms(2);
	
}
#elif (LCD_MODE==_4_BIT)
void LCD_WriteData(u8 data)
{
	
	GPIO_voidSetPinValue(RS,GPIO_HIGH);
	GPIO_voidSetPinValue(D7,GET_BIT(data,7));
	GPIO_voidSetPinValue(D6,GET_BIT(data,6));
	GPIO_voidSetPinValue(D5,GET_BIT(data,5));
	GPIO_voidSetPinValue(D4,GET_BIT(data,4));
	GPIO_voidSetPinValue(EN,GPIO_HIGH);
	Delay_ms(1);
	GPIO_voidSetPinValue(EN,GPIO_LOW);
	Delay_ms(1);
	GPIO_voidSetPinValue(D7,GET_BIT(data,3));
	GPIO_voidSetPinValue(D6,GET_BIT(data,2));
	GPIO_voidSetPinValue(D5,GET_BIT(data,1));
	GPIO_voidSetPinValue(D4,GET_BIT(data,0));
	GPIO_voidSetPinValue(EN,GPIO_HIGH);
	Delay_ms(1);
	GPIO_voidSetPinValue(EN,GPIO_LOW);
	Delay_ms(1);
}

void LCD_WriteCommand(u8 data)
{
	GPIO_voidSetPinValue(RS,GPIO_LOW);
	GPIO_voidSetPinValue(D7,GET_BIT(data,7));
	GPIO_voidSetPinValue(D6,GET_BIT(data,6));
	GPIO_voidSetPinValue(D5,GET_BIT(data,5));
	GPIO_voidSetPinValue(D4,GET_BIT(data,4));
	GPIO_voidSetPinValue(EN,GPIO_HIGH);
	Delay_ms(1);
	GPIO_voidSetPinValue(EN,GPIO_LOW);
	Delay_ms(1);
	GPIO_voidSetPinValue(D7,GET_BIT(data,3));
	GPIO_voidSetPinValue(D6,GET_BIT(data,2));
	GPIO_voidSetPinValue(D5,GET_BIT(data,1));
	GPIO_voidSetPinValue(D4,GET_BIT(data,0));
	GPIO_voidSetPinValue(EN,GPIO_HIGH);
	Delay_ms(1);
	GPIO_voidSetPinValue(EN,GPIO_LOW);
	Delay_ms(1);
	
}
void LCD_Init(void)
{
	Delay_ms(50);
	LCD_WriteCommand(0x02);
	Delay_ms(50);
	LCD_WriteCommand(0x28);//8 bit mode ,font 5*7 , 2 line
	Delay_ms(1);
	LCD_WriteCommand(0x0c);//0x0f ,0x0e display ,cursor
	Delay_ms(1);
	LCD_WriteCommand(0x01);//Clear screen
	Delay_ms(2);
	LCD_WriteCommand(0x06);//increas ddram address no
	Delay_ms(2);
	
}
#endif
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_WriteString(u8* str)
{
	u8 i=0;
	while(str[i]!=0)
	{
		
		LCD_WriteChar(str[i]);
		
		i++;
		
	}
	
}
void LCD_WriteNumber(s64 num)
{
	u8 ch[16]={0};
	u8 i=0;
	u8 j=0;	
	if(num==0)
	{
		LCD_WriteChar('0');
	}
	else if(num>0)
	{
		while(num!=0)
		{
			ch[i]=num%10;
			num=num/10;
			i++;
		}
		for(j=i-1;j>=0;j--)
		{
			
			LCD_WriteChar(ch[j]+'0');
			if(j==0) break;
		}
		
		
	}
	else if(num<0)
	{
		LCD_WriteChar('-');
		num=num*(-1);
			while(num!=0)
			{
				ch[i]=num%10;
				num=num/10;
				i++;
			}
			for(j=i-1;j>=0;j--)
			{
				
				LCD_WriteChar(ch[j]+'0');
				if(j==0) break;
			}
		
	}
		
	

}

void LCD_WriteNumberBinary(u16 num)
{
	s8 i,flag=0;
	for (i=15;i>=0;i--)
	{
		if (GET_BIT(num,i))
		{
			LCD_WriteData('1');
			flag=1;
		}
		else if(flag==1)
		{
			LCD_WriteData('0');
		}
	}
}

void LCD_WriteNumberBinary_16D(u16 num)
{
	s8 i;
	for (i=15;i>=0;i--)
	{
		if (GET_BIT(num,i))
		{
			LCD_WriteData('1');
		}
		else
		{
			LCD_WriteData('0');
		}
	}
}
void LCD_WriteNumberBinary_8D(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		if (GET_BIT(num,i))
		{
			LCD_WriteData('1');
		}
		else
		{
			LCD_WriteData('0');
		}
	}
}

void LCD_WriteNumberHex(u8 num)//11110001
{
	u8 hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','E','F'};
	u8 high=num>>4;
	u8 low=num&0x0f;
	LCD_WriteData(hex[high]);
	LCD_WriteData(hex[low]);
}

void LCD_WriteNumber_4D(u64 num)
{

		//LCD_WriteData((num/1000)+'0');
		//num=num%1000;
		LCD_WriteData((num/100)+'0');
		num=num%100;
		LCD_WriteData((num/10)+'0');
		num=num%10;
		LCD_WriteData((num/1)+'0');
	
	
}
void LCD_SetCursor(u8 row,u8 colm)
{
	if(row==0)
	{
		LCD_WriteCommand(0x80+colm);
		
	}
	else if(row==1)
	{
		
		LCD_WriteCommand(0x40+0x80+colm);
	}
}
void LCD_Clear(void)
{
	
	LCD_WriteCommand(0x01);
}
/*void LCD_PrintCharWithAsk(void)
{
		for(u8 i='A';i<='Z';i++)
		{
			LCD_SetCursor(0,0);
			LCD_WriteString("CHAR:");
			LCD_WriteChar(i);
			LCD_SetCursor(1,0);
			LCD_WriteString("ASK:");
			LCD_WriteNumber(i);
			Delay_ms(500);
	
		}
}
void LCD_PrintCharWithAskRevarce(void)
{
	
	for(u8 i='Z';i<='A';i--)
	{
		LCD_SetCursor(0,0);
		LCD_WriteString("CHAR:");
		LCD_WriteChar(i);
		LCD_SetCursor(1,0);
		LCD_WriteString("ASK:");
		LCD_WriteNumber(i);
		Delay_ms(500);
	}
}*/
int string_lens(u8*str)
{
	u8 i;
	for(i=0; str[i]; i++);
	return i;
}
void LCD_DisStrPattern1(u8 *str)
{
	 s8 i;
	while (1)
	{
		for(i=string_lens(str);i>=0;i--)
		{
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString(str+i);
			Delay_ms(CURSER_SPEED);
		}
		for(u8 i=1;i<16;i++)
		{
			LCD_Clear();
			LCD_SetCursor(0,i);
			LCD_WriteString(str);
			Delay_ms(CURSER_SPEED);
		}
		for(i=string_lens(str);i>=0;i--)
		{
			LCD_Clear();
			LCD_SetCursor(1,0);
			LCD_WriteString(str+i);
			Delay_ms(CURSER_SPEED);
		}
		for(u8 i=1;i<16;i++)
		{
			LCD_Clear();
			LCD_SetCursor(1,i);
			LCD_WriteString(str);
			Delay_ms(CURSER_SPEED);
		}
		
	}
}
void LCD_CustomChar(u8 loc,u8 *msg)
{
	u8 i;
	if(loc<8)
	{
		LCD_WriteCommand(0x40 + (loc*8));	    /* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	                   /* Write 8 byte for generation of 1 character */
		LCD_WriteData(msg[i]);
		LCD_WriteCommand(0x80);
	}
}

/*************************************/
