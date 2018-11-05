
#include "includes.h"


#ifdef _UART2USB

//0xaa,spid,reserve,0x55
static uint8_t spidAck[4]={0xaa,0,0,0x55};

typedef struct
{
	UINT8 prefix1;
	UINT8 prefix2;
	UINT8 sid;
	UINT8 crc;
}CMD_UPLOAD;

static unsigned char crc_high_first(unsigned char *ptr, unsigned char len)
{
    unsigned char i; 
    unsigned char crc=0x00; /* 计算的初始crc值 */ 

    while(len--)
    {
        crc ^= *ptr++;  /* 每次先与需要计算的数据异或,计算完指向下一数据 */  
        for (i=8; i>0; --i)   /* 下面这段计算过程与计算一个字节crc一样 */  
        { 
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x31;
            else
                crc = (crc << 1);
        }
    }

    return (crc); 
}

static BOOL	isCmdPkt(unsigned char *ptr, unsigned char len)
{
	//判断长度
	//判断前序
	//判断crc
	CMD_UPLOAD *cmdPtr = (CMD_UPLOAD*)ptr;
	UINT8 crc;
	
//	if(len != sizeof(CMD_UPLOAD))
//	{
//		return FALSE;
//	}

	if((cmdPtr->prefix1 != 0xfe) || (cmdPtr->prefix2 != 0xef))
	{
		return FALSE;
	}

//	crc = crc_high_first(ptr,len);
//	if(crc != cmdPtr->crc)
//	{
//		return FALSE;
//	}

	return TRUE;
	
}




static BOOL checkData(unsigned char *ptr, UINT16 len)
{
	UINT8 crc;
	
	crc = crc_high_first(ptr,len-1);
	if(crc == ptr[len-1])
	{
		return TRUE;
	}

	return FALSE;
}

static BOOL ReceiveCompleteAck(UINT8 pid)
{
	UINT8 ack_tmp[4],ack_len,n=2;

	spidAck[1] = pid;	//写入回复信息中
	rf_slave.rx_tout = 0;


//	while(n--)
	{
		rf_slave.rx_tout = 0;
		//rf_transceiver(RF_TRANSFER, 1,spidAck, 4, ack_tmp, sizeof(ack_tmp), &ack_len); //发送响应	
		rf_transceiver(RF_RECEIVER, RF_RX_TOUT, spidAck, sizeof(spidAck), ack_tmp, RF_FIFO_MAX, &ack_len);
	}
		
}



#ifdef _RF_HOST

idata UART_RECV uart = {0};
idata RF_HOST rf_host = {0};

//------------------------------------------------------------------------
//	Description	: 	UART receive data
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
void uart_receive(UINT8 dat)
{	
	uart.time_out = T_OUT_MAX;

	switch(uart.state)
	{
		case RECV_IDLE:
			if(uart.data_ok != TRUE)
			{
				//uart.index = 3;
				uart.index_tmp = 0;
				uart.state = RECV_DATA;
			}
			else
			{
				uart.state = RECV_STOP;
				break;
			}
			
		case RECV_DATA:
			if(uart.index_tmp >= (MAX_BUFF-3))
			{
				uart.state = RECV_STOP;
			}
			else
			{
				uart.buff_tmp[uart.index_tmp++] = dat;
			}
			break;
			
		case RECV_STOP:
			/* discard data */
			break;

		default:
			uart.state = RECV_IDLE;
			break;
	}
}


