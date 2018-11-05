
#ifndef __CV8F5025_H__
#define __CV8F5025_H__

//;---------------------------------------------------------------//;
//;GV8F5025.H                                                     //;
//;Header file for generic GV8F5025 microcontroller               //;
//;Copyright (c) 2013-2015 Globevia, Inc.                         //;
//;All rights reserved.                                           //;
//;---------------------------------------------------------------//;


//;---------------------------------------------------------------//;
//; BYTE Registers                                                //;
//;---------------------------------------------------------------//;


//;---------------------------------------------------------------//;
//; BANK 0                                                        //;
//;---------------------------------------------------------------//;
sfr P0                          = 0x80;                          //;port 0
sfr SP                          = 0x81;                          //;stack pointer
sfr DPL                         = 0x82;                          //;data pointer low half
sfr DPH                         = 0x83;                          //;data pointer high half
sfr CCON0                       = 0x84;                          //;clock control 0
sfr CCON1                       = 0x85;                          //;clock control 1
sfr PKEY                        = 0x86;                          //;pwm key
sfr PCON                        = 0x87;                          //;power control

sfr PG0CON0                     = 0x88;                          //;pwm generator 0 control 0
sfr PG0CON1                     = 0x89;                          //;pwm generator 0 control 1
sfr PG0CON2                     = 0x8A;                          //;pwm generator 0 control 2
sfr PG0DC0                      = 0x8B;                          //;pwm generator 0 duty cycle 0
sfr PG0DC1                      = 0x8C;                          //;pwm generator 0 duty cycle 1
sfr PG0ACT0                     = 0x8D;                          //;pwm generator 0 start adc conversion timer 0
sfr PG0ACT1                     = 0x8E;                          //;pwm generator 0 start adc conversion timer 1
sfr PG0DT                       = 0x8F;                          //;pwm generator 0 dead-time

sfr P1                          = 0x90;                          //;port 1
sfr P1OE                        = 0x91;                          //;port 1 output enable
sfr P1IE                        = 0x92;                          //;port 1 input enable
sfr P1PU                        = 0x93;                          //;port 1 pull up
sfr P1RIE                       = 0x94;                          //;port 1 rising interrupt enable
sfr P1FIE                       = 0x95;                          //;port 1 falling interupt enable
sfr P1IF                        = 0x96;                          //;port 1 interrupt flag
sfr CCON2                       = 0x97;                          //;clock control 2

sfr PG1CON0                     = 0x98;                          //;pwm generator 1 control 0
sfr PG1CON1                     = 0x99;                          //;pwm generator 1 control 1
sfr PG1CON2                     = 0x9A;                          //;pwm generator 1 control 2
sfr PG1DC0                      = 0x9B;                          //;pwm generator 1 duty cycle 0
sfr PG1DC1                      = 0x9C;                          //;pwm generator 1 duty cycle 1
sfr PG1ACT0                     = 0x9D;                          //;pwm generator 1 start adc conversion timer 0
sfr PG1ACT1                     = 0x9E;                          //;pwm generator 1 start adc conversion timer 1
sfr PG1DT                       = 0x9F;                          //;pwm generator 1 dead-time

sfr P2                          = 0xA0;                          //;port 2
sfr P2OE                        = 0xA1;                          //;port 2 output enable
sfr P2IE                        = 0xA2;                          //;port 2 input enable
sfr P2PU                        = 0xA3;                          //;port 2 pull up
sfr P2RIE                       = 0xA4;                          //;port 2 rising interrupt enable
sfr P2FIE                       = 0xA5;                          //;port 2 falling interupt enable
sfr P2IF                        = 0xA6;                          //;port 2 interrupt flag
//;sfr                             = 0xA7;                          //;

sfr IE0                         = 0xA8;                          //;interrupt enable 0
sfr IE1                         = 0xA9;                          //;interrupt enable 1
sfr IE2                         = 0xAA;                          //;interrupt enable 2
sfr IE3                         = 0xAB;                          //;interrupt enable 3
//;sfr                             = 0xAC;                          //;
//;sfr                             = 0xAD;                          //;
//;sfr                             = 0xAE;                          //;
//;sfr                             = 0xAF;                          //;

sfr P3                          = 0xB0;                          //;port 3
sfr P3OE                        = 0xB1;                          //;port 3 output enable
sfr P3IE                        = 0xB2;                          //;port 3 input enable
sfr P3PU                        = 0xB3;                          //;port 3 pull up
sfr P3RIE                       = 0xB4;                          //;port 3 rising interrupt enable
sfr P3FIE                       = 0xB5;                          //;port 3 falling interupt enable
sfr P3IF                        = 0xB6;                          //;port 3 interrupt flag
//;sfr                             = 0xB7;                          //;

sfr IP0                         = 0xB8;                          //;interrupt priority 0
sfr IP1                         = 0xB9;                          //;interrupt priority 1
sfr IP2                         = 0xBA;                          //;interrupt priority 2
sfr IP3                         = 0xBB;                          //;interrupt priority 3
sfr RC0                         = 0xBC;                          //;resume cpu 0
sfr RC1                         = 0xBD;                          //;resume cpu 1
sfr RC2                         = 0xBE;                          //;resume cpu 2
sfr RC3                         = 0xBF;                          //;resume cpu 3

sfr PG2CON0                     = 0xC0;                          //;pwm generator 2 control 0
sfr PG2CON1                     = 0xC1;                          //;pwm generator 2 control 1
sfr PG2CON2                     = 0xC2;                          //;pwm generator 2 control 2
sfr PG2DC0                      = 0xC3;                          //;pwm generator 2 duty cycle 0
sfr PG2DC1                      = 0xC4;                          //;pwm generator 2 duty cycle 1
sfr PG2ACT0                     = 0xC5;                          //;pwm generator 2 start adc conversion timer 0
sfr PG2ACT1                     = 0xC6;                          //;pwm generator 2 start adc conversion timer 1
sfr PG2DT                       = 0xC7;                          //;pwm generator 2 dead-time

sfr PG3CON0                     = 0xC8;                          //;pwm generator 3 control 0
sfr PG3CON1                     = 0xC9;                          //;pwm generator 3 control 1
sfr PG3CON2                     = 0xCA;                          //;pwm generator 3 control 2
sfr PG3DC0                      = 0xCB;                          //;pwm generator 3 duty cycle 0
sfr PG3DC1                      = 0xCC;                          //;pwm generator 3 duty cycle 1
sfr PG3ACT0                     = 0xCD;                          //;pwm generator 3 start adc conversion timer 0
sfr PG3ACT1                     = 0xCE;                          //;pwm generator 3 start adc conversion timer 1
sfr PG3DT                       = 0xCF;                          //;pwm generator 3 dead-time

sfr PSW                         = 0xD0;                          //;program stauts word
sfr ADCHIS0                     = 0xD1;                          //;adc hardware input select 0
sfr ADCHIS1                     = 0xD2;                          //;adc hardware input select 1
sfr ADCHIS2                     = 0xD3;                          //;adc hardware input select 2
sfr ADCHIS3                     = 0xD4;                          //;adc hardware input select 3
sfr ADCHIS4                     = 0xD5;                          //;adc hardware input select 4
sfr ADCHIS5                     = 0xD6;                          //;adc hardware input select 5
sfr ADCHIS6                     = 0xD7;                          //;adc hardware input select 6

sfr ADCCON0                     = 0xD8;                          //;adc control 0
sfr ADCCON1                     = 0xD9;                          //;adc control 1
sfr ADCBR                       = 0xDA;                          //;adc bit rate
sfr ADCBS                       = 0xDB;                          //;adc buffer select
sfr ADCBUF0                     = 0xDC;                          //;adc buffer 0
sfr ADCBUF1                     = 0xDD;                          //;adc buffer 1
sfr ADCBUFV0                    = 0xDE;                          //;adc buffer valid 0
sfr ADCBUFV1                    = 0xDF;                          //;adc buffer valid 1

sfr ACC                         = 0xE0;                          //;
sfr P0OE                        = 0xE1;                          //;port 0 output enable
sfr P0IE                        = 0xE2;                          //;port 0 input enable
sfr P0PU                        = 0xE3;                          //;port 0 pull up
sfr P0RIE                       = 0xE4;                          //;port 0 rising interrupt enable
sfr P0FIE                       = 0xE5;                          //;port 0 falling interrupt enable
sfr P0IF                        = 0xE6;                          //;port 0 interrupt flag
//;sfr                             = 0xE7;                          //;port/comparator start adc conversion enable

