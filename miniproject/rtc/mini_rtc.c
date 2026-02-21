#include<LPC21xx.h>
#include"rtc.h"
#include"types.h"
#include"lcd.h"
#include"rtc_defines.h"

// Array to hold names of days of the week

s8 week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};


/*

Initialize the Real-Time Clock (RTC)

This function disables the RTC, sets the prescaler values, 

and then enables the RTC.

*/

void RTC_Init(void) 

{

  // Disable and reset the RTC

	CCR = RTC_RESET;

  

#ifndef CPU_LPC2148

  // Set prescaler integer and fractional parts

	PREINT = PREINT_VAL;

	PREFRAC= PREFRAC_VAL;

  

  // Enable the RTC

	CCR = RTC_ENABLE;  

 

#else

  // Enable the RTC & select the clock source

	CCR = RTC_ENABLE | RTC_CLKSRC; 

	

#endif


}

/*

Get the current RTC time

hour Pointer to store the current hour

minute Pointer to store the current minute

second Pointer to store the current second

*/

void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second)

{

	*hour = HOUR;

	*minute = MIN;

	*second = SEC;

}
/*

Get the current RTC date

day Pointer to store the current date (1 31)

month Pointer to store the current month (1 12)

year Pointer to store the current year (four digits)

*/

void GetRTCDateInfo(s32 *date, s32 *month, s32 *year)

{

	*date = DOM;

	*month = MONTH;

	*year = YEAR;

}

/*

Get the current day of the week

dow Pointer to store Day of Week (0=Sunday, ..., 6=Saturday)

*/

void GetRTCDay(s32 *day)

{

	*day = DOW; 

}


/*

Display the RTC time on LCD

hour value (0 23)

minute value (0 59)

second value (0 59) seperated by ':'

*/

void DisplayRTCTime(u32 hour, u32 minute, u32 second)

{

		cmdLCD(0x80);//set the coursor to the beginning of firstline

		charLCD((hour/10)+48);

		charLCD((hour%10)+48);

		charLCD(':');

		charLCD((minute/10)+48);

		charLCD((minute%10)+48);

		charLCD(':');

		charLCD((second/10)+48);

		charLCD((second%10)+48);


}


/*

Display the RTC date on LCD

Day of month (1 31)

Month (1 12)

Year (four digits) and seperated by '/'

*/

void DisplayRTCDate(u32 date, u32 month, u32 year)		 

{

		cmdLCD(0xc0);//set the coursor to the secondline

		charLCD((date/10)+48);

		charLCD((date%10)+48);

		charLCD('/');

		charLCD((month/10)+48);

		charLCD((month%10)+48);

		charLCD('/');

		intLCD(year);

}


/*

Display the current day of the week on LCD

dow (Day of Week) (0=Sunday, ..., 6=Saturday)

*/

void DisplayRTCDay(u32 dow)

{

	cmdLCD(0x8A);//firstline 11th char position

	strLCD(week[dow]); 

}


/*

Set the RTC time

Hour to set (0 23)

Minute to set (0 59)

Second to set (0 59)

*/

void SetRTCTimeInfo(u32 hour, u32 minute, u32 second)

{

	HOUR = hour;

	MIN = minute;

	SEC = second;

}


/*

Set the day of the week in RTC

Day of Week to set (0=Sunday, ..., 6=Saturday)

*/

void SetRTCDay(u32 day)

{

	DOW = day;

}

/*

Set the RTC date

day of month to set (1 31)

month to set (1 12)

year to set (four digits)

*/

void SetRTCDateInfo(u32 date, u32 month, u32 year)

{

	DOM = date;

	MONTH = month;

	YEAR = year;	

}