//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL rf_tx_tout(TIME_OUT mode)
{
	BOOL flag = FALSE;
	
	switch(mode)
	{
		case TX_OUT:
			if(rf_host.tx_out > RF_SEND_TOUT) // tx time out
			{
				// tx timeout
				printf("tx tout.\r\n");
				flag = TRUE;
			}
			else
			{
				if(rf_host.rx_init)
				{
					flag = TRUE;
				}
			}
			break;

		case IDLE_OUT:
			if(rf_host.idleout > RF_IDLE_TOUT) // idle time out
			{
				// goto sleep
				rf_host.status = RF_PWR_OFF;
				
				printf("idle tout.\r\n");
				flag = TRUE;
			}
			break;

		case INIT_OUT:
			flag = TRUE;
			break;
			
		default:
			break;
	}

	return flag;
}

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL rf_host_send(void)
{
	BOOL status = FALSE;
	UINT8 ack_tmp[4];
	UINT8 ack_len;
	static UINT8 pkt_id = 0;

	/* clear tx timeout */
	rf_host.tx_out = 0;

	/* packet id counter */
	uart.buff[1] = pkt_id & 0x7F;
	pkt_id++;

RF_TRANSMIT:

	/* rf need to send 2 packets */
	if(uart.index > RF_FIFO_MAX)
	{
		status = rf_transceiver(RF_TRANSFER, RF_TX_TOUT, uart.buff, RF_FIFO_MAX, \
								ack_tmp, sizeof(ack_tmp), &ack_len);
												
		if(status) // tx ok, no timeout
		{
        #ifdef _RF_ACK_PLD
			status = !memcmp(ack_tmp, rf_ack, sizeof(rf_ack));
            #if 1
            if(!status) // ack fail, re-transmit
            {
                if(rf_tx_tout(TX_OUT))
                {
                    goto RF_TRANSMIT;
                }
            }
            #endif /* 0 */
        #endif /* _RF_ACK_PLD */
			
			if(status) // rx ack ok
			{
				status = rf_transceiver(RF_TRANSFER, RF_TX_TOUT, &uart.buff[RF_FIFO_MAX], \
										uart.index - RF_FIFO_MAX, ack_tmp, sizeof(ack_tmp), &ack_len);
			}
		}	
	}
	else
	{
		status = rf_transceiver(RF_TRANSFER, RF_TX_TOUT, uart.buff, uart.index, \
								ack_tmp, sizeof(ack_tmp), &ack_len);
	}
	
	if(status) // tx ok, no timeout
	{
	#ifdef _RF_ACK_PLD
		status = !memcmp(ack_tmp, rf_ack, sizeof(rf_ack));
        #if 1
        if(!status) // ack fail, re-transmit
        {
            if(rf_tx_tout(TX_OUT))
            {
                goto RF_TRANSMIT;
            }
        }
        #endif /* 0 */
	#endif /* _RF_ACK_PLD */
	}

	if(status) // rx ack ok, tx success
	{
		rf_host.idleout = 0; // clear idle cnt
	}

	return status;
}