sfr PG4CON0                     = 0xE8;                          //;pwm generator 4 control 0
sfr PG4CON1                     = 0xE9;                          //;pwm generator 4 control 1
sfr PG4CON2                     = 0xEA;                          //;pwm generator 4 control 2
sfr PG4DC0                      = 0xEB;                          //;pwm generator 4 duty cycle 0
sfr PG4DC1                      = 0xEC;                          //;pwm generator 4 duty cycle 1
sfr PG4ACT0                     = 0xED;                          //;pwm generator 4 start adc conversion timer 0
sfr PG4ACT1                     = 0xEE;                          //;pwm generator 4 start adc conversion timer 1
sfr PG4DT                       = 0xEF;                          //;pwm generator 4 dead-time

sfr B                           = 0xF0;                          //;B register
sfr PT0PR0                      = 0xF1;                          //;pwm timer 0 period 0
sfr PT0PR1                      = 0xF2;                          //;pwm timer 0 period 1
sfr PT1PR0                      = 0xF3;                          //;pwm timer 1 period 0
sfr PT1PR1                      = 0xF4;                          //;pwm timer 1 period 1
sfr PIOCON0                     = 0xF5;                          //;pwm io control 0
sfr PIOCON1                     = 0xF6;                          //;pwm io control 1
sfr PIOCON2                     = 0xF7;                          //;pwm io control 2

sfr PG5CON0                     = 0xF8;                          //;pwm generator 5 control 0
sfr PG5CON1                     = 0xF9;                          //;pwm generator 5 control 1
sfr PG5CON2                     = 0xFA;                          //;pwm generator 5 control 2
sfr PG5DC0                      = 0xFB;                          //;pwm generator 5 duty cycle 0
sfr PG5DC1                      = 0xFC;                          //;pwm generator 5 duty cycle 1
sfr PG5ACT0                     = 0xFD;                          //;pwm generator 5 start adc conversion timer 0
sfr PG5ACT1                     = 0xFE;                          //;pwm generator 5 start adc conversion timer 1
sfr PG5DT                       = 0xFF;                          //;pwm generator 5 dead-time


//;---------------------------------------------------------------//;
//; BANK 1                                                        //;
//;---------------------------------------------------------------//;
sfr UBCON                       = 0x80;                          //;usb bus control
//;sfr                             = 0x81;                          //;
//;sfr                             = 0x82;                          //;
//;sfr                             = 0x83;                          //;
sfr WDTCON                      = 0x84;                          //;watchdog timer control
sfr WDTCNT                      = 0x85;                          //;watchdog timer counter
sfr WDTPR                       = 0x86;                          //;watchdog timer period
//;sfr                             = 0x87;                          //;

sfr UE0CON                      = 0x88;                          //;usb ep 0 control
sfr UE0IOPS                     = 0x89;                          //;usb ep 0 in/out packet size
sfr UDADR                       = 0x8A;                          //;usb device address
sfr WUTCON                      = 0x8B;                          //;wakeup timer contro
sfr WUTCNT                      = 0x8C;                          //;wakeup timer counter
sfr WUTPR                       = 0x8D;                          //;wakeup timer period
//;sfr                             = 0x8E;                          //;
sfr LVDCON                      = 0x8F;                          //;lvd control

sfr UE1CON                      = 0x90;                          //;usb ep 1 control
sfr UE1IOPS                     = 0x91;                          //;usb ep 1 in/out packet size
sfr TPC0CON                     = 0x92;                          //;timer/pwm/capture 0 control
sfr TPC0CNT                     = 0x93;                          //;timer/pwm/capture 0 counter
sfr TPC0PR                      = 0x94;                          //;timer/pwm/capture 0 period
sfr SPI0CON                     = 0x95;                          //;spi 0 control
sfr SPI0BR                      = 0x96;                          //;spi 0 bit rate
sfr SPI0BUF                     = 0x97;                          //;spi 0 buffer

sfr UE2CON                      = 0x98;                          //;usb ep 2 control
sfr UE2IOPS                     = 0x99;                          //;usb ep 2 in/out packet size
sfr VREFCON                     = 0x9A;                          //;voltage reference control
sfr VREFS0                      = 0x9B;                          //;voltage reference select 0
sfr VREFS1                      = 0x9C;                          //;voltage reference select 1
sfr VREFS2                      = 0x9D;                          //;voltage reference select 2
sfr VREFS3                      = 0x9E;                          //;voltage reference select 3
sfr VREFS4                      = 0x9F;                          //;voltage reference select 4

sfr UE3CON                      = 0xA0;                          //;usb ep 3 control
sfr UE3IOPS                     = 0xA1;                          //;usb ep 3 in/out packet size
sfr TPC1CON                     = 0xA2;                          //;timer/pwm/capture 1 control
sfr TPC1CNT                     = 0xA3;                          //;timer/pwm/capture 1 counter
sfr TPC1PR                      = 0xA4;                          //;timer/pwm/capture 1 period
sfr SPI1CON                     = 0xA5;                          //;spi 1 control
sfr SPI1BR                      = 0xA6;                          //;spi 1 bit rate
sfr SPI1BUF                     = 0xA7;                          //;spi 1 buffer

//;sfr                             = 0xA8;                          //;
//;sfr                             = 0xA9;                          //;
//;sfr                             = 0xAA;                          //;
//;sfr                             = 0xAB;                          //;
//;sfr                             = 0xAC;                          //;
//;sfr                             = 0xAD;                          //;
//;sfr                             = 0xAE;                          //;
//;sfr                             = 0xAF;                          //;

sfr CMP0CON0                    = 0xB0;                          //;comparator 0 control 0
sfr CMP0CON1                    = 0xB1;                          //;comparator 0 control 1
sfr CMP0DFV0                    = 0xB2;                          //;comparator 0 digital-filter value 0
sfr CMP0DFV1                    = 0xB3;                          //;comparator 0 digital-filter value 1
//;sfr                             = 0xB4;                          //;
sfr ADCIBCON                    = 0xB5;                          //;adc input buffer control
sfr ADCRBCON                    = 0xB6;                          //;adc reference buffer control
sfr ADCDPC                      = 0xB7;                          //;adc data calibration

//;sfr                             = 0xB8;                          //;
//;sfr                             = 0xB9;                          //;
//;sfr                             = 0xBA;                          //;
//;sfr                             = 0xBB;                          //;
//;sfr                             = 0xBC;                          //;
//;sfr                             = 0xBD;                          //;
//;sfr                             = 0xBE;                          //;
//;sfr                             = 0xBF;                          //;

sfr CMP1CON0                    = 0xC0;                          //;comparator 1 control 0
sfr CMP1CON1                    = 0xC1;                          //;comparator 1 control 1
sfr CMP1DFV0                    = 0xC2;                          //;comparator 1 digital-filter value 0
sfr CMP1DFV1                    = 0xC3;                          //;comparator 1 digital-filter value 1
sfr HRPAD0                      = 0xC4;                          //;
sfr HRPAD1                      = 0xC5;                          //;
sfr HRPBD0                      = 0xC6;                          //;
sfr HRPBD1                      = 0xC7;                          //;

sfr CMP2CON0                    = 0xC8;                          //;comparator 2 control 0
sfr CMP2CON1                    = 0xC9;                          //;comparator 2 control 1
sfr CMP2DFV0                    = 0xCA;                          //;comparator 2 digital-filter value 0
sfr CMP2DFV1                    = 0xCB;                          //;comparator 2 digital-filter value 1
sfr HRPCD0                      = 0xCC;                          //;
sfr HRPCD1                      = 0xCD;                          //;
sfr HRPDD0                      = 0xCE;                          //;
sfr HRPDD1                      = 0xCF;                          //;

//;sfr                             = 0xD0;                          //;
sfr HRPED0                      = 0xD1;                          //;
sfr HRPED1                      = 0xD2;                          //;
sfr HRPFD0                      = 0xD3;                          //;
sfr HRPFD1                      = 0xD4;                          //;
sfr HRPCON                      = 0xD5;                          //;
//;sfr                             = 0xD6;                          //;
//;sfr                             = 0xD7;                          //;

