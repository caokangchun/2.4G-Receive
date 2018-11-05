
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	adc module init
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2014 - 02 - 19
//------------------------------------------------------------------------
void adc_init(void)
{
	/* ADC clock */
	ABR = 0x02;			// ACLK = 1/(ABR*8 + 1)
	
	/* ADC control */
	ACON = (0 << 7) |	// ADC Convertsion finish, 1 for finish
		   (0 << 6) |	// ADC Start Conversion, 1 for start
		   (3 << 4) |	// ADC Reference select
		   (1 << 3) |	// ADC Enable, 1 for enable
		   (5 << 0);	// ADC Input select
	
	ABUF1 |= (0 << 3) |	// ADC 8 Bit mode, 1 for enable
			 (0 << 2);	// ADC Power enable, 1 for enable
}


//------------------------------------------------------------------------
//	Description	: 	adc voltage detect
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2014 - 02 - 19
//------------------------------------------------------------------------
UINT16 adc_convert(void)
{
	UINT16 adc_value;
	
	AS = 1;						// ADC start
	while(!AF); 				// polling ADC flag
	AF = 0;						// clear flag
	adc_value = ABUF0;			// get ADC high 8bit value
	adc_value <<= 2;
	adc_value |= ABUF1 & 0x03;	// get ADC low 2bit value

	//printf("adc=%x.\r\n", (UINT16)adc_value);
	return adc_value;
}



