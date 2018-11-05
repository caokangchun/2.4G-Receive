
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	beep_ctrl
//	Parameters 	: 	cnt - beep times
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2014 - 12 - 05
//------------------------------------------------------------------------
void beep_ctrl(UINT8 cnt, UINT16 period)
{
	UINT8 i;
	
#ifndef DC_BUZZER
	UINT16 t, tmp;

	t = period;
	t = (t * 13) / 5; // x factor=2.6
#endif /* DC_BUZZER */

	_sfrb_bank0();
	
	for(i = 0; i < cnt; i++)
	{
    #ifdef DC_BUZZER
		PCINT1 = ON;
		delay_1ms(period);
        PCINT1 = OFF;
    #else
        tmp = t;
		while(tmp--)
		{
		    PCINT1 = ON;
		    delay_1us(153);
            PCINT1 = OFF;
		    delay_1us(224);
		    watchdog_feed();
		}
    #endif /* DC_BUZZER */

		if(cnt != 1)
		delay_1ms(period);
		watchdog_feed();
	}
}

volatile BOOL beep_flag = 0;
UINT8 beep_time = 0;

//------------------------------------------------------------------------
//	Description	: 	beep_ctrl
//	Parameters 	: 	cnt - beep times
//	Return 		: 	None
//	Author 		: 	RAY
//	Date 		: 	2014 - 12 - 05
//------------------------------------------------------------------------
void beep_wait_over(void)
{
	if(beep_flag) // Wait Decode Buz Over
	{
		while(beep_flag)
		Watchdog_feed();
	}
}

//------------------------------------------------------------------------
//	Description	: 	beep_ctrl
//	Parameters 	: 	cnt - beep times
//	Return 		: 	None
//	Author 		: 	RAY
//	Date 		: 	2014 - 12 - 05
//------------------------------------------------------------------------
void beep_task(void)
{
	static UINT8 beep_t = 0;
	
	if(beep_flag)
	{
		beep_t++;
		if(beep_t > beep_time)
		{
			beep_flag = 0;
			beep_t = 0;
			
            _sfrb_bank0();
            PCINT1 = OFF;
		}
	}
}

//------------------------------------------------------------------------
//	Description	: 	beep_ctrl
//	Parameters 	: 	cnt - beep times
//	Return 		: 	None
//	Author 		: 	RAY
//	Date 		: 	2014 - 12 - 05
//------------------------------------------------------------------------
void beep_enable(UINT8 time)
{
	beep_flag = 1;
	beep_time = time;
	
    _sfrb_bank0();
    PCINT1 = ON;
}

//------------------------------------------------------------------------
//	Description	: 	io init
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void io_init(void)
{    
    // PORT0~PORT3 configuration ---------------------
    _sfrb_bank0();

	// All IO pullup
	P0PU = 0xFF;
	P1PU = 0xFF;
	P2PU = 0xFF;
	P3PU = 0xFF;
	
	//P0OE |= BIT_MASK(0); // LED
	//P2IE |= BIT_MASK(2); // IRQ

	P3OE |= BIT_MASK(4); // SPI_CS
	P34 = 1;
	
	P3OE |= BIT_MASK(5); // SPI_CLK
	P35 = 0;
	
    // PORT4 configuration ----------------------------
    _sfrb_bank1();

	// All IO pullup
	P4PU = 0x3F;

	// UART IO config
	P4OE |= BIT_MASK(0);
	P4IE |= BIT_MASK(1);
	
	P4IE |= BIT_MASK(3); // IRQ

	// SPI IO config
	P4OE |= BIT_MASK(5); // SPI_MOSI
	P4IE |= BIT_MASK(4); // SPI_MISO
}