sfr CMP3CON0                    = 0xD8;                          //;comparator 3 control 0
sfr CMP3CON1                    = 0xD9;                          //;comparator 3 control 1
sfr CMP3DFV0                    = 0xDA;                          //;comparator 3 digital-filter value 0
sfr CMP3DFV1                    = 0xDB;                          //;comparator 3 digital-filter value 1
sfr EFCON                       = 0xDC;                          //;embedded flash control
sfr EFBUF                       = 0xDD;                          //;embedded flash buffer
sfr EFADR0                      = 0xDE;                          //;embedded flash address 0
sfr EFADR1                      = 0xDF;                          //;embedded flash address 1

//;sfr                             = 0xE0;                          //;
sfr T0CON                       = 0xE1;                          //;timer 0 control
sfr T0CNT0                      = 0xE2;                          //;timer 0 counter 0
sfr T0CNT1                      = 0xE3;                          //;timer 0 counter 1
sfr T0PR0                       = 0xE4;                          //;timer 0 period 0
sfr T0PR1                       = 0xE5;                          //;timer 0 period 1
sfr PSYNC0                      = 0xE6;                          //;pwm sync 0
sfr PSYNC1                      = 0xE7;                          //;pwm sync 1

sfr UT0CON0                     = 0xE8;                          //;uart 0 control 0
sfr UT0CON1                     = 0xE9;                          //;uart 0 control 1
sfr UT0BR                       = 0xEA;                          //;uart 0 baud rate
sfr UT0BUF                      = 0xEB;                          //;uart 0 buffer
sfr UT1CON0                     = 0xEC;                          //;uart 1 control 0
sfr UT1CON1                     = 0xED;                          //;uart 1 control 1
sfr UT1BR                       = 0xEE;                          //;uart 1 baud rate
sfr UT1BUF                      = 0xEF;                          //;uart 1 buffer

//;sfr                             = 0xF0;                          //;
sfr T1CON                       = 0xF1;                          //;timer 1 control
sfr T1CNT0                      = 0xF2;                          //;timer 1 counter 0
sfr T1CNT1                      = 0xF3;                          //;timer 1 counter 1
sfr T1PR0                       = 0xF4;                          //;timer 1 period 0
sfr T1PR1                       = 0xF5;                          //;timer 1 period 1
sfr ADCCE0                      = 0xF6;                          //;adc conversion enable 0
sfr ADCCE1                      = 0xF7;                          //;adc conversion enable 1

sfr P4                          = 0xF8;                          //;port 4
sfr P4OE                        = 0xF9;                          //;port 4 output enable
sfr P4IE                        = 0xFA;                          //;port 4 input enable
sfr P4PU                        = 0xFB;                          //;port 4 pull up
sfr P4RIE                       = 0xFC;                          //;port 4 rising interrupt enable
sfr P4FIE                       = 0xFD;                          //;port 4 falling interupt enable
sfr P4IF                        = 0xFE;                          //;port 4 interrupt flag
//;sfr                             = 0xFF;                          //;



//;---------------------------------------------------------------//;
//; BIT Registers                                                 //;
//;---------------------------------------------------------------//;

//;   list from bit 0 ~ bit 7
//;---------------------------------------------------------------//;
//; CCON0                                                         //;
//;---------------------------------------------------------------//;
//;    SCS0                                                       //;system clock select 0                          //;0~7 - IHOSC,  ILOSC,  XHOSC,  XLOSC,
//;    SCS1                                                       //;system clock select 1                          //;      XPCLK,  --   ,  --   ,  DSCLK
//;    SCS2                                                       //;system clock select 2                          //;
//;    XHOSCE                                                     //;external highspeed crystal oscillator enable   //;0 - disable                     1 - enable
//;    XLOSCE                                                     //;external lowpower crystal oscillator enable    //;0 - disable                     1 - enable
//;    IHOSCE                                                     //;internal highspeed crystal oscillator enable   //;0 - disable                     1 - enable
//;    ILOSCE                                                     //;internal lowpower crystal oscillator enable    //;0 - disable                     1 - enable
//;    XPCLKE                                                     //;external port clock enable                     //;0 - disable                     1 - enable

//;---------------------------------------------------------------//;
//; CCON1                                                         //;
//;---------------------------------------------------------------//;
//;    DSCHW0                                                     //;divided system clock high width                //;0~15 - clock high width = ((0 ~ 15) + 1) x sclk
//;    DSCHW1                                                     //;divided system clock high width                //;
//;    DSCHW2                                                     //;divided system clock high width                //;
//;    DSCHW3                                                     //;divided system clock high width                //;
//;    DSCLW0                                                     //;divided system clock low width                 //;0~15 - clock low width = ((0 ~ 15) + 1) x sclk
//;    DSCLW1                                                     //;divided system clock low width                 //;
//;    DSCLW2                                                     //;divided system clock low width                 //;
//;    DSCLW3                                                     //;divided system clock low width                 //;

//;---------------------------------------------------------------//;
//; CCON2                                                         //;
//;---------------------------------------------------------------//;
//;                                                               //;                                               //;0 - 0                           1 - 1
//;                                                               //;                                               //;0 - 0                           1 - 1
//;                                                               //;                                               //;0 - 0                           1 - 1
//;                                                               //;                                               //;0 - 0                           1 - 1
//;    DSCLKE                                                     //;divided system clock enable                    //;0 - disable                     1 - enable
//;    XHOSCP                                                     //;XHOSC power control                            //;0 - high power (speed)          1 - low power (speed)
//;    XLOSCP                                                     //;XLOSC power control                            //;0 - high power (speed)          1 - low power (speed)
//;    XHOSCF                                                     //;XHOSC failed                                   //;0 - XHOSC works good            1 - XHOSC failed
//;    XLOSCF                                                     //;XLOSC failed                                   //;0 - XLOSC works good            1 - XLOSC failed

//;---------------------------------------------------------------//;
//; PCON                                                          //;
//;---------------------------------------------------------------//;
//;    HOLD                                                       //;hold cpu                                       //;0 - cpu runs                    1 - hold cpu
//;    SLEEP                                                      //;syste sleep                                    //;0 - system runs                 1 - system sleep
//;    LVDRF                                                      //;lvd reset flag                                 //;0 - no lvd reset                1 - lvd reseted
//;    CMP1RF                                                     //;CMP1 reset flag                                //;0 - no CMP1 reset               1 - CMP1 reseted
//;    CMP2RF                                                     //;CMP2 reset flag                                //;0 - no CMP2 reset               1 - CMP2 reseted
//;    WDTRF                                                      //;wdt reset flag                                 //;0 - no wdt reset                1 - wdt reseted
//;    NRSTRF                                                     //;nrst reset flag                                //;0 - no nrst reset               1 - nrst reseted
//;    PORF                                                       //;power-on reset flag                            //;0 - no power-on reset           1 - power-on reseted


//;---------------------------------------------------------------//;
//; UT0CON0                                                       //;
//;---------------------------------------------------------------//;
sbit UT0TD8                     = UT0CON0^0;                     //;uart 0 tx data bit8, write only                //;0 - 0                           1 - 1 
sbit UT0RD8                     = UT0CON0^1;                     //;uart 0 rx data bit8, read only                 //;0 - 0                           1 - 1
sbit UT0TS                      = UT0CON0^2;                     //;uart 0 tx start                                //;0 - no operation                1 - start
sbit UT0RE                      = UT0CON0^3;                     //;uart 0 rx enable                               //;0 - disable                     1 - enable
sbit UT0TF                      = UT0CON0^4;                     //;uart 0 tx finish                               //;0 - not finish                  1 - finish
sbit UT0RF                      = UT0CON0^5;                     //;uart 0 rx finish                               //;0 - not finish                  1 - finish
sbit UT0RO                      = UT0CON0^6;                     //;uart 0 rx overrun                              //;0 - not overrun                 1 - overrun
sbit UT0E                       = UT0CON0^7;                     //;uart 0 enable                                  //;0 - disable                     1 - enable


