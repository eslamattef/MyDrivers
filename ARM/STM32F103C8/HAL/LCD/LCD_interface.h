/*
 * LCD.h
 *
 * Created: 12/3/2020 12:12:58 AM
 *  Author: Eslam
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"


#define  RS    GPIO_PINA4
#define  EN    GPIO_PINA5

#define LCD_PORT GPIO_PORTA
#define CURSER_SPEED 200

#define _4_BIT 0
#define _8_BIT 1
#define LCD_MODE _4_BIT

#define D4 GPIO_PINA0
#define D5 GPIO_PINA1
#define D6 GPIO_PINA2
#define D7 GPIO_PINA3

void LCD_Init(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*str);
void LCD_WriteNumber(s64 num);
void LCD_WriteNumberBinary(u16 num);
void LCD_WriteNumberBinary_16D(u16 num);
void LCD_WriteNumberBinary_8D(u8 num);
void LCD_WriteNumberHex(u8 num);
void LCD_WriteNumber_4D(u64 num);
void LCD_SetCursor(u8 row,u8 colm);
void LCD_Clear(void);
void LCD_PrintCharWithAsk(void);
void LCD_PrintCharWithAskRevarce(void);
void LCD_DisStrPattern1(u8 *str);
void LCD_CustomChar(unsigned char loc, unsigned char *msg);

#endif /* LCD_INTERFACE_H_ */
