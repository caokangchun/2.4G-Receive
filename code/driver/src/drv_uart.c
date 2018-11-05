
#include "includes.h"

#ifdef _UART_EN

//------------------------------------------------------------------------
//	Description	: 	UART hartware init
//	Parameters 	: 	none
//	Return 		: 	none
//	Author 		: 	Sycreader
//	Date 		: 	2012 - 12 - 25
//------------------------------------------------------------------------
void uart0_init(UINT16 baud_rate, UART_MODE m)
{
	UINT8 h, l;
    
	h = (baud_rate >> 8) & 0x0F;
	l = baud_rate & 0xFF;
	
	/* Select bank1 before set UART register */
    _sfrb_bank1();
			
	UT0CON0 = (1 << 7) | // UT0E Enable UART0, must be set first
	          (0 << 6) | // UT0RO Data overrun when receive data
			  (0 << 5) | // UT0RF Uart RX data flag
			  (0 << 4) | // UT0TF Uart TX data flag
			  (1 << 3) | // UT0RE Enable UART RX data
			  (0 << 2) | // UT0TS TX satrt
			  (0 << 1) | // UT0RD8 Read only, the 9th bit data, used only in mode 2
			  (0 << 0);  // UT0TD8 Write only, the 9th bit data, used only in mode 2

    /* uart bit period = UT0CON1[3~0] UT0BR[7~0] */
    /* uart mode = UT0CON1[6~4] */
	UT0CON1 = (0 << 7) | // Not used
			  (m << 4) | // Mode
			  (h << 0);  // 
	
	UT0BR = l;
}

#ifdef _UART_TX
//------------------------------------------------------------------------
//	Description	: 	uart send data
//	Parameters 	: 	dat -> data to be send
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2012 - 12 - 25
//------------------------------------------------------------------------
void uart0_send_byte(UINT8 dat)
{
    BOOL sfrb_bak = SFRB; // backup status
	
    // Switch to BANK1
    _sfrb_bank1();
	
	UT0BUF = dat;	// data to buff
	UT0TS = 1;		// start tx
	//mcu_hold();		// cpu idle
	while(!UT0TF);	// wait tx done
	UT0TF = 0;		// clear flag

    SFRB = sfrb_bak; // restore status
}

//------------------------------------------------------------------------
//	Description	: 	uart send data
//	Parameters 	: 	dat -> data to be send
//	Return 		: 	None
//	Author 		: 	Sycreader
//	Date 		: 	2012 - 12 - 25
//------------------------------------------------------------------------
void uart0_tx_datas(UINT8 *pdat, UINT16 len)
{
    UINT16 i;

    for(i = 0; i < len; i++)
    {
        uart0_send_byte(pdat[i]);
    }
}

#ifdef _PRINTF
unsigned char Hex2Ascii( unsigned char uDat )
{
    if( uDat < 0x0A )
        return ('0' + uDat);
    else
        return ( 'A' + uDat - 0x0A );
}

void UartSendHex(BYTE uDat )
{   
    UartSendAscii( Hex2Ascii( (uDat & 0xF0) >> 4 ) );
    UartSendAscii( Hex2Ascii( uDat & 0x0F ) );
}

void printf(const char *fmt,...) reentrant
{
    short nTemp16;
    void *pList = (BYTE*)&fmt + sizeof(fmt); 

    while( *fmt )
    {
        if(*fmt == '%')
        {
            fmt ++;
            switch (*fmt)
            {
            case 'x':
                {
                    nTemp16 = *(uint16*)pList;
                    UartSendHex( nTemp16 );
                    pList = ((uint16*)pList) + 1;
                    break;
                }
            case 'X':
                {
                    nTemp16 = *(uint16*)pList;
                    UartSendHex( (nTemp16 >> 8) );
                    UartSendHex( nTemp16 );
                    pList = ((uint16*)pList) + 1;
                    break;
                }
                
            default: 
                break;                                                                                          
            }
        }
        else if( *fmt == 0x0A )
        {
            UartSendAscii( 0x0D );
            UartSendAscii( 0x0A );
        }
        else 
        {
            UartSendAscii(*fmt);
        }

        fmt ++;
    }
}
#endif /* _PRINTF */

#endif /* _UART_TX */

#endif /* _UART_EN */

