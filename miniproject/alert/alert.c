/*Include alert function and its declarations*/
#include"alert.h"

/*Include delay functions and its declarations*/
#include"delay.h"

/*Include lcd functions and its delarations*/
#include"lcd.h"

/*external variable declaration*/
extern u8 med_on_min;

/*----Alert initializations Function----*/

void alert_init(void){

IODIR1|=BUZZER_PIN;//configure the buzzer pin as an output

IODIR0|=REDLED_on;//configure the RED led pin as an output

IOCLR0=REDLED_on;//Turn off the LED Initially
}

/*start alert function*/
void alert_start(void){

IOSET1=BUZZER_PIN;//Set the buzzer pin High to turn ON buzzer
}

/*stop Alert(Turnoff the buzzer*/
void alert_stop(void){

IOCLR1=BUZZER_PIN;//clear buzzer pin to turn OFF the BUZZER
}

/*Missed medicine Alert*/
void alert_missed(void){

IOSET0=REDLED_on;//Turn ON red LED to indicate missed medicine

cmdLCD(0x01);//clear LCD

strLCD("Failed to taken Medicine");//Display medicine missed

med_on_min=0;//Reset ON minute

delay_ms(5000);//Keep alert for 5 seconds

IOCLR0=REDLED_on;//Turn OFF red LED after delay
}

