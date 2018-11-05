
#ifndef __TIMER_H__
#define __TIMER_H__


#define STEPS_PER_US  	(PERIPH_CLK / (1000 * 1000UL))
#define T1_CNT_MAX		(1000 * STEPS_PER_US - 1) // 1MS CNT

void timer0_init(UINT16 period);
void timer1_init(UINT16 period);


#endif /* end of __TIMER_H__ */

