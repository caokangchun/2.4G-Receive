
#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

#define WDT_KEY		0xFA
#define WDT_ENABLE

void watchdog_init(UINT8 t);
void Watchdog_feed(void);

#ifdef WDT_ENABLE
#define watchdog_feed()		Watchdog_feed()
#else
#define watchdog_feed()
#endif


#endif /* end of __WATCHDOG_H__ */

