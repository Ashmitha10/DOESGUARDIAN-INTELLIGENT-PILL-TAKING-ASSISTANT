/*Include LPC21xx register definitions*/
#include<LPC21xx.h>

/*Include delay definitions*/
#include"delay.h"

/*Include datatype definitions*/
#include"types.h"

/*Include common macro definitions*/
#include"defines.h"

/*Include LCD pin definitions*/
#include"lcd.h"

/*Include  mini project specific definitions*/
#include"mini_defines.h"

/*----Function:initLCD,purpose:Initialize 16*2  LCD in 8-bit mode----*/
void initLCD(void){
/*configure LCD data pins and control pins as OUTPUT*/
IODIR0|=0xff<<LCD_data|(1<<RS)|(1<<RW)|(1<<EN);

/*Intial power-on display*/
delay_ms(20);

/*Enable 8-bit mode*/
cmdLCD(0x30);

/*min of 8 msec*/
delay_ms(8);

/*Enable 8-bit mode*/
cmdLCD(0x30);

/*min. of 160usec*/
delay_ms(1);

/*Enable 8-bit mode*/
cmdLCD(0x30);

/*min. of 160usec*/
delay_ms(1);

/*Enable 8-bit mode with 5*7 font with 2 lines disp*/
cmdLCD(0x38);

/*display OFF*/
cmdLCD(0x08);

/*CLR Disp*/
cmdLCD(0x01);

/*Inc cursor after writing everybyte*/
cmdLCD(0x06);

/*Enable disp with cursor blinking*/
cmdLCD(0x0f);
}

/*----Function:dispLCD,purpose:send data/command to LCD----*/
void dispLCD(u8 val){

/*select write operation*/
IOCLR0=1<<RW;

/*Write 8-bit value to LCD data pins*/
WRITEBYTE(IOPIN0,LCD_data,val);

/*Generate enable pulse*/
IOSET0=1<<EN;
delay_us(1);
IOCLR0=1<<EN;

/*execution delay*/
delay_ms(2);
}

/*----Function:cmdLCD,purpose:send command to LCD----*/
void cmdLCD(u8 cmd){

/*select command register*/
IOCLR0=1<<RS;

/*send command*/
dispLCD(cmd);
}

/*----Function:charLCD,purpose:display single character on LCD----*/
void charLCD(s8 dat){

/*select data register*/
IOSET0=1<<RS;

/*send character*/
dispLCD(dat);
}

/*----Function:strLCD,purpose: Display a string on LCD----*/
void strLCD(s8*ptr){

/*Loop until the end of string*/
while(*ptr!='\0'){

/*Display each character*/
charLCD(*ptr);
ptr++;
}
}
/*int LCD*/
void intLCD(s32 num){
s8 a[10],i=0;//Array to store digits
if(num==0){	//if number is equal to zero
charLCD(0+48);//48 is ASCII value of '0'
}
else
{
if(num<0){//if number is negative
charLCD('-');//display negative sign
num=-num;//convert to negative to postive
}
while(num){//extract digits one by one(reverse order)
a[i++]=num%10+48;//covert digit to ASCII and store
num/=10;//remove last digit
}
--i;//Adjust index to last valid digit
for(;i>=0;i--)//print digit in correct order
charLCD(a[i]);//send digit to LCD
}
}




	 

