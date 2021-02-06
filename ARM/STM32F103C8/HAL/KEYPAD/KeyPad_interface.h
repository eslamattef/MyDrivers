/*
 * KeyPad.h
 *
 * Created: 12/6/2020 11:57:53 PM
 *  Author: Eslam
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "GPIO_interface.h"

//#define KEYPAD_PINR1 PIND0
//#define KEYPAD_PINR2 PIND1
//#define KEYPAD_PINR3 PIND2
//#define KEYPAD_PINR4 PIND3
//#define KEYPAD_PINC1 PIND4
//#define KEYPAD_PINC2 PIND5
//#define KEYPAD_PINC3 PIND6
//#define KEYPAD_PINC4 PIND7

#define FIRST_INPUT  GPIO_PINB0
#define FIRST_OUTPUT GPIO_PINB4

#define NO_KEY  'K'
u8 Keypad_GetKey(void);




#endif /* KEYPAD_INTERFACE_H_ */
