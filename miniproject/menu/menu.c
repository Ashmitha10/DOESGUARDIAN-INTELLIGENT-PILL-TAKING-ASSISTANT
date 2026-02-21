/*Include menu related functions and its declarations*/
#include"menu.h"

/*Include LCD functions and it declarations*/
#include"lcd.h"

/*Include kepad input functions*/
#include"mini_keypad.h"

/*Include medicine related functions and it declarations*/
#include"medicine.h"

/*Include RTC functions and it declarations*/
#include"rtc.h"

/*Include delay definitions*/
#include"delay.h"

/*Include datatype definitions*/
#include"types.h"


/*-------Read 2digits safely stops when D key is pressed----*/
static int read2Digit(void){

char a;//Variable to store key pressed

int n=0;//variable to store the 2-digit Number

cmdLCD(0xc0);//Move LCD cursor to the second line

while(1)//Infinetely loop until exit key is pressed
{

a=readkeyval();//Read key value from keypad

delay_ms(100);//small delay for key debounce

if(a>='0' && a<='9')//check if key is a digit
{

n=(n*10)+(a-'0');//Append digit to a Number

charLCD(a);//Display enter digit on LCD

while(colstat()==0);//wait until the key is pressed

}else if(a=='D'){//if D key is pressed

break;//exit input loop

}else if(a=='*'){//if * key is pressed

if(n>0){//check if number exists

n=n/10;//remove the last digit

cmdLCD(0x10);//moves cursor left

charLCD(' ');//clear the character

cmdLCD(0x10);//move the cursor left again
}
}

}

return n;//returned the enter number

}


/*-----EDIT RTC MENU------*/

static void EditRTCMenu(void){

char key;//variable to store keypad input

s32 h,m,s,d,mo,y,day;//variables to store hour,minute,second,month,year,day,day of the week

while(1){//loop until exist option is chosen

cmdLCD(0x01);//clear LCD

strLCD("1.H 2.M 3.S 4.Day");//Display the options on LCD

cmdLCD(0xc0);//Move the cursor to the second line

strLCD("5.d 6.M 7.Y 8.E");//Display remaining options on LCD

key=readkeyval();//Read keypad input

delay_ms(100);//Delay for debounce

GetRTCTimeInfo(&h,&m,&s);//Get current RTC time

GetRTCDateInfo(&d,&mo,&y);//Get current RTC date

GetRTCDay(&day);//Get RTC day

/*----check selected option----*/
switch(key)
{

case '1':/*HOUR*/

cmdLCD(0x01);//clear LCD

strLCD("set hour(00-23):");//display the string on LCD

h=read2Digit();//Read hour

if(h<=23)//if hour is lessthan equal to 23 or not is checked

SetRTCTimeInfo(h,m,s);//Update RTC hour

break;

case '2':/*minute*/

cmdLCD(0x01);//clear LCD

strLCD("set min(00-59):");//display string on LCD

m=read2Digit();// Read minute

if(m<=59)//if minute is lessthan equal to 59 or not checked

SetRTCTimeInfo(h,m,s);//Update RTC minute

break;

case '3':/*seconds*/

cmdLCD(0x01);//clear LCD

strLCD("set seconds(00-59):");//display string on LCD

s=read2Digit();//Read seconds

if(s<=59)//if seconds is lessthan equal to 59 or not checked

SetRTCTimeInfo(h,m,s);//Update RTC seconds

break;

case '4':/*Day*/

cmdLCD(0x01);//clear LCD

strLCD("set Day(0.SUN..6):");//Display string on LCD

day=read2Digit();//Read day

if(day<=6)//if day is lessthan equal to 6 or not checked

SetRTCDay(day);//Update RTC day

break;

case '5':/*Date*/

cmdLCD(0x01);//clear LCD

strLCD("Date(01-31):");//Display string on LCD

d=read2Digit();//Read the day

if(d>=1 && d<=31)//if the date of month is greater than equlto 1 and date is lessthan equalto 31 is checked

SetRTCDateInfo(d,mo,y);//Update the date

break;

case '6':/*Month*/

cmdLCD(0x01);//clear LCD

strLCD("Month(01-12):");//display string on LCD

mo=read2Digit();//Read the month

if(mo>=1 && mo<=12)//if the month is greater than equlto 1 and month is lessthan equalto 12 is checked

SetRTCDateInfo(d,mo,y);//Update RTC month

break;

case '7':/*Year*/

cmdLCD(0x01);//clear LCD

strLCD("Year(YYYY):");//Display string on LCD

y=2000+read2Digit();//Read the year

SetRTCDateInfo(d,mo,y);//Update the year

break;

case '8':/*Exit*/

cmdLCD(0x01);//clear LCD

strLCD("Exit RTC Menu");//Display string on LCD

delay_ms(800);

return;//Exit RTC menu

default:
cmdLCD(0x01);//clear LCD

strLCD("Invalid Key");//display invalid key

delay_ms(500);
}
}
}


/*-----MEDICINE TIME MENU-----*/

static void EditMedicineMenu(void){

char key;//variable for keypad input

u32 on_h,on_m,off_h,off_m;//Medicine ON OFF time

while(1){

cmdLCD(0x01);//clear LCD

strLCD("1.E.MED TIME");//display Edit option

cmdLCD(0xc0);//cursor on secondline in LCD

strLCD("2.EXIT");//display exit option

key=readkeyval();//Read key from keypad

if(key=='1'){//if edit medicine time selected

/*---ON TIME*/

cmdLCD(0x01);//clear LCD

strLCD("ONTIME HHMM:");//Display ONTIME on LCD

on_h=read2Digit();// Read ON hour

on_m=read2Digit();//Read ON minute

if(on_h>23 || on_m>59)//valid ON time
{

cmdLCD(0x01);//clear LCD

strLCD("Invalid on Time");//display invalid on time on LCD

delay_ms(800);
return;
}

/*----OFF TIME-----*/

cmdLCD(0x01);//clear LCD

strLCD("OFF TIME HHMM:");//display OFF time on LCD

off_h=read2Digit();//Read OFF hour

off_m=read2Digit();//Read OFF minute

if(off_h>23 || off_m>59){//validate OFF time

cmdLCD(0x01);//clear LCD

strLCD("Invalid off Time");//Display invalid off time

delay_ms(800);
continue;
}

/*----save medicine timing----*/

 Medicine_SetOnOffTime(on_h,on_m,off_h,off_m);

 cmdLCD(0x01);//clear LCD

 strLCD("Med Time Saved");//Display medicine time is saved

	med_enable=1;//Enable the medicine reminder

 delay_ms(1000);//delay for user visibility

 }
 else if(key=='2'){//Exit medicine menu

 return;
 }else{//Invalid key pressed

 cmdLCD(0x01);//clear LCD

 strLCD("Invalid Key");//Display invalid key on LCD

 delay_ms(500);
 }
 }
 }


/*-----SHOW MENU------*/

void showmainmenu(void){//function to display main menu

char key;//variable to strore key input

cmdLCD(0x01);//clear LCD

strLCD("1.E.RTCINFO 2.E.MEDICINE TIME");//Display main menu options on LCD

cmdLCD(0xc0);//cursor move to the second line

strLCD("3.EXIT");//Display exit option


key=readkeyval();//Read key from keypad

delay_ms(100);//delay for debounce

if(key=='1'){//RTC menu selected

EditRTCMenu();//call RTC menu function

}else if(key=='2'){//If medicine menu selected

EditMedicineMenu();//call medicine menu function
}else{
return;//Exit the main Menu
}

}


