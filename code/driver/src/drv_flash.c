
#include "includes.h"

//------------------------------------------------------------------------
//	Description	: 	system clock config
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void Flash_PageErase( uint16 uAddr16 )
{
    BYTE ii = (BYTE)( uAddr16 >> 8 );
    ii &= ~0x01;

    SFRB = 1;

    EFADR1 = (BYTE)ii;
    EFADR0 = 0x00;

    EFCON = 0x77;       /* key 1 */
    EFCON = 0x3B;       /* key 2 */

    while( !( EFCON & 0x80) )
    {
    }

    EFCON &= ~0x80;
}

//------------------------------------------------------------------------
//	Description	: 	system clock config
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void Flash_Read( uint16 uAddr16, BYTE* pBuf, uint16 ulen )

{
    uint16 ii;
    BYTE code* pData;

    pData = (BYTE code* )uAddr16;

    for(ii = 0; ii < ulen; ii++)
    {
        *pBuf = *pData;
        pBuf++;
        pData++;
    }
}

//------------------------------------------------------------------------
//	Description	: 	system clock config
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void Flash_PageWrite( uint16 uAddr16, BYTE* pBuf, uint16 ulen )
{
    uint16 ii;
    uAddr16 &= 0xFE00;

    SFRB = 1;
    for( ii = 0; ii < 512; ii ++, uAddr16 ++ )
    {
        EFADR1 = (BYTE)(uAddr16 >> 8 );
        EFADR0 = (BYTE)uAddr16;
        if(ii < ulen)
        {
            EFBUF = *pBuf ++ ;
        }
        else
        {
            EFBUF = 0xFF;
        }
        EFCON = 0x5D;       /* key 1 */
        EFCON = 0x74;       /* key 2 */
    
        while( !( EFCON & 0x80) )
        {
        }
    
        EFCON &= ~0x80; 
    }
}

//------------------------------------------------------------------------
//	Description	: 	system clock config
//	Parameters 	: 	None
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2016 - 05 - 31
//------------------------------------------------------------------------
void Flash_Write( uint16 uAddr16, BYTE* pBuf, uint16 ulen )
{
    uint16 ii;

    SFRB = 1;
    for( ii = 0; ii < ulen; ii ++, uAddr16 ++ )
    {
        EFADR1 = (BYTE)(uAddr16 >> 8 );
        EFADR0 = (BYTE)uAddr16;
        
        EFBUF = *pBuf;
        
        EFCON = 0x5D;       /* key 1 */
        EFCON = 0x74;       /* key 2 */
    
        while( !( EFCON & 0x80) )
        {
        }
    
        EFCON &= ~0x80;

        /* flash need write twice ? */
        EFADR1 = (BYTE)(uAddr16 >> 8 );
        EFADR0 = (BYTE)uAddr16;
        
        EFBUF = *pBuf;
        
        EFCON = 0x5D;       /* key 1 */
        EFCON = 0x74;       /* key 2 */
    
        while( !( EFCON & 0x80) )
        {
        }
    
        EFCON &= ~0x80;

        /* flash need write triple ? */
        EFADR1 = (BYTE)(uAddr16 >> 8 );
        EFADR0 = (BYTE)uAddr16;
        
        EFBUF = *pBuf;
        
        EFCON = 0x5D;       /* key 1 */
        EFCON = 0x74;       /* key 2 */
    
        while( !( EFCON & 0x80) )
        {
        }
    
        EFCON &= ~0x80;

        pBuf ++;
    }
}


