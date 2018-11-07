
#include "includes.h"

#ifdef _USB_CMD

xdata usb_report_s usb_report _at_ 0x8200;// = {0};

/*************************************************************************
*	Function	: 	usb_report_init
*	Description : 	init report data 
*	Parameters 	: 	data_length -> report valid data length
*	Return 		: 	None
*	Author 		: 	Sycreader
*	Date 		: 	2013 - 09 - 17
***************************************************************************/
static void usb_report_init(UINT8 data_length)
{
	/* clear usb report buff data first */
	memset(usb_report.dat_buff, 0 , _HID_CMD_LEN);
	
	usb_report.dat_buff[0] = 0x03;	// report id + 7 bytes 0
	// between all be zero
	usb_report.dat_buff[8] = 0xAA;//STX;	// data head
	usb_report.dat_buff[9] = 0; 	// machine id
	usb_report.dat_buff[10] = data_length;//data length	
	//user data proc...
	usb_report.dat_buff[data_length + 12] = 0xBB;//ETX; // data end
}


/*************************************************************************
*	Function	: 	usb_return_status
*	Description : 	return err report 
*	Parameters 	: 	err_type -> error type
*	Return 		: 	None
*	Author 		: 	Sycreader
*	Date 		: 	2013 - 10 - 28
***************************************************************************/
static void usb_ret_datas(void)
{
    _sfrb_bank1();

	//Ep0_Send_Table(usb_report.dat_buff, 256);
	Ep0_Send_Table(usb_report.dat_buff, usb_report.dat_buff[10] + 5 + _CMD_STX_LEN);
}


/*************************************************************************
*	Function	: 	usb_return_status
*	Description : 	return err report 
*	Parameters 	: 	err_type -> error type
*	Return 		: 	None
*	Author 		: 	Sycreader
*	Date 		: 	2013 - 10 - 28
***************************************************************************/
static void usb_ret_status(UINT8 status, UINT8 ret_type)
{
	usb_report_init(2); // 2 bytes data

	usb_report.dat_buff[11] = status; 	// STATUS
	usb_report.dat_buff[12] = ret_type;	// ok
	
	/* XOR check for valid data (except STX+ETX) */
	usb_report.dat_buff[13] = usb_report.dat_buff[10] ^ \
							  usb_report.dat_buff[11] ^ \
							  usb_report.dat_buff[12];
    usb_ret_datas();
}

/*************************************************************************
*	Function	: 	usb_set_report
*	Description : 	usb set report
*	Parameters 	: 	ulen -> fifo data length, pCmd -> usb cmd data
*	Return 		: 	None
*	Author 		: 	Sycreader
*	Date 		: 	2013 - 09 - 17
***************************************************************************/
void usb_report_out(UINT8 dat_cnt)
{   
	if(0 == usb_report.dat_total)
	{
		/* first time get valid data total length */
		usb_report.dat_total = _wLengthl;
		usb_report.dat_index = 0;

        if(dat_cnt > _CMD_STX_LEN)
        {
    		memcpy(&usb_report.dat_buff[usb_report.dat_index], &uEP0InOut[8], dat_cnt - _CMD_STX_LEN);
    		usb_report.dat_index += (dat_cnt - _CMD_STX_LEN);
		}
	}
	else
	{
    	memcpy(&usb_report.dat_buff[usb_report.dat_index], uEP0InOut, dat_cnt);
    	usb_report.dat_index += dat_cnt;
	}
}

/*************************************************************************
*	Function	: 	usb_get_report
*	Description : 	usb get report
*	Parameters 	: 	None
*	Return 		: 	None
*	Author 		: 	Sycreader
*	Date 		: 	2013 - 09 - 17
***************************************************************************/
void usb_report_in(void)
{
	switch(usb_report.dat_buff[3]) // usb hid cmd
	{
	    case IAP_JUMP_S :
	        rf_slave.status = RF_UPD_S;
	        usb_ret_status(STATUS_OK, SET_OK);
	        break;
	        
		default:
			usb_ret_status(STATUS_ERR, CMD_ERR); // error cmd
			break;
	}
}

#endif /* _USB_HID */

#ifdef _USB_TX

#include "ascii2hid.h"

//idata UINT8 usb_speed = 0;

//;-------------------------------------------------------------;
//; usb vcom send data, use ep2                                 ;
//;-------------------------------------------------------------;
void usb_speed_set(UINT8 usb_speed)
{
    if(usb_speed == 0)
    {
        // No Delay.
    }
    else if(usb_speed == 1)
    {
        delay_1ms(1); // 1CHAR = 4MS
    }
    else if(usb_speed == 2)
    {
        delay_1ms(3); // 1CHAR = 8MS
    }
    else
    {
        delay_1ms(7); // 1CHAR = 16MS
    }
}

