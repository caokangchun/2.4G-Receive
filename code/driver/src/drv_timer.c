
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	timer0 config
//	Parameters 	: 	period -> timer for x us
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void timer0_init(UINT16 period)
{
	UINT16 temp16;
	
	/* Select bank1 before set TIMER1 register */
	_sfrb_bank1();
	
	/* set T0 period */
	temp16 = (period * STEPS_PER_US) - 1;
	T0PR1 = temp16 / 256;
	T0PR0 = temp16 % 256;

	/* T0 control */
	T0CON = (0 << 7) | // TOV flag
			(0 << 4) | // Clock divide
			(0 << 2) | // 0: sys clock, 1: rising edge. 2: falling edge 3: rising edge and falling edge
			(0 << 1) | // Reserved
			(1 << 0);  // TE Enable TIMER0

	/* clear T0 counter */
	T0CNT0 = 0;
	T0CNT1 = 0;
}

//------------------------------------------------------------------------
//	Description	: 	timer1 config
//	Parameters 	: 	period -> timer for x us
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void timer1_init(UINT16 period)
{
	UINT16 temp16;

	/* Select bank1 before set TIMER1 register */
	_sfrb_bank1();

	/* set T1 period */
	temp16 = (period * STEPS_PER_US) - 1;
	T1PR1 = temp16 / 256;
	T1PR0 = temp16 % 256;

	/* T1 control */
	T1CON = (0 << 7) | // TOV flag
			(0 << 4) | // Clock divide
			(0 << 2) | // 0: sys clock, 1: rising edge. 2: falling edge 3: rising edge and falling edge
			(0 << 1) | // Reserved
			(1 << 0);  // TE Enable TIMER0

	/* clear T1 counter */
	T1CNT0 = 0;
	T1CNT1 = 0;
}

