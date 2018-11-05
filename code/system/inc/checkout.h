
#ifndef __CHECKOUT_H__
#define __CHECKOUT_H__


BOOL data_xor_check(const UINT8 *src, UINT8 len, UINT8 xor);
UINT8 calc_xor_value(const UINT8 *src, UINT8 len);
BOOL data_zero_check(const UINT8 *src, UINT8 len);
UINT8 calc_sum_value(const UINT8 *src, UINT8 len);
UINT16 calc_crc16_ccitt(UINT8 *pdat, UINT8 len);


#endif /* end of __CHECKOUT_H__ */

