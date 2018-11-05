
#ifndef _USB_APP_H_
#define _USB_APP_H_

#define _HID_CMD_LEN        256
#define _CMD_STX_LEN        8

/* usb SETUP struct */
typedef struct _usb_setup
{
	UINT8 bmRequestType;
	UINT8 bRequest;
  	UINT8 wValue_l;
  	UINT8 wValue_h;
  	UINT8 wIndex_l;
  	UINT8 wIndex_h;
  	UINT8 wLength_l;
  	UINT8 wLength_h;
}usb_setup;

typedef struct _usb_report_s
{
    UINT8 rpt_flag;
	UINT8 dat_total;
	UINT8 dat_index;
	UINT8 dat_buff[_HID_CMD_LEN];
	UINT16 time_out;
}usb_report_s;

typedef enum _usb_hid_cmd
{
    HALT_CMD    = 0x06,
	SET_SNR 	= 0x82,
	GET_SNR 	= 0x83,
	WR_USRINFO  = 0x84,
	READ_CARD   = 0x25,
	AUTO_READ 	= 0x0F,
	SET_BUZZER 	= 0x89,
	SET_LED 	= 0x88,
	UPD_SLAVE   = 0xF0,
	UPD_HOST    = 0xF1,
    // IAP Command
    IAP_JUMP_S  = 0xA0,
    IAP_STAT_S  = 0xA1,
    IAP_DATA_S  = 0xA2,
    IAP_FAIL_S  = 0xA3,
    IAP_EXIT_S  = 0xA4,
    IAP_JUMP_H  = 0xB0,
    IAP_STAT_H  = 0xB1,
    IAP_DATA_H  = 0xB2,
    IAP_FAIL_H  = 0xB3,
    IAP_EXIT_H  = 0xB4,
}usb_hid_cmd;

typedef enum _usb_hid_resp
{
	STATUS_OK 	= 0x00,
	STATUS_ERR 	= 0x01,	
	SET_OK		= 0x80,
	SET_ERR		= 0x81,
	NOT_EXIST 	= 0x83,
	PARA_ERR  	= 0x89,
	CMD_ERR   	= 0x8F
}usb_hid_resp;

extern xdata usb_report_s usb_report;// _at_ 0x8200;

void usb_report_out(UINT8 dat_cnt);
void usb_report_in(void);

void usb_int_disable(void);
void usb_int_enable(void);

BOOL usb_key_send(UINT8 *send_buff, UINT16 length, UINT8 type);

#endif /* _USB_APP_H_ */

