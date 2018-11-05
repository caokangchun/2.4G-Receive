
#include "includes.h"

//---------------------------------------------------------------------------------------
//	Description	: 	i2c io init
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
void i2c_init(void)
{
	I2C_BUS_PULLUP;
	
	I2C_SCL_OUT(1);
	I2C_SCL_OUTPUT;

	I2C_SDA_OUT(1);
	I2C_SDA_OUTPUT;
}

void i2c_delay(UINT8 t)
{
	while(t--);
}

//---------------------------------------------------------------------------------------
//	Description	: 	i2c generate start signal
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
void i2c_start(void)
{
	I2C_SDA_OUTPUT;
	I2C_SDA_OUT(1);
	I2C_SCL_OUT(1);
	i2c_delay(I2C_DELAY);
	
	
	/* when scl high, sda falling -> iic start */
	I2C_SDA_OUT(0);
	i2c_delay(I2C_DELAY);
	I2C_SCL_OUT(0);
}


//---------------------------------------------------------------------------------------
//	Description	: 	i2c generate stop signal
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
void i2c_stop(void)
{
	I2C_SDA_OUTPUT;
	I2C_SCL_OUT(0);
	I2C_SDA_OUT(0);
	i2c_delay(I2C_DELAY);

	/* when scl high, sda rising -> iic stop */
	I2C_SCL_OUT(1);
	i2c_delay(I2C_DELAY);
	I2C_SDA_OUT(1);
}


//---------------------------------------------------------------------------------------
//	Description	: 	i2c wait device ack
//	Parameters 	: 	none
//	Return 		: 	TRUE / FALSE -> ack success / fail
//	Author 		: 	Sycreader
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
static BOOL i2c_wait_ack(void)
{
	UINT8 ack_timeout = 0;
	
	I2C_SDA_INPUT;

	i2c_delay(I2C_DELAY);
	I2C_SCL_OUT(1);
	i2c_delay(I2C_DELAY);
	
	/* when scl high, read sda val */
	while(I2C_SDA_IN != 0)
	{
		if(++ack_timeout > I2C_ACK_TIME_OUT)
		{
			return FALSE;
		}
	}
	
	I2C_SCL_OUT(0);
	return TRUE;
}


//---------------------------------------------------------------------------------------
//	Description	: 	i2c send device ack
//	Parameters 	: 	ack_type -> i2c send ack type
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
static void i2c_ack(ACK_TYPE ack_type)
{
	I2C_SDA_OUTPUT;

	if(SEND_ACK == ack_type)
	{
		I2C_SDA_OUT(0);
	}
	else //send nack
	{
		I2C_SDA_OUT(1);		
	}
	i2c_delay(I2C_DELAY);
	
	I2C_SCL_OUT(1);
	i2c_delay(I2C_DELAY);
	I2C_SCL_OUT(0);	
}


//---------------------------------------------------------------------------------------
//	Description	: 	i2c write data
//	Parameters 	: 	dat -> data to be write
//	Return 		: 	TRUE / FALSE -> write success / fail
//	Author 		: 	Sycreader
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
BOOL i2c_write(UINT8 dat)
{
	UINT8 i;
	
	I2C_SDA_OUTPUT;

	for(i = 0; i < 8; i++)
	{
		if(dat & 0x80) //MSB first
		{
			I2C_SDA_OUT(1);
		}
		else
		{
			I2C_SDA_OUT(0);
		}

	#if (SYS_CLK == SYS_24MHZ)
		i2c_delay(I2C_DELAY);
	#endif
		I2C_SCL_OUT(1);
		i2c_delay(I2C_DELAY);
		I2C_SCL_OUT(0);

		dat <<= 1; //next bit
	}

	return i2c_wait_ack();
}


//---------------------------------------------------------------------------------------
//	Description	: 	i2c read sda data
//	Parameters 	: 	ack_type -> i2c send ack type
//	Return 		: 	dat -> data to be read
//	Author 		: 	Sycreader
//	Date		:	2013 - 09 - 16
//---------------------------------------------------------------------------------------
UINT8 i2c_read(ACK_TYPE ack_type)
{
	UINT8 i;
	UINT8 dat;

	I2C_SDA_INPUT;

	for(i = 0; i < 8; i++)
	{
		i2c_delay(I2C_DELAY);
		I2C_SCL_OUT(1);
		i2c_delay(I2C_DELAY);

		dat <<= 1;
		dat |= I2C_SDA_IN; //get SDA dat in
		
		I2C_SCL_OUT(0);		
	}

	i2c_ack(ack_type);
	return dat;
}


