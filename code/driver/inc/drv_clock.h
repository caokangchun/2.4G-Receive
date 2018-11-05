
#ifndef __CLOCK_H__
#define __CLOCK_H__


#define mcu_hold()		PCON |= (1 << 0)
#define mcu_sleep()		PCON |= (1 << 1)

void colck_config(void);


#endif /* end of __CLOCK_H__  */

