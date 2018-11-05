
#ifndef __MAIN_H__
#define __MAIN_H__

#define SYS_6MHZ        6*1000000UL
#define SYS_12MHZ       12*1000000UL
#define SYS_24MHZ       24*1000000UL

/*----------------- user define --------------------------*/
#if 0//def _IAR_RF_HOST
  #define SYS_CLK		SYS_12MHZ//SYS_6MHZ//	  // CPU clock
  #define _RF_HOST
  #define _AT24C256
  #define _UART_EN
#else
  #define SYS_CLK		SYS_24MHZ   // CPU clock
  #define _RF_SLAVE
  #define _AT24C02
  #define _USB_FUNC
  #define _UART_EN
#endif

#define PERIPH_CLK		(SYS_CLK*2)

//#define _EXT_OSC

#define _UART2USB
#define _UART_TX
#define _USB_TX
//#define _SPI_HARDWARE

#define _USB_HID
#define _USB_CMD
//#define _HID_KEYBOARD
//#define _HID_VENDER
#define _USB_VCOM

//#define _PRINTF
#define DC_BUZZER
//#define RF_CARRIER
#define _RF_ACK_PLD

#define MAC0    0x5F
#define MAC1    0x6E
#define MAC2    0x7D
#define MAC3    0x8C

#define VERSION     "SYC:3025-XN297L-160504"

#endif /* end of __MAIN_H__ */

