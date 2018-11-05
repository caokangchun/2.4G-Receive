
#include "includes.h"

//#define RF_CMD_NEW

/* ----------------- rf cmd data ------------------------------------------------------------------------- */

#ifdef RF_CMD_NEW

    #ifdef _RF_HOST
    
    code UINT8 default_mode[8]          = {0x24, 0x4E, 0x4F, 0x52, 0x4D, 0x44, 0x25, 0x0D};
    code UINT8 store_mode[8]            = {0x24, 0x49, 0x4E, 0x56, 0x4D, 0x44, 0x25, 0x0D};
    code UINT8 all_data_up[8]           = {0x24, 0x54, 0x58, 0x4D, 0x45, 0x4D, 0x25, 0x0D};
    code UINT8 last_data_up[8]          = {0x24, 0x54, 0x58, 0x4E, 0x45, 0x57, 0x25, 0x0D};
    
    code UINT8 break_data_up[8]         = {0x24, 0x54, 0x58, 0x43, 0x4F, 0x4E, 0x25, 0x0D};
    code UINT8 scan_total_num[8]        = {0x24, 0x23, 0x54, 0x43, 0x4E, 0x54, 0x25, 0x0D};
    code UINT8 scan_last_num[8]         = {0x24, 0x53, 0x54, 0x43, 0x4E, 0x54, 0x25, 0x0D};
    code UINT8 clear_all_data[8]        = {0x24, 0x2A, 0x4E, 0x45, 0x57, 0x2A, 0x25, 0x0D};

    code UINT8 rf_set_mode[8]           = {0x24, 0x52, 0x46, 0x53, 0x45, 0x54, 0x25, 0x0D};
    code UINT8 host_set_ch[8]           = {0x41, 0x54, 0x24, 0x31, 0x31, 0x31, 0x3D, 0x0D};
    code UINT8 host_set_id[8]           = {0x41, 0x54, 0x24, 0x31, 0x32, 0x31, 0x3D, 0x0D};
    code UINT8 host_set_rx_id[8]        = {0x41, 0x54, 0x24, 0x31, 0x32, 0x32, 0x3D, 0x0D};
    code UINT8 host_set_buzzer[8]       = {0x41, 0x54, 0x24, 0x31, 0x32, 0x34, 0x3D, 0x0D};
    code UINT8 host_set_default[10]     = {0x41, 0x54, 0x24, 0x31, 0x38, 0x30, 0x3D, 0x31, 0x25, 0x0D};
    code UINT8 rf_set_save[5]           = {0x41, 0x54, 0x4F, 0x25, 0x0D};

    code UINT8 host_same_on[8]          = {0x24, 0x45, 0x4E, 0x43, 0x48, 0x4B, 0x25, 0x0D};
    code UINT8 host_same_off[8]         = {0x24, 0x4E, 0x4F, 0x43, 0x48, 0x4B, 0x25, 0x0D};
    code UINT8 host_same_6s[12]         = {0x41, 0x54, 0x24, 0x31, 0x33, 0x32, 0x3D, 0x31, 0x39, 0x32, 0x25, 0x0D};
    code UINT8 host_same_5s[12]         = {0x41, 0x54, 0x24, 0x31, 0x33, 0x32, 0x3D, 0x31, 0x36, 0x35, 0x25, 0x0D};
    code UINT8 host_same_4s[12]         = {0x41, 0x54, 0x24, 0x31, 0x33, 0x32, 0x3D, 0x31, 0x33, 0x35, 0x25, 0x0D};
    code UINT8 host_same_3s[12]         = {0x41, 0x54, 0x24, 0x31, 0x33, 0x32, 0x3D, 0x31, 0x30, 0x35, 0x25, 0x0D};
    code UINT8 host_same_2s[11]         = {0x41, 0x54, 0x24, 0x31, 0x33, 0x32, 0x3D, 0x37, 0x30, 0x25, 0x0D};
    code UINT8 host_same_1s[11]         = {0x41, 0x54, 0x24, 0x31, 0x33, 0x32, 0x3D, 0x33, 0x32, 0x25, 0x0D};

    code UINT8 slave_set_ch[8]          = {0x41, 0x54, 0x24, 0x32, 0x31, 0x31, 0x3D, 0x0D};
    code UINT8 slave_set_id[8]          = {0x41, 0x54, 0x24, 0x32, 0x32, 0x31, 0x3D, 0x0D};

    code UINT8 soft_version[8]		    = {0x24, 0x53, 0x46, 0x56, 0x45, 0x52, 0x25, 0x0D};

    #else
    code UINT8 slave_set_save[5]		= {0x41, 0x54, 0x4F, 0x25, 0x0D};
    #endif /* _RF_HOST */

    code UINT8 slave_id_on[10]          = {0x41, 0x54, 0x24, 0x32, 0x32, 0x36, 0x3D, 0x32, 0x25, 0x0D};
    code UINT8 slave_id_off[10]         = {0x41, 0x54, 0x24, 0x32, 0x32, 0x36, 0x3D, 0x30, 0x25, 0x0D};
    code UINT8 slave_id_tab[10]         = {0x41, 0x54, 0x24, 0x32, 0x33, 0x31, 0x3D, 0x39, 0x25, 0x0D};
    code UINT8 slave_id_blank[11]       = {0x41, 0x54, 0x24, 0x32, 0x33, 0x31, 0x3D, 0x33, 0x32, 0x25, 0x0D};
    code UINT8 slave_id_link[11]        = {0x41, 0x54, 0x24, 0x32, 0x33, 0x31, 0x3D, 0x34, 0x35, 0x25, 0x0D};
    code UINT8 slave_set_default[10]    = {0x41, 0x54, 0x24, 0x31, 0x39, 0x38, 0x3D, 0x31, 0x25, 0x0D};

