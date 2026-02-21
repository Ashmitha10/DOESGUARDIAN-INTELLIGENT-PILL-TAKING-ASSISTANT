#include<LPC21xx.h>
//include the all defines
#include"defines.h"
//include keypad specific pin definitions
#include"mini_keypad_defines.h"
//include keypad function declarations
#include"mini_keypad.h"

#include"mini_defines.h"
void keypadinit(void){//function to initialize the keypad
//configure the row pins
IODIR1|=((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
}
//function to check coumn status
int colstat(void){
//read 4 column bits and check if all are high
if(((IOPIN1>>c0)&0xf)==0xf)
return 1;//no key pressed
else
return 0;//key is pressed
}		
//function to scan keypad return pressed key value
char readkeyval(void){
char rowval,colval;//variables to store to detect row and column number
//clear lower 16 bits
WRITEBYTE(IOPIN1,16,0);
//wait until any key is pressed
while(colstat());
IOCLR1=1<<R0;//make row0 low
IOSET1=((1<<R1)|(1<<R2)|(1<<R3));//oter rows are high
//key found in row0
if(((IOPIN1>>c0)&0xf)!=0xf){
rowval=0;
goto colcheck;
}
IOCLR1=1<<R1;//make row1 low
IOSET1=((1<<R0)|(1<<R2)|(1<<R3));//other rows are high
//key found in row 1
if(((IOPIN1>>c0)&0xf)!=0xf){
rowval=1;
goto colcheck;
}

IOCLR1=1<<R2;//make row2 is low
IOSET1=((1<<R0)|(1<<R1)|(1<<R3));//other rows are high
//keyfound in row 2
if(((IOPIN1>>c0)&0xf)!=0xf){
rowval=2;
goto colcheck;
}
IOCLR1=1<<R3;//make row 3 is low
IOSET1=((1<<R0)|(1<<R1)|(1<<R2));//other rows are high
//key found in row 3
if(((IOPIN1>>c0)&0xf)!=0xf)
rowval=3;
//now determine which column is pressed
colcheck:
if(((IOPIN1>>c0)&1)==0)
colval=0;
//column 1 is pressed
else if(((IOPIN1>>c1)&1)==0)
colval=1;
//column 2 is pressed
else if(((IOPIN1>>c2)&1)==0)
rowval=2;
else
//cloumn 3 pressed
colval=3;
//wait until the key is released
while(((IOPIN1>>c0)&0xf)!=0xf);
//return corresponding key value from lookup table
return (LUT[rowval][colval]);
}




