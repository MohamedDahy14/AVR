/*
 * Program.c
 *
 * Created: 3/7/2024 10:59:44 AM
 *  Author: eqw18
 */ 

#define F_CPU 16000000 

#include "../../UTILES.LIB/STD_DATA_TYPES.h"
#include "LCD_interface.h"
#include "LCD_Register.h"
#include "..\..\MCAL\DIO\DIO.h"
#include <util/delay.h>

static void intToString(u32 num, u8* buffer);

void LCD_voidInit()
{
	_delay_ms(200);
	
	DIO_voidSetPinDirection(LCD_DATA_PORT, D7, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, D6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, D5, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, D4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_OUTPUT);
	
	LCD_voidWriteCommand(RETURN_HOME);
	_delay_ms(10);
	LCD_voidWriteCommand(_4_BITS);
	
	_delay_ms(1);
	
	LCD_voidWriteCommand(CURSOR_OFF_DISPLAN_ON);
	
	_delay_ms(1);
	
	LCD_voidWriteCommand(CLEAR);
	
	_delay_ms(10);
	
	LCD_voidWriteCommand(ENTRY_MODE);
	_delay_ms(1);
	
}

void LCD_voidWriteCommand(u8 copy_u8command)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_LOW);
	
	DIO_voidSetPinValue(LCD_DATA_PORT, D7, (copy_u8command >> 7)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D6, (copy_u8command >> 6)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D5, (copy_u8command >> 5)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D4, (copy_u8command >> 4)&0x1);
	
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(LCD_DATA_PORT, D7, (copy_u8command >> 3)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D6, (copy_u8command >> 2)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D5, (copy_u8command >> 1)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D4, (copy_u8command >> 0)&0x1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_LOW);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	
	_delay_ms(1);
}
void LCD_voidWriteData(u8 copy_u8data)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_HIGH);
	
	DIO_voidSetPinValue(LCD_DATA_PORT, D7, (copy_u8data >> 7)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D6, (copy_u8data >> 6)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D5, (copy_u8data >> 5)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D4, (copy_u8data >> 4)&0x1);
	
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(LCD_DATA_PORT, D7, (copy_u8data >> 3)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D6, (copy_u8data >> 2)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D5, (copy_u8data >> 1)&0x1);
	DIO_voidSetPinValue(LCD_DATA_PORT, D4, (copy_u8data >> 0)&0x1);
	
	//DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_LOW);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
	

	_delay_ms(1);	
}
void LCD_voidWriteString(u8 *copy_str)
{
	u8 index = 0;
	
	while(copy_str[index] != '\0'){
		LCD_voidWriteData(copy_str[index]);
		index++;
	}
	
}
void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col)
{
	switch (copy_u8Row)
	{
		case 0:
		/*	Row 0	*/
		LCD_voidWriteCommand(0x80+copy_u8Col);
		break;
		case 1:
		/* Row 1 */
		LCD_voidWriteCommand(0xC0+copy_u8Col);
		break;
		case 2:
		/* Row 1 */
		LCD_voidWriteCommand(0x94+copy_u8Col);
		break;
		
		case 3:
		/* Row 1 */
		LCD_voidWriteCommand(0xD4+copy_u8Col);
		break;
		
	}
}
void LCD_voidClear(void)
{
	LCD_voidWriteCommand(CLEAR);
	_delay_ms(10);
}

void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum )
{
	u8 i=0;
	LCD_voidWriteCommand(0x40 +(copy_u8ByteNum*8));
	for (i =0; i<8;i++)
	{
		LCD_voidWriteData(copy_u8data[i]);
	}
	LCD_voidWriteCommand(0x02);
	
}
void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum )
{
	LCD_voidWriteData(copy_u8ByteNum);
}