//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL check_same_code(void)
{
	BOOL flag = FALSE;
	
	if(rf_host.same_flag)
	{
		UINT8 tmp;
		UINT8 len;
		UINT8 i = 0;
		
		flag = TRUE;
		len = uart.index - 3; // no cnt & pkt & pid
		
		at24cxx_read(LAST_DATA, &tmp, 1);

		if(tmp != len)
		{
			flag = FALSE;
			at24cxx_write(LAST_DATA, &len, 1);
		}
		else
		{
			/* check if time out for same code is over */
			if(rf_host.same_out < rf_host.same_time)
			{
				for(i = 0; i < len; i++)
				{
					at24cxx_read(LAST_DATA + 1 + i, &tmp, 1);

					if(tmp != uart.buff[3 + i])
					{
						flag = FALSE;
						break;
					}
				}
			}
			else
			{
				flag = FALSE;
			}
		}
		
		// clear time out cnt
		rf_host.same_out = 0;

		if(!flag)
		{
			at24cxx_write(LAST_DATA + 1, (UINT8 *)&uart.buff[3], len);
		}
	}

	return flag;
}

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL store_code_data(void)
{
    #define E2_VOL_1    E2_VOLUME*9/10
    #define E2_VOL_2    E2_VOLUME*95/100
    
	BOOL flag = TRUE;
	UINT8 len;

    if(rf_host.store_addr > E2_VOL_2)
    {
    #if 0
        watchdog_feed();
        PCINT1 = ON;
        delay_1ms(250);
        delay_1ms(250);
        PCINT1 = OFF;
        watchdog_feed();
    #else
        beep_ctrl(1, 500);
    #endif /* 0 */
        return FALSE;
    }
    else
    {
        if(rf_host.store_addr > E2_VOL_1)
        {
        #if 0
            watchdog_feed();
            PCINT1 = ON;
            delay_1ms(250);
            PCINT1 = OFF;
            watchdog_feed();
        #else
            beep_ctrl(1, 250);
        #endif /* 0 */
            //return FALSE;
        }
    }
    
	//len = uart.index - 2; // no cnt & pid
	len = uart.buff[0] - 2; // no cnt & pid
	uart.buff[2] = len; // pid -> len

	rf_host.cur_num++;
	rf_host.total_num++;
	at24cxx_write(TOTAL_NUM, (UINT8 *)&rf_host.total_num, 2);
	
	printf("T=%d,Cur=%d\r\n", (UINT16)rf_host.total_num, (UINT16)rf_host.cur_num);

	at24cxx_write(rf_host.store_addr, (UINT8 *)&uart.buff[2], len);
	
	rf_host.store_addr += len;
	at24cxx_write(STORE_ADDR, (UINT8 *)&rf_host.store_addr, 2);

	rf_host.idleout = 0; // clear idle cnt
	return flag;
}

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
void rf_slave_init(void)
{
	UINT8 rf_pipe_bak;
	UINT8 tx_cnt = 0;
	
	rf_pipe_bak = xn297l.pipe_index;
	xn297l.pipe_index = 16;
	rf_set_ch();

	uart_int_disable();

	while(1)
	{
		if(rf_host_send())
		{
			break;
		}
		else
		{
			if(++tx_cnt > 6)
			{
				tx_cnt = 0;
				
				if(rf_host.beep)
				{
					beep_ctrl(1, 80);
                    delay_1ms(60);
				}
			}
		}

		if(rf_tx_tout(IDLE_OUT))
		{
			break;
		}

		if(UART_INT_FLAG)
		{
			//uart_rx_disable();
			uart_disable();
			UOR = 0;
			URF = 0;
			break;
		}
	}
	
	rf_host.rx_init = FALSE;
	xn297l.pipe_index = rf_pipe_bak;
	rf_set_ch();

	uart_int_enable();
	uart_enable();
}

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL uart_to_rf(void)
{
	BOOL status = FALSE;
	
	if(uart.data_ok)
	{
	    //__disable_interrupt();
	    //uart_int_disable();
        uart.index = uart.index_tmp;
	    memcpy(&uart.buff[3], uart.buff_tmp, uart.index);
        uart.data_ok = FALSE;
        //__enable_interrupt();
        //uart_int_enable();

        uart.index += 3;

		/* tx total bytes */
		uart.buff[0] = uart.index;

		/* tx host id number */
		uart.buff[2] = rf_host.pid;
		
		printf("host get data.\r\n");
		#if 0
		{
			UINT8 i;
			
			for(i = 0; i < uart.buff[0]-3; i++)
			{
				//printf("-%x", (UINT16)uart.buff[i]);
				uart_send_byte(uart.buff[3+i]);
			}
			//printf("\r\n");
			//uart_send_byte(0x0a);
		}
		#endif
	
		watchdog_feed();

		if(rf_host_cmd(uart.buff) != TRUE)
		{
			UINT8 beep_cnt = 0;
			
			if(rf_host.store_flag)
			{
				if(check_same_code() != TRUE)
				{
					/* store diff code */
					beep_cnt = 0;
					store_code_data();
				}
				else
				{
					beep_cnt = 5;
				}
			}
			else
			{
				if(check_same_code() != TRUE)
				{
					if(rf_host_send() != TRUE)
					{
						/* store diff code */
						beep_cnt = 3;
						store_code_data();
					}
					else
					{
						beep_cnt = 1;
					}
					
					// enable data rx
                    //uart.data_ok = 0;
				}
				else
				{
					beep_cnt = 5;
				}
			}

			if(rf_host.beep)
			{
				beep_ctrl(beep_cnt, 80);
			}
		}
		else
		{
			if(rf_host.rx_init) // slave data
			{
				rf_slave_init();
			}
		}

		watchdog_feed();
		//uart.data_ok = 0;
	}
	else
	{
		//printf(".");
		mcu_goto_idle();
		rf_tx_tout(IDLE_OUT); // idle timeout
	}
	
	return status;
}

#endif

#ifdef _RF_SLAVE

xdata RF_SLAVE rf_slave = {0};// _at_ 0xA8;//

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL rf_rx_tout(void)
{
	if(rf_slave.rx_tout > RF_RECV_TOUT) // rx time out
	{
		printf("rx tout.\r\n");
		return TRUE;
	}

	return FALSE;
}

