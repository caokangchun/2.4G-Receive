
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	interrupt0 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void PORT0_Handler(void) interrupt 0
{
	/* port0 interrupt -------------------------------------------------*/
}


//------------------------------------------------------------------------
//	Description	: 	interrupt1 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void PORT1_Handler(void) interrupt 1
{	
	/* port1 interrupt -------------------------------------------------*/
}


//------------------------------------------------------------------------
//	Description	: 	interrupt2 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void PORT2_Handler(void) interrupt 2
{	
	/* port2 interrupt -------------------------------------------------*/
}

//------------------------------------------------------------------------
//	Description	: 	interrupt3 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void PORT3_Handler(void) interrupt 3
{	
	/* port3 interrupt -------------------------------------------------*/
}

idata volatile UINT8 delay_tick;
//------------------------------------------------------------------------
//	Description	: 	interrupt4 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void TIMER0_Handler(void) interrupt 4
{
    BOOL sfrb_bak = SFRB; // backup status
	
	/* TIMER0 interrupt -------------------------------------------------*/
    _sfrb_bank1();          // Switch Bank1
	T0CON &= ~ BIT_MASK(7); // Clear TOV
    //_sfrb_bank0();          // Switch Bank0
    
    // for test:
	//test_pin0 = !test_pin0;
	
	delay_tick++;
	
#ifdef _UART2USB
	#ifdef _RF_HOST
	ad_t++;
	rf_host.idleout++;
	rf_host.tx_out++;
	rf_host.same_out++;
	if(rf_host.same_out > 6500)
	{
		rf_host.same_out = 6500;
	}
	if(uart.state != RECV_IDLE)
	{
		if(uart.time_out != 0)
		{
			uart.time_out--;
			if(0 == uart.time_out)
			{
				/* receive data timeout */
				if(RECV_DATA == uart.state)
				{
					//rf_host.tx_out = 0;
					//test_pin2 = !test_pin2;
					uart.data_ok = TRUE;
				}
				/* overflow data timeout */
				else if(RECV_STOP == uart.state)
				{
					//uart.index = 0;
				}
				
				uart.state = RECV_IDLE;
			}
		}
	}
	#else
	rf_slave.rx_tout++;
	/* clear pkt_cnt for idle */
	if(rf_slave.clear_t != 0)
	{
		rf_slave.clear_t--;
		if(0 == rf_slave.clear_t)
		{
			//rf_slave.pkt_id = INIT_ID;
		}
	}
	beep_task();
	#endif
#endif /* _UART2USB */
	
    SFRB = sfrb_bak; // restore status
}

//------------------------------------------------------------------------
//	Description	: 	interrupt5 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void TIMER1_Handler(void) interrupt 5
{	
    BOOL sfrb_bak = SFRB; // backup status
	
	/* TIMER1 interrupt -------------------------------------------------*/
	_sfrb_bank1();           // Switch Bank1
	T1CON &= ~(BIT_MASK(7)); // Clear TOV
    _sfrb_bank0();           // Switch Bank0
    // for test:
    //test_pin1 = !test_pin1;
    
    SFRB = sfrb_bak; // restore status
}

//------------------------------------------------------------------------
//	Description	: 	interrupt9 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void WDT_Handler(void) interrupt 9
{	
    BOOL sfrb_bak = SFRB; // backup status
    
	/* WDT interrupt -------------------------------------------------*/
    _sfrb_bank1();				// Switch Bank1
    if(WDTCON & BIT_MASK(7))
    {
    	/* Write protect Key first */
		WDTCNT = WDT_KEY;

		/* Clear WDT OV flag */
    	WDTCON &= ~ BIT_MASK(7);
		
		/* Clear WDT CNT */
		WDTCNT = 0;
    }
    _sfrb_bank0();              // Switch Bank0
    // for test:
    //test_pin0 = !test_pin0;
    
    SFRB = sfrb_bak; // restore status
}

//------------------------------------------------------------------------
//	Description	: 	interrupt10 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void ADC_Handler(void) interrupt 10
{	
	/* ADC interrupt -------------------------------------------------*/
}

//------------------------------------------------------------------------
//	Description	: 	interrupt11 handler
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void UART_Handler(void) interrupt 11
{	
	UINT8 buf;
	
    BOOL sfrb_bak = SFRB; // backup status
	
	/* UART interrupt -------------------------------------------------*/
    _sfrb_bank1();			// Switch Bank1
	if(UT0RF)				// UART rx data
	{
		UT0RF = 0;
		buf = UT0BUF;
		
	#ifdef _UART2USB
		//uart_receive(buf);
	#endif /* _UART2USB */
	}
    _sfrb_bank0();			// Switch Bank0
    // for test:
    //test_pin0 = !test_pin0;
    
    SFRB = sfrb_bak; // restore status
}

