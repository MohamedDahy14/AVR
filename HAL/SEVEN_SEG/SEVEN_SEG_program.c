/*
 * SEVEN_SEG_program.c
 *
 * Created: 3/9/2024 12:04:32 AM
 *  Author: eqw18
 */ 

#include "../../UTILES.LIB/Bitmath.h"

#include "SEVEN_SEG_Interface.h"

void SEVEN_SEG_voidInit(){
		
		
		DIO_voidSetPinDirection(DATA_PORT,DATA0,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DATA_PORT,DATA1,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DATA_PORT,DATA2,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DATA_PORT,DATA3,DIO_PIN_OUTPUT);
		
		
		DIO_voidSetPinDirection(EN1_PORT,EN1_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(EN2_PORT,EN2_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(EN3_PORT,EN3_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(EN4_PORT,EN4_PIN,DIO_PIN_OUTPUT);

}




void seven_segment_write_number(u8 number) {


	DIO_voidSetPinValue(DATA_PORT, DATA0, (number >> 0)&0x1);
	DIO_voidSetPinValue(DATA_PORT, DATA1, (number >> 1)&0x1);
	DIO_voidSetPinValue(DATA_PORT, DATA2, (number >> 2)&0x1);
	DIO_voidSetPinValue(DATA_PORT, DATA3, (number >> 3)&0x1);
}