//------------------------------------------------------------------------
//	Description	: 	data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
void usb_data_proc(UINT8 mode, UINT8 *data_buff)
{
	if(rf_slave.pkt_id != (data_buff[1] & 0x1F))
	{
		rf_slave.clear_t = RF_SEND_TOUT;
		
		if(mode != INIT_MODE)
		{
		    UINT8 crc_l = data_buff[data_buff[0]-1];
		    UINT8 crc_h = data_buff[data_buff[0]-2];

		    UINT16 crc = calc_crc16_ccitt(&data_buff[HEAD_LEN], data_buff[0]-HEAD_LEN-2);
		    
            if((((crc>>8) & 0xFF) == crc_h) && ((crc & 0xFF) == crc_l))
            {
    			UINT8 language;
    			
    			rf_slave.add_type = DAT_RIGHT(data_buff[1], 5);
    			//language = DAT_RIGHT(data_buff[1], 6);
    			language = data_buff[3];

                #if 0
    			if(language & 0x80)
    			{
    			    usb_key_send(NULL, 1, language & 0x80);
    				
    				/* Wait 1600Ms */
    				delay_1ms(250);
    				watchdog_feed();
    				delay_1ms(250);
    				watchdog_feed();
    				delay_1ms(250);
    				watchdog_feed();
    				delay_1ms(250);
    				watchdog_feed();
    				
    				delay_1ms(250);
    				watchdog_feed();
    				delay_1ms(250);
    				watchdog_feed();
    				delay_1ms(100);
    			}
                #endif /* 0 */
    			
    			//if(rf_slave.pid_flag)
    			if(rf_slave.add_type)
    			{
    				UINT8 tmp_dat[4];
    				UINT8 len = 0;
    				UINT8 tmp;
    				UINT8 host_id = data_buff[2]; 

    				tmp = host_id / 100;
    				if(tmp != 0)
    				{
    					tmp_dat[len++] = tmp + '0';
    				}

    				tmp = host_id % 100 / 10;
    				if((len != 0) || (tmp != 0))
    				{
    					tmp_dat[len++] = tmp + '0';
    				}

    				tmp_dat[len++] = host_id % 10 + '0';
    				
    				switch(rf_slave.add_type)
    				{
    					case ADD_TAB:
    						tmp_dat[len++] = 0x09/*hid_tab*/;
    						break;

    					case ADD_BLANK:
    						tmp_dat[len++] = 0x20/*hid_space*/;
    						break;

    					case ADD_LINE:
    						tmp_dat[len++] = 0x2D/*hid_underline*/;
    						break;

    				    case ADD_NOT:
    				        break;

    					default:
    						break;
    				}
    				
    				watchdog_feed();

    				/* send prefix for ID data */
    				usb_key_send(tmp_dat, len, language & 0x7F);
    			}

    			watchdog_feed();

    			/* send scan data from rf host ------------------------- */
    			usb_key_send(&data_buff[HEAD_LEN], data_buff[0]-HEAD_LEN-2, language & 0x7F);
			}
			else
			{
			    return;
			}
		}
		else
		{
			/* handle for init cmd */
			//rf_slave_cmd(data_buff);
		}
		
		rf_slave.pkt_id = data_buff[1] & 0x1F;
	}
}

