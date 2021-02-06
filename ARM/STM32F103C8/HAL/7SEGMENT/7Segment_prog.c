/*
 * segment.c
 *
 * Created: 12/1/2020 1:31:08 PM
 *  Author: Eslam
 */ 


/*
 * segment.c
 *
 * Created: 12/2/2020 12:21:52 AM
 *  Author: Mr.MaM
 */ 
#include "7Segment_interface.h"

u8  arr_cathod[10]  ={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
u8  arr_anode [10]  ={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};



#if MODE==NORMAL
void SEG_DISPLAY_D(u8 Copy_u87SegCount,u8 Copy_u8Number)
{
#if     COMMAN==CATHOD
	if(Copy_u87SegCount==1)
	{
		GPIO_voidSetPortNipleValue(SEG1_PORT,SEG1_PORT_NIPLE,arr_cathod[Copy_u8Number%10]);
	}
	else if(Copy_u87SegCount==2)
	{
		GPIO_voidSetPortNipleValue(SEG1_PORT,SEG1_PORT_NIPLE,arr_cathod[Copy_u8Number%10]);
		GPIO_voidSetPortNipleValue(SEG2_PORT,SEG2_PORT_NIPLE,arr_cathod[Copy_u8Number/10]);
	}

#elif	COMMAN==ANODE
	if(Copy_u87SegCount==1)
	{
		GPIO_voidSetPortNipleValue(SEG1_PORT,SEG1_PORT_NIPLE,arr_anode[Copy_u8Number%10]);
	}
	else if(Copy_u87SegCount==2)
	{
		GPIO_voidSetPortNipleValue(SEG1_PORT,SEG1_PORT_NIPLE,arr_anode[Copy_u8Number%10]);
		GPIO_voidSetPortNipleValue(SEG2_PORT,SEG2_PORT_NIPLE,arr_anode[Copy_u8Number/10]);
	}

#endif
}

#elif MODE==MULTPX

void SEG_DISPLAY_D(u8 Copy_u87SegCount,u8 Copy_u8Number)
{
#if     COMMAN==CATHOD
	if(Copy_u87SegCount==1)
	{
		GPIO_voidSetPinValue(SEG1_EN,GPIO_HIGH);
		GPIO_voidSetPortNipleValue(SEG_PORT,SEG1_PORT_NIPLE,(arr_cathod[Copy_u8Number%10])<<1);
	}
	else if(Copy_u87SegCount==2)
	{
		GPIO_voidSetPinValue(SEG1_EN,GPIO_HIGH);
		GPIO_voidSetPortNipleValue(SEG_PORT,SEG1_PORT_NIPLE,(arr_cathod[Copy_u8Number%10])<<1);
		GPIO_voidSetPinValue(SEG2_EN,GPIO_LOW);
		Delay_ms(1);
		GPIO_voidSetPinValue(SEG2_EN,GPIO_HIGH);
		GPIO_voidSetPortNipleValue(SEG_PORT,SEG2_PORT_NIPLE,(arr_cathod[Copy_u8Number/10])<<1);
		GPIO_voidSetPinValue(SEG1_EN,GPIO_LOW);
		Delay_ms(1);
	}


#elif	COMMAN==ANODE
	if(Copy_u87SegCount==1)
	{
		GPIO_voidSetPinValue(SEG1_EN,GPIO_HIGH);
		GPIO_voidSetPortNipleValue(SEG_PORT,SEG1_PORT_NIPLE,(arr_anode[Copy_u8Number%10])<<1);
	}
	else if(Copy_u87SegCount==2)
	{
		GPIO_voidSetPinValue(SEG1_EN,GPIO_HIGH);
		GPIO_voidSetPortNipleValue(SEG_PORT,SEG1_PORT_NIPLE,(arr_anode[Copy_u8Number%10])<<1);
		GPIO_voidSetPinValue(SEG2_EN,GPIO_LOW);
		Delay_ms(1);
		GPIO_voidSetPinValue(SEG2_EN,GPIO_HIGH);
		GPIO_voidSetPortNipleValue(SEG_PORT,SEG1_PORT_NIPLE,(arr_anode[Copy_u8Number/10])<<1);
		GPIO_voidSetPinValue(SEG1_EN,GPIO_LOW);
		Delay_ms(1);
	}


#endif

}

#endif
