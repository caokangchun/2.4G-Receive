
#include "includes.h"

#define PWM_KEY		0xE3

//------------------------------------------------------------------------
//	Description	: 	timer0 config
//	Parameters 	: 	period -> timer for x us
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void pwm0_init(UINT32 freq, UINT8 duty)
{
	UINT16 PT0PR, PG0DC;

	PT0PR = (PERIPH_CLK / freq) - 1;
	PG0DC = (PERIPH_CLK / freq) * duty / 100;
	
	PIOCON0 = (1 << 7) | // PWM generator 1 LO default (turn off) state
			  (1 << 6) | // PWM generator 1 HO default (turn off) state
			  (0 << 5) | // PWM generator 1 LO invert
			  (0 << 4) | // PWM generator 1 HO invert
			  (1 << 3) | // PWM generator 0 LO default (turn off) state
			  (1 << 2) | // PWM generator 0 HO default (turn off) state
			  (0 << 1) | // PWM generator 0 LO invert
			  (0 << 0);  // PWM generator 0 HO invert

	PKEY = PWM_KEY;

	// PWM period
	PT1PR0 = PT0PR % 256;
	PT1PR1 = PT0PR / 256;

	// PWM duty
	PG0DC0 = PG0DC % 256;
	PG0DC1 = PG0DC / 256;

	PG0DT = 0; // PWM dead time

	PG0CON0 = (0 << 7) | // Fault 1 flag
			  (0 << 6) | // fault 0 flag
			  (0 << 5) | // Center-aligned mode
			  (0 << 4) | // immediate fault switch
			  (1 << 3) | // TIMER select. 0 : PTMR0. 1 : PTMR1.
			  (0 << 2) | // turn on PWM
			  (1 << 1) | // Enable PWMx
			  (0 << 0);  // Update PWMx duty immediate, 0: wait period end, 1: immediate
}