#else

    #ifdef _RF_HOST
    code UINT8 default_mode[8] 			= {0x25, 0x23, 0x4E, 0x4F, 0x52, 0x4D, 0x44, 0x0D};
    code UINT8 store_mode[8]   			= {0x25, 0x23, 0x49, 0x4E, 0x56, 0x4D, 0x44, 0x0D};
    code UINT8 all_data_up[8]  			= {0x25, 0x23, 0x54, 0x58, 0x4D, 0x45, 0x4D, 0x0D};
    code UINT8 last_data_up[8] 			= {0x25, 0x23, 0x54, 0x58, 0x4E, 0x45, 0x57, 0x0D};

    code UINT8 break_data_up[8] 		= {0x25, 0x23, 0x54, 0x58, 0x43, 0x4F, 0x4E, 0x0D};
    code UINT8 scan_total_num[8]		= {0x25, 0x23, 0x2B, 0x54, 0x43, 0x4E, 0x54, 0x0D};
    code UINT8 scan_last_num[8]			= {0x25, 0x23, 0x53, 0x54, 0x43, 0x4E, 0x54, 0x0D};
    code UINT8 clear_all_data[8]		= {0x25, 0x23, 0x2A, 0x4E, 0x45, 0x57, 0x2A, 0x0D};

    code UINT8 rf_set_mode[8]			= {0x25, 0x23, 0x52, 0x46, 0x53, 0x45, 0x54, 0x0D};
    code UINT8 host_set_ch[8]			= {0x41, 0x54, 0x53, 0x31, 0x31, 0x31, 0x3D, 0x0D};
    code UINT8 host_set_id[8]			= {0x41, 0x54, 0x53, 0x31, 0x32, 0x31, 0x3D, 0x0D};
    code UINT8 host_set_rx_id[8]		= {0x41, 0x54, 0x53, 0x31, 0x32, 0x32, 0x3D, 0x0D};
    code UINT8 host_set_buzzer[8]		= {0x41, 0x54, 0x53, 0x31, 0x32, 0x34, 0x3D, 0x0D};
    code UINT8 host_set_default[10]		= {0x41, 0x54, 0x53, 0x31, 0x38, 0x30, 0x3D, 0x31, 0x23, 0x0D};
    code UINT8 rf_set_save[5]			= {0x41, 0x54, 0x4F, 0x23, 0x0D};

    code UINT8 host_same_on[8]			= {0x25, 0x23, 0x45, 0x4E, 0x43, 0x48, 0x4B, 0x0D};
    code UINT8 host_same_off[8]			= {0x25, 0x23, 0x4E, 0x4F, 0x43, 0x48, 0x4B, 0x0D};
    code UINT8 host_same_6s[12]			= {0x41, 0x54, 0x53, 0x31, 0x33, 0x32, 0x3D, 0x31, 0x39, 0x32, 0x23, 0x0D};
    code UINT8 host_same_5s[12]			= {0x41, 0x54, 0x53, 0x31, 0x33, 0x32, 0x3D, 0x31, 0x36, 0x35, 0x23, 0x0D};
    code UINT8 host_same_4s[12]			= {0x41, 0x54, 0x53, 0x31, 0x33, 0x32, 0x3D, 0x31, 0x33, 0x35, 0x23, 0x0D};
    code UINT8 host_same_3s[12]			= {0x41, 0x54, 0x53, 0x31, 0x33, 0x32, 0x3D, 0x31, 0x30, 0x35, 0x23, 0x0D};
    code UINT8 host_same_2s[11]			= {0x41, 0x54, 0x53, 0x31, 0x33, 0x32, 0x3D, 0x37, 0x30, 0x23, 0x0D};
    code UINT8 host_same_1s[11]			= {0x41, 0x54, 0x53, 0x31, 0x33, 0x32, 0x3D, 0x33, 0x32, 0x23, 0x0D};

    code UINT8 slave_set_ch[8]			= {0x41, 0x54, 0x53, 0x32, 0x31, 0x31, 0x3D, 0x0D};
    code UINT8 slave_set_id[8]			= {0x41, 0x54, 0x53, 0x32, 0x32, 0x31, 0x3D, 0x0D};

    code UINT8 soft_version[8]		    = {0x41, 0x54, 0x53, 0x33, 0x31, 0x31, 0x3D, 0x0D};

    #else
    code UINT8 slave_set_save[5]		= {0x41, 0x54, 0x4F, 0x23, 0x0D};
    #endif /* _RF_HOST */

    code UINT8 slave_id_on[10]			= {0x41, 0x54, 0x53, 0x32, 0x32, 0x36, 0x3D, 0x32, 0x23, 0x0D};
    code UINT8 slave_id_off[10]			= {0x41, 0x54, 0x53, 0x32, 0x32, 0x36, 0x3D, 0x30, 0x23, 0x0D};
    code UINT8 slave_id_tab[10]			= {0x41, 0x54, 0x53, 0x32, 0x33, 0x31, 0x3D, 0x39, 0x23, 0x0D};
    code UINT8 slave_id_blank[11]		= {0x41, 0x54, 0x53, 0x32, 0x33, 0x31, 0x3D, 0x33, 0x32, 0x23, 0x0D};
    code UINT8 slave_id_link[11]		= {0x41, 0x54, 0x53, 0x32, 0x33, 0x31, 0x3D, 0x34, 0x35, 0x23, 0x0D};
    code UINT8 slave_set_default[10]	= {0x41, 0x54, 0x53, 0x31, 0x39, 0x38, 0x3D, 0x31, 0x23, 0x0D};

