/*
 * RTC.h
 *
 *  Created on: Apr 20, 2018
 *      Author: leenovoz510
 */

#ifndef RTC_H_
#define RTC_H_


void RTC_Init(void);
void RTC_GetDateTime(unsigned char *h,unsigned char *m,unsigned char *s ,unsigned char *y,unsigned char *mo,unsigned char *d);
#endif /* RTC_H_ */
