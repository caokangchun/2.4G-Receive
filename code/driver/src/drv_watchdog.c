
#include "includes.h"
	
//------------------------------------------------------------------------
//	Description :	watchdog config
//	Parameters	:	t -> wdt ov time level
//	Return		:	None
//	Author		:	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void watchdog_init(UINT8 t)
{
	/* Select bank1 before set wdt register */
    _sfrb_bank1();

	/* Write protect Key first */
	WDTCNT = WDT_KEY;
	/* WDT period */
	WDTPR = 0xF7;
	
	/* Write protect Key first */
	WDTCNT = WDT_KEY;
	/* watchdog control register */
	WDTCON = (0 << 7) | // WDTOV WDT time over flag
			 (t << 4) | // WDTPS2[2~0] Pre-scaler select
			 (1 << 3) | // WDTRE Reset Enable
			 (0 << 2) | // WDTWE Wakeup Enable
			 (0 << 1) | // WDTCS WDT Clock Select
			 (1 << 0);  // WDTE WDT Enable

	/* Write protect Key first */
	WDTCNT = WDT_KEY;
	/* Clear WDT CNT */
	WDTCNT = 0;
}


//------------------------------------------------------------------------
//	Description :	watchdog refresh
//	Parameters	:	None
//	Return		:	None
//	Author		:	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void Watchdog_feed(void)
{
    BOOL sfrb_bak = SFRB; // backup status

	/* Select bank1 */
    _sfrb_bank1();
	
	/* Write protect Key first */
	WDTCNT = WDT_KEY;
	
	/* Clear WDT CNT */
	WDTCNT = 0;
	
    SFRB = sfrb_bak; // restore status
}

