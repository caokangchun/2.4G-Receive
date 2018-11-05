
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	mcu init
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void mcu_init(void)
{
	colck_config();
	
	UsbDeInit();
	delay_1ms(10);
	
	io_init();
	//test_pin0 = !test_pin0;
	delay_1us(10);
	//test_pin0 = !test_pin0;
	
#ifdef WDT_ENABLE
	watchdog_init(5); // 2S
#endif /* WDT_ENABLE */

	timer0_init(1000);
	//pwm0_init(2025, 50);

#ifndef _SPI_HARDWARE
	spi_init();
#else
	//serial_baud(S1, SPEED_1M);
	//serial_mode(S1, SPI_LOW_FALLING_TX);
#endif /* _SPI_HARDWARE */

#ifdef _UART_EN
	uart0_init(UART_BAUD(9600), UART_8BIT);
#endif /* _UART_EN */

    //uart0_send_byte(0xAA);
    //uart0_send_byte(0x55);

	it_config();

	/* project info */
	printf("---------------------------------------------------\r\n");
	printf("@Project      : OUR5025 Based 1D-Barcode Scanner\r\n");
	printf("@Main File    : "__FILE__"\r\n");
	printf("@Compile Date : "__DATE__"\r\n");
	printf("@Compile Time : "__TIME__"\r\n");
	printf("@Author       : Sycreader\r\n");
	printf("---------------------------------------------------\r\n");
}

//------------------------------------------------------------------------
//	Description	: 	mcu init
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void RdSerialNum( UINT8* szBuf )
{
    UINT8 uIndex8;
    UINT8 uAddr8 = 0x40;

    _sfrb_bank1();

    for( uIndex8 = 0; uIndex8 < 8; uIndex8 ++ )
    {
        EFADR1 = 0x00;
        EFADR0 = uAddr8 ++;
        EFCON = 0x74;
        EFCON = 0x16;
        while( EFCON & 0x80 == 0 )
        {
        }
        *szBuf ++ = EFBUF;

        EFCON &= ~0x80;
    }
} 