//------------------------------------------------------------------------
//	Description	: 	data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
void usb_data_proc1(UINT8 mode, UINT8 *data_buff)	
{
//	if(rf_slave.pkt_id != (data_buff[3] & 0x1F))
	{
		rf_slave.clear_t = RF_SEND_TOUT;
		
		if(mode != INIT_MODE)
		{
			UINT8 language;
			UINT16 total_len;

			total_len = data_buff[1];
			total_len <<= 8;
			total_len += data_buff[2];

			//if(!usb_type_cmd(&data_buff[HEAD_LEN+2], total_len-(HEAD_LEN+2)))
			{
    			rf_slave.add_type = DAT_RIGHT(data_buff[3], 5);
    			language = data_buff[5];


    			watchdog_feed();

    			/* send scan data from rf host ------------------------- */
    			usb_key_send(&data_buff[HEAD_LEN+2], total_len - (HEAD_LEN+2)-1, language);		//-1  crc
			}
		}
	}
}
//void usb_data_proc1(UINT8 mode, UINT8 *data_buff)	
//{
//	if(rf_slave.pkt_id != (data_buff[3] & 0x1F))
//	{
//		rf_slave.clear_t = RF_SEND_TOUT;
//		
//		if(mode != INIT_MODE)
//		{
//			UINT8 language;
//			UINT16 total_len;
//
//			total_len = data_buff[1];
//			total_len <<= 8;
//			total_len += data_buff[2];
//
//			//if(!usb_type_cmd(&data_buff[HEAD_LEN+2], total_len-(HEAD_LEN+2)))
//			{
//    			rf_slave.add_type = DAT_RIGHT(data_buff[3], 5);
//    			language = data_buff[5];
//
//                #if 0
//    			if(language & 0x80)
//    			{
//    			    usb_key_send(NULL, 1, language & 0x80);
//    				
//    				/* Wait 1600Ms */
//    				delay_1ms(250);
//    				watchdog_feed();
//    				delay_1ms(250);
//    				watchdog_feed();
//    				delay_1ms(250);
//    				watchdog_feed();
//    				delay_1ms(250);
//    				watchdog_feed();
//    				
//    				delay_1ms(250);
//    				watchdog_feed();
//    				delay_1ms(250);
//    				watchdog_feed();
//    				delay_1ms(100);
//    			}
//                #endif /* 0 */
//    			
//    			//if(rf_slave.pid_flag)
//    			if(rf_slave.add_type)
//    			{
//    				UINT8 tmp_dat[4];
//    				UINT8 len = 0;
//    				UINT8 tmp;
//    				UINT8 host_id = data_buff[4]; 
//
//    				tmp = host_id / 100;
//    				if(tmp != 0)
//    				{
//    					tmp_dat[len++] = tmp + '0';
//    				}
//
//    				tmp = host_id % 100 / 10;
//    				if((len != 0) || (tmp != 0))
//    				{
//    					tmp_dat[len++] = tmp + '0';
//    				}
//
//    				tmp_dat[len++] = host_id % 10 + '0';
//    				
//    				switch(rf_slave.add_type)
//    				{
//    					case ADD_TAB:
//    						//tmp_dat[len++] = 0x09/*hid_tab*/;
//    						break;
//
//    					case ADD_BLANK:
//    						tmp_dat[len++] = 0x20/*hid_space*/;
//    						break;
//
//    					case ADD_LINE:
//    						tmp_dat[len++] = 0x2D/*hid_underline*/;
//    						break;
//
//    				    case ADD_NOT:
//    				        break;
//
//    					default:
//    						break;
//    				}
//    				
//    				watchdog_feed();
//
//    				/* send prefix for ID data */
//    				usb_key_send(tmp_dat, len, language);
//    			}
//
//    			watchdog_feed();
//
//    			/* send scan data from rf host ------------------------- */
//    			usb_key_send(&data_buff[HEAD_LEN+2], total_len - (HEAD_LEN+2), language);
//			}
//		}
//		else
//		{
//			/* handle for init cmd */
//			//rf_slave_cmd(data_buff);
//		}
//		
//		rf_slave.pkt_id = data_buff[3] & 0x1F;
//	}
//}

