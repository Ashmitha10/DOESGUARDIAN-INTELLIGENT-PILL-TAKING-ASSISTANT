/*prevent multiple inclusions of this file*/
#ifndef KEYPAD_H

/*macro definition for header guard*/
#define KEYPAD_H

void keypadinit(void);//Function to Initialize keypad

char readkeyval(void);//Fuction to read the key value from keypad

int colstat(void);//Function to check the column status
//End of the header
#endif
