
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	mcu init
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void spi_init(void)
{
    // Switch to BANK0
	_sfrb_bank0();
	
	P3OE |= BIT_MASK(4); // SPI_CS
	P34 = 1;
	P3OE |= BIT_MASK(5); // SPI_CLK
	P35 = 0;

    // Switch to BANK1
	_sfrb_bank1();
	P4OE |= BIT_MASK(5); // SPI_MOSI
	P4IE |= BIT_MASK(4); // SPI_MISO
}

//------------------------------------------------------------------------
//	Description	: 	mcu init
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
UINT8 spi_send_1byte(UINT8 byte)
{
	UINT8 i, dat;
	    
	for(i = 0; i < 8; i++)
	{
        _sfrb_bank1();
		if(byte & 0x80)		// send bit
			SPI_DO_PIN = 1;
		else
			SPI_DO_PIN = 0;
		byte <<= 1;			// next bit

		_nop_();_nop_();
		
        _sfrb_bank0();
		SPI_CLK_PIN = 1;	// pre edge

		dat <<= 1;			// next bit
        _sfrb_bank1();
		if(SPI_DI_PIN)		// sample bit
			dat |= 0x01;
		else
			dat &= 0xFE;

		_nop_();_nop_();
		
        _sfrb_bank0();
		SPI_CLK_PIN = 0;	// post edge
	}
	
	return dat;
}