#endif /* RF_CMD_NEW */

#ifdef _RF_HOST

//------------------------------------------------------------------------
//	Description	: 	hex data to ascii
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 12 - 29
//------------------------------------------------------------------------
static UINT8 hex_to_ascii(UINT16 hex16, UINT8 *out)
{
	INT8 i;
	UINT8 len;
	UINT8 tmp8;
	UINT16 n;
	UINT8 flag;
	
	n = 10000;
	flag = 0;
	len = 0;
	
	for(i = 5; i > 0; i--)
	{
		tmp8 = (UINT8)(hex16 / n);
		
		if(0 == flag)
		{
			if((tmp8 != 0) || (1 == i))
			{
				flag = 1;
			}
		}

		if(flag)
		{
			out[len++] = tmp8 + '0';
		}
		
		hex16 = hex16 % n;
		n = n / 10; 							
	}
	
	return len;
}

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
void set_type_init(SET_TYPE type, MENU_SET *set)
{
	switch(type)
	{
		case SET_NONE:
			set->ch = 0xFF;
			set->id = 0xFF;
			break;

		case SET_CH:
			set->ch = 0xFF;
			break;

		case SET_ID:
			set->id = 0xFF;
			break;

		case SET_BUZZ:
			break;

		default:
			break;
	}

	set->len = 0;
	set->type = type;
	my_memset(set->dat, 0, SET_BUF);
}

