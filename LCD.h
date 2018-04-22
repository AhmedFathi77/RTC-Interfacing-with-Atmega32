/*
 * LCD.h
 *
 *  Created on: Apr 7, 2018
 *      Author: leenovoz510
 */


#ifndef LCD_H_
#define LCD_H_


#define En PD5
#define RS PD7
#define RW PD6

void LCD_SendCommand(char command);
void LCD_SendData(unsigned char Data);
void LCD_Clear();
void LCD_Init();
void LCD_Print(char *data);
void Go_to(char x ,char y);
void LCD_IntegerToStringPrint(int num);
void lcd_send (unsigned char BCD_data);
#endif /* LCD_H_ */