//;---------------------------------------------------------------//;
//; UT1CON0                                                       //;
//;---------------------------------------------------------------//;
//;    UT1TD8                     = UT1CON0^0;                     //;uart 1 tx data bit8, write only                //;0 - 0                           1 - 1
//;    UT1RD8                     = UT1CON0^1;                     //;uart 1 rx data bit8, read only                 //;0 - 0                           1 - 1
//;    UT1TS                      = UT1CON0^2;                     //;uart 1 tx start                                //;0 - no operation                1 - start
//;    UT1RE                      = UT1CON0^3;                     //;uart 1 rx enable                               //;0 - disable                     1 - enable
//;    UT1TF                      = UT1CON0^4;                     //;uart 1 tx finish                               //;0 - not finish                  1 - finish
//;    UT1RF                      = UT1CON0^5;                     //;uart 1 rx finish                               //;0 - not finish                  1 - finish
//;    UT1RO                      = UT1CON0^6;                     //;uart 1 rx overrun                              //;0 - not overrun                 1 - overrun
//;    UT1E                       = UT1CON0^7;                     //;uart 1 enable                                  //;0 - disable                     1 - enable


//;---------------------------------------------------------------//;
//; UTxCON1                                                       //;
//;---------------------------------------------------------------//;
//;    UTxBR8                                                     //;uart x baud rate bit 8                         //;0 - 0                           1 - 1
//;    UTxBR9                                                     //;uart x baud rate bit 9                         //;0 - 0                           1 - 1
//;    UTxBR10                                                    //;uart x baud rate bit 10                        //;0 - 0                           1 - 1
//;    UTxBR11                                                    //;uart x baud rate bit 11                        //;0 - 0                           1 - 1
//;    UTxM0                                                      //;uart x mode                                    //;0~7 - uart8,  uart8p, uart9,  --      ,
//;    UTxM1                                                      //;                                               //;      spiilr, spiihr, spiilf, spiihf  ,
//;    UTxM2                                                      //;                                               //;
//;                                                               //;                                               //;



//;---------------------------------------------------------------//;
//; TxCON                                                         //;
//;---------------------------------------------------------------//;
//;    TxE                                                        //;timer x enable                                 //;0 - disable                     1 - enable
//;                                                               //;                                               //;0 -                             1 -           
//;    TxS0                                                       //;timer x source                                 //;0~3 - sclk,    P02R,   P02F,   P02RF
//;    TxS1                                                       //;                                               //;
//;    TxPS0                                                      //;                                               //;
//;    TxPS1                                                      //;                                               //;
//;    TxPS2                                                      //;                                               //;
//;    TxOV                                                       //;timer x overflow                               //;0 - no overflow                 1 - overflow


//;---------------------------------------------------------------//;
//; SPIxCON                                                       //;
//;---------------------------------------------------------------//;
//;    SPIxM0                                                     //;spi mode 0                                     //;0~15 - spiilr, spiihr, spiilf, spiihf,
//;    SPIxM1                                                     //;                                               //;       iictsd, iictd,  iictds, iicrd,
//;    SPIxM2                                                     //;                                               //;       iicrds, --    , --    , --    ,
//;    SPIxM3                                                     //;                                               //;       --    , --    , --    , --    ,
//;    SPIxS                                                      //;spi start                                      //;0 - no operation                1 - start tx/rx
//;    SPIxE                                                      //;spi enable                                     //;0 - disable                     1 - enable
//;    IICxACK                                                    //;iic ack bit                                    //;0 - nack                        1 - ack
//;    SPIxF                                                      //;spi flag                                       //;0 - not finish                  1 - finished


//;---------------------------------------------------------------//;
//; IE0                                                           //;
//;---------------------------------------------------------------//;
//;sbit P0IE                       = IE0^0;                         //;port 0 interrupt enable                        //;0 - disable                     1 - enable
//;sbit P1IE                       = IE0^1;                         //;port 1 interrupt enable                        //;0 - disable                     1 - enable
//;sbit P2IE                       = IE0^2;                         //;port 2 interrupt enable                        //;0 - disable                     1 - enable
//;sbit P3IE                       = IE0^3;                         //;port 3 interrupt enable                        //;0 - disable                     1 - enable
sbit T0IE                       = IE0^4;                         //;timer 0 interrupt enable                       //;0 - disable                     1 - enable
sbit T1IE                       = IE0^5;                         //;timer 1 interrupt enable                       //;0 - disable                     1 - enable
sbit TPCIE                      = IE0^6;                         //;tpc 0 interrupt enable                         //;0 - disable                     1 - enable
sbit EA                         = IE0^7;                         //;global interrupt enable                        //;0 - disable                     1 - enable



//;---------------------------------------------------------------//;
//; CMP0CON0                                                      //;
//;---------------------------------------------------------------//;
sbit CMP0L                      = CMP0CON0^0;                    //;cmp 0 less function                            //;0 - flags@input>ref             1 - flags@input<ref
sbit CMP0IS                     = CMP0CON0^1;                    //;cmp 0 input select                             //;0 - P04                         1 - P10
sbit CMP0RS                     = CMP0CON0^2;                    //;cmp 0 reference select                         //;0 - internal vref               1 - P05
sbit CMP0OS                     = CMP0CON0^3;                    //;cmp 0 output state                             //;0 - input<ref                   1 - input>ref
sbit CMP0E                      = CMP0CON0^4;                    //;cmp 0 enable                                   //;0 - disable                     1 - enable
sbit CMP0RE                     = CMP0CON0^5;                    //;cmp 0 reset enable                             //;0 - disable                     1 - enable
sbit CMP0WE                     = CMP0CON0^6;                    //;cmp 0 wakeup enable                            //;0 - disable                     1 - enable
sbit CMP0F                      = CMP0CON0^7;                    //;cmp 0 flag                                     //;0 - disable                     1 - enable



//;---------------------------------------------------------------//;
//; CMP1CON0                                                      //;
//;---------------------------------------------------------------//;
sbit CMP1L                      = CMP1CON0^0;                    //;cmp 1 less function                            //;0 - flags@input>ref             1 - flags@input<ref
sbit CMP1IS                     = CMP1CON0^1;                    //;cmp 1 input select                             //;0 - P04                         1 - P10
sbit CMP1RS                     = CMP1CON0^2;                    //;cmp 1 reference select                         //;0 - internal vref               1 - P05
sbit CMP1OS                     = CMP1CON0^3;                    //;cmp 1 output state                             //;0 - input<ref                   1 - input>ref
sbit CMP1E                      = CMP1CON0^4;                    //;cmp 1 enable                                   //;0 - disable                     1 - enable
sbit CMP1RE                     = CMP1CON0^5;                    //;cmp 1 reset enable                             //;0 - disable                     1 - enable
sbit CMP1WE                     = CMP1CON0^6;                    //;cmp 1 wakeup enable                            //;0 - disable                     1 - enable
sbit CMP1F                      = CMP1CON0^7;                    //;cmp 1 flag                                     //;0 - disable                     1 - enable


//;---------------------------------------------------------------//;
//; CMP2CON0                                                      //;
//;---------------------------------------------------------------//;
sbit CMP2L                      = CMP2CON0^0;                    //;cmp 2 less function                            //;0 - flags@input>ref             1 - flags@input<ref
sbit CMP2IS                     = CMP2CON0^1;                    //;cmp 2 input select                             //;0 - P04                         1 - P10
sbit CMP2RS                     = CMP2CON0^2;                    //;cmp 2 reference select                         //;0 - internal vref               1 - P05
sbit CMP2OS                     = CMP2CON0^3;                    //;cmp 2 output state                             //;0 - input<ref                   1 - input>ref
sbit CMP2E                      = CMP2CON0^4;                    //;cmp 2 enable                                   //;0 - disable                     1 - enable
sbit CMP2RE                     = CMP2CON0^5;                    //;cmp 2 reset enable                             //;0 - disable                     1 - enable
sbit CMP2WE                     = CMP2CON0^6;                    //;cmp 2 wakeup enable                            //;0 - disable                     1 - enable
sbit CMP2F                      = CMP2CON0^7;                    //;cmp 2 flag                                     //;0 - disable                     1 - enable


//;---------------------------------------------------------------//;
//; CMP3CON0                                                      //;
//;---------------------------------------------------------------//;
sbit CMP3L                      = CMP3CON0^0;                    //;cmp 3 less function                            //;0 - flags@input>ref             1 - flags@input<ref
sbit CMP3IS                     = CMP3CON0^1;                    //;cmp 3 input select                             //;0 - P04                         1 - P10
sbit CMP3RS                     = CMP3CON0^2;                    //;cmp 3 reference select                         //;0 - internal vref               1 - P05
sbit CMP3OS                     = CMP3CON0^3;                    //;cmp 3 output state                             //;0 - input<ref                   1 - input>ref
sbit CMP3E                      = CMP3CON0^4;                    //;cmp 3 enable                                   //;0 - disable                     1 - enable
sbit CMP3RE                     = CMP3CON0^5;                    //;cmp 3 reset enable                             //;0 - disable                     1 - enable
sbit CMP3WE                     = CMP3CON0^6;                    //;cmp 3 wakeup enable                            //;0 - disable                     1 - enable
sbit CMP3F                      = CMP3CON0^7;                    //;cmp 3 flag                                     //;0 - disable                     1 - enable


