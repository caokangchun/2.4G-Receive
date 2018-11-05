
#ifndef __GPIO_H__
#define __GPIO_H__

#define test_pin0			P23
#define test_pin1			P24
#define test_pin2			P25
#define RT9701_EN			P15 // power
#define SW_PIN              P32

#ifdef _RF_HOST
///////////////////////////---RF_HOST---//////////////////////////////////
#ifdef _SPI_HARDWARE
#define SPI_CS_PIN	P14//P13
#define CE_PIN		P13//P14
#define PKT_PIN		P21
#endif /* _SPI_HARDWARE */

#define pkt_int_enable()	//P2FIE |= BIT_MASK(1);
#define pkt_int_disable()	//P2FIE &= ~ BIT_MASK(1);
#define pkt_int_clear()		//P2IF &= ~ BIT_MASK(1);

#define RT9701_EN			P15 // power

#if 1
#define SW_PIN              P32
#define sw_io_init()		P32 = 1;	
#define sw_int_on()			P3FIE |= BIT_MASK(2); // SW_INT
#define sw_int_off()		P3FIE &= ~ BIT_MASK(2);
#define sw_int_clear()		P3IF &= ~ BIT_MASK(2);
#define sw_int_flg()		(P3IF & BIT_MASK(2))
#else
#define sw_io_init()		P30 = 1;	
#define sw_int_on()			P3FIE |= BIT_MASK(0); // SW_INT
#define sw_int_off()		P3FIE &= ~ BIT_MASK(0);
#define sw_int_clear()		P3IF &= ~ BIT_MASK(0);
#define sw_int_flg()		(P3IF & BIT_MASK(0))
#endif

#define PCINT1				P31 // buzz

//////////////////////////////////////////////////////////////////////////
#else
//////////////////////////---RF_SLAVE---//////////////////////////////////

#define SPI_CS_PIN	        P34//P01
#define CE_PIN		        P01//P00
#define PKT_PIN		        P43

#define pkt_int_enable()	//P1FIE |= BIT_MASK(6);
#define pkt_int_disable()	//P1FIE &= ~ BIT_MASK(6);
#define pkt_int_clear()		//P1IF &= ~ BIT_MASK(6);

#define PCINT1				P10 // led

//////////////////////////////////////////////////////////////////////////
#endif /* _RF_HOST */

extern volatile BOOL beep_flag;
extern UINT8 beep_time;

void io_init(void);
void beep_ctrl(UINT8 cnt, UINT16 period);
void beep_enable(UINT8 time);
void beep_task(void);
void beep_wait_over(void);

#endif /* end of __GPIO_H__ */

