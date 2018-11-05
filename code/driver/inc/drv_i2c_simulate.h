
#ifndef __I2C_MASTER_H__
#define __I2C_MASTER_H__

#ifdef _RF_HOST
///////////////////////////---RF_HOST---//////////////////////////////////

#define I2C_SCL_PIN			P25
#define I2C_SDA_PIN			P27

#define I2C_SCL_OUT(a)		I2C_SCL_PIN = a
#define I2C_SDA_OUT(a)		I2C_SDA_PIN = a
#define I2C_SDA_IN			I2C_SDA_PIN

#define I2C_SCL_OUTPUT		P2OE |= BIT_MASK(5)
#define I2C_SDA_OUTPUT		P2OE |= BIT_MASK(7)
#define I2C_SCL_INPUT		P2OE &= ~ BIT_MASK(5)
#define I2C_SDA_INPUT		P2OE &= ~ BIT_MASK(7)

#define I2C_BUS_PULLUP		P2PU |= BIT_MASK(5); P4PU |= BIT_MASK(7);

//////////////////////////////////////////////////////////////////////////
#else
//////////////////////////---RF_SLAVE---//////////////////////////////////

#define I2C_SCL_PIN			P12
#define I2C_SDA_PIN			P17

#define I2C_SCL_OUT(a)		I2C_SCL_PIN = a
#define I2C_SDA_OUT(a)		I2C_SDA_PIN = a
#define I2C_SDA_IN			I2C_SDA_PIN

#define I2C_SCL_OUTPUT		P1OE |= BIT_MASK(2); P1IE &= ~ BIT_MASK(2);
#define I2C_SDA_OUTPUT		P1OE |= BIT_MASK(7); P1IE &= ~ BIT_MASK(7);
#define I2C_SCL_INPUT		P1OE &= ~ BIT_MASK(2); P1IE |= BIT_MASK(2);
#define I2C_SDA_INPUT		P1OE &= ~ BIT_MASK(7); P1IE |= BIT_MASK(7);

#define I2C_BUS_PULLUP		P1PU |= BIT_MASK(2); P1PU |= BIT_MASK(7);
//////////////////////////////////////////////////////////////////////////
#endif /* _RF_HOST */

#if (SYS_CLK == SYS_6MHZ)
#define I2C_ACK_TIME_OUT	50
#define I2C_DELAY			2
#elif (SYS_CLK == SYS_12MHZ)
#define I2C_ACK_TIME_OUT	80
#define I2C_DELAY			3
#elif (SYS_CLK == SYS_24MHZ)
#define I2C_ACK_TIME_OUT	200
#define I2C_DELAY			8
#endif

typedef enum
{
	SEND_ACK,
	SEND_NACK
}ACK_TYPE;

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);

BOOL i2c_write(UINT8 dat);
UINT8 i2c_read(ACK_TYPE ack_type);

#endif /* end of __I2C_MASTER_H__ */

