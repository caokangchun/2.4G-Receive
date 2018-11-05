
#ifndef __SERIAL_H__
#define __SERIAL_H__

typedef enum
{
	S0 = 0,
	S1 = 1
}SERIAL_NO;

typedef enum
{
#if (SYS_CLK == SYS_6MHZ)
	SPEED_3M 	= 0x00,
	SPEED_1M 	= 0x02,
	SPEED_375K	= 0x07,
#elif (SYS_CLK == SYS_12MHZ)
    SPEED_3M    = 0x03,
    SPEED_1M    = 0x0B,
#elif (SYS_CLK == SYS_24MHZ)
	SPEED_3M 	= 0x07,
	SPEED_1M 	= 0x17,
	SPEED_375K	= 0x3F,
	SPEED_400K	= 0x3B,
#endif
}SERIAL_BUAD;

typedef enum
{
	SPI_LOW_RISING_TX   = 0x00,
    SPI_HIGH_RISING_TX  = 0x01,
    SPI_LOW_FALLING_TX  = 0x02,
    SPI_HIGH_FALLING_TX = 0x03,

	IIC_TX_START_DATA = 0x08,
    IIC_TX_DATA_STOP  = 0x09,
	IIC_TX_DATA       = 0x0A,
	IIC_RX_DATA       = 0x0B,
	IIC_RX_DATA_STOP  = 0x0C	
}SERIAL_MODE;

#define serial_tx_data(sx, dat)     serial_transceive(sx, dat)
#define serial_rx_data(sx)          serial_transceive(sx, 0)

void serial_baud(SERIAL_NO sx, SERIAL_BUAD baud);
void serial_reset(SERIAL_NO sx);
void serial_mode(SERIAL_NO sx, SERIAL_MODE m);
UINT8 serial_transceive(SERIAL_NO sx, UINT8 dat);

#endif /* end of __SERIAL_H__ */

