
#ifndef __ASCII2HID_H__
#define __ASCII2HID_H__

#include "usb_hid.h"
#include "typedef.h"

typedef struct
{
	unsigned char hid;
	unsigned char func;
}CONVERT, LANG;

#ifdef __KEIL_C51__
extern code CONVERT *lang_ptr[];
#else
void language(UINT8 type, UINT8 index, LANG *lang);
#endif /* __KEIL_C51__ */

#endif /* __ASCII2HID_H__ */


