

#ifndef __USB_DESCRIPT_H__
#define __USB_DESCRIPT_H__

extern unsigned char code uDevHidTable[];
extern unsigned char code uDevHidCfgTable[];
extern unsigned char code uDevCdcTable[];
extern unsigned char code uDevCdcCfgTable[];

extern unsigned char code uKeyReportTable[];
extern unsigned char code uMouseReportTable[];
extern unsigned char code uHidReportTable[];

#define _DEV_STR_DES_EN         1
#define _KEY_REPORT_TAB_SIZE_   63
#define _MOUSE_REPORT_TAB_SIZE_ 0xAB
#define _HID_REPORT_TAB_SIZE_   53

extern unsigned char code uLanguageTab[];
extern unsigned char code uMftTab[];
extern unsigned char code uProductTab[];
extern unsigned char code uSerialNoTab[];
extern unsigned char code uInterfaceTab0[];
extern unsigned char code uInterfaceTab1[];

unsigned char* GetHid0Des();
unsigned char* GetHid1Des();

#endif
