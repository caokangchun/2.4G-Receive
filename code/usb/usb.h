

#ifndef __USB_H__
#define __USB_H__

#include "main.h"
#include "typedef.h"

#if( SYS_CLK == SYS_24MHZ )
    #define _USB_FULL_SPEED_
#endif

#ifdef _USB_FULL_SPEED_
    #define _MAX_EP_SIZE_       0x40
#else
    #define _MAX_EP_SIZE_       0x08
#endif

#define _U_EP0_STALL_           0x01
#define _U_EP1_IN_STALL_        0x02
#define _U_EP2_IN_STALL_        0x04
#define _U_EP1_OUT_STALL_       0x08
#define _U_EP2_OUT_STALL_       0x10
#define _U_BOOT_PTL_            0x20
#define _U_REMOTE_WK_           0x40
#define _U_SUSPEND_             0x80

#define _U_DEFAULT_STATE_       0x00
#define _U_ADDRESS_STATE_       0x01
#define _U_CONFIGURED_STATE_    0x02
#define _U_SUSPEND_STATE_       0x03

#ifdef _USB_FULL_SPEED_
#define _bmRequestType          uEP0InOut[0]
#define _bRequest               uEP0InOut[1]
#define _wValuel                uEP0InOut[2]
#define _wValueh                uEP0InOut[3]
#define _wIndexl                uEP0InOut[4]
#define _wIndexh                uEP0InOut[5]
#define _wLengthl               uEP0InOut[6]
#define _wLengthh               uEP0InOut[7]
#endif

extern unsigned char idata uEP0InOut[_MAX_EP_SIZE_];// _at_ 0x60;

extern unsigned char xdata uEp1In[_MAX_EP_SIZE_];// _at_ 0x8000;
extern unsigned char xdata uEp1Out[_MAX_EP_SIZE_];// _at_ 0x8040;

extern unsigned char xdata uEp2In[_MAX_EP_SIZE_];// _at_ 0x8080;
extern unsigned char xdata uEp2Out[_MAX_EP_SIZE_];// _at_ 0x80C0;

extern unsigned char xdata uEp3In[_MAX_EP_SIZE_];// _at_ 0x8100;
extern unsigned char xdata uEp3Out[_MAX_EP_SIZE_];// _at_ 0x8140;

//----------------------------------------------------------------------------
//						CDC Class Request Types
//----------------------------------------------------------------------------
/* Class-Specific Requests */
#define SET_LINE_CODING			0x20
#define GET_LINE_CODING			0x21
#define SET_CONTROL_LINE_STATE	0x22

/* Class-Specific Notifications */
#define SERIAL_STATE			0x20

typedef struct
{
	UINT8 dwDTERate[4];
	UINT8 bCharFormat;
	UINT8 bParityType;
	UINT8 bDataBits;
}LINE_CODING_STRUCT;

/* USB VCOM open state : Activate carrier & DTE Present */
#define ACT_BIT                 0x02
#define DTE_BIT                 0x01
#define usb_vcom_open()         (bit_map & DTE_BIT)

#define USB_DevHID              0
#define USB_DevCDC              1

extern unsigned char uDevState;
extern unsigned char uUsbState;
extern unsigned char uUsbType;
extern unsigned char bit_map;

void ResumeUsb();
void UsbDeInit();
void UsbInit(BYTE UsbType);

void Ep0_Send_Table( BYTE* lpszBuf, uint16 uSize );
void Ep1_Send( BYTE* lpszBuf, BYTE uSize );
void Ep2_Send( BYTE* lpszBuf, BYTE uSize );
void usb_key_report( BYTE modifier, BYTE key );

#endif
