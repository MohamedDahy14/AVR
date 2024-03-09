/*
 * SEVEN_SEG_Interface.h
 *
 * Created: 3/9/2024 12:04:00 AM
 *  Author: eqw18
 */ 
#include "SEVEN_SEG_Reg.h"
#include "..\..\UTILES.LIB\STD_DATA_TYPES.h"

#ifndef SEVEN_SEG_INTERFACE_H_
#define SEVEN_SEG_INTERFACE_H_

void SEVEN_SEG_voidInit();

void seven_segment_write_number(u8 number);


#endif /* SEVEN_SEG_INTERFACE_H_ */