MENU_SET set = {0xFF, 0xFF, 0};

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL rf_host_cmd(UINT8 *cmd_dat)
{
	BOOL flag = TRUE;

	switch(cmd_dat[0])
	{
		case CMD_LEN1:
			if(!memcmp(&cmd_dat[CMD_NO], default_mode, LEN1))
			{
				//debug("host normal mode.\r\n");
				rf_host.store_flag = 0;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], store_mode, LEN1))
			{
				//debug("host store mode.\r\n");
				rf_host.store_flag = 1;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], all_data_up, LEN1))
			{					
				//debug("all data up.\r\n");
				
				rf_host.up_num = rf_host.total_num;
				rf_host.up_addr = START_ADDR;
				
			DATA_UP:
			
				while(rf_host.up_num > 0)
				{
					UINT8 len = 0;
					
					/* feed WDT */
					watchdog_feed();
					
					if(at24cxx_read(rf_host.up_addr, &len, 1))
					{
						if((len > 1) && (len < (MAX_BUFF - HEAD_LEN)))
						{
    						if(at24cxx_read(rf_host.up_addr + 1, (UINT8 *)&uart.buff[3], len - 1))
    						{
    						#if 0
    							UINT8 i;
    							watchdog_feed();
    							
    							for(i = 0; i < uart.buff[0]; i++)
    							{
    								printf("+%x", (UINT16)uart.buff[i]);
    							}
    							printf("\r\n");
    						#endif
    			
    							uart.index = len + 2;
    							uart.buff[0] = uart.index;
    							uart.buff[2] = rf_host.pid;
    							
    							if(rf_host_send())
    							{								
    								if(rf_host.beep)
    								{
    									beep_ctrl(1, 80);
    									//delay_1ms(60);
    								}
    								
    								rf_host.up_num--;
    								if(rf_host.up_num != 0)
    								{
    									rf_host.up_addr += len;
    									continue;
    								}
    								
    								break;
    							}
    							else
    							{
    							//ERR_OUT:
    							
    								if(rf_host.beep)
    								{
    									beep_ctrl(3, 80);
    								}
    								
    								break;
    							}
    						}
						}
					}

                    if(rf_host.beep)
                    {
				        beep_ctrl(2, 80);
				        break;
				    }
				}
				
				//debug("up data done.\r\n");
			}
			else if(!memcmp(&cmd_dat[CMD_NO], last_data_up, LEN1))
			{
				rf_host.up_num = rf_host.cur_num;
				rf_host.up_addr = rf_host.cur_addr;
								
				//debug("last data up.\r\n");
				goto DATA_UP;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], break_data_up, LEN1))
			{
				//debug("break data up.\r\n");
				goto DATA_UP;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], scan_total_num, LEN1))
			{
				code_ptr *str = "Total Counters = ";
				UINT8 len = 17;//strlen(str);
				UINT8 tmp;
				UINT8 beep_cnt;
				
				//debug("scan total num=%d.\r\n", (UINT16)rf_host.total_num);
				
				my_memcpy(&cmd_dat[3], str, len);
				tmp = hex_to_ascii(rf_host.total_num, &cmd_dat[3+len]);
				len = 3 + len + tmp;
				cmd_dat[len] = 0x0D; // enter
				cmd_dat[0] = len + 1; // total
				uart.index = cmd_dat[0];

			TX_COUNTER:
			
				if(rf_host_send())
				{
					beep_cnt = 1;
				}
				else
				{
					beep_cnt = 3;
				}

				if(rf_host.beep)
				{
					beep_ctrl(beep_cnt, 80);
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], scan_last_num, LEN1))
			{
				code_ptr *str = "subTotal Counters = ";
				UINT8 len = 20;//strlen(str);
				UINT8 tmp;
				
				//debug("scan last num=%d.\r\n", (UINT16)rf_host.cur_num);
				
				my_memcpy(&cmd_dat[3], str, len);
				tmp = hex_to_ascii(rf_host.cur_num, &cmd_dat[3+len]);
				len = 3 + len + tmp;
				cmd_dat[len] = 0x0D; // enter
				cmd_dat[0] = len + 1; // total
				uart.index = cmd_dat[0];

				goto TX_COUNTER;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], soft_version, LEN1))
			{
				code_ptr *str = VERSION;
				UINT8 len = 22;//strlen(str);
				//UINT8 tmp;
				
				my_memcpy(&cmd_dat[3], str, len);
				//tmp = hex_to_ascii(rf_host.cur_num, &cmd_dat[3+len]);
				len = 3 + len;// + tmp;
				cmd_dat[len] = 0x0D; // enter
				cmd_dat[0] = len + 1; // total
				uart.index = cmd_dat[0];
				
				goto TX_COUNTER;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], clear_all_data, LEN1))
			{
			//CLEAR_ALL:

				rf_host.cur_addr = START_ADDR;
				rf_host.up_addr = 0;
				rf_host.cur_num = 0;
				rf_host.up_num = 0;
				rf_host.total_num = 0;
				rf_host.store_addr = START_ADDR;
				
				at24cxx_write(STORE_ADDR, (UINT8 *)&rf_host.store_addr, 2);
				at24cxx_write(TOTAL_NUM, (UINT8 *)&rf_host.total_num, 2);
				at24cxx_write(START_ADDR, (UINT8 *)&rf_host.total_num, 2);
				
				//debug("clear all data.\r\n");
			}
			/*------------------------------------------------------------------*/
			else if(!memcmp(&cmd_dat[CMD_NO], rf_set_mode, LEN1))
			{
				/* enable host & slave set */
				set.host = TRUE;
				set.slave = TRUE;
				
				rf_host.rx_init = FALSE;
				
				set_type_init(SET_NONE, &set);
				//debug("host set mode.\r\n");
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_set_ch, LEN1))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					
					set_type_init(SET_CH, &set);
					//debug("host set ch.\r\n");
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_set_id, LEN1))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					
					set_type_init(SET_ID, &set);
					//debug("host set id.\r\n");
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_set_rx_id, LEN1))
			{
				if(set.host)
				{
					//set.slave = FALSE;
					//rf_host.rx_init = FALSE;
					
					//set.type = SET_RX_ID;
					//printf("host set rx id.\r\n");
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_set_buzzer, LEN1))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					
					set_type_init(SET_BUZZ, &set);
					//debug("host set buzzer.\r\n");
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_same_on, LEN1))
			{
				UINT8 zero = 0;
				
				rf_host.same_flag = TRUE;
				rf_host.same_time = 6000;

				at24cxx_write(LAST_DATA, &zero, 1);
				at24cxx_write(REPEAT_ID, &rf_host.same_flag, 1);
				//debug("host same on.\r\n");
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_same_off, LEN1))
			{
				rf_host.same_flag = FALSE;
				at24cxx_write(REPEAT_ID, &rf_host.same_flag, 1);
				//debug("host same off.\r\n");
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_set_ch, LEN1))
			{							
				if(set.slave)
				{
					set.host = FALSE;					
					set_type_init(SET_CH, &set);
					//debug("slave set ch.\r\n");
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_set_id, LEN1))
			{
				if(set.slave)
				{
					set.host = FALSE;
					set_type_init(SET_ID, &set);
					//debug("slave set id.\r\n");
				}
				else
				{
					flag = FALSE;
				}
			}
			else
			{
				flag = FALSE;
			}
			break;

		case CMD_LEN2:
			if(!memcmp(&cmd_dat[CMD_NO], rf_set_save, LEN2))
			{
				if(set.host)
				{
					set.host = FALSE;
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
				
					if(set.ch != 0xFF)
					{
						rf_set_pipe(set.ch);
						rf_set_ch();
						at24cxx_write(RF_CH_NO, &set.ch, 1);
					}
				
					if(set.id != 0xFF)
					{
						rf_host.pid = set.id;
						at24cxx_write(DEVICE_ID, &set.id, 1);
					}
					
					//debug("host set save.\r\n");
				}
 				else if(set.slave)
				{
					set.slave = FALSE;
					//rf_host.rx_init = TRUE;
					
					//flag = FALSE;
					//debug("slave set save.\r\n");
				}
				else
				{
					flag = FALSE;
				}
			}
			else
			{
				flag = FALSE;
			}
			break;

		case CMD_LEN3:
			if(!memcmp(&cmd_dat[CMD_NO], host_set_default, LEN3))
			{
				if(set.host)
				{	
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					
					set.type = SET_NONE;
					
					rf_set_pipe(rf_def_para[4]);
					rf_set_ch();
					at24cxx_write(RF_CH_NO, (UINT8 *)&rf_def_para[4], 1);
				
					rf_host.pid = 0;
					at24cxx_write(DEVICE_ID, &rf_host.pid, 1);
					
					rf_host.same_flag = FALSE;
					at24cxx_write(REPEAT_ID, &rf_host.same_flag, 1);
					
					//debug("host set default.\r\n");

                #if 0 // do not clear data
					goto CLEAR_ALL;
                #endif /* 0 */
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_set_default, LEN3))
			{
				//debug("slave set default.\r\n");
				
			SLAVE_INIT:
			
				if(set.slave)
				{
					set.host = FALSE;
					rf_host.rx_init = TRUE;
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_id_on, LEN3))
			{
				//debug("slave id on.\r\n");
				goto SLAVE_INIT;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_id_off, LEN3))
			{
				//debug("slave id off.\r\n");
				goto SLAVE_INIT;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_id_tab, LEN3))
			{
				//debug("slave id tab.\r\n");
				goto SLAVE_INIT;
			}
			else
			{
				flag = FALSE;
			}
			break;

		case CMD_LEN4:
			if(!memcmp(&cmd_dat[CMD_NO], host_same_2s, LEN4))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					rf_host.same_time = 2000;
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_same_1s, LEN4))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					rf_host.same_time = 1000;
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_id_blank, LEN4))
			{
				//debug("slave id blank.\r\n");
				goto SLAVE_INIT;
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_id_link, LEN4))
			{
				//debug("slave id link.\r\n");
				goto SLAVE_INIT;
			}
			else
			{
				flag = FALSE;
			}
			break;
			
		case CMD_LEN5:
			if(!memcmp(&cmd_dat[CMD_NO], host_same_6s, LEN5))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					rf_host.same_time = 6000;
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_same_5s, LEN5))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					rf_host.same_time = 5000;
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_same_4s, LEN5))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					rf_host.same_time = 4000;
				}
				else
				{
					flag = FALSE;
				}
			}
			else if(!memcmp(&cmd_dat[CMD_NO], host_same_3s, LEN5))
			{
				if(set.host)
				{
					set.slave = FALSE;
					rf_host.rx_init = FALSE;
					rf_host.same_time = 3000;
				}
				else
				{
					flag = FALSE;
				}
			}
			else
			{
				flag = FALSE;
			}
			break;

		default:
			if(set.host || set.slave)
			{
				UINT8 num;
				num = cmd_dat[CMD_NO];
				
				if((0x05 == cmd_dat[0]) && (0x0D == cmd_dat[4]))
				{
					if(((num >= '0') && (num <= '9')) || ('#' == num))
					{
						switch(set.type)
						{
							case SET_CH :
								if('#' == num) // set over
								{
									if(set.len != 0) // valid data len
									{
										if(1 == set.len) // for 1byte
										{
											set.ch = set.dat[0];
										}
										else // for 2bytes
										{
											set.ch = (set.dat[0] * 10) + set.dat[1];
										}
										
										if(set.ch > 15)
											set.ch = 0;
											
										//debug("set ch=%d.\r\n", (UINT16)set.ch);

										if(set.slave)
										{
											//debug("done.\r\n");
											rf_host.rx_init = TRUE;
											uart.index = 6;
											cmd_dat[0] = 6;
											cmd_dat[3] = 0xAA;
											cmd_dat[4] = set.ch;
											cmd_dat[5] = 0xAA;
										}
									}
								}
								else
								{
								#if 0
									/* valid data formate bit0 : 0 ~ 1, bit1 : 0 ~ 5 */
									if(((0 == set.len) && (('0' == num) || ('1' == num))) || \
									((1 == set.len) && ((num >= '0') && (num <= '5'))))
									{
										set.dat[set.len++] = num - '0';
									}
								#else
									if(set.len < 2)
									{
										set.dat[set.len++] = num - '0';
									}
								#endif
								}
								break;
	
							case SET_ID :
								if('#' == num) // set over
								{
									if(set.len != 0) // valid data len
									{
										if(1 == set.len) // for 1byte
										{
											set.id = set.dat[0];
										}
										else if(2 == set.len) // for 2bytes
										{
											set.id = (set.dat[0] * 10) + set.dat[1];
										}
										else // for 3bytes
										{
											UINT16 tmp;
			
											tmp = set.dat[0];
											tmp = (tmp * 100) + (set.dat[1] * 10) + set.dat[2];
			
											if(tmp >= 0xFF)
											{
												set.id = 0xFF;
											}
											else
											{
												set.id = tmp;
											}
										}
			
										if(0 == set.id)
										{
											set.id = 0xFF;
										}
										
										//debug("set id=%d.\r\n", (UINT16)set.id);

										if(set.slave)
										{
											//debug("done.\r\n");
											rf_host.rx_init = TRUE;
											uart.index = 6;
											cmd_dat[0] = 6;
											cmd_dat[3] = 0xBB;
											cmd_dat[4] = set.id;
											cmd_dat[5] = 0xBB;
										}
									}
								}
								else
								{
									if(set.len < 3)
									{
										set.dat[set.len++] = num - '0';
									}
								}
								break;
	
							//case SET_RX_ID :
							//	break;
	
							case SET_BUZZ :
								if(('#' == num) && (1 == set.len)) // set over
								{
									if('2' == set.dat[0])
									{
										rf_host.beep = FALSE;
									}
									else if('3' == set.dat[0])
									{
										rf_host.beep = TRUE;
									}
								}
								else
								{
									/* valid bit0 : 2 ~ 3 */
									if((0 == set.len) && \
									(('2' == num) || ('3' == num)))
									{
										set.dat[set.len++] = num;
									}
								}
								break;
	
							default :
								flag = FALSE;
								break;
						}
					}
				}
			}
			else
			{
				flag = FALSE;
			}
			break;
	}

	return flag;
}

