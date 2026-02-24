/*definitions for LPC21xx*/
#include<LPC21xx.h>

/*project specific macro definitions*/
#include"mini_defines.h"

/*userdefine datatypes(u8,s32...etc)*/
#include"types.h"

/*menu handling functions*/
#include"menu.h"

/*LCD control functions*/
#include"lcd.h"

/*keypad functions*/
#include"mini_keypad.h"

/*delay functions*/
#include"delay.h"

/*medicine functions*/
#include"medicine.h"

/*RTC functions*/
#include"rtc.h"

/*Buzzer/led/control functions*/
#include"alert.h"

/*switch input functions*/
#include"switches.h"

/*Extern variable to know medicine minute*/
extern u8 med_on_min;

/*entry point of program*/
int main(void){

/*variables to strore RTC time*/
s32 hour,minute,second;

/*variables to store RTC date*/
s32 date,month,year;

/*variable to store day of the week*/
s32 day;

/*variables for acknowledgement handling*/
u32 wait;u8 ack;


/*---Intializations---*/

initLCD();//Initialize the LCD

keypadinit();//Initialize the keypad

RTC_Init();//RTC Initializations

/*set initial RTC time(example:10:29:50)*/
SetRTCTimeInfo(10,29,50);

/*set initial RTC date(example:12/12/2025)*/
SetRTCDateInfo(12,12,2025);

/*set the day of week*/
SetRTCDay(5);//1=monday(example)

/*Initialize medicine data*/
medicine_init();

/*Initialize switches*/
switches_init();

/*Initialize alert(buzzer,LEDs)*/
alert_init();

/*--------MAIN LOOP---------*/
while(1){

/*Read current RTC time*/
GetRTCTimeInfo(&hour,&minute,&second);

/*Read current RTC date*/
GetRTCDateInfo (&date,&month,&year);

/*Read current day*/
GetRTCDay(&day);

/*Display time on LCD*/
DisplayRTCTime(hour,minute,second);

/*Display date on LCD*/
DisplayRTCDate(date,month,year);

/*Display day on LCD*/
DisplayRTCDay(day);

/*--------MENU SWITCH-------*/
if(switch1_pressed()){

/*Enter menu for RTC/medicine setup*/
showmainmenu();

/*clear LCD after exiting menu*/
cmdLCD(0x01);
}

/*----MEDICINE CHECK----*/
if(Medicine_Check()){

/*start buzzer alert*/
alert_start();

/*show remainder on LCD*/
cmdLCD(0x01);
strLCD("Medicine Time");

/*Reset acknowledgement flags*/
ack=0;
wait=0;

/*wait for acknowledgement for limited time*/
while(wait<ACKTIMEOUT){

/*check if user pressed acknowledgement switch*/ 
if(switch2_pressed()){

ack=1;//medicine taken
break;
}
/*wait for 1 second*/
delay_ms(1000);
wait++;
}

/*stop buzzer after waiting*/
alert_stop();

/*----Acknowledgement result----*/
if(ack){

/*medicine taken successfully*/
cmdLCD(0x01);
strLCD("Medicine Taken");

/*Reset acknowledgement flag*/
ack=0;
minute=0;//reset minute to zero

/*small delay for user visibility*/
delay_ms(1000);

cmdLCD(0x01);//clear LCD
}else{

/*Medicine missed*/
alert_missed();//turns ON red LED 
}

/*wait for minute is equal to the medicine minute*/
while(minute==med_on_min);

/*Reset medicine minute after alert*/
med_on_min=0;
}

/*small delay to reduce CPU load*/
delay_ms(300);
}
}



