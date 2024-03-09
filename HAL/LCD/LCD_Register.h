/*
 * LCD_Register.h
 *
 * Created: 3/8/2024 3:59:18 PM
 *  Author: eqw18
 */ 


#ifndef LCD_REGISTER_H_
#define LCD_REGISTER_H_



#define EN_PIN				DIO_PIN2
#define RS_PIN				DIO_PIN3


#define LCD_DATA_PORT       DIO_PORTB
#define LCD_CONTROL_PORT    DIO_PORTA


	
#define D4            DIO_PIN0
#define D5            DIO_PIN1
#define D6            DIO_PIN2
#define D7            DIO_PIN4


#define CLEAR 0x01
#define CURSOR_OFF_DISPLAN_ON 0x0C
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define _4_BITS 0x28



#endif /* LCD_REGISTER_H_ */