
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	system clock config
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void colck_config(void)
{
    _sfrb_bank0();
    
#ifndef _EXT_OSC
	/* system clock control0 */
	CCON0 = (0 << 7) | // CSF
			(0 << 4) | // SCS
			(0 << 3) | // XLOSCE
			(0 << 2) | // XHOSCE
			(1 << 1) | // ILOSCE
			(1 << 0) ; // IHOSCE
#else
	/* system clock control0 */
	CCON0 = (0 << 7) | // CSF
			(2 << 4) | // SCS
			(0 << 3) | // XLOSCE
			(1 << 2) | // XHOSCE
			(1 << 1) | // ILOSCE
			(1 << 0) ; // IHOSCE
	while(!(CCON0 & 0x80));
#endif

    CCON1 = 0x00;
    CCON2 = 0x00;
}
		
	

