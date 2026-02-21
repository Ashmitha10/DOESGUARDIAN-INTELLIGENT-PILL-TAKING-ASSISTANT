/*Include LPC21xx register definitions*/
#include<LPC21xx.h>

/*Include datatype definitions*/
#include"types.h"

/*Include medicine definitions*/
#include"medicine.h"

/*Include LCD pin definitions*/
#include"lcd.h"

/*Include delay definitions*/
#include"delay.h"

/*----variables to store medicine ON and OFF timings----*/
u8 med_on_hour;//Hour at which medicine reminder turns ON

u8 med_on_min;//Minute at which medicine reminder turns ON

u8 med_off_hour;//Hour at which medicine reminder turn OFF

u8 med_off_min;//Minute at which medicine reminder turn OFF

u8 med_hour;//current hour used internally

u8 med_min;//current minutes used internally

u8 med_enable;//flag to enable or disable medicine reminder(0=disable,1=enable)

/*----Intialize Medicine Timings---*/

/*Functions to initialize medicine-related variables*/
void medicine_init(void){

med_hour=0;//set current hour to 0

med_min=0;//set current minute to 0

med_enable=0;//disable medicine remainder initially
}

/*----MEdicine set ON OFF time----*/
void Medicine_SetOnOffTime(u32 on_h,u32 on_m,u32 off_h,u32 off_m){

med_on_hour=on_h;//store ON hour

med_on_min=on_m;//store ON minute

med_off_hour=off_h;//store OFF hour

med_off_min=off_m;//store OFF minute

delay_s(2);//wait for 2 seconds 
}

/*------MEDICINE CHECK----*/

/*----check if medicine remainder should trigger----*/
u8 Medicine_Check(void){

/*variables to store current time from RTC(hour,minutes,seconds)*/
s32 cur_h,cur_m,cur_s;

/*Read current  time from RTC */
GetRTCTimeInfo(&cur_h,&cur_m,&cur_s);

/*check if medicine reminder is enabled*/
if(med_enable)
{

/*check if current time matches ON time*/
if((cur_h==med_on_hour)&&(cur_m==med_on_min)){

return 1;//Trigger medicine reminder
}
}
return 0;//No reminder at this time
}