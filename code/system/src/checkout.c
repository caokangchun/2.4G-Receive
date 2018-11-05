
#include "includes.h"

//---------------------------------------------------------------------------------------
//	Description	: 	calc XOR check value
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2014 - 09 - 22
//---------------------------------------------------------------------------------------
UINT8 calc_xor_value(const UINT8 *src, UINT8 len)
{
	UINT8 i, tmp;

	for(i = 0, tmp = 0; i < len; i++)
	{
		tmp ^= src[i];
	}

	return tmp;
}


//---------------------------------------------------------------------------------------
//	Description	: 	data XOR check
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2014 - 09 - 22
//---------------------------------------------------------------------------------------
BOOL data_xor_check(const UINT8 *src, UINT8 len, UINT8 xor)
{
	UINT8 tmp;

	tmp = calc_xor_value(src, len);

	if(tmp == xor)
	{
		return TRUE;
	}

	return FALSE;
}


//---------------------------------------------------------------------------------------
//	Description	: 	zero value check
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2014 - 09 - 27
//---------------------------------------------------------------------------------------
BOOL data_zero_check(const UINT8 *src, UINT8 len)
{
	UINT8 i;

	for(i = 0; i < len; i++)
	{
		if(src[i] != 0)
		{
			return FALSE;
		}
	}

	return TRUE;
}

//---------------------------------------------------------------------------------------
//	Description	: 	zero value check
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	RAY
//	Date		:	2014 - 09 - 27
//---------------------------------------------------------------------------------------
UINT8 calc_sum_value(const UINT8 *src, UINT8 len)
{
    UINT8 i;
    UINT8 sum = 0;

    for(i = 0; i < len; i++)
    {
        sum += src[i];
    }

    return sum;
}

#define POLY        0x1021
#define INIT        0xFFFF

/** 
 * Calculating CRC-16 in 'C' 
 * @para addr, start of data 
 * @para num, length of data 
 * @para crc, incoming CRC 
 */  
UINT16 calc_crc16_ccitt(UINT8 *pdat, UINT8 len)
{
    UINT8 i, j;
    UINT16 crc_reg = INIT;
    UINT16 crc_cur;
    
    for (i = 0; i < len; i++)                   /* Step through bytes in memory */
    {
        crc_cur = pdat[i];
        crc_cur <<= 8;                          /* Fetch byte from memory */
        crc_reg ^= crc_cur;                     /* XOR into CRC top byte*/
        for (j = 0; j < 8; j++)                 /* Prepare to rotate 8 bits */
        {
            if (crc_reg & 0x8000)               /* b15 is set... */
                crc_reg = (crc_reg<<1)^POLY;    /* rotate and XOR with polynomic */
            else                                /* b15 is clear... */
                crc_reg <<= 1;                  /* just rotate */
        }                                       /* Loop for 8 bits */
        //crc_reg &= 0xFFFF;                    /* Ensure CRC remains 16-bit value */
    }                                           /* Loop until num=0 */
    
    return(crc_reg);                            /* Return updated CRC */
}  


