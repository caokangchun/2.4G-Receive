
#ifndef _SPI_SIMULATE
#define _SPI_SIMULATE

#define SPI_DO_PIN		P45
#define SPI_DI_PIN		P44
#define SPI_CLK_PIN		P35

#define SPI_DAT_OUTPUT  P4IE &= ~(1 << 4);P4OE |= (1 << 4);
#define SPI_DAT_INPUT   P4OE &= ~(1 << 4);P4IE |= (1 << 4);

void spi_init(void);
UINT8 spi_send_1byte(UINT8 byte);

#endif /* end of _SPI_SIMULATE */


