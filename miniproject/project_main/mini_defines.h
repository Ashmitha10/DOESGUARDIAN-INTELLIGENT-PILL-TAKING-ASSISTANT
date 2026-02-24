/*----project defines----*/
#ifndef MINI_DEFINES_H
#define MINI_DEFINES_H
//include header file
#include<LPC21xx.h>
/*---LEDs----*/
#define REDLED_on (1<<5)//red led connected to port0 pin5 

/*-----BUZZER-----*/
#define BUZZER_PIN (1<<26)//Buzzer is connected to port1 pin26
#define ACKTIMEOUT 30//Timeout value for acknowledgement

/*----LCD------*/
#define LCD_data 8//here p0.8 top0.16 are lcd data ines
#define RS 16//Register select connected to port0 pin 16
#define RW 19//read write connected to port0. pin 19
#define EN 17//Enable is connected to port0 pin 17

/*-----KEYPAD-----*/
#define R0 16//row0 is connected to port1 pin 16
#define R1 17//row1 is connected to port1 pin 17
#define R2 18//row2 is connected to port1 pin 18
#define R3 19//row3 is connected to port1 pin 19

#define c0 20//column0 is connected to port1 pin 20
#define c1 21//column1 is connected to port1 pin 21
#define c2 22//column2 is connected to port1 pin 22
#define c3 23//column3 is connected to port1 pin 23

/*----switches----*/
#define SWITCH1_PIN 28//switch1 is connected to port0 pin 28
#define SWITCH2_PIN 25//switch2 is connected to port0 pin25

#endif			 
                                                         



