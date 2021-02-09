/*
 * UTILS.h
 *
 * Created: 12/1/2020 1:18:48 AM
 *  Author: Eslam Attef
 */ 


#ifndef UTILS_H_
#define UTILS_H_
/*************************COMMAND********************/
#define SET_BIT(Reg,Bit)  (Reg|=(1<<Bit))
#define CLR_BIT(Reg,Bit)  (Reg&=~(1<<Bit))
#define TOG_BIT(Reg,Bit) (Reg^=(1<<Bit))
#define GET_BIT(Reg,Bit)    ((Reg>>Bit)&1)
//#define WRITE_BIT(Reg,Bit,data) ()




#endif /* UTILS_H_ */
