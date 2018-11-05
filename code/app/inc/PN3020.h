
#ifndef __PN3020_H__
#define __PN3020_H__

#include "PN3020_Def.h"

#define PN3020_CS				SPI_CS_PIN
#define PN3020_PKT				PKT_PIN
#define PN3020_CE				CE_PIN
#define DUMMY_BYTE				0x00
#define RF_FIFO_MAX				32

#define RF_AUTO_ACK
#define RF_ACK_PLD
#define RF_DATA_RATE            RF_RATE_40K//RF_RATE_200K//

#define RF_IRQ_FLAGS            (_RX_DR | _TX_DS | _MASK_MAX_RT)

#define FLUSH_RX                0x01
#define FLUSH_TX                0x02
#define FLUSH_ALL               0x03

#define RF_CE_SOFT

#ifdef  RF_CE_SOFT
#define RF_CE_SET_LOW           pn3020_set_ce_0();
#define RF_CE_SET_HIGH          pn3020_set_ce_1();
#else
#define RF_CE_SET_LOW           PN3020_CE = 0;
#define RF_CE_SET_HIGH          PN3020_CE = 1;
#endif

#ifndef _SPI_HARDWARE
#define pn3020_spi_send(a)		spi_send_1byte(a)
#define pn3020_spi_recv(a)		spi_recv_1byte()
#define	pn3020_spi_mode(a)		;/##/
#define pn3020_spi_reset()		;/##/
//#define RF_CE_SOFT
#else
#ifdef _RF_HOST
#define pn3020_spi_no			S1
#else
#define pn3020_spi_no			S1//S0
#endif
#define pn3020_spi_send(a)		serial_tx_data(pn3020_spi_no, a)
#define pn3020_spi_recv(a)		serial_rx_data(pn3020_spi_no)
#define	pn3020_spi_mode(a)		serial_mode(pn3020_spi_no, a)
#define pn3020_spi_reset()		serial_reset(pn3020_spi_no)
#endif

#define mcu_goto_idle			mcu_hold

#if 0
typedef enum _RF_D_RATE
{
    RF_RATE_40K,
    RF_RATE_80K,
    RF_RATE_200K,
    RF_RATE_400K,
}RF_D_RATE;
#else
#define RF_RATE_40K             0
#define RF_RATE_200K            1
#endif /* 0 */

typedef enum _RF_DIR
{
	RF_TRANSFER = 0,
	RF_RECEIVER
}RF_DIR;

typedef struct _RF_CONTROL
{
	UINT8 ch_no;
//	UINT8 ch_index : 3;
//	UINT8 pipe_index : 5;

//	UINT8 mac[4];
	//UINT16 rf_power;
}RF_CONTROL;

extern idata RF_CONTROL pn3020;

BOOL pn3020_init(void);
void pn3020_goto_idle(void);
void pn3020_goto_sleep(void);
void pn3020_goto_wakeup(void);
void pn3020_set_channel(UINT8 rf_ch);
void pn3020_channel_conf(UINT8 Fb, UINT8 Fc);
void pn3020_set_mac(UINT8 *mac);
void pn3020_read_1byte(UINT8 reg_addr, UINT8 *reg_dat);

void pn3020_goto_tx(void);
void pn3020_goto_rx(void);
void pn3020_tx_start(void);
void pn3020_rx_start(void);
void pn3020_tx_mode(void);
void pn3020_rx_mode(void);
UINT8 pn3020_get_irq_flag(void);
void pn3020_clear_irq_flag(UINT8 irq_flag);


BOOL pn3020_transceive (
	RF_DIR rf_dir, UINT8 t_out,
	UINT8 *tx_src, UINT8 tx_len,  
	UINT8 *rx_dst, UINT8 dst_len, UINT8 *rx_len
);

void RF_Carrier(void);

#endif /* __PN3020_H__ */


