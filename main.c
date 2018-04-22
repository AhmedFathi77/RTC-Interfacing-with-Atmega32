/*
 * main.c
 *
 *  Created on: Apr 20, 2018
 *      Author: leenovoz510
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"
#include "I2C.h"
#include "RTC.h"
#include <stdio.h>

int main(void){

unsigned char Second,Minute,Houre;
unsigned char Year,Month,Day;
//unsigned char Day,Month,Year;

RTC_Init();
//I2C_Init();
LCD_Init();
_delay_ms(10);
LCD_Clear();
Go_to(1,1);
LCD_Print("Time : ");
//Go_to(1,2);
//LCD_Print("Date : ");
int Sec ;
	while(1){
		RTC_GetDateTime(&Houre,&Minute,&Second,&Year,&Month,&Day);
		Sec = atoi(Year);
		Go_to(8,1);
		LCD_IntegerToStringPrint(Sec);
	}
	return 0;
}
