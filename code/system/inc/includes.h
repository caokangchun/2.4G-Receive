
#ifndef __INCLUDES_H__
#define __INCLUDES_H__


/* main includes ---------------------------------------------------------------*/
#include <string.h>
#include "CV8F5025.h"
#include "typedef.h"
#include "main.h"
#include "interrupt.h"

/* driver includes -------------------------------------------------------------*/
#include "drv_clock.h"
#include "drv_gpio.h"
#include "drv_uart.h"
#include "drv_timer.h"
#include "drv_pwm.h"
#include "drv_adc.h"
#include "drv_serial.h"
#include "drv_flash.h"
#include "drv_watchdog.h"
#include "drv_i2c_simulate.h"
#include "drv_spi_simulate.h"

#include "usb.h"
#include "usb_descript.h"

/* system includes -------------------------------------------------------------*/
#include "delay.h"
#include "initial.h"
#include "it_config.h"
#include "checkout.h"

/* user includes ---------------------------------------------------------------*/
#include "usb_app.h"
#include "uart2usb.h"
#include "at24cxx.h"
#include "xn297l.h"
#include "rf.h"
#include "rf_cmd.h"


#endif /*end of __INCLUDES_H__ */

