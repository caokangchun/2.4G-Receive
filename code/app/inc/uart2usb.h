
#ifndef __UART2USB_H__
#define __UART2USB_H__

#define MAX_BUFF	1600//1024//64//48
#define T_OUT_MAX 	10 // MS
#define RF_TX_TOUT	15 // MS
#define RF_RX_TOUT	80 // MS

#define RF_IDLE_TOUT 	60*1000	 	// idle for sleep
#define RF_SEND_TOUT	1*1000		// tx data timeout
#define RF_RECV_TOUT	600//1*1000	// rx data timeout

#define INIT_MODE		0
#define DATA_MODE		1
#define INIT_ID			0x10//0x20//0x08//0x80
#define ID_MASK         0x1F

typedef enum
{
	TYPE_ID,
	TYPE_DATA
}RECV_TYPE;

typedef enum
{
	RECV_IDLE,
	RECV_DATA,
	RECV_STOP,
	RECV_OVER
}RECV_STATUS;

typedef struct
{
	RECV_STATUS state : 3;
	UINT8 data_ok : 1;
	UINT8 time_out;
	UINT8 index;
	UINT8 index_tmp;
	UINT8 buff[MAX_BUFF];
	UINT8 buff_tmp[MAX_BUFF-3];
}UART_RECV;

typedef enum
{
	TX_OUT = 0,
	IDLE_OUT,
	INIT_OUT,
}TIME_OUT;

typedef enum
{
	ADD_NONE = 0,
	ADD_TAB,
	ADD_BLANK,
	ADD_LINE,
    ADD_NOT,
}ADD_TYPE;

typedef struct
{
	UINT16 tx_out;		// 1 tx data
	UINT16 idleout;		// sys idle
	UINT8 status;		// rf state

	UINT8 store_flag;
	UINT16 store_addr;	// store+init
	UINT16 cur_addr;	// init
	UINT16 up_addr;		// no init

	UINT16 total_num; 	// store+init
	UINT16 cur_num;		// reset
	UINT16 up_num;		// no init

	UINT8 beep;			// beep flag
	UINT8 pid;			// product id + store

	UINT8 same_flag;	// same data + store
	UINT16 same_out;	// same tine out
	UINT16 same_time;	// same time

	UINT8 rx_init;		// slave init
}RF_HOST;

typedef struct
{
	UINT16 rx_tout;			// rx data
	UINT16 clear_t;			// reset id
	UINT8 status;// : 3;	// rf state
	UINT8 pipe_bak;// : 4;	// for init
	
	UINT8 add_type;// : 2;	// init + store
	UINT8 pid_flag;// : 1;	// store

	UINT8 pkt_id;			//
	UINT8 pid;				// store
	UINT8 buff[MAX_BUFF];	//
}RF_SLAVE;

#if 0
#define rf_slave_config()\
do{\
	rf_slave.pipe_bak = xn297l.pipe_index;\
	xn297l.pipe_index = 16;\
	rf_set_ch();\
	rf_to_usb(INIT_MODE);\
	xn297l.pipe_index = rf_slave.pipe_bak;\
	rf_set_ch();\
}while(0);
#else
void rf_slave_config(void);
#endif /* 0 */

extern idata UART_RECV uart;
extern idata RF_HOST rf_host;
extern xdata RF_SLAVE rf_slave;

void uart_receive(UINT8 dat);
void uart_to_usb(void);
BOOL uart_to_rf(void);
BOOL rf_to_usb(UINT8 mode);
BOOL rf_tx_tout(TIME_OUT mode);
BOOL rf_rx_tout(void);
BOOL rf_host_send(void);
void rf_slave_update(void);

#endif /* __UART2USB_H__ */