//;---------------------------------------------------------------//;
//; CMPxCON1                                                      //;
//;---------------------------------------------------------------//;
//;    CMPxDFR0                                                   //;cmp x digital-filter rate                      //;0 - no digital-filter
//;    CMPxDFR1                                                   //;                                               //;1~7 - 1 per 2^(1 ~ 7) x 32 sclks
//;    CMPxDFR2                                                   //;                                               //;
//;    CMPxOE                                                     //;cmp x output enable                            //;0 - not output to pin           1 - output to P06
//;    CMPxHS0                                                    //;cmp x hysteresis                               //;0~3 - lowspeed:  50mv,    26mv,    10mv,    0
//;    CMPxHS1                                                    //;                                               //;      highspeed: 64mv,    33mv,    13mv,    0
//;    CMPxID                                                     //;cmp x input divider                            //;0 - disable                     1 - enable
//;    CMPxS                                                      //;cmp x speed                                    //;0 - low speed (power)           1 - high speed




//;---------------------------------------------------------------//;
//; PSW                                                           //;
//;---------------------------------------------------------------//;
sbit P                          = PSW^0;                         //;parity                                         //;0 - even                        1 - odd
sbit SFRB                       = PSW^1;                         //;SFR Bank                                       //;0 - Bank 0                      1 - Bank 1
sbit OV                         = PSW^2;                         //;overflow                                       //;0 - overflow                    1 - no overflow
sbit RS0                        = PSW^3;                         //;register select                                //;0~3 - 00~07h, 08~0Fh, 10~17h, 18~1Fh
sbit RS1                        = PSW^4;                         //;                                               //;
sbit MD16E                      = PSW^5;                         //;mul/div 16-bit enable                          //;0 - disable                     1 - enable
sbit AC                         = PSW^6;                         //;auxiliary carry                                //;0 - carry                       1 - no carry
sbit CY                         = PSW^7;                         //;carry/borrow                                   //;0 - carry/borrow                1 - carry/borrow



//;---------------------------------------------------------------//;
//; ACC                                                           //;
//;---------------------------------------------------------------//;
sbit A0                         = ACC^0;                         //;                                               //;0 - 0                           1 - 1
sbit A1                         = ACC^1;                         //;                                               //;0 - 0                           1 - 1
sbit A2                         = ACC^2;                         //;                                               //;0 - 0                           1 - 1
sbit A3                         = ACC^3;                         //;                                               //;0 - 0                           1 - 1
sbit A4                         = ACC^4;                         //;                                               //;0 - 0                           1 - 1
sbit A5                         = ACC^5;                         //;                                               //;0 - 0                           1 - 1
sbit A6                         = ACC^6;                         //;                                               //;0 - 0                           1 - 1
sbit A7                         = ACC^7;                         //;                                               //;0 - 0                           1 - 1


//;---------------------------------------------------------------//;
//; B                                                             //;
//;---------------------------------------------------------------//;
sbit B0                         = B^0;                           //;                                               //;0 - 0                           1 - 1
sbit B1                         = B^1;                           //;                                               //;0 - 0                           1 - 1
sbit B2                         = B^2;                           //;                                               //;0 - 0                           1 - 1
sbit B3                         = B^3;                           //;                                               //;0 - 0                           1 - 1
sbit B4                         = B^4;                           //;                                               //;0 - 0                           1 - 1
sbit B5                         = B^5;                           //;                                               //;0 - 0                           1 - 1
sbit B6                         = B^6;                           //;                                               //;0 - 0                           1 - 1
sbit B7                         = B^7;                           //;                                               //;0 - 0                           1 - 1


//;---------------------------------------------------------------//;
//; P0                                                            //;
//;---------------------------------------------------------------//;
sbit P00                        = P0^0;                          //;                                               //;0 - 0                           1 - 1
sbit P01                        = P0^1;                          //;                                               //;0 - 0                           1 - 1
sbit P02                        = P0^2;                          //;                                               //;0 - 0                           1 - 1
sbit P03                        = P0^3;                          //;                                               //;0 - 0                           1 - 1
sbit P04                        = P0^4;                          //;                                               //;0 - 0                           1 - 1
sbit P05                        = P0^5;                          //;                                               //;0 - 0                           1 - 1
sbit P06                        = P0^6;                          //;                                               //;0 - 0                           1 - 1
sbit P07                        = P0^7;                          //;                                               //;0 - 0                           1 - 1


//;---------------------------------------------------------------//;
//; P1                                                            //;
//;---------------------------------------------------------------//;
sbit P10                        = P1^0;                          //;                                               //;0 - 0                           1 - 1
sbit P11                        = P1^1;                          //;                                               //;0 - 0                           1 - 1
sbit P12                        = P1^2;                          //;                                               //;0 - 0                           1 - 1
sbit P13                        = P1^3;                          //;                                               //;0 - 0                           1 - 1
sbit P14                        = P1^4;                          //;                                               //;0 - 0                           1 - 1
sbit P15                        = P1^5;                          //;                                               //;0 - 0                           1 - 1
sbit P16                        = P1^6;                          //;                                               //;0 - 0                           1 - 1
sbit P17                        = P1^7;                          //;                                               //;0 - 0                           1 - 1


//;---------------------------------------------------------------//;
//; P2                                                            //;
//;---------------------------------------------------------------//;
sbit P20                        = P2^0;                          //;                                               //;0 - 0                           1 - 1
sbit P21                        = P2^1;                          //;                                               //;0 - 0                           1 - 1
sbit P22                        = P2^2;                          //;                                               //;0 - 0                           1 - 1
sbit P23                        = P2^3;                          //;                                               //;0 - 0                           1 - 1
sbit P24                        = P2^4;                          //;                                               //;0 - 0                           1 - 1
sbit P25                        = P2^5;                          //;                                               //;0 - 0                           1 - 1
sbit P26                        = P2^6;                          //;                                               //;0 - 0                           1 - 1
sbit P27                        = P2^7;                          //;                                               //;0 - 0                           1 - 1


//;---------------------------------------------------------------//;
//; P3                                                            //;
//;---------------------------------------------------------------//;
sbit P30                        = P3^0;                          //;                                               //;0 - 0                           1 - 1
sbit P31                        = P3^1;                          //;                                               //;0 - 0                           1 - 1
sbit P32                        = P3^2;                          //;                                               //;0 - 0                           1 - 1
sbit P33                        = P3^3;                          //;                                               //;0 - 0                           1 - 1
sbit P34                        = P3^4;                          //;                                               //;0 - 0                           1 - 1
sbit P35                        = P3^5;                          //;                                               //;0 - 0                           1 - 1
sbit P36                        = P3^6;                          //;                                               //;0 - 0                           1 - 1
sbit P37                        = P3^7;                          //;                                               //;0 - 0                           1 - 1


//;---------------------------------------------------------------//;
//; P4                                                            //;
//;---------------------------------------------------------------//;
sbit P40                        = P4^0;                          //;                                               //;0 - 0                           1 - 1
sbit P41                        = P4^1;                          //;                                               //;0 - 0                           1 - 1
sbit P42                        = P4^2;                          //;                                               //;0 - 0                           1 - 1
sbit P43                        = P4^3;                          //;                                               //;0 - 0                           1 - 1
sbit P44                        = P4^4;                          //;                                               //;0 - 0                           1 - 1
sbit P45                        = P4^5;                          //;                                               //;0 - 0                           1 - 1
sbit P46                        = P4^6;                          //;                                               //;0 - 0                           1 - 1
sbit P47                        = P4^7;                          //;                                               //;0 - 0                           1 - 1


