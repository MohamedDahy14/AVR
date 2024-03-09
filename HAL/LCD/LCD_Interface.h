/*
 * LCD_Interface.h
 *
 * Created: 3/7/2024 11:00:38 AM
 *  Author: eqw18
 */ 

#include "LCD_Register.h"

#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H

#include "../../UTILES.LIB/Bitmath.h"
#include "../../UTILES.LIB/STD_DATA_TYPES.h"


void LCD_voidInit();
void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);



void LCD_voidWriteString(u8 * copy_str);

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);

void LCD_voidClear(void);
void LCD_voidWriteNumber( u32 Copy_u32num );


void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum );

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ) ;






#endif