#else

//------------------------------------------------------------------------
//	Description	: 	UART data to usb send
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date 		: 	2014 - 03 - 11
//------------------------------------------------------------------------
BOOL rf_slave_cmd(UINT8 *cmd_dat)
{
	BOOL flag = TRUE;
	//static UINT8 set_ch = 0xFF;
	//static UINT8 set_id = 0xFF;

	switch(cmd_dat[0])
	{
		case 6://CMD_LEN1:
			//if(!memcmp(&cmd_dat[CMD_NO], slave_set_ch, LEN1))
			if((0xAA == cmd_dat[3]) && (0xAA == cmd_dat[5]))
			{
				UINT8 set_ch;
				
				//rf_slave.status = RF_INITED;
				
				set_ch = cmd_dat[4];
				rf_slave.pipe_bak = set_ch;
				rf_set_pipe(set_ch);
				rf_set_ch();
				at24cxx_write(RF_CH_NO, &set_ch, 1);
				//debug("slave set ch %d.\r\n", (UINT16)set_ch);
			}
			//else if(!memcmp(&cmd_dat[CMD_NO], slave_set_id, LEN1))
			else if((0xBB == cmd_dat[3]) && (0xBB == cmd_dat[5]))
			{
				UINT8 set_id;
				
				//rf_slave.status = RF_INITED;

				set_id = cmd_dat[4];
				rf_slave.pid = set_id;
				at24cxx_write(DEVICE_ID, &set_id, 1);
				//debug("slave set id.\r\n");
			}
			else
			{
				flag = FALSE;
			}
			break;

		case CMD_LEN2:
		#if 0
			if(!memcmp(&cmd_dat[CMD_NO], slave_set_save, LEN2))
			{
				rf_slave.status = RF_CONFIG;
			
				if(set_ch != 0xFF)
				{
					rf_set_pipe(set_ch);
					rf_set_ch();
					at24cxx_write(RF_CH_NO, &set_ch, 1);
				}
			
				if(set_id != 0xFF)
				{
					rf_slave.pid = set_id;
					at24cxx_write(DEVICE_ID, &set_id, 1);
				}
				
				//debug("slave set save.\r\n");
			}
			else
			{
				flag = FALSE;
			}
		#endif
			break;
			
		case CMD_LEN3:
			if(!memcmp(&cmd_dat[CMD_NO], slave_id_on, LEN3))
			{
				//rf_slave.status = RF_INITED;
				
				rf_slave.pid_flag = 1;
				//rf_slave.add_type = ADD_TAB;
				//debug("slave id on.\r\n");
				
				at24cxx_write(ID_SHOW, &rf_slave.pid_flag, 1);
                //at24cxx_write(PREFIX_TYPE, &rf_slave.add_type, 1);
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_id_off, LEN3))
			{
				//rf_slave.status = RF_INITED;
				
				rf_slave.pid_flag = 0;
				//rf_slave.add_type = ADD_TAB;
				//printf("slave id off.\r\n");
				
				at24cxx_write(ID_SHOW, &rf_slave.pid_flag, 1);
                //at24cxx_write(PREFIX_TYPE, &rf_slave.add_type, 1);
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_id_tab, LEN3))
			{
				//rf_slave.status = RF_INITED;
				
				rf_slave.add_type = ADD_TAB;
				//printf("slave id tab.\r\n");
                at24cxx_write(PREFIX_TYPE, &rf_slave.add_type, 1);
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_set_default, LEN3))
			{
				//rf_slave.status = RF_INITED;
				
				rf_slave.pid_flag = 0;
				rf_slave.add_type = ADD_TAB;
				at24cxx_write(ID_SHOW, &rf_slave.pid_flag, 1);
                at24cxx_write(PREFIX_TYPE, &rf_slave.add_type, 1);

				rf_slave.pipe_bak = rf_def_para[4];
				rf_set_pipe(rf_def_para[4]);
				rf_set_ch();
				at24cxx_write(RF_CH_NO, (UINT8 *)&rf_def_para[4], 1);
			
				rf_slave.pid = 1;
				at24cxx_write(DEVICE_ID, &rf_slave.pid, 1);
				
				printf("slave set default.\r\n");
			}
			else
			{
				flag = FALSE;
			}
			break;
		
		case CMD_LEN4:
			if(!memcmp(&cmd_dat[CMD_NO], slave_id_blank, LEN4))
			{
				//rf_slave.status = RF_INITED;
				
				rf_slave.add_type = ADD_BLANK;
				printf("slave id blank.\r\n");
                at24cxx_write(PREFIX_TYPE, &rf_slave.add_type, 1);
			}
			else if(!memcmp(&cmd_dat[CMD_NO], slave_id_link, LEN4))
			{
				//rf_slave.status = RF_INITED;
				
				rf_slave.add_type = ADD_LINE;
				printf("slave id link.\r\n");
                at24cxx_write(PREFIX_TYPE, &rf_slave.add_type, 1);
			}
			else
			{
				flag = FALSE;
			}
			break;

		default:
		#if 0
			if(slave_set)
			{
				if((0x05 == cmd_dat[0]) && (0x0D == cmd_dat[4]))
				{
					if(((cmd_dat[3] >= '0') && (cmd_dat[3] <= '9')) || ('#' == cmd_dat[3]))
					{
						switch(set_mode)
						{
							case SET_CH :
								if(('#' == cmd_dat[3]) && (set_len > 0))
								{
									set_ch = (set_dat[0] * 10) + set_dat[1];
									printf("set ch=%d.\r\n", (UINT16)set_ch);
								}
								else
								{
									if(((0 == set_len) && (('0' == cmd_dat[3]) || ('1' == cmd_dat[3]))) || \
									((1 == set_len) && ((cmd_dat[3] >= '0') && (cmd_dat[3] <= '5'))))
									{
										set_dat[set_len++] = cmd_dat[3] - '0';
									}
								}
								break;
	
							case SET_ID :
								if('#' == cmd_dat[3])
								{
									if(1 == set_len)
									{
										set_id = set_dat[0];
									}
									else if(2 == set_len)
									{
										set_id = (set_dat[0] * 10) + set_dat[1];
									}
									else
									{
										UINT16 tmp;
	
										tmp = set_dat[0];
										tmp = (tmp * 100) + (set_dat[1] * 10) + set_dat[2];
	
										if(tmp > 254)
										{
											set_id = 0xFF;
										}
										else
										{
											set_id = tmp;
										}
									}
	
									if(0 == set_id)
									{
										set_id = 0xFF;
									}
									printf("set id=%d.\r\n", (UINT16)set_id);
								}
								else
								{
									if(set_len < 3)
									{
										set_dat[set_len++] = cmd_dat[3] - '0';
									}
								}
								break;
	
							default :
								break;
						}
					}
				}
			}
			else
		#endif
			{
				flag = FALSE;
			}
			break;
	}
	
	return flag;
}

#endif