//;---------------------------------------------------------------//;
//; ADCCON0                                                       //;
//;---------------------------------------------------------------//;
sbit ADCDIS0                    = ADCCON0^0;                     //;adc default input select                       //;0~15 - P06,     P07,     P13,     P14,
sbit ADCDIS1                    = ADCCON0^1;                     //;                                               //;       P15,     P21,     P22,     P23,
sbit ADCDIS2                    = ADCCON0^2;                     //;                                               //;       P24,     P25,     P26,     P27,
sbit ADCDIS3                    = ADCCON0^3;                     //;                                               //;       P30,     VREF,    VDD33,   AVDD33,
sbit ADCE                       = ADCCON0^4;                     //;adc enable and initiallize                     //;0 - disable                     1 - enable, init@1st enable
sbit ADCDCS                     = ADCCON0^5;                     //;adc default conversion start                   //;0 - disable                     1 - enable
sbit ADCBPI                     = ADCCON0^6;                     //;adc buffer pointer init                        //;0 - do nothing                  1 - BP=ADCBS[7:4]
sbit ADCCP                      = ADCCON0^7;                     //;adc conversion processing                      //;0 - not start                   1 - processing



//;---------------------------------------------------------------//;
//; ADCCON1                                                       //;
//;---------------------------------------------------------------//;
//;    ADCRS0                                                     //;adc reference select                           //;0~7 - VREFx1,  VREFx2,  VREFx2.5,VREFx3,
//;    ADCRS1                                                     //;                                               //;      P20,     P31,     P33,     AVDD33,
//;    ADCRS2                                                     //;                                               //;
//;    ADCDA                                                      //;adc data alignment                             //;0 - LSB                         1 - MSB
//;    ADCBM0                                                     //;adc buffer mode                                //;0~3 - 
//;    ADCBM1                                                     //;                                               //;      
//;    ADCIS                                                      //;adc initialization start                       //;0 - do nothing                  1 - start
//;    ADCIF                                                      //;adc initialization finish                      //;0 - not finish                  1 - finish


//;---------------------------------------------------------------//;
//; ADCIBCON                                                      //;
//;---------------------------------------------------------------//;
//;                                                               //;                                               //;
//;    ADCIBOCM                                                   //;adc input buffer offset calibration mode       //;0 - static                      1 - dynamic
//;    ADCIBOC                                                    //;adc input buffer offset calibration            //;0 - disable                     1 - enable
//;    ADCIBE                                                     //;adc input buffer enable                        //;0 - disable                     1 - enable
//;    ADCIBOCS3                                                  //;adc input buffer offset calibration select     //;0~15 - 0 ~ VDD       
//;    ADCIBOCS2                                                  //;                                               //;
//;    ADCIBOCS1                                                  //;                                               //;
//;    ADCIBOCS0                                                  //;                                               //;


//;---------------------------------------------------------------//;
//; ADCRBCON                                                      //;
//;---------------------------------------------------------------//;
//;                                                               //;                                               //;
//;    ADCRBOCM                                                   //;adc reference buffer offset calibration mode   //;0 - static                      1 - dynamic
//;    ADCRBOC                                                    //;adc reference buffer offset calibration        //;0 - disable                     1 - enable
//;    ADCRBE                                                     //;adc reference buffer enable                    //;0 - disable                     1 - enable
//;    ADCRBOCS3                                                  //;adc reference buffer offset calibration select //;0~15 - 0 ~ VDD      
//;    ADCRBOCS2                                                  //;                                               //;
//;    ADCRBOCS1                                                  //;                                               //;
//;    ADCRBOCS0                                                  //;                                               //;



//;---------------------------------------------------------------//;
//; ADCDPC                                                        //;
//;---------------------------------------------------------------//;
//;    ADCDOC3                                                    //;adc data offset calibration                    //;0~15 - data = data + ADCDOC
//;    ADCDOC2                                                    //;                                               //;
//;    ADCDOC1                                                    //;                                               //;
//;    ADCDOC0                                                    //;                                               //;
//;    ADCDGC3                                                    //;adc data gain calibration                      //;
//;    ADCDGC2                                                    //;                                               //;
//;    ADCDGC1                                                    //;                                               //;
//;    ADCDGC0                                                    //;                                               //;




//;---------------------------------------------------------------//;
//; UBCON                                                         //;
//;---------------------------------------------------------------//;
sbit UE                         = UBCON^0;                       //;usb enable                                     //;0 - disable                     1 - enable
sbit USRSM                      = UBCON^1;                       //;usb start resume                               //;0 - not start                   1 - device start resume
sbit UFS                        = UBCON^2;                       //;usb full speed                                 //;0 - low speed                   1 - full speed
sbit USHC                       = UBCON^3;                       //;usb sync host clock                            //;0 - not sync                    1 - sync, calibrates the IHOSC
sbit ULT                        = UBCON^4;                       //;usb loopback test                              //;0 - usr mode                    1 - loopback test mode
sbit UBRSM                      = UBCON^5;                       //;usb bus resume                                 //;0 - not resume                  1 - host wakeup the device
sbit UBSPD                      = UBCON^6;                       //;usb bus suspend                                //;0 - not suspend                 1 - host suspend the device
sbit UBRST                      = UBCON^7;                       //;usb bus reset                                  //;0 - not reset                   1 - host reset the device


//;---------------------------------------------------------------//;
//; UE0CON                                                        //;
//;---------------------------------------------------------------//;
sbit UE0DINS                         = UE0CON^0;                 //;usb ep 0 data in start                         //;0 - not start                   1 - start
sbit UE0DOUTS                        = UE0CON^1;                 //;usb ep 0 data out start                        //;0 - not start                   1 - start
sbit UE0SINS                         = UE0CON^2;                 //;usb ep 0 status in start                       //;0 - not start                   1 - start
sbit UE0SOUTS                        = UE0CON^3;                 //;usb ep 0 status out start                      //;0 - not start                   1 - start
sbit UE0STL                          = UE0CON^4;                 //;usb ep 0 stall                                 //;0 - not start                   1 - start
//;sbit                                = UE0CON^5;                 //;                                               //;0 - 0                           1 - 1
sbit UE0LTS                          = UE0CON^6;                 //;usb ep 0 loopback test start                   //;0 - not start                   1 - start
sbit UE0SDF                          = UE0CON^7;                 //;usb ep 0 setup/data flag                       //;0 - not finish                  1 - finish


//;---------------------------------------------------------------//;
//; UE1CON                                                        //;
//;---------------------------------------------------------------//;
sbit UE1INS                          = UE1CON^0;                 //;usb ep 1 in start                              //;0 - not start                   1 - start
sbit UE1OUTS                         = UE1CON^1;                 //;usb ep 1 out start                             //;0 - not start                   1 - start
sbit UE1IND0                         = UE1CON^2;                 //;usb ep 1 in start                              //;0 - not start                   1 - start
sbit UE1OUTD0                        = UE1CON^3;                 //;usb ep 1 out start                             //;0 - not start                   1 - start
sbit UE1INSTL                        = UE1CON^4;                 //;usb ep 1 in stall                              //;0 - not stall                   1 - stall
sbit UE1OUTSTL                       = UE1CON^5;                 //;usb ep 1 out stall                             //;0 - not stall                   1 - stall
sbit UE1INF                          = UE1CON^6;                 //;usb ep 1 in flag                               //;0 - not finish                  1 - finish
sbit UE1OUTF                         = UE1CON^7;                 //;usb ep 1 out flag                              //;0 - not finish                  1 - finish


//;---------------------------------------------------------------//;
//; UE2CON                                                        //;
//;---------------------------------------------------------------//;
sbit UE2INS                          = UE2CON^0;                 //;usb ep 2 in start                              //;0 - not start                   1 - start
sbit UE2OUTS                         = UE2CON^1;                 //;usb ep 2 out start                             //;0 - not start                   1 - start
sbit UE2IND0                         = UE2CON^2;                 //;usb ep 2 in start                              //;0 - not start                   1 - start
sbit UE2OUTD0                        = UE2CON^3;                 //;usb ep 2 out start                             //;0 - not start                   1 - start
sbit UE2INSTL                        = UE2CON^4;                 //;usb ep 2 in stall                              //;0 - not stall                   1 - stall
sbit UE2OUTSTL                       = UE2CON^5;                 //;usb ep 2 out stall                             //;0 - not stall                   1 - stall
sbit UE2INF                          = UE2CON^6;                 //;usb ep 2 in flag                               //;0 - not finish                  1 - finish
sbit UE2OUTF                         = UE2CON^7;                 //;usb ep 2 out flag                              //;0 - not finish                  1 - finish