#ifdef RF_250KBPS
//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
//BOOL rf_to_usb(UINT8 mode)
//{
//	BOOL rx_ok;
//	UINT8 i;
//	UINT8 ulen;
//	UINT8 ack_data[4];
//	UINT8 bag_id;
//	UINT16 total_len = 0;
//	UINT8 *rx_index = NULL;
//
//	/* clear recv time out */
//	rf_slave.rx_tout = 0;
//
//	for(i = 0; i < 100; i++)
//	{
//	RF_RECEIVE:
//	    
//        watchdog_feed();
//	    
//		if(mode == INIT_MODE)
//		{
//			rf_get_mac(ack_data); // ack MAC to Host
//		}
//		else // DATA MODE
//		{
//			//my_memcpy(ack_data, (code_ptr *)&rf_ack[i][0], ACK_C);
//			memcpy(ack_data, &rf_ack[0][0], ACK_C);
//		}
//
//		rx_index = &rf_slave.buff[i*(RF_FIFO_MAX-1)];
//		
//		rx_ok = rf_transceiver(RF_RECEIVER, RF_RX_TOUT, ack_data, sizeof(ack_data), \
//							   rx_index, RF_FIFO_MAX, &ulen);
//
//		if(rx_ok) // get RF data
//		{
//			//uart_send_byte(rx_index[0]);
//			
//			/* clear rx time out */
//			rf_slave.rx_tout = 0;
//
//			/* get current data bag id */
//			bag_id = rx_index[0];
//
//			if((bag_id >= 1) & (bag_id <= 102)) // support 102 bag
//			{
//				if(bag_id == (i + 1)) // bag id is correct
//				{
//					memcpy(rx_index, rx_index + 1, ulen - 1); // shift left one byte
//					total_len += (ulen - 1);
//				}
//			#if 1
//				else if(bag_id == i) // bag id to be last one
//				{
//					// receive again
//					goto RF_RECEIVE;
//				}
//			#endif /* 0 */
//				else // bag id is incorrect
//				{
//					rx_ok = 0;
//					break;
//				}
//			}
//			else // bag id is incorrect
//			{
//				rx_ok = 0;
//				break;
//			}
//		}
//		else
//		{
//			break; // RF rx timeout
//		}
//
//		if(rx_ok)
//		{
//			if(mode == DATA_MODE)
//			{
//			    if(rf_slave.buff[0] != 0xFF) // Old Protocol
//			    {
//    				if(rf_slave.buff[0] == total_len) // full data bag received
//    				{
//    					//uart_send_byte(0xAA);
//
//    					// last bag may need more ack
//    					rf_slave.rx_tout = RF_RECV_TOUT;
//    					rf_transceiver(RF_RECEIVER, 30, ack_data, sizeof(ack_data), &i, 1, &ulen);
//
//                        beep_wait_over();
//                        delay_1ms(10);
//                        beep_enable(60);
//
//    	        		/* handle the received rf data */
//    	        		usb_data_proc(mode, rf_slave.buff);    	                
//    					break;
//    				}
//				}
//				else // New Protocol
//				{
//				    UINT16 temp_len;
//
//				    temp_len = rf_slave.buff[1];
//				    temp_len <<= 8;
//				    temp_len += rf_slave.buff[2];
//
//				    if(temp_len == total_len) // full data bag received
//				    {
//    					// last bag may need more ack
//    					rf_slave.rx_tout = RF_RECV_TOUT;
//    					rf_transceiver(RF_RECEIVER, 30, ack_data, sizeof(ack_data), &i, 1, &ulen);
//
//                        beep_wait_over();
//                        delay_1ms(10);
//                        beep_enable(60);
//
//    	        		/* handle the received rf data */
//    	        		usb_data_proc1(mode, rf_slave.buff);
//    					break;
//				    }
//				}
//			}
//			else // INIT MODE
//			{
//				break;
//			}
//		}
//	}
//    
//	memset(rf_slave.buff, 0, sizeof(rf_slave.buff));
//
//	return rx_ok;
//}
static UINT8 rx_temp[RF_FIFO_MAX]={0};

