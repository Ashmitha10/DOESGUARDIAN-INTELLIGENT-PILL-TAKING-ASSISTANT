//To prevent multiple inclusions
#ifndef RTC_H
//define RTC_H macro
#define RTC_H
//include custom datatype definitions
#include"types.h"
//structure to store RTC time information
typedef struct{
//stores hour value(0-23)
u8 hour;
//stores minute value(0-59)
u8 min;
//stores seconds(0-59)
u8 sec;
//stores the date(1-31)
u8 day_of_month;
//store the month(1-12)
u8 month;
//stores the year
u8 year;
u8 day_of_week;	/* 0=sun-----6=sat*/
}RTC_TimeDate_t; //defines structure name 

//Intialize RTC 
void RTC_Init(void);
//Reads current RTC time and stores values using pointers
void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second);
//Display time on LCD
void DisplayRTCTime(u32 hour, u32 minute, u32 second);
//setting RTC time 
void SetRTCTimeInfo(u32 hour, u32 minute, u32 second);
//Reads current RTC date and stores values using pointers
void GetRTCDateInfo(s32 *date, s32 *month, s32 *year);
//Display date on LCD
void DisplayRTCDate(u32 date, u32 month, u32 year);
//setting RTC dateinfo
void SetRTCDateInfo(u32 date, u32 month, u32 year);

 //Reads current RTC day and stores values using pointers
void GetRTCDay(s32 *day);
//Display day on LCD
void DisplayRTCDay(u32 dow);
//setting RTC day
void SetRTCDay(u32 day);

//display RTCtime
void DisplayRTCTime(u32 hour, u32 minute, u32 second);
//display RTC date
void DisplayRTCDate(u32 date, u32 month, u32 year);
//display RTC day
void DisplayRTCDay(u32 dow);
//end of the header
#endif
