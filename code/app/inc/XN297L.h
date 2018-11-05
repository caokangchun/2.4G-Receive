
#ifndef __BK2425_H__
#define __BK2425_H__

#include "XN297L_Def.h"

#define XN297L_CS				SPI_CS_PIN
#define XN297L_PKT				PKT_PIN
#define XN297L_CE				CE_PIN
#define DUMMY_BYTE				0x00

#define RF_250KBPS
#ifdef RF_250KBPS
#define _RF_RATE				_RF_DR_250K
#define RF_FIFO_MAX				16
#else
#define _RF_RATE				_RF_DR_1M
#define RF_FIFO_MAX				32
#endif

#define _RF_POWER               (_PA_GC_L1 | _RF_PA_PWR_L7) // 10dBm=0x0F

#define RF_CE_PKT_SOFT

#ifndef _SPI_HARDWARE
#define xn297l_spi_send(a)		spi_send_1byte(a)
#define xn297l_spi_recv(a)		spi_send_1byte(a)
#define	xn297l_spi_mode(a)		//;/##/
#define xn297l_spi_reset()		//;/##/
#else
#ifdef _RF_HOST
#define xn297l_spi_no			S1
#else
#define xn297l_spi_no			S1//S0
#endif
#define xn297l_spi_send(a)		serial_tx_data(xn297l_spi_no, a)
#define xn297l_spi_recv(a)		serial_rx_data(xn297l_spi_no)
#define	xn297l_spi_mode(a)		serial_mode(xn297l_spi_no, a)
#define xn297l_spi_reset()		serial_reset(xn297l_spi_no)
#endif

#define mcu_goto_idle			mcu_hold

typedef struct _BK2425_BANK0
{
	UINT8 addr;
	UINT8 dat;
}BK2425_BANK0;

typedef struct _BK2425_BANK1
{
	UINT8 addr;
	UINT32 dat;
}BK2425_BANK1;

typedef enum _RF_DIR
{
	RF_TRANSFER = 0,
	RF_RECEIVER
}RF_DIR;

typedef struct _RF_CONTROL
{
	UINT8 ch_no;
	UINT8 ch_index;// : 3;
	UINT8 pipe_index;// : 5;

	UINT8 mac[4];
	//UINT16 rf_power;
}RF_CONTROL;

extern idata RF_CONTROL xn297l;

BOOL xn297l_init(void);
void xn297l_goto_sleep(void);
void xn297l_goto_wakeup(void);
void xn297l_set_channel(UINT8 rf_ch);
void xn297l_set_mac(UINT8 *mac);
void xn297l_read_1byte(UINT8 reg_addr, UINT8 *reg_dat);

BOOL xn297l_transceive (
	RF_DIR rf_dir, UINT8 pwr_ctrl, UINT8 t_out,
	UINT8 *tx_src, UINT8 tx_len,  
	UINT8 *rx_dst, UINT8 dst_len, UINT8 *rx_len
);

void RF_Carrier(UINT8 ucChannel_Set);

#endif /* __BK2425_H__ */


