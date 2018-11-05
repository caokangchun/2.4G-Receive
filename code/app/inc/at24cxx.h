
#ifndef __AT24CXX_H__
#define __AT24CXX_H__

#ifdef _AT24C02
#define EE_ADDR	UINT8
#define _E2_PAGE_SIZE	8
#else
#define EE_ADDR	UINT16
#define _E2_PAGE_SIZE	64
#define E2_VOLUME       (32*1024UL)//32KB
#endif

#define AT24CXX_ADDR	0xA0
#define I2C_TRY_TIMES	0x03
#define _E2_WR_WAIT		5

#define IIC_SX			0 // S0

/** Warning C322 : Unknown identifier
-> enum constants cannot be resolved */
#if (IIC_SX == 0) // S0
#define	_iic_ack_ok()	!S0NACK
#else
#define	_iic_ack_ok()	!S1NACK
#endif

#define INIT_CHECK		0x01 			// 2bytes
#define RF_MAC			INIT_CHECK + 2	// 4bytes
#define RF_CH_NO		RF_MAC + 4		// 1byte
#define TOTAL_NUM		RF_CH_NO + 1	// 2byte
#define STORE_ADDR		TOTAL_NUM + 2	// 2bytes
#define DEVICE_ID		STORE_ADDR + 2  // 1byte
#define REPEAT_ID		DEVICE_ID + 1	// 1byte
#define ID_SHOW			REPEAT_ID + 1	// 1byte
#define PREFIX_TYPE		ID_SHOW + 1	// 1byte

#define LAST_DATA		0x20
#define START_ADDR		0x80

extern code UINT8 rf_def_para[5];

void at24cxx_init(void);
UINT8 at24cxx_read(EE_ADDR addr, UINT8 *save, UINT8 length);
UINT8 at24cxx_write(EE_ADDR addr, UINT8 *pdat, UINT8 length);
UINT8 at24cxx_store(EE_ADDR addr, UINT8 *pdat, UINT8 length);
UINT8 at24cxx_clear(EE_ADDR addr, UINT8 length);

#endif /* end of __AT24CXX_H__ */

