
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	serial baudrate
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2014 - 02 - 17
//------------------------------------------------------------------------
void serial_baud(SERIAL_NO sx, SERIAL_BUAD baud)
{
	_sfrb_bank1();
	if(S0 == sx)    SPI0BR = baud;
	else			SPI1BR = baud;
}


//------------------------------------------------------------------------
//	Description	: 	serial disable
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2014 - 02 - 17
//------------------------------------------------------------------------
void serial_reset(SERIAL_NO sx)
{
	_sfrb_bank1();
	if(S0 == sx)	SPI0CON = 0x00;
	else			SPI1CON = 0x00;
}


//------------------------------------------------------------------------
//	Description	: 	serial mode config
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2014 - 02 - 17
//------------------------------------------------------------------------
void serial_mode(SERIAL_NO sx, SERIAL_MODE m)
{
	UINT8 sxcon;
    
	sxcon = (0 << 7) | // Finish
			(0 << 6) | // IIC ACK bit for read
			(1 << 5) | // Enable, 1 for enable
			(0 << 4) | // Start
			(m << 0);  // Mode
			
	_sfrb_bank1();
	if(S0 == sx)	SPI0CON = sxcon;
	else			SPI1CON = sxcon;
}


//------------------------------------------------------------------------
//	Description	: 	serial send data
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2014 - 02 - 17
//------------------------------------------------------------------------
UINT8 serial_transceive(SERIAL_NO sx, UINT8 dat)
{
    UINT8 buf_dat;
    
	_sfrb_bank1();
	if(S0 == sx)
	{
		SPI0BUF = dat;	            // send dat
		SPI0CON |= 0x10;            // start
		//mcu_hold(); 	            // cpu idle
		while(!(SPI0CON & 0x80));	// wait complete
		SPI0CON &= ~0x90;		    // clear flag
		buf_dat = SPI0BUF;          // recv data
	}
	else
	{
		SPI1BUF = dat;	            // send dat
		SPI1CON |= 0x10;            // start
		//mcu_hold(); 	            // cpu idle
		while(!(SPI1CON & 0x80));	// wait complete
		SPI1CON &= ~0x90;		    // clear flag
		buf_dat = SPI1BUF;          // recv data
	}

    return buf_dat;
}

