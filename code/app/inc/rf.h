
#ifndef __RF_H__
#define __RF_H__

#define STX					0x02
#define ETX					0x03
#define ACK_R				4
#define ACK_C				4
#define CH_INDEX_MAX		3
#define PIPE_INDEX_MAX		25

extern code UINT8 rf_ack[ACK_R][ACK_C];

typedef enum _RF_STATE
{
	RF_OFFLINE = 0,
	RF_ONLINE,
	RF_CONFIG,
	RF_INITED,
	RF_PWR_OFF,
	RF_UPD_S,
}RF_STATE;

BOOL rf_init(void);
void rf_auto_match(void);
void rf_ping_check(void);
void rf_send_data(void);
void rf_receive_data(void);
void rf_set_pipe(UINT8 pipe_x);
UINT8 rf_set_ch(void);
void rf_get_mac(UINT8 *mac);
void rf_set_mac(UINT8 *mac);

BOOL rf_transceiver (
	RF_DIR rf_dir, UINT8 t_out,
	UINT8 *tx_src, UINT8 tx_len,
	UINT8 *rx_dst, UINT8 dst_len, UINT8 *rx_len
);

#endif /* end of __RF_H__ */


