/*
 * RTC.c
 *
 *  Created on: Apr 20, 2018
 *      Author: leenovoz510
 */


#include <avr/io.h>
#include <avr/delay.h>
#include "I2C.h"


 void RTC_Init(void){
        I2C_Init();                 // Initialize the I2c module.
        I2C_Start();                // Start I2C communication

        I2C_SendData(0xD0);         // Address location of RTC
        I2C_SendData(0x07);        // Set Pointer Register to control register
        I2C_SendData(0x00);        // disable the RTC clock

        I2C_End();                // Stop I2C communication after initializing DS1307
 }

 void RTC_GetDateTime(unsigned char *h,unsigned char *m,unsigned char *s ,unsigned char *y,unsigned char *mo,unsigned char *d){
	 I2C_Start();              // Start I2C communication
	 I2C_SendData(0XD0);       // connect to DS1307 by sending its ID on I2c Bus
	 I2C_SendData(0X00);       // Request Sec RAM address at 00H
	 I2C_End();                // Stop I2C communication after selecting Sec Register

	 I2C_Start();              // Start I2C communication
	 I2C_SendData(0XD1);       // connect to DS1307(Read mode) by sending its ID
	 *s    = I2C_ReadData_With_AK();
	 *m    = I2C_ReadData_With_AK();
	 *h    = I2C_ReadData_With_AK();
	 *d    = I2C_ReadData_With_AK();
	 *mo    = I2C_ReadData_With_AK();
	 *y    = I2C_ReadData_With_NonAK();
	 I2C_End();

 }
