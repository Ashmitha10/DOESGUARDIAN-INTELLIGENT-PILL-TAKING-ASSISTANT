//include function declarations of delay functions
#include"delay.h"
//include datatype definitions
#include"types.h"
//function to generate delay in microseconds
void delay_us(u32 tdly){
//multiply by 12 (approx clock cycles needed for 1 microsecond
//if processor clock is 12MHZ)
tdly*=12;
//Busy wait loop until tdly becomes 0
//eachloop consumes cpu cycles
while(tdly--);
}
//function to generate delay in milliseconds
void delay_ms(u32 tdly){
//multiply by 12000(approx clock cycles needed for 1 millisecond
//because 1ms=1000us
//12cycles *1000=12000(for 12MHZ clock)
tdly*=12000;
//Busy wait loop until tdly becomes 0
//each loop consumes cpu cycles
while(tdly--);
}
//function to generate delay in seconds

void delay_s(u32 tdly){
//multiply by 12000000(approx clock cycles needed for 1 second
//because 1 second=1000ms
//12000*1000=12,000,000(for 12MHZ clock)

tdly*=12000000;
//Busy wait loop until tdly becomes 0
//each loop consumes cpu cycles
while(tdly--);
}
