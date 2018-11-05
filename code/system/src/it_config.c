
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	interrupt config
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void it_config(void)
{
    _sfrb_bank0();
	
	IE0 = (0 << 7) | // global interrupt enable
		  (0 << 6) | // TPC0/TPC1 interrupt
		  (0 << 5) | // TIMER1 interrupt
		  (1 << 4) | // TIMER0 interrupt
		  (0 << 3) | // P3/P4 interrupt
		  (0 << 2) | // P2 interrupt
		  (0 << 1) | // P1 interrupt
		  (0 << 0);  // P0 interrupt

	IE1 = (0 << 7) | // CMP3 interrupt
		  (0 << 6) | // CMP2 interrupt
		  (0 << 5) | // CMP1 interrupt
		  (0 << 4) | // CMP0 interrupt
		  (0 << 3) | // UART0/1 Rx/Overrun interrupt
		  (0 << 2) | // ADC interrupt
		  (0 << 1) | // WDT/WUT interrupt
		  (0 << 0);  // LVD interrupt

	IE2 = (0 << 7) | // USB Ep3 OUT interrupt
		  (0 << 6) | // USB Ep3 IN interrupt
		  (0 << 5) | // USB Ep2 OUT interrupt
		  (0 << 4) | // USB Ep2 IN interrupt
		  (0 << 3) | // USB Ep1 OUT interrupt
		  (0 << 2) | // USB Ep1 IN interrupt
		  (1 << 1) | // USB Ep0 interrupt
		  (1 << 0);  // USB bus interrupt

	IE3 = (0 << 7) | // PWM5 indterrupt
		  (0 << 6) | // PWM4 indterrupt
		  (0 << 5) | // PWM3 indterrupt
		  (0 << 4) | // PWM2 indterrupt
		  (0 << 3) | // PWM1 indterrupt
		  (0 << 2) | // PWM0 indterrupt
		  (0 << 1) | // SPI/UART Tx interrupt
		  (0 << 0);  // PT0/PT1 interrupt
}