//;---------------------------------------------------------------//;
//; UE3CON                                                        //;
//;---------------------------------------------------------------//;
sbit UE3INS                          = UE3CON^0;                 //;usb ep 3 in start                              //;0 - not start                   1 - start
sbit UE3OUTS                         = UE3CON^1;                 //;usb ep 3 out start                             //;0 - not start                   1 - start
sbit UE3IND0                         = UE3CON^2;                 //;usb ep 3 in start                              //;0 - not start                   1 - start
sbit UE3OUTD0                        = UE3CON^3;                 //;usb ep 3 out start                             //;0 - not start                   1 - start
sbit UE3INSTL                        = UE3CON^4;                 //;usb ep 3 in stall                              //;0 - not stall                   1 - stall
sbit UE3OUTSTL                       = UE3CON^5;                 //;usb ep 3 out stall                             //;0 - not stall                   1 - stall
sbit UE3INF                          = UE3CON^6;                 //;usb ep 3 in flag                               //;0 - not finish                  1 - finish
sbit UE3OUTF                         = UE3CON^7;                 //;usb ep 3 out flag                              //;0 - not finish                  1 - finish


//;---------------------------------------------------------------//;
//; LVDCON                                                        //;
//;---------------------------------------------------------------//;
//;    LVDS0                                                      //;lvd divider select                             //;0~15 - 
//;    LVDS1                                                      //;                                               //;
//;    LVDS2                                                      //;                                               //;
//;    LVDS3                                                      //;                                               //;
//;    LVDE                                                       //;lvd enable                                     //;0 - disable                     1 - enable
//;    LVDIS                                                      //;lvd input select                               //;0 - VDD33                       1 - P37
//;    LVDWE                                                      //;lvd wakeup enable                              //;0 - disable                     1 - enable
//;    LVDF                                                       //;lvd flag                                       //;0 - voltage not low             1 - voltage is low


//;---------------------------------------------------------------//;
//; VREFCON                                                       //;
//;---------------------------------------------------------------//;
//;    VREFX0                                                     //;vref x n                                       //;0~3  - 1,      2,       2.5,     3 
//;    VREFX1                                                     //;                                               //;
//;                                                               //;                                               //;0 - 0                           1 - 1
//;                                                               //;                                               //;0 - 0                           1 - 1
//;    VREFE                                                      //;vref enable                                    //;0 - disable                     1 - enable
//;    VREF2OE                                                    //;vref 2 output enable                           //;0 - disable                     1 - enable
//;    LVDSACE                                                    //;lvd start adc conversion enable                //;0 - disable                     1 - enable
//;    LVDRE                                                      //;lvd reset enable                               //;0 - disable                     1 - enable         



//;---------------------------------------------------------------//;
//; TPCxCON                                                       //;
//;---------------------------------------------------------------//;
//;    TPCxM0                                                     //;tpc mode                                       //;0~7 - timer, timer sac, capture rising, 
//;    TPCxM1                                                     //;                                               //;      capture falling, capture toggle, pwm high
//;    TPCxM2                                                     //;                                               //;      pwm low
//;    TPCxE                                                      //;tpc enable                                     //;0 - disabble                    1 - enable
//;    TPCxPS0                                                    //;tpc pre-scaler                                 //;0~7 - 
//;    TPCxPS1                                                    //;                                               //;
//;    TPCxPS2                                                    //;                                               //;
//;    TPCxOV                                                     //;tpc overflow                                   //;0 - not overflow                1 - overflow


//;---------------------------------------------------------------//;
//; EFCON                                                         //;
//;---------------------------------------------------------------//;
//;    EFKEY0                                                     //;embedded flash key                             //;0x77 + 0x3B - sector erase
//;    EFKEY1                                                     //;                                               //;0x5D + 0x74 - byte program
//;    EFKEY2                                                     //;                                               //;
//;    EFKEY3                                                     //;                                               //;
//;    EFKEY4                                                     //;                                               //;
//;    EFKEY5                                                     //;                                               //;
//;    EFKEY6                                                     //;                                               //;
//;    EFOPF                                                      //;embedded flash operation finish                //;0 - not finish                  1 - finish   



//;---------------------------------------------------------------//;
//; PIOCON0                                                       //;
//;---------------------------------------------------------------//;
//;    PG0HINV                                                    //;pwm generator 0 HO invert                      //;0 - disable                     1 - enable
//;    PG0LINV                                                    //;pwm generator 0 LO invert                      //;0 - disable                     1 - enable
//;    PG0HDS                                                     //;pwm generator 0 HO default (turn off) state    //;0 - low                         1 - high
//;    PG0LDS                                                     //;pwm generator 0 LO default (turn off) state    //;0 - low                         1 - high
//;    PG1HINV                                                    //;pwm generator 1 HO invert                      //;0 - disable                     1 - enable
//;    PG1LINV                                                    //;pwm generator 1 LO invert                      //;0 - disable                     1 - enable
//;    PG1HDS                                                     //;pwm generator 1 HO default (turn off) state    //;0 - low                         1 - high
//;    PG1LDS                                                     //;pwm generator 1 LO default (turn off) state    //;0 - low                         1 - high

//;---------------------------------------------------------------//;
//; PIOCON1                                                       //;
//;---------------------------------------------------------------//;
//;    PG2HINV                                                    //;pwm generator 2 HO invert                      //;0 - disable                     1 - enable
//;    PG2LINV                                                    //;pwm generator 2 LO invert                      //;0 - disable                     1 - enable
//;    PG2HDS                                                     //;pwm generator 2 HO default (turn off) state    //;0 - low                         1 - high
//;    PG2LDS                                                     //;pwm generator 2 LO default (turn off) state    //;0 - low                         1 - high
//;    PG3HINV                                                    //;pwm generator 3 HO invert                      //;0 - disable                     1 - enable
//;    PG3LINV                                                    //;pwm generator 3 LO invert                      //;0 - disable                     1 - enable
//;    PG3HDS                                                     //;pwm generator 3 HO default (turn off) state    //;0 - low                         1 - high
//;    PG3LDS                                                     //;pwm generator 3 LO default (turn off) state    //;0 - low                         1 - high

//;---------------------------------------------------------------//;
//; PIOCON2                                                       //;
//;---------------------------------------------------------------//;
//;    PG4HINV                                                    //;pwm generator 4 HO invert                      //;0 - disable                     1 - enable
//;    PG4LINV                                                    //;pwm generator 4 LO invert                      //;0 - disable                     1 - enable
//;    PG4HDS                                                     //;pwm generator 4 HO default (turn off) state    //;0 - low                         1 - high
//;    PG4LDS                                                     //;pwm generator 4 LO default (turn off) state    //;0 - low                         1 - high
//;    PG5HINV                                                    //;pwm generator 5 HO invert                      //;0 - disable                     1 - enable
//;    PG5LINV                                                    //;pwm generator 5 LO invert                      //;0 - disable                     1 - enable
//;    PG5HDS                                                     //;pwm generator 5 HO default (turn off) state    //;0 - low                         1 - high
//;    PG5LDS                                                     //;pwm generator 5 LO default (turn off) state    //;0 - low                         1 - high

//;---------------------------------------------------------------//;
//; PG0CON0                                                       //;
//;---------------------------------------------------------------//;
sbit PG0ICU                          = PG0CON0^0;                //;pwm generator 0 immediate control update       //;0 - period                      1 - immediate
sbit PG0E                            = PG0CON0^1;                //;pwm generator 0 enable                         //;0 - disable                     1 - enable
sbit PG0ON                           = PG0CON0^2;                //;pwm generator 0 turn on                        //;0 - turn on                     1 - turn off
sbit PG0TS                           = PG0CON0^3;                //;pwm generator 0 timer select                   //;0 - timer 0                     1 - timer 1
sbit PG0IFS                          = PG0CON0^4;                //;pwm generator 0 immediate fault switch         //;0 - period                      1 - immediate
sbit PG0CA                           = PG0CON0^5;                //;pwm generator 0 center-aligned mode            //;0 - edge-aligned                1 - center-aligned
sbit PG0F0F                          = PG0CON0^6;                //;pwm generator 0 fault 0 flag                   //;0 - not occur                   1 - occured
sbit PG0F1F                          = PG0CON0^7;                //;pwm generator 0 fault 1 flag                   //;0 - not occur                   1 - occured

