
#ifndef __UART_H__
#define __UART_H__

#define UART_BAUD(a)	((PERIPH_CLK / 2 / a) - 1)

typedef enum
{
	UART_8BIT = 0,
	UART_8BIT_C,
	UART_9BIT,
	RESERVED,
	SPI_LOW_RISING,
	SPI_HIGH_RISING,
	SPI_LOW_FALLING,
	SPI_HIGH_FALLING
}UART_MODE;

void uart0_init(UINT16 baud_rate, UART_MODE m);
void uart0_send_byte(UINT8 dat);
void uart0_tx_datas(UINT8 *pdat, UINT16 len);

#ifdef _PRINTF
#define UartSendAscii uart0_send_byte
void UartSendHex(BYTE uDat );
void printf(const char *fmt,...) reentrant;
#else
#define UartSendAscii   ;/##/
#define UartSendHex     ;/##/
#define printf          ;/##/
#endif /* _PRINTF */

#endif /* end of __UART_H__ */

