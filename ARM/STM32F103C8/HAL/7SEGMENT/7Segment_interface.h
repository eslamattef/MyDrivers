/*
 * segment.h
 *
 * Created: 12/1/2020 1:31:28 PM
 *  Author: Eslam
 */ 
#include "GPIO_interface.h"

#ifndef SEGMENT_H_
#define SEGMENT_H_
/***********************Config Segmant Tyep***********/

#define NORMAL    0
#define MULTPX    1

#define ANODE     0
#define CATHOD    1


#define COMMAN  ANODE
#define MODE    MULTPX


/*******************for Normal 7Segment********************/
#define  SEG1_PORT           GPIO_PORTB
#define  SEG1_PORT_NIPLE     LOW_NIPLE

#define  SEG2_PORT           GPIO_PORTB
#define  SEG2_PORT_NIPLE     HIGH_NIPLE
/*******************for Mult 7Segment********************/
#define SEG1_EN              GPIO_PINB0
#define SEG2_EN              GPIO_PINB1
#define SEG_PORT             GPIO_PORTA
#define SEG_PORT_NIPLE       LOW_NIPLE
/*****************************************************/

void SEG_DISPLAY_D(u8 Copy_u87SegCount,u8 Copy_u8Number);



#endif /* SEGMENT_H_ */