//;---------------------------------------------------------------//;
//; PG1CON0                                                       //;
//;---------------------------------------------------------------//;
sbit PG1ICU                          = PG1CON0^0;                //;pwm generator 1 immediate control update       //;0 - period                      1 - immediate
sbit PG1E                            = PG1CON0^1;                //;pwm generator 1 enable                         //;0 - disable                     1 - enable
sbit PG1ON                           = PG1CON0^2;                //;pwm generator 1 turn on                        //;0 - turn on                     1 - turn off
sbit PG1TS                           = PG1CON0^3;                //;pwm generator 1 timer select                   //;0 - timer 0                     1 - timer 1
sbit PG1IFS                          = PG1CON0^4;                //;pwm generator 1 immediate fault switch         //;0 - period                      1 - immediate
sbit PG1CA                           = PG1CON0^5;                //;pwm generator 1 center-aligned mode            //;0 - edge-aligned                1 - center-aligned
sbit PG1F0F                          = PG1CON0^6;                //;pwm generator 1 fault 0 flag                   //;0 - not occur                   1 - occured
sbit PG1F1F                          = PG1CON0^7;                //;pwm generator 1 fault 1 flag                   //;0 - not occur                   1 - occured

//;---------------------------------------------------------------//;
//; PG2CON0                                                       //;
//;---------------------------------------------------------------//;
sbit PG2ICU                          = PG2CON0^0;                //;pwm generator 2 immediate control update       //;0 - period                      1 - immediate
sbit PG2E                            = PG2CON0^1;                //;pwm generator 2 enable                         //;0 - disable                     1 - enable
sbit PG2ON                           = PG2CON0^2;                //;pwm generator 2 turn on                        //;0 - turn on                     1 - turn off
sbit PG2TS                           = PG2CON0^3;                //;pwm generator 2 timer select                   //;0 - timer 0                     1 - timer 1
sbit PG2IFS                          = PG2CON0^4;                //;pwm generator 2 immediate fault switch         //;0 - period                      1 - immediate
sbit PG2CA                           = PG2CON0^5;                //;pwm generator 2 center-aligned mode            //;0 - edge-aligned                1 - center-aligned
sbit PG2F0F                          = PG2CON0^6;                //;pwm generator 2 fault 0 flag                   //;0 - not occur                   1 - occured
sbit PG2F1F                          = PG2CON0^7;                //;pwm generator 2 fault 1 flag                   //;0 - not occur                   1 - occured

//;---------------------------------------------------------------//;
//; PG3CON0                                                       //;
//;---------------------------------------------------------------//;
sbit PG3ICU                          = PG3CON0^0;                //;pwm generator 3 immediate control update       //;0 - period                      1 - immediate
sbit PG3E                            = PG3CON0^1;                //;pwm generator 3 enable                         //;0 - disable                     1 - enable
sbit PG3ON                           = PG3CON0^2;                //;pwm generator 3 turn on                        //;0 - turn on                     1 - turn off
sbit PG3TS                           = PG3CON0^3;                //;pwm generator 3 timer select                   //;0 - timer 0                     1 - timer 1
sbit PG3IFS                          = PG3CON0^4;                //;pwm generator 3 immediate fault switch         //;0 - period                      1 - immediate
sbit PG3CA                           = PG3CON0^5;                //;pwm generator 3 center-aligned mode            //;0 - edge-aligned                1 - center-aligned
sbit PG3F0F                          = PG3CON0^6;                //;pwm generator 3 fault 0 flag                   //;0 - not occur                   1 - occured
sbit PG3F1F                          = PG3CON0^7;                //;pwm generator 3 fault 1 flag                   //;0 - not occur                   1 - occured

//;---------------------------------------------------------------//;
//; PG4CON0                                                       //;
//;---------------------------------------------------------------//;
sbit PG4ICU                          = PG4CON0^0;                //;pwm generator 4 immediate control update       //;0 - period                      1 - immediate
sbit PG4E                            = PG4CON0^1;                //;pwm generator 4 enable                         //;0 - disable                     1 - enable
sbit PG4ON                           = PG4CON0^2;                //;pwm generator 4 turn on                        //;0 - turn on                     1 - turn off
sbit PG4TS                           = PG4CON0^3;                //;pwm generator 4 timer select                   //;0 - timer 0                     1 - timer 1
sbit PG4IFS                          = PG4CON0^4;                //;pwm generator 4 immediate fault switch         //;0 - period                      1 - immediate
sbit PG4CA                           = PG4CON0^5;                //;pwm generator 4 center-aligned mode            //;0 - edge-aligned                1 - center-aligned
sbit PG4F0F                          = PG4CON0^6;                //;pwm generator 4 fault 0 flag                   //;0 - not occur                   1 - occured
sbit PG4F1F                          = PG4CON0^7;                //;pwm generator 4 fault 1 flag                   //;0 - not occur                   1 - occured

//;---------------------------------------------------------------//;
//; PG5CON0                                                       //;
//;---------------------------------------------------------------//;
sbit PG5ICU                          = PG5CON0^0;                //;pwm generator 5 immediate control update       //;0 - period                      1 - immediate
sbit PG5E                            = PG5CON0^1;                //;pwm generator 5 enable                         //;0 - disable                     1 - enable
sbit PG5ON                           = PG5CON0^2;                //;pwm generator 5 turn on                        //;0 - turn on                     1 - turn off
sbit PG5TS                           = PG5CON0^3;                //;pwm generator 5 timer select                   //;0 - timer 0                     1 - timer 1
sbit PG5IFS                          = PG5CON0^4;                //;pwm generator 5 immediate fault switch         //;0 - period                      1 - immediate
sbit PG5CA                           = PG5CON0^5;                //;pwm generator 5 center-aligned mode            //;0 - edge-aligned                1 - center-aligned
sbit PG5F0F                          = PG5CON0^6;                //;pwm generator 5 fault 0 flag                   //;0 - not occur                   1 - occured
sbit PG5F1F                          = PG5CON0^7;                //;pwm generator 5 fault 1 flag                   //;0 - not occur                   1 - occured



//;---------------------------------------------------------------//;
//; PGxCON1                                                       //;
//;---------------------------------------------------------------//;
//;    PGxF0S0                                                    //;pwm generator x fault 0 select                 //;0~3 - disable, P02,     P03,     P04,
//;    PGxF0S1                                                    //;                                               //;
//;    PGxF1S0                                                    //;pwm generator x fault 1 select                 //;0~3 - disable, CMP0,    CMP1,    CMP2,
//;    PGxF1S1                                                    //;                                               //;
//;    PGxHIFR                                                    //;pwm generator x ignore fault from HO rising    //;0 - disable                     1 - enable
//;    PGxHIFF                                                    //;pwm generator x ignore fault from HO falling   //;0 - disable                     1 - enable
//;    PGxLIFR                                                    //;pwm generator x ignore fault from LO rising    //;0 - disable                     1 - enable
//;    PGxLIFF                                                    //;pwm generator x ignore fault from LO falling   //;0 - disable                     1 - enable

//;---------------------------------------------------------------//;
//; PGxCON2                                                       //;
//;---------------------------------------------------------------//;
//;    PGxIFT0                                                    //;pwm generator x ignore fault time              //;0~63 - ignore time = (((0 ~ 63) + 1) x 4) x sclk
//;    PGxIFT1                                                    //;                                               //;
//;    PGxIFT2                                                    //;                                               //;
//;    PGxIFT3                                                    //;                                               //;
//;    PGxIFT4                                                    //;                                               //;
//;    PGxIFT5                                                    //;                                               //;
//;    PGxHFS                                                     //;pwm generator x HO fault state                 //;0 - low                         1 - high
//;    PGxLFS                                                     //;pwm generator x LO fault state                 //;0 - low                         1 - high


//;---------------------------------------------------------------//;
//; PGxDC1                                                        //;
//;---------------------------------------------------------------//;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;    PGxACTPS2                                                  //;                                               //;
//;    PGxIDU                                                     //;pwm generator x immedate duty update           //;0 - period                      1 - immediate


//;---------------------------------------------------------------//;
//; PGxACT1                                                       //;
//;---------------------------------------------------------------//;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;                                                               //;                                               //;
//;    PGxACTPS0                                                  //;pwm generator x start adc conversion timer     //;0~7 - 1 per (1~16)                                
//;    PGxACTPS1                                                  //;post-sacler                                    //;

#define _sfrb_bank0()       do{SFRB = 0;}while(0)
#define _sfrb_bank1()       do{SFRB = 1;}while(0)

#endif