//;-------------------------------------------------------------;
//; usb vcom send data, use ep2                                 ;
//;-------------------------------------------------------------;
void usb_gbk_input(UINT16 gbk,UINT8 speed)
{
    UINT8 i, key[5];

    key[4] = gbk % 10;
    gbk /= 10;
    key[3] = gbk % 10;
    gbk /= 10;
    key[2] = gbk % 10;
    gbk /= 10;
    key[1] = gbk % 10;
    gbk /= 10;
    key[0] = gbk % 10;
    
    usb_key_report(0x04, 0);	usb_speed_set(speed);
    for(i = 0; i < 5; i++)
    {
        if(key[i] == 0)
        {
            key[i] = hid_nk_0;
        }
        else
        {
            key[i] = key[i]-1+hid_nk_1;
        }
        usb_key_report(0x04, key[i]);	usb_speed_set(speed);
        usb_key_report(0x04, 0);		usb_speed_set(speed);
    }
    usb_key_report(0, 0);	usb_speed_set(speed);
}

/*************************************************************************
*	Function	: 	usb_key_send
*	Description : 	usb send usb key value
*	Parameters 	: 	--send_buff -> pointer to data buff to be send
*					--length -> send data length
*					--type -> 0 : Composite keys, !0 : single keys
*	Return 		:	None
*	Author 		: 	Sycreader
*	Date 		: 	2016 - 05 - 25
***************************************************************************/
static char yyy[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static BOOL datacheck(UINT8 *send_buff, UINT16 length)
{
	uint8 i;
	if(length != sizeof(yyy))
		return FALSE;

	for(i=0;i<length-1;i++)
	{
		if(yyy[i] != send_buff[i])
		{
			return FALSE;
		}
	}
	if(0x0d != send_buff[length-1])
	{
		return FALSE;	
	}

	return TRUE;
}

static uint8 countBuf[7]={0,0,0,0,0,0,'\r'};

static void countBufHandle(void)
{
	uint8 carry=0,i=5;
	
	do{
		carry = 0;	
		countBuf[i]++;
		if(countBuf[i] == 10)
		{
			countBuf[i] = 0;
			carry = 1;	
			i--;
			if(i==0xff)
			{
				return;
			}
		}
	}while(carry);
}
BOOL usb_key_send(UINT8 *send_buff, UINT16 length, UINT8 speed)
{
	
	UINT8 dat_buff[8] = {0};
	UINT8 index;
	UINT8 tmp;

	countBufHandle();

	//测试端数据判断
	if(!datacheck(send_buff,length))
	{
		send_buff[0]='e';
		send_buff[1]='r';
		send_buff[2]='r';
		send_buff[3]='o';
		send_buff[4]='r';
		send_buff[5] ='\r';
		length=6;
	}
	else
	{
		send_buff[0]=countBuf[0] + '0';
		send_buff[1]=countBuf[1] + '0';
		send_buff[2]=countBuf[2] + '0';
		send_buff[3]=countBuf[3] + '0';
		send_buff[4]=countBuf[4] + '0';
		send_buff[5]=countBuf[5] + '0';
		send_buff[6] ='\r';
		length=7;
	}
	
    while(length--)
    {
        /* usb device should have enum finished and not in suspend state */
        if(( uDevState != _U_CONFIGURED_STATE_ ) || ( uUsbState & _U_SUSPEND_ ))
        {
            delay_1ms(50);
            return FALSE;
        }
        
        watchdog_feed();

        index = *send_buff++;


        if(index == 0xFF) // gbk head sign
        {
            if(length >= 2)
            {
                UINT16 gbk;
                
                gbk = *send_buff++;
                gbk <<= 8;
                gbk += *send_buff++;
                length -=2;
                
                usb_gbk_input(gbk,speed);
                continue;
            }
            else // not valid len
            {
                return FALSE;
            }
        }
        else
        {
        	if(index >= 0x20)
				usb_gbk_input(index,speed);
			else	//防止有些测试软件打印不了换行符号，只能使用键值
			{

				tmp = (lang_ptr[0])[index].hid;
				
				if(tmp == 0x00)
					continue;
					
				dat_buff[2] = tmp;
				dat_buff[0] = (lang_ptr[0])[index].func;
				//dat_buff[0] = lang_p.func;
			

			
				/* USB Key Send */
				Ep1_Send(dat_buff, 8);
				usb_speed_set(speed);
				
				/* USB key Clear */
				dat_buff[0] = 0;
				dat_buff[2] = 0;
				Ep1_Send(dat_buff, 8);
				usb_speed_set(speed);
			}
        }

    }

    return TRUE;
}
#endif /* _USB_TX */

void usb_int_disable(void)
{
    _sfrb_bank0();
    IE2 &= ~ 0x03;
}

void usb_int_enable(void)
{
    _sfrb_bank0();
    IE2 |= 0x03;
}

