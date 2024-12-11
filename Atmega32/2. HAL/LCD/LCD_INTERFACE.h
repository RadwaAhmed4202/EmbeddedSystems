/*
 * LCD_INTERFACE.h
 *
 *  Created on: 15 Sep 2023
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit();

void LCD_voidConfiguration();

void LCD_voidSendString(u8 * Copy_pu8String);

void LCD_voidSendNumber(u32 Copy_u32Number);

void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y);

void LCD_voidSendSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8X, u8 Copy_u8Y);


#endif /* LCD_INTERFACE_H_ */
