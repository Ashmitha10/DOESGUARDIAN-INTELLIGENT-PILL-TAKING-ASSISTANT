//include custom datatype definitions
#include"types.h"
//initializes the LCd function definition
void initLCD(void);
//sends a command to LCD function definition
void cmdLCD(u8);
//Display a single char onLCD function definition
void charLCD(s8);
//display a string ON LCD function definition
void strLCD(s8*);

//Display a integer onLCD function definition

void intLCD(s32);
//Display a float onLCD function definition

void floatLCD(f32,u32);
//Display a specialcustom characters onLCD function definition

void writetocgRAM(void);
//Display on LCD function definition

void displayLCD(u8);
//Display a hexa decimal valueonLCD function definition

void HexLCD(u32);

