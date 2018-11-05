
#ifndef _DRV_PWM_H_
#define _DRV_PWM_H_

#include "typedef.h"

#define PWM0_ON 	PG0CON0 |= BIT_MASK(2);
#define PWM0_OFF	PG0CON0 &= ~ BIT_MASK(2);

void pwm0_init(UINT32 freq, UINT8 duty);


#endif /* end of _DRV_PWM_H_ */


