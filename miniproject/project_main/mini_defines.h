#ifndef MINI_DEFINES_H
#define MINI_DEFINES_H
#include<LPC21xx.h>
/*---LEDs----*/
#define REDLED_on (1<<5)//p0.5 formedicine

/*-----BUZZER-----*/
#define BUZZER_PIN (1<<18)
#define ACKTIMEOUT 30

/*----LCD------*/
#define LCD_data 8//here p0.16 top0.23 are lcd data ines
#define RS 16
#define RW 19
#define EN 17

/*-----KEYPAD-----*/
#define R0 16
#define R1 17
#define R2 18
#define R3 19

#define c0 20
#define c1 21
#define c2 22
#define c3 23

/*----switches----*/
#define SWITCH1_PIN 28
#define SWITCH2_PIN 25

#endif			 
                                                         
