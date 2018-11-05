
#include "includes.h"

code UINT8 rf_def_para[5] = {MAC0, MAC1, MAC2, MAC3, 0x00};

//---------------------------------------------------------------------------------------
//	Description	: 	eeprom init
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2014 - 03 - 14
//---------------------------------------------------------------------------------------
void at24cxx_init(void)
{
	UINT8 ee_tmp[5] = {0};

	/* i2c io init */
	i2c_init();

	if(at24cxx_read(INIT_CHECK, ee_tmp, 2))
	{
		printf("check i2c ok...\r\n");
		
		if((ee_tmp[0] != 0xAA) || (ee_tmp[1] != 0x55))
		{
			printf("first run init.\r\n");
			
			ee_tmp[0] = 0xAA;
			ee_tmp[1] = 0x55;
			at24cxx_write(INIT_CHECK, ee_tmp, 2);
			
		CONFIG_PARAMETER:
			printf("rf para.\r\n");
			
			/* RF mac id = 4bytes + ch = 1byte */
			my_memcpy(ee_tmp, (code_ptr *)rf_def_para, 5);
			
			at24cxx_write(RF_MAC, ee_tmp, 5);

		#ifdef _RF_HOST
			rf_host.store_addr = START_ADDR;
			at24cxx_write(STORE_ADDR, (UINT8 *)&rf_host.store_addr, 2);
			
			rf_host.total_num = 0;
			at24cxx_write(TOTAL_NUM, (UINT8 *)&rf_host.total_num, 2);

			rf_host.pid = 1;
			at24cxx_write(DEVICE_ID, &rf_host.pid, 1);

			rf_host.same_flag = 0;
			at24cxx_write(REPEAT_ID, &rf_host.same_flag, 1);
		#else // _RF_SLAVE
			rf_slave.pid = 1;
			at24cxx_write(DEVICE_ID, &rf_slave.pid, 1);
			
			rf_slave.pid_flag = 0;
			at24cxx_write(ID_SHOW, &rf_slave.pid_flag, 1);
			
			rf_slave.add_type = ADD_TAB;
			at24cxx_write(PREFIX_TYPE, &rf_slave.add_type, 1);
		#endif
		}
		else
		{
			at24cxx_read(RF_MAC, ee_tmp, 5);
			#if 0
			{
				UINT8 i;

				for(i = 0; i < 5; i++)
				{
					printf("%x, ", (UINT16)ee_tmp[i]);
				}

				printf("\r\n");
			}
			#endif

		#ifdef _RF_HOST
			at24cxx_read(STORE_ADDR, (UINT8 *)&rf_host.store_addr, 2);
			at24cxx_read(TOTAL_NUM, (UINT8 *)&rf_host.total_num, 2);

			at24cxx_read(DEVICE_ID, &rf_host.pid, 1);
            #if 0
			if((0 == rf_host.pid) || (0xFF == rf_host.pid))
			{
				rf_host.pid = 1;
				at24cxx_write(DEVICE_ID, &rf_host.pid, 1);
			}
            #endif /* 0 */

			at24cxx_read(REPEAT_ID, &rf_host.same_flag, 1);
		#else // _RF_SLAVE
			at24cxx_read(DEVICE_ID, &rf_slave.pid, 1);
            #if 0
			if((0 == rf_slave.pid) || (0xFF == rf_slave.pid))
			{
				rf_slave.pid = 1;
				at24cxx_write(DEVICE_ID, &rf_slave.pid, 1);
			}
            #endif /* 0 */
			
			at24cxx_read(ID_SHOW, &rf_slave.pid_flag, 1);
			at24cxx_read(PREFIX_TYPE, &rf_slave.add_type, 1);
			if(rf_slave.add_type > ADD_LINE)
			{
			    rf_slave.add_type = ADD_TAB;
			}
		#endif
		}

		memcpy(xn297l.mac, ee_tmp, 4);
		rf_set_pipe(ee_tmp[4]);

	#ifdef _RF_HOST
		rf_host.cur_addr = rf_host.store_addr;

		ee_tmp[0] = 0;
		at24cxx_write(LAST_DATA, &ee_tmp[0], 1);
		rf_host.same_time = 6000;
	#endif
	}
	else
	{
		/* if no eeprom, set to default */
		goto CONFIG_PARAMETER;
	}
}