BOOL rf_to_usb(UINT8 mode)
{
	BOOL rx_ok;
	UINT8 i;
	UINT8 ulen;
	UINT8 ack_data[4];
	UINT8 bag_id;
	UINT16 total_len = 0;
	UINT8 *rx_index = NULL;

	/* clear recv time out */
	rf_slave.rx_tout = 0;

	for(i = 0; i < 100; i++)
	{
	RF_RECEIVE:
	    
        watchdog_feed();
	    
		if(mode == INIT_MODE)
		{
			rf_get_mac(ack_data); // ack MAC to Host
		}
		else // DATA MODE
		{
			//my_memcpy(ack_data, (code_ptr *)&rf_ack[i][0], ACK_C);
			memcpy(ack_data, &rf_ack[0][0], ACK_C);
		}

		if(0 != i)	//非第一组
		{
			rx_index = &rf_slave.buff[i*(RF_FIFO_MAX-1)];
		}
		else		//第一组数据
		{
			rx_index = rx_temp;
		}
		
		//接收
		rx_ok = rf_transceiver(RF_RECEIVER, RF_RX_TOUT, ack_data, sizeof(ack_data), \
							   rx_index, RF_FIFO_MAX, &ulen);

		if(rx_ok) // get RF data
		{
			/* clear rx time out */
			rf_slave.rx_tout = 0;

			/* get current data bag id */
			bag_id = rx_index[0];

			if((bag_id >= 1) & (bag_id <= 102)) // support 102 bag
			{
				if(bag_id == (i + 1)) // bag id is correct
				{
					memcpy(rx_index, rx_index + 1, ulen - 1); // shift left one byte		 //左移1字节
					total_len += (ulen - 1);




/*添加命令包*/
//					if(isCmdPkt(rx_index+6, ulen - 7))	//是命令包
//					{
//						if(((CMD_UPLOAD*)(rx_index+6))->sid == rf_slave.pkt_id)
//						{
//							usb_data_proc1(mode, rf_slave.buff);	//usb上传 
//							rf_slave.pkt_id = INIT_ID; //clear pid
//						}
//						break;
//					}
/**/					






					if(1==bag_id)
					{
						if(rx_index[4] == rf_slave.pkt_id)	//spid == pid
						{
							usb_data_proc1(mode, rf_slave.buff);	//usb上传	
							rf_slave.pkt_id = INIT_ID; //clear pid
						}
						memcpy(&rf_slave.buff[0], rx_index, ulen - 1);	//将数据写入rf_slave.buff
					}
				}
			#if 1
				else if(bag_id == i) // bag id to be last one
				{
					// receive again
					goto RF_RECEIVE;
				}
			#endif /* 0 */
				else // bag id is incorrect
				{
					rx_ok = 0;
					break;
				}
			}
			else // bag id is incorrect
			{
				rx_ok = 0;
				break;
			}
		}
		else
		{
			break; // RF rx timeout
		}

		if(rx_ok)
		{
			if(mode == DATA_MODE)
			{
				if(rf_slave.buff[0] == 0xFF)
				{
				    UINT16 temp_len;

				    temp_len = rf_slave.buff[1];
				    temp_len <<= 8;
				    temp_len += rf_slave.buff[2];

				    if(temp_len == total_len) // full data bag received
				    {
    					// last bag may need more ack
//    					rf_slave.rx_tout = RF_RECV_TOUT;
//    					rf_transceiver(RF_RECEIVER, 30, ack_data, sizeof(ack_data), &i, 1, &ulen);

//                        beep_wait_over();
//                        delay_1ms(500);		//10
//                        beep_enable(60);

    	        		/* handle the received rf data */
						//crc校验
						//记录spid
						//返回spid

						if(checkData(&rf_slave.buff[0],temp_len))
						{
							rf_slave.pkt_id = (rf_slave.buff[3] & 0x1F);	//记录rf_slave.pkt_id 
							ReceiveCompleteAck(rf_slave.pkt_id);
						}		
						
    					break;
				    }
				}
			}
			else // INIT MODE
			{
				break;
			}
		}
	}
    
	//memset(rf_slave.buff, 0, sizeof(rf_slave.buff));

	return rx_ok;
}
#else

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL rf_to_usb(UINT8 mode)
{
	UINT8 ulen1 = 0, ulen2 = 0;
	BOOL rx_ok;
	//UINT8 ack_data[4] = {STX, 0x01, 0xFE, ETX};
	UINT8 ack_data[4];

	if(mode == INIT_MODE)
	{
		rf_get_mac(ack_data); // ack MAC to Host
	}
	else // DATA MODE
	{
		//my_memcpy(ack_data, (code_ptr *)rf_ack, 4);
		my_memcpy(ack_data, (code_ptr *)&rf_ack[0][0], ACK_C);
	}

	/* clear recv time out */
	rf_slave.rx_tout = 0;

	rx_ok = rf_transceiver(RF_RECEIVER, RF_RX_TOUT, ack_data, sizeof(ack_data), \
							rf_slave.buff, RF_FIFO_MAX, &ulen1);

	if(rx_ok && ulen1)
	{
	#if 0
		UINT8 i;
		watchdog_feed();
		
		printf("1st pkt :\r\n");
		
		for(i = 0; i < /*ulen1*/rf_slave.buff[0]-3; i++)
		{
			printf("+%x", (UINT16)rf_slave.buff[i]);
			uart_send_byte(rf_slave.buff[3+i]);
		}
		uart_send_byte(0x0a);
		printf("\r\n");
	#endif

		if((ulen1 == sizeof(ack_data)) && \
		(!memcmp(ack_data, rf_slave.buff, ulen1)))
		{
			// idle or ping pkt
			rx_ok = 0;
		}
		else
		{
			/* data length is in valid range of the buffer -------------*/
			if((rf_slave.buff[0] > RF_FIFO_MAX) && (rf_slave.buff[0] <= MAX_BUFF))
			{
				/* may be last 2nd pkt or error pkt */
				if(ulen1 != RF_FIFO_MAX)
				{
					rx_ok = 0;
				}
				else
				{
					UINT8 retry = 0;

					//printf("2nd pkt :\r\n");
					
					/* clear recv time out */
					rf_slave.rx_tout = 0;//RF_RECV_TOUT - 1000; // 1s left
					
				RETRY_RX:	
					rx_ok = rf_transceiver(RF_RECEIVER, RF_RX_TOUT, ack_data, sizeof(ack_data), \
											&rf_slave.buff[RF_FIFO_MAX], MAX_BUFF - RF_FIFO_MAX, &ulen2);

					if(rx_ok && ulen2)
					{
					#if 0
						watchdog_feed();
						
						for(i = 0; i < ulen2; i++)
						{
							printf("-%x", (UINT16)rf_slave.buff[ulen1+i]);
						}
						printf("\r\n");
					#endif
					
						if((ulen2 == sizeof(ack_data)) && \
						(!memcmp(ack_data, &rf_slave.buff[RF_FIFO_MAX], ulen2)))
						{
							// idle or ping pkt
							rx_ok = 0;
						}
						else
						{
							if(rf_slave.buff[0] != (ulen1 + ulen2) && \
							(!memcmp(rf_slave.buff, &rf_slave.buff[ulen1], ulen2)))
							{
								/* may be the 1st pkt */
								if(++retry < 3)
								{
									ulen2 = 0;
									goto RETRY_RX;
								}
								else
								{
									rx_ok = 0;
								}
							}
						}
					}
					else
					{
						rx_ok = 0;
					}
				}
			}
			else
			{
				/* may be last 2nd pkt or error pkt */
				if(rf_slave.buff[0] != ulen1)
				{
					rx_ok = 0;
				}
				else
				{
					// need to do:
				}
			}
			
			if(rx_ok && (ulen1 || ulen2))
			{
			#if 0
				UINT8 i;
				watchdog_feed();
				
				printf("send key.\r\n");
				
				for(i = 0; i < rf_slave.buff[0]; i++)
				{
					printf("%x, ", (UINT16)rf_slave.buff[i]);
				}
				printf("\r\n");
			#endif
		
                PCINT1 = ON; // led on

        		/* handle the received rf data */
        		usb_data_proc(mode, rf_slave.buff);
        		
                PCINT1 = OFF; // led off
            }
        }
        
		memset(rf_slave.buff, 0, sizeof(rf_slave.buff));
	}

	return rx_ok;
}
#endif /* RF_250KBPS */

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
void rf_slave_config(void)
{
	UINT8 init_mac[4] = {MAC0, MAC1, MAC2, MAC3};
	
	rf_set_pipe(PIPE_INDEX_MAX);
	rf_set_ch();
	rf_set_mac(init_mac);

	rf_to_usb(INIT_MODE);
	rf_to_usb(INIT_MODE);
	rf_to_usb(INIT_MODE);
	
	rf_set_pipe((xn297l.mac[3] + 1) % PIPE_INDEX_MAX);
	rf_set_ch();
	rf_set_mac(xn297l.mac);
}

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
void rf_slave_update(void)
{
    #define _IAP_ADDR   0x0000 // Bootloader
    #define _FLAG_ADDR  (5*1024 + 512)
    
    UINT8 goto_flag[4] = {0xAA, 0xBB, 0xCC, 0xDD};
    
    Flash_PageErase(_FLAG_ADDR);
    Flash_Write(_FLAG_ADDR, goto_flag, 4);
    
    // Disable All Interrupt. 
    _sfrb_bank0();
    IE0 = 0;
    IE1 = 0;
    IE2 = 0;
    IE3 = 0;

    // Goto Iap Start ADDR.
    ((void (code *)(void))_IAP_ADDR)();
}

#endif

#endif /* _UART2USB */

