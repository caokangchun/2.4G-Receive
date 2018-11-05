
#include "includes.h"

idata RF_CONTROL pn3020 =
{
	/*.ch_no     = */0,
//	/*.ch_index  = */0,
//	/*.ch_pipe 	 = */0,
//	/*.mac[0] 	 = */0x0F,
//	/*.mac[1] 	 = */0x1E,
//	/*.mac[2] 	 = */0x2D,
//	/*.mac[3] 	 = */0x3C
};

code UINT8 pn3020_init_seq[] = 
{    
	( CMD_FLUSH_RX /*0xE2*/ ), 0x01, ( 0x00 ), /* CLEAR RXFIFO */
    ( CMD_FLUSH_TX /*0xE1*/ ), 0x01, ( 0x00 ), /* CLEAR TXFIFO */
    
    ( REG_STATUS    /*0x07*/ | CMD_W_REGISTER ), 0x01, ( _RX_DR | _TX_DS | _MAX_RT ),
    ( REG_RF_CH     /*0x05*/ | CMD_W_REGISTER ), 0x01, ( 0x00 ), /* default ch0 */
    ( REG_RX_PW_P0  /*0x11*/ | CMD_W_REGISTER ), 0x01, ( RF_FIFO_MAX ), /* set fifo length */
    ( REG_SETUP_AW  /*0x03*/ | CMD_W_REGISTER ), 0x01, ( _SETUP_AW_5B ), /* 5byte width */
    ( REG_EN_RXADDR /*0x02*/ | CMD_W_REGISTER ), 0x01, ( _ENRX_P0 ),
    ( REG_TX_ADDR   /*0x10*/ | CMD_W_REGISTER ), 0x05, 0x1F, 0x2E, 0x3D, 0x4C, 0x5D,
    ( REG_RX_ADDR_P0/*0x0A*/ | CMD_W_REGISTER ), 0x05, 0x1F, 0x2E, 0x3D, 0x4C, 0x5D,

#if ( RF_DATA_RATE == RF_RATE_40K )
    ( REG_BB_CAL    /*0x1F*/ | CMD_W_REGISTER ), 0x05, 0x3F, 0xFC, 0x1F, 0x1F, 0x04,
    ( REG_DEM_CAL1  /*0x19*/ | CMD_W_REGISTER ), 0x05, 0x01, 0x4D, 0x48, 0x34, 0x8C,
    ( REG_DEM_CAL2  /*0x1B*/ | CMD_W_REGISTER ), 0x04, 0x0B, 0xE7, 0x00, 0x00,
    //( REG_RF_CAL    /*0x1E*/ | CMD_W_REGISTER ), 0x05, 0xC4, 0xFF, 0xFF, 0x5F, 0xD8, /* 18dbm */
    //( REG_RF_CAL    /*0x1E*/ | CMD_W_REGISTER ), 0x05, 0xC4, 0xF9, 0xF8, 0x5F, 0xD8, /* 9dbm */
    ( REG_RF_CAL    /*0x1E*/ | CMD_W_REGISTER ), 0x05, 0xC4, 0xF9, 0xF9, 0x5F, 0xD8, /* 14dbm */
    ( REG_RF_CAL2   /*0x1A*/ | CMD_W_REGISTER ), 0x05, 0xC8, 0x1E, 0x68, 0x39, 0xF6,
    ( REG_RF_CAL3   /*0x18*/ | CMD_W_REGISTER ), 0x05, 0x01, 0x08, 0xD4, 0x02, 0x66,
#elif ( RF_DATA_RATE == RF_RATE_200K )
    ( REG_BB_CAL    /*0x1F*/ | CMD_W_REGISTER ), 0x05, 0x3F, 0xFC, 0x1F, 0x1F, 0x04,
    ( REG_DEM_CAL1  /*0x19*/ | CMD_W_REGISTER ), 0x05, 0x01, 0x8C, 0x48, 0x4C, 0x84,
    ( REG_DEM_CAL2  /*0x1B*/ | CMD_W_REGISTER ), 0x04, 0x0B, 0xE7, 0x00, 0x00,
    //( REG_RF_CAL    /*0x1E*/ | CMD_W_REGISTER ), 0x05, 0xC4, 0xFF, 0xFF, 0xDF, 0xD9, /* 18dbm */
    //( REG_RF_CAL    /*0x1E*/ | CMD_W_REGISTER ), 0x05, 0xC4, 0xF9, 0xF8, 0xDF, 0xD9, /* 9dbm */
    ( REG_RF_CAL    /*0x1E*/ | CMD_W_REGISTER ), 0x05, 0xC4, 0xF9, 0xF9, 0xDF, 0xD9, /* 14dbm */
    ( REG_RF_CAL2   /*0x1A*/ | CMD_W_REGISTER ), 0x05, 0xC8, 0x1E, 0x68, 0x39, 0xF6,
    ( REG_RF_CAL3   /*0x18*/ | CMD_W_REGISTER ), 0x05, 0x01, 0x08, 0xD4, 0x02, 0x66,
#endif /* 0 */

    ( REG_DYNPD     /*0x1C*/ | CMD_W_REGISTER ), 0x01, ( _DPL_P0 ), /* Pipe0 Dynamic data length */

#ifdef RF_AUTO_ACK
    ( REG_SETUP_RETR/*0x04*/ | CMD_W_REGISTER ), 0x01, ( _ARD_1210us | _ARC_3 ),
    ( REG_EN_AA     /*0x01*/ | CMD_W_REGISTER ), 0x01, ( _ENAA_P0 ), /* _ENAA_P0 */
#else
    ( REG_SETUP_RETR/*0x04*/ | CMD_W_REGISTER ), 0x01, ( 0x00 ),
    ( REG_EN_AA     /*0x01*/ | CMD_W_REGISTER ), 0x01, ( 0x00 ),
#endif /* 0 */

    ( CMD_ACTIVATE /*0x50*/ ), 0x01, ( 0x73 ), /* R_RX_PL_WID Enable */

    ( REG_FEATURE   /*0x1D*/ | CMD_W_REGISTER ), 0x01, ( _EN_DPL |
                                                    #ifdef RF_ACK_PLD
                                                        _EN_ACK_PAY |
                                                    #else
                                                        _DATA_LEN_SEL_64B | 
                                                    #endif /* RF_ACK_PLD */
                                                    #ifdef RF_CE_SOFT
                                                        _CE_SEL |
                                                    #endif /* RF_CE_SOFT */
                                                        0 ),
#if ( RF_DATA_RATE == RF_RATE_40K )                                                        
    ( REG_RF_SETUP  /*0x06*/ | CMD_W_REGISTER ), 0x01, ( _RF_DR_40K | 0x12), /* Data Rate and Channel */
#elif ( RF_DATA_RATE == RF_RATE_200K )
    ( REG_RF_SETUP  /*0x06*/ | CMD_W_REGISTER ), 0x01, ( _RF_DR_200K | 0x12), /* Data Rate and Channel */
#endif

	0xFF // reg int end sign
};


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 reg write
//	Parameters 	: 	reg_addr -> reg addr, reg_dat -> data to be write
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2013 - 03 - 26
//---------------------------------------------------------------------------------------
static void pn3020_write_1byte(UINT8 reg_addr, UINT8 reg_dat)
{
    _sfrb_bank1();
	PN3020_CS = 0;
	
	pn3020_spi_mode(SPI_LOW_FALLING_TX);
	pn3020_spi_send(reg_addr); //reg address
	pn3020_spi_send(reg_dat);  //reg data

    _sfrb_bank1();
	PN3020_CS = 1;
	pn3020_spi_reset();
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 reg write
//	Parameters 	: 	reg_addr -> reg addr, reg_dat -> data to be write
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2013 - 03 - 26
//---------------------------------------------------------------------------------------
static void pn3020_write_bytes(UINT8 reg_addr, UINT8 *reg_dat, UINT8 dat_len)
{
	UINT8 i;
	
    _sfrb_bank1();
	PN3020_CS = 0;
	
	pn3020_spi_mode(SPI_LOW_FALLING_TX);
	pn3020_spi_send(reg_addr); //reg address

	for(i = 0; i < dat_len; i++)
	{
		pn3020_spi_send(*reg_dat++); //reg data
	}
	
    _sfrb_bank1();
	PN3020_CS = 1;
	pn3020_spi_reset();
}

#if 0
static void pn3020_write_bytes1(UINT8 reg_addr, UINT8 code *reg_dat, UINT8 dat_len)
{
	UINT8 i;
	
    _sfrb_bank1();
	PN3020_CS = 0;
	
	pn3020_spi_mode(SPI_LOW_FALLING_TX);
	pn3020_spi_send(reg_addr); //reg address
	//uart_send_byte(reg_addr);

	for(i = 0; i < dat_len; i++)
	{
        //uart_send_byte(*reg_dat);
		pn3020_spi_send(*reg_dat++); //reg data
	}

    _sfrb_bank1();
	PN3020_CS = 1;
	pn3020_spi_reset();
	
    _sfrb_bank0();
}
#endif /* 0 */

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 reg read
//	Parameters 	: 	reg_addr -> reg address
//	Return 		: 	read out data
//	Author 		: 	Sycreader
//	Date		:	2013 - 03 - 26
//---------------------------------------------------------------------------------------
void pn3020_read_1byte(UINT8 reg_addr, UINT8 *reg_dat)
{
    _sfrb_bank1();
	PN3020_CS = 0;
	
	pn3020_spi_mode(SPI_LOW_FALLING_TX);
	pn3020_spi_send(reg_addr);//reg address

	//pn3020_spi_mode(SPI_LOW_FALLING_TX);
	*reg_dat = pn3020_spi_recv(0); //reg data
	
    _sfrb_bank1();
	PN3020_CS = 1;
	pn3020_spi_reset();
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 reg read
//	Parameters 	: 	reg_addr -> reg address
//	Return 		: 	read out data
//	Author 		: 	Sycreader
//	Date		:	2013 - 03 - 26
//---------------------------------------------------------------------------------------
static void pn3020_read_bytes(UINT8 reg_addr, UINT8 *reg_dat, UINT8 dat_len)
{
	UINT8 i;
	
    _sfrb_bank1();
	PN3020_CS = 0;
	
	pn3020_spi_mode(SPI_LOW_FALLING_TX);
	pn3020_spi_send(reg_addr);//reg address

	//pn3020_spi_mode(SPI_LOW_FALLING_TX);

	for(i = 0; i < dat_len; i++)
	{
		*reg_dat++ = pn3020_spi_recv(0); //reg data
	}
	
    _sfrb_bank1();
	PN3020_CS = 1;
	pn3020_spi_reset();
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 sleep mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 03 - 26
//---------------------------------------------------------------------------------------
void pn3020_clear_tx_fifo(void)
{
	pn3020_write_1byte(CMD_FLUSH_TX, 0);
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 sleep mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 03 - 26
//---------------------------------------------------------------------------------------
void pn3020_clear_rx_fifo(void)
{
	pn3020_write_1byte(CMD_FLUSH_RX, 0);
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 sleep mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 03 - 26
//---------------------------------------------------------------------------------------
void pn3020_fifo_flush(UINT8 flush_mask)
{
    if(flush_mask & FLUSH_TX)
    {
        /* clear tx fifo */
        pn3020_clear_tx_fifo();
    }

    if(flush_mask & FLUSH_RX)
    {
        /* clear rx fifo */
        pn3020_clear_rx_fifo();
    }
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 write fifo
//	Parameters 	: 	src - data buff pointer, length - data length
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 04 - 17
//---------------------------------------------------------------------------------------
static void pn3020_write_pld_fifo(UINT8 *src, UINT8 length)
{
	if(length > RF_FIFO_MAX) /* fifo max = 32 */
	{
		length = RF_FIFO_MAX;
	}
	
	pn3020_write_bytes(CMD_W_TX_PAYLOAD, src, length);
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 write fifo
//	Parameters 	: 	src - data buff pointer, length - data length
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 04 - 17
//---------------------------------------------------------------------------------------
static void pn3020_write_ack_fifo(UINT8 pipex, UINT8 *src, UINT8 length)
{
	if(length > RF_FIFO_MAX) /* fifo max = 32 */
	{
		length = RF_FIFO_MAX;
	}
	
	pn3020_write_bytes(CMD_W_ACK_PAYLOAD | pipex, src, length);
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 read fifo
//	Parameters 	: 	dst - data buff pointer, rx_len - data length
//	Return 		: 	true/false - get data success/fail
//	Author 		: 	Sycreader
//	Date		:	2013 - 04 - 17
//---------------------------------------------------------------------------------------
static void pn3020_fifo_read(UINT8 *dst, UINT8 dst_len, UINT8 *rx_len)
{
	UINT8 fifo_len;

	pn3020_read_1byte(CMD_R_RX_PL_WID, &fifo_len);
	//printf("fifo len=%d\r\n", (UINT16)fifo_len);
	//uart_send_byte(fifo_len);

	if(fifo_len != 0)
	{
    	if(dst_len > fifo_len)
    	{
    		dst_len = fifo_len;
    	}
    	
    	pn3020_read_bytes(CMD_R_RX_PAYLOAD, dst, dst_len);
	}
	else
	{
	    dst_len = 0;
	}
	
	*rx_len = dst_len;
}

#ifdef RF_CE_SOFT

//static INT8 ce_status = -1;

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 rf channel config
//	Parameters 	: 	rf_ch - rf channel
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_set_ce_1(void)
{
    //if(ce_status != 1)
    {
        //ce_status = 1;
	    pn3020_write_1byte(CMD_CE_FSPI_ON, 0);
	}
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 rf channel config
//	Parameters 	: 	rf_ch - rf channel
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_set_ce_0(void)
{
    //if(ce_status != 0)
    {
        //ce_status = 0;
	    pn3020_write_1byte(CMD_CE_FSPI_OFF, 0);
	}
}

#endif /* RF_CE_SOFT */

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 mac config
//	Parameters 	: 	mac - sync word
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_set_mac(UINT8 *mac)
{
	pn3020_write_bytes(REG_TX_ADDR | CMD_W_REGISTER , mac, 4);
	pn3020_write_bytes(REG_RX_ADDR_P0 | CMD_W_REGISTER , mac, 4);
}

code UINT8 Dem_cal2_dat0[4] = {0x0B, 0xE7, 0x00, 0x00};
code UINT8 Dem_cal2_dat1[4] = {0x0B, 0xE7, 0x00, 0x03}; // Dataout_Sel = 1
code UINT8 RF_cal3_dat0[5] = {0x01, 0x08, 0xD4, 0x02, 0x76}; // Vco_Calibration EN
code UINT8 RF_cal3_dat1[5] = {0x01, 0x18, 0xD4, 0x02, 0x76}; // Vco_Calibration_SPI_Triger
//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 mac config
//	Parameters 	: 	mac - sync word
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_calibrate_vco(void)
{
    UINT8 i = 0, j = 0, h = 0;
    
#if ( RF_DATA_RATE == RF_RATE_40K )
    UINT8 Dem_cal1_dat[5] = {0x01, 0x4D, 0x48, 0x34, 0x8C}; // 40K
#elif ( RF_DATA_RATE == RF_RATE_200K )
    UINT8 Dem_cal1_dat[5] = {0x01, 0x8C, 0x48, 0x4C, 0x84}; // 200K
#endif

	pn3020_goto_wakeup();
	
    pn3020_goto_rx();
    delay_1ms(5);
	pn3020_rx_start();
    delay_1ms(2);

    pn3020_write_bytes(CMD_W_REGISTER + REG_DEM_CAL2, Dem_cal2_dat1, sizeof(Dem_cal2_dat1)); 
    pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL3, RF_cal3_dat0, sizeof(RF_cal3_dat0)); 
    pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL3, RF_cal3_dat1, sizeof(RF_cal3_dat1)); 
    delay_1ms(5);
    
    pn3020_read_1byte(REG_DATAOUT, &i);                                                                     
    pn3020_read_1byte(REG_FIFO_STATUS, &j);
    i >>= 2;
    i &= 0x30;
    j &= 0x0C;
    h = i | j;
    Dem_cal1_dat[1] &= 0xC3;
    Dem_cal1_dat[1] |= h;   
    
    pn3020_write_bytes(CMD_W_REGISTER + REG_DEM_CAL2, Dem_cal2_dat0, sizeof(Dem_cal2_dat0));
    pn3020_write_bytes(CMD_W_REGISTER + REG_DEM_CAL1, Dem_cal1_dat, sizeof(Dem_cal1_dat));
    
    RF_CE_SET_LOW;

	pn3020_goto_idle();
    pn3020_goto_sleep();
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 rf channel config
//	Parameters 	: 	rf_ch - rf channel
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_set_channel(UINT8 rf_ch)
{
	pn3020_write_1byte(REG_RF_CH | CMD_W_REGISTER, rf_ch & (~ BIT_MASK(7)));
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 rf channel config
//	Parameters 	: 	rf_ch - rf channel
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_channel_conf(UINT8 Fb, UINT8 Fc)
{
#if ( RF_DATA_RATE == RF_RATE_40K )
    pn3020_write_1byte(CMD_W_REGISTER + REG_RF_SETUP, Fb | _RF_DR_40K);
#elif ( RF_DATA_RATE == RF_RATE_200K )
    pn3020_write_1byte(CMD_W_REGISTER + REG_RF_SETUP, Fb | _RF_DR_200K);
#endif
    
    pn3020_write_1byte(CMD_W_REGISTER + REG_RF_CH, Fc);

    pn3020_calibrate_vco();
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 idle mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 04 - 15
//---------------------------------------------------------------------------------------
void pn3020_goto_idle(void)
{
    RF_CE_SET_LOW;

	pn3020_write_1byte(REG_CONFIG | CMD_W_REGISTER, \
						( _PWR_UP | _MASK_RX_DR | _MASK_TX_DS | _MASK_MAX_RT | _EN_CRC | _CRC_2B |
					#ifdef _RF_HOST
						0 ));
					#else
						_PRIM_RX));
					#endif
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 sleep mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 03 - 26
//---------------------------------------------------------------------------------------
void pn3020_goto_sleep(void)
{
    RF_CE_SET_LOW;

	pn3020_write_1byte(REG_CONFIG | CMD_W_REGISTER, \
						( _MASK_RX_DR | _MASK_TX_DS | _MASK_MAX_RT | _EN_CRC | _CRC_2B |
					#ifdef _RF_HOST
						0 ));
					#else
						_PRIM_RX));
					#endif
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 idle mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 04 - 15
//---------------------------------------------------------------------------------------
void pn3020_goto_wakeup(void)
{
    pn3020_goto_idle(); // standby 1 state
    
    delay_1ms(2);  // wait startup done
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_goto_tx(void)
{
    RF_CE_SET_LOW;

	pn3020_write_1byte(REG_CONFIG | CMD_W_REGISTER, \
						( /*_MASK_RX_DR |*/ _EN_CRC | _CRC_2B | _PWR_UP ));
    delay_1us(10);
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_goto_rx(void)
{
    RF_CE_SET_LOW;

	pn3020_write_1byte(REG_CONFIG | CMD_W_REGISTER, \
						( _MASK_TX_DS | _MASK_MAX_RT | _EN_CRC | _CRC_2B | _PWR_UP | _PRIM_RX ));
    delay_1us(10);
}

code UINT8 RF_cal3_tmp0[] = {0x01, 0x08, 0xD4, 0x02, 0x64};
code UINT8 RF_cal3_tmp1[] = {0x01, 0x08, 0xD4, 0x02, 0x66};

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
static void pn3020_clk_patch(void)
{
    pn3020_write_bytes(REG_RF_CAL3 | CMD_W_REGISTER,  RF_cal3_tmp0,  sizeof(RF_cal3_tmp0));
    delay_1us(15);
    pn3020_write_bytes(REG_RF_CAL3 | CMD_W_REGISTER,  RF_cal3_tmp1,  sizeof(RF_cal3_tmp1));
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_tx_start(void)
{   
    RF_CE_SET_HIGH;
    delay_1us(150);
    
    pn3020_clk_patch();
    
    RF_CE_SET_LOW;
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_rx_start(void)
{
    RF_CE_SET_HIGH;
    
    delay_1us(150);

    pn3020_clk_patch();
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_tx_data(UINT8 *tx_dat, UINT8 tx_len, UINT8 flush_mask)
{
    /* rf tx state */
    pn3020_goto_tx();
    
    /* clear all fifo */
    pn3020_fifo_flush(flush_mask);
    
    /* clear all irq flags */
    pn3020_clear_irq_flag(RF_IRQ_FLAGS);
    
    /* write data to tx payload fifo */
    pn3020_write_pld_fifo(tx_dat, tx_len);
    
    /* rf tx start */
    pn3020_tx_start();
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_rx_data(UINT8 *tx_ack, UINT8 tx_len, UINT8 flush_mask)
{
    /* rf rx state */
    pn3020_goto_rx();

    /*
     * why cann't clear tx fifo
     * under ack with payload mode ?
     */
#ifdef RF_ACK_PLD
    /* void compiler warning */
	flush_mask = flush_mask;
	
    /* clear rx fifo */
    pn3020_clear_rx_fifo();

    /* write data to ack payload fifo */
    pn3020_write_ack_fifo(0, tx_ack, tx_len);
#else
    /* clear all fifo */
    pn3020_fifo_flush(flush_mask);
#endif /* RF_ACK_PLD */

    /* clear all irq flags */
    pn3020_clear_irq_flag(RF_IRQ_FLAGS);

    /* rf rx start */
	pn3020_rx_start();
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
void pn3020_clear_irq_flag(UINT8 irq_flag)
{
	pn3020_write_1byte(REG_STATUS | CMD_W_REGISTER, irq_flag & (_RX_DR | _TX_DS | _MAX_RT));
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
UINT8 pn3020_get_irq_flag(void)
{
	UINT8 flag;
	
	pn3020_read_1byte(REG_STATUS | CMD_R_REGISTER, &flag);

	return (flag & ( _RX_DR | _TX_DS | _MAX_RT ));
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 tx mode
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
static void pn3020_chip_reset(void)
{
	pn3020_write_1byte(CMD_RST_FSPI, 0x5A);
	delay_1ms(5);
	pn3020_write_1byte(CMD_RST_FSPI, 0xA5);
	delay_1ms(20);
}


//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 initial
//	Parameters 	: 	none
//	Return 		: 	true/false - init success/fail
//	Author 		: 	Sycreader
//	Date		:	2013 - 03 - 26
//---------------------------------------------------------------------------------------
BOOL pn3020_init(void)
{
	UINT8 addr;
	UINT8 bytes;
	UINT8 *dat = pn3020_init_seq;//NULL;
	UINT8 index = 0;

	//dat = pn3020_init_seq;
	
#if 1
    pn3020_chip_reset();
#else
    PN3020_CE = 0;
    delay_1ms(10);
#endif /* 0 */

	while(1)
	{
		addr = dat[index++];
		
		if(addr != 0xFF)
		{
			bytes = dat[index++];
			//printf("byte:%d\r\n", (UINT16)bytes);
			
			if(bytes != 0x01)
			{
				pn3020_write_bytes(addr, &dat[index], bytes);
			}
			else
			{
				UINT8 tmp;
				
				pn3020_write_1byte(addr, dat[index]);

				tmp = addr & ~CMD_W_REGISTER;
				/* check bank0 0~6 reg */
				if((tmp < 0x07) || (0x11 == tmp) || (0x1C == tmp) || (0x1D == tmp))
				{
					pn3020_read_1byte(tmp, &tmp);
					printf("wr=%x,rd=%x\r\n", (UINT16)(dat[index]), (UINT16)tmp);

					/* check if write success */
					if(tmp != (dat[index]))
					{
						printf("pn3020 init err.\r\n");
						return FALSE;
					}
				}
			}
			
			index += bytes;
		}
		else
		{
			break;
		}
	}
	
	delay_1ms(1);

    //pn3020_read_1byte(REG_RX_PW_P0, &addr);
	//uart0_send_byte(addr);
	
	//pn3020_set_channel(pn3020.ch_no);
	//pn3020_set_mac(pn3020.mac);	
	
	printf("pn3020 init ok.\r\n");
	return TRUE;
}

//---------------------------------------------------------------------------------------
//	Description	: 	pn3020 send data
//	Parameters 	: 	src - data to be send, tx_len - src length, time_out - send time out
//	Return 		: 	true/false - send success/fail
//	Author 		: 	Sycreader
//	Date		:	2013 - 08 - 18
//---------------------------------------------------------------------------------------
BOOL pn3020_transceive (
	RF_DIR rf_dir, UINT8 t_out,
	UINT8 *tx_src, UINT8 tx_len,
	UINT8 *rx_dst, UINT8 dst_len, UINT8 *rx_len
)
{    
	BOOL flag = FALSE;
	
	/* pkt io config */
	pkt_int_enable();
	
	/* clear pkt int */
	pkt_int_clear();
	
	/* wait ack signal */
	delay_tick = 0;
    
	/* rf host transfer */
	if(RF_TRANSFER == rf_dir)
	{
        /* host tx data to slave */
		pn3020_tx_data(tx_src, tx_len, FLUSH_TX);
	}
	else // for RF_RECEIVER
	{
        /* slave rx data from host */
		pn3020_rx_data(tx_src, tx_len, FLUSH_RX);
	}
	
	while(delay_tick < t_out)
	{
	#ifdef _RF_HOST
		/* idle for low power */
		mcu_goto_idle();
	#endif

	    watchdog_feed();

        _sfrb_bank0();
		/* wait for rf irq */
		if(0 == PN3020_PKT)
		{
			UINT8 irq_flag;
			
			irq_flag = pn3020_get_irq_flag();
            //printf("irq=%x.\r\n", (UINT16)irq_flag);
            //uart0_send_byte(irq_flag);

            if(irq_flag != 0)
            {
    			/* rf host transfer */
    			if(RF_TRANSFER == rf_dir)
    			{
    				/* TX_DS = 1:rf get ack */
    				if(irq_flag & (_TX_DS | _RX_DR))
    				{
    				    if(!(irq_flag & _MAX_RT))
    				    {
    				    #ifdef RF_ACK_PLD
    				        if(irq_flag & _RX_DR)
        				    {
            					//printf("get ack.\r\n");
            					flag = TRUE;
        				    }
        				    else
        				    {
        				        // clear data send flag first
        				        // then wait rx ack flag
        				        pn3020_clear_irq_flag(_TX_DS);
        					    continue;
        					}
        				#else
                            flag = TRUE;
        					goto RF_CLEAR;
        				#endif
    					}
    					else
    					{
    					    // _MAX_RT for tx fail
                            goto RF_CLEAR;
    					}
    				}
    				else
    				{
                        /* error status */
    					goto RF_CLEAR;
    				}
    			}
    			else // for RF_RECEIVER
    			{
    				/* only get rx data */
    				if(irq_flag & _RX_DR)
    				{
    					//RF_CE_SET_LOW;
    					
    					/* ack has not tx done */
    					delay_1ms(5); // time for ack
    					
    					flag = TRUE;
    				}
    				else // err state
    				{
    					goto RF_CLEAR;
    				}
    			}
    			
    			/* get rf fifo data */
    			pn3020_fifo_read(rx_dst, dst_len, rx_len);

    			if(*rx_len == 0)
    			{
    			    flag = FALSE;
    			}
    			
    		RF_CLEAR:
                /* clear all fifo */
                pn3020_fifo_flush(FLUSH_ALL);
    			
    		    /* clear irq flag */
                pn3020_clear_irq_flag(irq_flag);
    			break;
			}
		}

	}

	/* pkt io reset */
	pkt_int_disable();
	pkt_int_clear();

	/* rf goto idle state */
	pn3020_goto_idle();
	
	return flag;
}


#ifdef RF_CARRIER

#define         RF18DBM                        1
#define         RF14DBM                        2
#define         RF9DBM                         3
#define         RF1DBM                         4

#define         RF_POWER                       RF18DBM   
#define         FB_DEFAULT                     0X11
#define         FC_DEFAULT                     0X01

/******************************************************************************/
//            RF_SetPower
//      in: RF_cal1_data
//      in: power   ndbm ,define by rf.h
/******************************************************************************/
void RF_SetPower( UINT8 * p,UINT8 power)
{    
    switch (power)
    {
    case RF18DBM :         
        *(p+1) &= ~0xfe;//8-15
        *(p+1) |= 0xfe;
        *(p+2) &= ~0x07;//16-23
        *(p+2) |= 0x07;  
        pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL,   p, 5);    
        break;
        
    case RF14DBM:
      
        *(p+1) &= ~0xfe;
        *(p+1) |= 0xf8;
        *(p+2) &= ~0x07;
        *(p+2) |= 0x01;  
        pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL,   p, 5); 
        break;
        
    case RF9DBM:
         *(p+1) &= ~0xfe;
        *(p+1) |= 0xf8;
        *(p+2) &= ~0x07;
        *(p+2) |= 0x00;  
        pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL,   p, 5);     
        break;
            
    case RF1DBM:
        *(p+1) &= ~0xfe;
        *(p+1) |= 0x60;
        *(p+2) &= ~0x07;
        *(p+2) |= 0x00;  
        pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL,   p, 5);     
        break;
   
        
     default:
        break;
     }
   
}

/******************************************************************************/
//in Fb[5:0], FC[8:1]
// return none
//315   fre = 1/6*8000000*(200+fb+fc/400)hz
//433  fre = 1/4*8000000*(200+fb+fc/400)hz=400Mhz+2fbMhz+50fckHz
//868 915 feq = 1/2*8000000*(200+fb+fc/400)hz=800Mhz+4fbMhz+100kHz
// for example fre= 434.1khz ,Fb=0x11  Fc=0x01.  default fc[0]=0,only set fc[8:1](reg5) .

/******************************************************************************/

void RF_SetChannel(UINT8 Fb,UINT8 Fc )
{
        UINT8 RFSetup_temp = 0;
        Fb &= 0x3f;
        pn3020_read_1byte(REG_RF_SETUP, &RFSetup_temp);
        RFSetup_temp = (RFSetup_temp&0xc0);
        RFSetup_temp |= Fb;
        pn3020_write_1byte(CMD_W_REGISTER + REG_RF_SETUP,RFSetup_temp);        
        pn3020_write_1byte(CMD_W_REGISTER + REG_RF_CH,Fc);        
  
}

void RF_Carrier(void)
{
    UINT8 BB_cal_data[]     = {0x09,0x04,0x07,0x1F,0x05};
    UINT8 Dem_cal1_data[]   = {0xE1,0x8e,0x48,0x4c,0x80};
    UINT8 Dem_cal2_data[]   = {0x0B,0xE7,0x00,0x05};
    UINT8 RF_cal1_data[]    = {0xC4,0xFF,0xFF,0xDF,0xDB};
    UINT8 RF_cal2_data[]    = {0xC8,0x1E,0x68,0x39,0xF6};
    UINT8 RF_cal3_data[]    = {0x01,0x08,0xD4,0x02,0x66};
    static UINT8 tmp = 0;

#ifdef _SPI_HARDWARE
    serial_baud(pn3020_spi_no, SPEED_3M);
#else
    spi_half_duplex_init();
#endif /* _SPI_HARDWARE */
    
    //pn3020_chip_reset();
	pn3020_goto_wakeup();
	RF_CE_SET_HIGH;
    delay_1ms(5);
    pn3020_write_1byte(CMD_W_REGISTER + REG_CONFIG, 0x0E);
    pn3020_write_1byte(CMD_W_REGISTER + REG_RF_SETUP,  0xd2);
    RF_SetChannel(FB_DEFAULT, FC_DEFAULT);
    //pn3020_write_1byte(CMD_W_REGISTER + REG_RF_CH, ucChannel_Set);
    pn3020_read_1byte(CMD_R_REGISTER + REG_RF_CH , &tmp);
    tmp = 0;
    pn3020_write_bytes(CMD_W_REGISTER + REG_BB_CAL,  BB_cal_data,  sizeof(BB_cal_data));
    pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL2,  RF_cal2_data,  sizeof(RF_cal2_data));
    pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL3,  RF_cal3_data,  sizeof(RF_cal3_data));
    pn3020_write_bytes(CMD_W_REGISTER + REG_DEM_CAL2, Dem_cal2_data, sizeof(Dem_cal2_data));
    delay_1ms(5);
    pn3020_write_bytes(CMD_W_REGISTER + REG_DEM_CAL1, Dem_cal1_data, sizeof(Dem_cal1_data));
    delay_1ms(5);
    //pn3020_write_bytes(CMD_W_REGISTER + REG_RF_CAL,  RF_cal1_data,  sizeof(RF_cal1_data));
    RF_SetPower(RF_cal1_data,RF_POWER);

    //pn3020_clk_patch();
    RF_CE_SET_LOW;	

    while(1);
}
#endif /* RF_CARRIER */


