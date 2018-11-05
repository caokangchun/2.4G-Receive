
#ifndef _FLASH_H__
#define _FLASH_H__

void Flash_PageErase( uint16 uAddr16 );
void Flash_Read( uint16 uAddr16, BYTE* pBuf, uint16 ulen );
void Flash_PageWrite( uint16 uAddr16, BYTE* pBuf, uint16 ulen );
void Flash_Write( uint16 uAddr16, BYTE* pBuf, uint16 ulen );

#endif

