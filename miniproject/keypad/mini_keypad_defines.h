/*prevents multiple inclusion of this header file*/
#ifndef KEYPAD_DEFINES_H

/*Define the macro to ensure the file is included only once*/
#define KEYPAD_DEFINES_H

/*Include user-define data types like u8--*/
#include"types.h"

//4*4 lookup table to map keypad rows and columns to key values
 s8 LUT[4][4]={
{'1','2','3','A'},//first row of keypad keys
{'4','5','6','B'},//second row of keypad keys
{'7','8','9','c'},//third row of keypad keys
{'*','0','#','D'}//Fourth row of keypad keys
};

/*End of header guard*/
#endif
