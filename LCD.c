/*
 * LCD.C
 *
 *  Created on: Apr 7, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"

void LCD_Init(){
	DDRB = 0xFF; // LCD OUTPUT
	DDRD |= ( (1<<En) | (1<<RS) | (1<<RW) ) ; // Enable , RS , R/W
	LCD_SendCommand(0x38); //8-bit mode
	LCD_SendCommand(0x0C); // Display On
	LCD_SendCommand(0x06); //cursor right
	LCD_SendCommand(0x80); // 1st Line
}
void LCD_SendCommand(char command){
	PORTB = command;

	PORTD &= ~(1<<RS); //
	PORTD &= ~(1<<RW);

	PORTD |= (1<<En);
	_delay_ms(1);
    PORTD &= ~(1<<En);
}
void LCD_SendData(unsigned char Data){
	PORTB = Data;

	PORTD &= ~(1<<RW);
	PORTD |=  (1<<RS);

	PORTD |= (1<<En);
	_delay_ms(1);
	PORTD &= ~(1<<En);
}
void LCD_Clear(){
	LCD_SendCommand(0x01);
	_delay_ms(1);
}

void LCD_Print(char *data){
	int i = 0;
	while(data[i] != '\0'){
		LCD_SendData(data[i]);
		i++;
	}
}
void Go_to(char x ,char y){
	char firstAddress[] = {0x80,0xC0,0x94,0xD4};
	LCD_SendCommand(firstAddress[y-1] + x-1);
		_delay_ms(1);
}
void LCD_IntegerToStringPrint(int num){
	char buff[16]; /* String to hold the ascii result */
	itoa(num,buff,10); /* 10 for decimal */
	LCD_Print(buff);
}

void lcd_send (unsigned char BCD_data)
{
    unsigned char x,y;
	x= BCD_data & 0x0F;
	LCD_SendData(x|0x30);
	y= BCD_data & 0xF0;
	y= y>>4;
	LCD_SendData(y|0x30);
}
			/* **********End LCD Configurations********** */
