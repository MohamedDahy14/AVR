/*
 * SEVEN_SEG_Reg.h
 *
 * Created: 3/9/2024 12:03:32 AM
 *  Author: eqw18
 */ 
#include "../../MCAL/DIO/DIO.h"

#ifndef SEVEN_SEG_REG_H_
#define SEVEN_SEG_REG_H_


#define DATA_PORT		DIO_PORTB


#define DATA0		DIO_PIN0
#define DATA1		DIO_PIN1
#define DATA2		DIO_PIN2
#define DATA3		DIO_PIN4

#define EN1_PIN			DIO_PIN3
#define EN2_PIN			DIO_PIN2
#define EN3_PIN			DIO_PIN5
#define EN4_PIN			DIO_PIN6

#define EN1_PORT			DIO_PORTA
#define EN2_PORT			DIO_PORTA
#define EN3_PORT			DIO_PORTB
#define EN4_PORT			DIO_PORTB


#endif /* SEVEN_SEG_REG_H_ */