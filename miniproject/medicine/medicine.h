//To prevent multiple inclusions
#ifndef MEDICINE_H

//Macro definitions for medicine module
#define MEDICINE_H

/*Include the user-define data types*/
#include"types.h"

/*Include RTC related functions and its declarations*/
#include"rtc.h"

/*External variable to store medicine ON hour*/
extern u8 med_on_hour;


/*External variable to store medicine ON minute*/
extern u8 med_on_min;


/*External variable to store medicine OFF hour*/
extern u8 med_off_hour;


/*External variable to store medicine OFF minute*/
extern u8 med_off_min;


/*External variable to store medicine enable or disable medicine reminder*/
extern u8 med_enable;

void medicine_init(void);//Function ti initialize the medicine parameters

/*Function to set medicine ON and OFF timings*/
void Medicine_SetOnOffTime(u32 on_h,u32 on_m,u32 off_h,u32 off_m);


u8 Medicine_Check(void);//Function to check medicine timing

//Return 1 if medicine time matches else 0

//End of header
#endif
