/*Include LPC21xx.h register functions*/
#include<LPC21xx.h>

/*Include switch pin definitions*/
#include"switches.h"

/*Include common macro definitions*/
#include"defines.h"

/*Include delay function declarations*/
#include"delay.h"

/*Include miniproject specific definitions*/
#include"mini_defines.h"

/*----Function:switches_init/purpose:configure switch pins as input----*/
void switches_init(void){

/*clear the direction bits to configure SWITCH1 and SWITCH2 as input*/
IODIR0&=~(SWITCH1_PIN |SWITCH2_PIN);
}

/*----Function:SWITCH1 check whether the SWITCH1 is pressed Return 1 if pressed,0 otherwise----*/
int switch1_pressed(void){

/*Read SWITCH1 pin status*/
if(((IOPIN0>>SWITCH1_PIN)&1)==0){

/*small delay for switch debouncing*/
delay_ms(10);

/*SWITCH1 is pressed*/
return 1;
}
/*SWITCH1 is not pressed*/
return 0;
}

/*----Function:SWITCH2 check whether the SWITCH2 is pressed Return 1 if pressed,0 otherwise----*/
int switch2_pressed(void){

/*Read SWITCH1 pin status*/
if(((IOPIN0>>SWITCH2_PIN)&1)==0){

/*small delay for switch debouncing*/
delay_ms(10);

/*SWITCH2 is pressed*/
return 1;
}
/*SWITCH2 is not pressed*/
return 0;
}
