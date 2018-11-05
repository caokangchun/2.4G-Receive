
#ifndef __DELAY_H__
#define __DELAY_H__


#ifdef __KEIL_C51__
#include <intrins.h>
#else
#error "This code will not work without the Keil Compiler."
#endif


void delay_1ms(UINT8 delay_t);
void delay_1us(UINT8 delay_t);


#endif /* end of __DELAY_H__ */

