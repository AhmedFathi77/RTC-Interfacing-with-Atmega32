/*
 * I2C.h
 *
 *  Created on: Apr 19, 2018
 *      Author: leenovoz510
 */

#ifndef I2C_H_
#define I2C_H_


#include "std_types.h"

void I2C_Init();
void I2C_Start();
void I2C_End();
void I2C_SendData(unsigned char Data);
unsigned char I2C_ReadData_With_AK();
unsigned char I2C_ReadData_With_NonAK();
unsigned char TWI_Get_Status(void);
unsigned char I2C_Read(unsigned char Ack);
void I2C_Slave_init(unsigned char Address);

#define C_Ds1307ReadMode_U8   0xD1u  // DS1307 ID
#define C_Ds1307WriteMode_U8  0xD0u  // DS1307 ID

#define C_Ds1307SecondRegAddress_U8   0x00u   // Address to access Ds1307 SEC register
#define C_Ds1307DateRegAddress_U8     0x04u   // Address to access Ds1307 DATE register
#define C_Ds1307ControlRegAddress_U8  0x07u   // Address to access Ds1307 CONTROL register

#endif /* I2C_H_ */
