#if 0
//---------------------------------------------------------------------------------------
//	Description	: 	write multi bytes to at24cxx
//	Parameters 	: 	addr -> write address, pdat -> data to be write, length -> data num
//	Return 		: 	TRUE / FALSE -> write success / fail
//	Author 		: 	RAY
//	Date		:	2013 - 10 - 12
//---------------------------------------------------------------------------------------
UINT8 at24cxx_write_1page(UINT8 addr, UINT8 *pdat, UINT8 length)// reentrant
{
	UINT8 flag = FALSE;
	UINT8 i2c_try_times = I2C_TRY_TIMES;

	while((!flag) && (i2c_try_times--))
	{
		i2c_start();

		if(i2c_write(AT24CXX_ADDR)) //device addr
		{
			if(i2c_write(addr)) //memory addr
			{
				while(1)
				{
					if(i2c_write(*pdat++)) //write data
					{
						if(0 == --length)
						{
							flag = TRUE;
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
		}

		i2c_stop();
	}
	
	return flag;
}


//---------------------------------------------------------------------------------------
//	Description	: 	read data from at24cxx
//	Parameters 	: 	addr -> write address, save -> save data to
//	Return 		: 	TRUE / FALSE -> read success / fail
//	Author 		: 	RAY
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
UINT8 at24cxx_read(UINT8 addr, UINT8 *save, UINT8 length)// reentrant
{
	UINT8 flag = FALSE;
	UINT8 i;
	UINT8 i2c_try_times = I2C_TRY_TIMES;
	
	while((!flag) && (i2c_try_times--))
	{
		i2c_start();

		if(i2c_write(AT24CXX_ADDR)) //device addr
		{
			if(i2c_write(addr)) //memory addr
			{
				i2c_start();
				
				if(i2c_write(AT24CXX_ADDR | 0x01)) //device addr, read
				{
					for(i = 0; i < (length - 1); i++)
					{
						*save++ = i2c_read(SEND_ACK);
					}
					
					*save = i2c_read(SEND_NACK);
					flag = TRUE;
				}
			}
		}
		
		i2c_stop();
	}
	
	return flag;
}

#else

//---------------------------------------------------------------------------------------
//	Description	: 	write multi bytes to at24cxx
//	Parameters 	: 	addr -> write address, pdat -> data to be write, length -> data num
//	Return 		: 	TRUE / FALSE -> write success / fail
//	Author 		: 	RAY
//	Date		:	2013 - 10 - 12
//---------------------------------------------------------------------------------------
UINT8 at24cxx_write_1page(EE_ADDR addr, UINT8 *pdat, UINT8 length)
{
	UINT8 flag = FALSE;
	UINT8 i2c_try_times = I2C_TRY_TIMES;
	
	while((!flag) && (i2c_try_times--))
	{
		i2c_start();

		if(i2c_write(AT24CXX_ADDR)) //device addr
		{
		#ifdef _AT24C02
			if(i2c_write(addr)) //memory addr
		#else
			UINT8 addr_h, addr_l;
			
			addr_h = addr >> 8;
			addr_l = addr;
			
			if(i2c_write(addr_h) && i2c_write(addr_l)) //memory addr
		#endif
			{
				while(1)
				{
					if(i2c_write(*pdat++)) //write data
					{
						if(0 == --length)
						{
							flag = TRUE;
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
		}

		i2c_stop();
	}
	
	return flag;
}


//---------------------------------------------------------------------------------------
//	Description	: 	read data from at24cxx
//	Parameters 	: 	addr -> write address, save -> save data to
//	Return 		: 	TRUE / FALSE -> read success / fail
//	Author 		: 	RAY
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
UINT8 at24cxx_read(EE_ADDR addr, UINT8 *save, UINT8 length)
{
	UINT8 flag = FALSE;
	UINT8 i;
	UINT8 i2c_try_times = I2C_TRY_TIMES;
	
	while((!flag) && (i2c_try_times--))
	{
		i2c_start();

		if(i2c_write(AT24CXX_ADDR)) //device addr
		{
		#ifdef _AT24C02
			if(i2c_write(addr)) //memory addr
		#else
			UINT8 addr_h, addr_l;

			addr_h = addr >> 8;
			addr_l = addr;
			
			if(i2c_write(addr_h) && i2c_write(addr_l)) //memory addr
		#endif
			{
				i2c_start();
				
				if(i2c_write(AT24CXX_ADDR | 0x01)) //device addr, read
				{
					for(i = 0; i < (length - 1); i++)
					{
						*save++ = i2c_read(SEND_ACK);
					}
					
					*save = i2c_read(SEND_NACK);
					flag = TRUE;
				}
			}
		}
		
		i2c_stop();
	}
	
	return flag;
}
#endif

//---------------------------------------------------------------------------------------
//	Description	: 	write multi bytes to at24cxx
//	Parameters 	: 	addr -> write address, pdat -> data to be write, length -> data num
//	Return 		: 	TRUE / FALSE -> write success / fail
//	Author 		: 	RAY
//	Date		:	2013 - 10 - 12
//---------------------------------------------------------------------------------------
UINT8 at24cxx_write(EE_ADDR addr, UINT8 *pdat, UINT8 length)
{
	UINT8 tmp;
	UINT8 num_of_head = 0, num_of_page = 0, num_of_tail = 0;

	tmp = addr % _E2_PAGE_SIZE;
	if(tmp != 0)//address not page size aligned
	{
		tmp = _E2_PAGE_SIZE - tmp;//page free space
	}
		
	if(length > tmp)//page free space not enough
	{
		num_of_head = tmp;
		num_of_page = (length - num_of_head) / _E2_PAGE_SIZE;
		num_of_tail = (length - num_of_head) % _E2_PAGE_SIZE;
	}
	else//page free space enough
	{
		num_of_head = length;
	}
	
	if(num_of_head != 0)//write head data to page
	{
		if( at24cxx_write_1page(addr, pdat, num_of_head) )
		{
			addr += num_of_head;
			pdat += num_of_head;
			
			delay_1ms(_E2_WR_WAIT);
		}
		else
		{
			goto WRITE_ERROR;
		}
	}

	while(num_of_page--)//write hole page
	{
		if( at24cxx_write_1page(addr, pdat, _E2_PAGE_SIZE) )
		{
			addr += _E2_PAGE_SIZE;
			pdat += _E2_PAGE_SIZE;
			
			delay_1ms(_E2_WR_WAIT);
		}
		else
		{
			goto WRITE_ERROR;
		}
	}

	if(num_of_tail != 0)//write tail data to page
	{
		if( at24cxx_write_1page(addr, pdat, num_of_tail) )
		{
			delay_1ms(_E2_WR_WAIT);
		}
		else
		{
			goto WRITE_ERROR;
		}
	}
	
	return TRUE;

WRITE_ERROR :
	return FALSE;	
}

#if 0
//---------------------------------------------------------------------------------------
//	Description	: 	write multi bytes to at24cxx
//	Parameters 	: 	addr -> write address, pdat -> data to be write, length -> data num
//	Return 		: 	TRUE / FALSE -> write success / fail
//	Author 		: 	RAY
//	Date		:	2013 - 10 - 12
//---------------------------------------------------------------------------------------
UINT8 at24cxx_store(EE_ADDR addr, UINT8 *pdat, UINT8 length)
{
	#define TMP_LEN		8
	#define MAX_TRY		3

	UINT8 tmp[TMP_LEN];
	UINT8 i, j, k;
	UINT8 cnt = 0;
	UINT8 flag = FALSE;

	while(++cnt > MAX_TRY)
	{
		if(at24cxx_write(addr, pdat, length))
		{
			flag = TRUE;

			i = 0;
			j = length;
			k = 0;
			
			while(i < j)
			{
				if(j > TMP_LEN)
				{
					i = TMP_LEN;
					j -= TMP_LEN;
				}
				else
				{
					i = j;
					j = 0;
				}

				if(at24cxx_read(addr + k, tmp, i))
				{
					if(memcmp(tmp, &pdat[k], i))
					{
						//uart_send_byte('$');
						flag = FALSE;
						break;
					}
				}
				else
				{
					//uart_send_byte('&');
					flag = FALSE;
					break;
				}
				
				k += i;
			}
		}
		else
		{
			uart_send_byte('!');
		}
	}

	//uart_send_byte(flag);
	return flag;
}
#endif /* 0 */

//---------------------------------------------------------------------------------------
//	Description	: 	write multi bytes to at24cxx
//	Parameters 	: 	addr -> write address, pdat -> data to be write, length -> data num
//	Return 		: 	TRUE / FALSE -> write success / fail
//	Author 		: 	RAY
//	Date		:	2013 - 10 - 12
//---------------------------------------------------------------------------------------
UINT8 at24cxx_clear(EE_ADDR addr, UINT8 length)
{
	#define TMP_LEN 	8
	#define MAX_TRY 	3
	
	UINT8 flag;
	UINT8 zero[TMP_LEN] = {0};
	UINT8 cnt = 0;
	UINT8 i, j;
	EE_ADDR addr_tmp;

	while(cnt++ < MAX_TRY)
	{
		flag = TRUE;
		addr_tmp = addr;
		i = length / TMP_LEN;

		for(j = 0; j < i; j++)
		{
			if(at24cxx_write(addr_tmp, zero, TMP_LEN))
			{
				addr_tmp += TMP_LEN;
			}
			else
			{
				flag = FALSE;
				break;
			}
		}

		if(!flag)
		{
			continue;
		}
		
		i = length % TMP_LEN;

		if(i != 0)
		{
			if(at24cxx_write(addr_tmp, zero, i))
			{
				break;
			}
			else
			{
				flag = FALSE;
				continue;
			}
		}
	}

	return flag;
}

