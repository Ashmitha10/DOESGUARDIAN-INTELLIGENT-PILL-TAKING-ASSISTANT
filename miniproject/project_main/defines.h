//macro for setbit
#define SETBIT(WORD,BP)WORD|=(1<<BP)
//macro for clearbit
#define CLRBIT(WORD,BP) WORD&=~(1<<BP)
//macro for complement bit
#define CPLBIT(WORD,BP) WORD^=(1<<BP)
//macro for writebit
#define WRITEBIT(WORD,BP,BIT) WORD=((WORD&~(1<<BP))|(BIT<<BP))
//macro for writenibble
#define WRITENIBBLE(WORD,SBP,NIBBLE) (WORD=((WORD&~(0x0f<<SBP))|(NIBBLE<<SBP)))
//macro for writebyte
#define WRITEBYTE(WORD,SBP,BYTE)   WORD=((WORD&~(0xff<<SBP)|(BYTE<<SBP)))
//macro for writehalfword
#define WRITEHWORD(WORD,SBP,HWORD)
