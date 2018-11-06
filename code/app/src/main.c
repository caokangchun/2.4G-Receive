
//#message "OUR3025+xn297l Based 2.4G Wireless Sacnner"

/**
  ******************************************************************************
  * @file    	Project/code/app/src/main.c
  * @author		Sycreader
  * @version	V1.0
  * @date		2015.02.07
  ******************************************************************************
  * @project 	OUR3025 Based Wireless Data Transfer
  * @COPYRIGHT 	Shenzhen Sycreader RFID Co.Ltd
  ******************************************************************************
  */

#include "includes.h"

   UINT8 xxx[]=	"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\r";




int main(void)
{
	mcu_init();
	//at24cxx_init();
	    
#ifdef _RF_HOST
	rf_host.beep = TRUE;
	rf_host.status = RF_ONLINE;
#else // RF_SLAVE
	rf_slave.status = RF_INITED;
	rf_slave.pkt_id = INIT_ID;
    //usb_connect();
    UsbInit(uUsbType);
#endif

	EA = 1;
	
    if(rf_init())
    {
	    // RF init OK.
	    beep_ctrl(2, 100);
    }
    
#ifdef RF_CARRIER
    RF_Carrier(0);
    //rf_host.status = RF_OFFLINE;
#endif /* RF_CARRIER */

	while(1)
	{
		watchdog_feed();
		
	#ifdef _RF_HOST
		switch(rf_host.status)
		{
			case RF_ONLINE:
				/* rf tx uart data */
				uart_to_rf();
				
				/* check battery */
				bat_pwr_check();
				break;

			case RF_PWR_OFF:
				/* rf power down */
				low_power_mode();
				rf_host.status = RF_ONLINE;
				break;
				
			default:
				break;
		}
	#else /* _RF_SLAVE */
		switch(rf_slave.status)
		{
            #if 0//def _USB_CMD
			case RF_HIDCON:
				usb_int_disable();
				rf_hid_cmd();
				usb_int_enable();
				rf_slave.status = RF_ONLINE;
				break;
            #endif /* _USB_HID */
            
			case RF_ONLINE:
				/* usb send rf data */
				rf_to_usb(DATA_MODE);

			   /*≤‚ ‘*/
//					usb_key_send(xxx,sizeof(xxx),2);
//					delay_1ms(800);


//					ReceiveCompleteAck();

				/*≤‚ ‘end*/
				break;

			case RF_CONFIG:
				/* slave power on init */
				rf_slave_config();
				rf_slave.status = RF_ONLINE;
				break;

			case RF_INITED:
    			//if(usb_connected())
    			rf_slave.status = RF_CONFIG;
			    break;
				
			case RF_UPD_S:
			    rf_slave_update();
				rf_slave.status = RF_ONLINE;
			    break;
				
			default:
				break;
		}
	#endif
	}
}


