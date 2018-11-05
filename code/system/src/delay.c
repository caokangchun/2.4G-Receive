
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	delay 1us
//	Parameters 	: 	n us
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2013 - 11 - 27
//------------------------------------------------------------------------
void delay_1us(UINT8 delay_t)
{
#if (SYS_CLK == SYS_6MHZ)
	delay_t -= 3;
	do{
		_nop_();_nop_();
	}while(--delay_t);
#elif (SYS_CLK == SYS_24MHZ)
	do{
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();
	}while(--delay_t);
#endif
}


//------------------------------------------------------------------------
//	Description	: 	delay 1ms
//	Parameters 	: 	n ms
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2013 - 11 - 27
//------------------------------------------------------------------------
void delay_1ms(UINT8 delay_t)
{
	do{
		delay_1us(250);
		delay_1us(250);
		delay_1us(250);
		
		/* us num revise */
	#if (SYS_CLK == SYS_6MHZ)
		delay_1us(249);
	#elif (SYS_CLK == SYS_24MHZ)
		delay_1us(248);
	#endif
	}while(--delay_t);
}


