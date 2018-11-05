
#include "includes.h"

code UINT8 rf_ack[ACK_R][ACK_C] =
{
	STX, 0x01, 0xFE, ETX, 
	STX, 0x02, 0xFD, ETX, 
	STX, 0x03, 0xFC, ETX, 
	STX, 0x04, 0xFB, ETX, 
};

code UINT8 rf_ch_list[PIPE_INDEX_MAX+1][CH_INDEX_MAX] = 
{
#if 0
    2, 34,62,
    5, 37,65,
    13,41,73,
    15,43,75,

    4, 64,92, 
    //7, 67,95, 
    31,91,103,
    16,76,98, 
    18,78,100,

    17,32,77,
    20,35,80,
    23,38,83,
    28,40,88,

    19,79,94, 
    22,82,97, 
    26,86,101,
    31,91,103,

    31,91,103,
    31,91,103,
    31,91,103,
    31,91,103,

    31,91,103,
    31,91,103,
    31,91,103,
    31,91,103,
    31,91,103,
    
	8, 8, 8, // Sync channel
#else
    0, 25,50,
    1, 26,51,
    2, 27,52,
    3, 28,53,

    4, 29,54, 
    5, 30,55, 
    6, 31,56, 
    7, 32,57,

    8, 33,58,
    9, 34,59,
    10,35,60,
    11,36,61,

    12,37,62, 
    13,38,63, 
    14,39,64,
    15,40,65,

    16,41,66,
    17,42,67,
    18,43,68,
    19,44,69,

    20,45,70,
    21,46,71,
    22,47,72,
    23,48,73,
    24,49,74,

	80,80,80, // Sync channel
#endif
};


//---------------------------------------------------------------------------------------
//	Description	: 	rf change to next channel
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
static void rf_goto_next_ch(void)
{
	xn297l.ch_index++;

	/* get next channel index */
	if(xn297l.ch_index == CH_INDEX_MAX)
	{
		xn297l.ch_index = 0;
	}
}


//---------------------------------------------------------------------------------------
//	Description	: 	rf change to next pipe
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
#if 0
static void rf_goto_next_pipe(void)
{
	xn297l.pipe_index++;

	/* get next channel index */
	if(xn297l.pipe_index == PIPE_INDEX_MAX)
	{
		xn297l.pipe_index = 0;
	}
}
#else
void rf_set_pipe(UINT8 pipe_x)
{
	xn297l.pipe_index = pipe_x;// & 0x0F;
}
#endif


//---------------------------------------------------------------------------------------
//	Description	: 	rf channel no
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
static void rf_get_ch_no(void)
{
	xn297l.ch_no = rf_ch_list[xn297l.pipe_index][xn297l.ch_index];
}


//---------------------------------------------------------------------------------------
//	Description	: 	rf channel no
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
UINT8 rf_set_ch(void)
{
	UINT8 ch_no;
	
	/* rf goto next channel */
	rf_goto_next_ch();

	/* rf get ch no */
	rf_get_ch_no();

	/* set rf channel */
	xn297l_set_channel(xn297l.ch_no);

	/* read out current rf ch no */
	xn297l_read_1byte(REG_RF_CH | CMD_R_REGISTER, &ch_no);

	return ch_no;
}

code UINT8 mac_dat[4] = {0xFF, 0xFF, 0xFF, 0xFF};
//---------------------------------------------------------------------------------------
//	Description	: 	rf get mac
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2016 - 06 - 02
//---------------------------------------------------------------------------------------
void rf_get_mac(UINT8 *mac)
{
#if 0
	memcpy(mac, mac_dat, 4);
#else
    UINT8 snr[8];
    RdSerialNum(snr);
    memcpy(mac, &snr[4], 4);
#endif /* 0 */
}

//---------------------------------------------------------------------------------------
//	Description	: 	rf set mac
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2016 - 06 - 02
//---------------------------------------------------------------------------------------
void rf_set_mac(UINT8 *mac)
{
	xn297l_set_mac(mac);
}

//---------------------------------------------------------------------------------------
//	Description	: 	rf init
//	Parameters 	: 	none
//	Return 		: 	true/false - init success/fail
//	Author 		: 	RAY
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
BOOL rf_init(void)
{
	UINT8 i;
	
#ifndef _SPI_HARDWARE
	//spi_half_duplex_init(); // mode 0, 1
	spi_init();
#else
	serial_baud(xn297l_spi_no, SPEED_3M);
#endif

	rf_get_mac(xn297l.mac);
	rf_set_pipe((xn297l.mac[3] + 1) % PIPE_INDEX_MAX);

	/* try init rf for 3 times */
	for(i = 0; i < 3; i++)
	{
		if(xn297l_init())
		{	
			//printf("rf init ok.\r\n");
			//uart0_send_byte('O');
			//uart0_send_byte('K');
            rf_set_ch();
			xn297l_goto_sleep();
			//RF_Carrier(8);
			return TRUE;
		}

		delay_1ms(10);
	}

#if 0
	while(1); // for reset
#endif
	return FALSE;
}


//---------------------------------------------------------------------------------------
//	Description	: 	rf send data
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
BOOL rf_transceiver (
	RF_DIR rf_dir, UINT8 t_out,
	UINT8 *tx_src, UINT8 tx_len,
	UINT8 *rx_dst, UINT8 dst_len, UINT8 *rx_len
)
{
	BOOL flag = FALSE;

	/* rf wakeup first */
	xn297l_goto_wakeup();

	while(1)
	{
		flag = xn297l_transceive(rf_dir, 0, t_out, \
								 tx_src, tx_len, \
								 rx_dst, dst_len, rx_len);
		//printf("*");
        //uart_send_byte('*');
		
	#ifdef _RF_HOST
		/* rx ack ok */
		if(flag)
		{
			break;
		}


		/* rf send timeout */
		if(rf_tx_tout(TX_OUT))
		{
			break;
		}
	#else // _RF_SLAVE
		/* wait untill receive data */
		if(flag)
		{
			break;
		}
		
		/* rf recv timeout */
		if(rf_rx_tout())
		{
			break;
		}
	#endif
		
		rf_set_ch();
		
		watchdog_feed();
	}
	
	/* rf goto sleep */
	xn297l_goto_sleep();

	return flag;
}


