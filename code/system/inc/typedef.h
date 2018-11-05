
#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

//typedef signed char 	INT8;
typedef unsigned char 	BYTE;
typedef unsigned char 	UINT8, uint8, uint8_t;
//typedef signed short 	INT16;
typedef unsigned short 	UINT16, uint16, uint16_t;
//typedef signed long		INT32;
typedef unsigned long	UINT32, uint32, uint32_t;
typedef bit				BOOL;

#ifndef NULL
#define NULL			0
#endif

#ifndef FALSE
#define FALSE			0
#endif

#ifndef TRUE
#define TRUE			1
#endif

#ifndef OFF
#define OFF				0
#endif

#ifndef ON
#define ON				1
#endif

#define BIT_MASK(a)		(1 << a)

#define DAT_LEFT(a, b)		(a << b)
#define DAT_RIGHT(a, b)		(a >> b)

#endif /* end of __TYPEDEF_H__ */

