

$NOMOD51

NAME CV8F5025_PROGRAM

#include "../inc/CV8F5025.H"

#define _P_CLK                  P20
#define _P_DAT                  P21

#define _CMD_ADDR_H             0x33
#define _CMD_ADDR_L             0x34
#define _CMD_WR_BYTE            0x35
#define _CMD_RD_BYTE            0x36
#define _CMD_ERASE_ALL          0x37
    

?PR?_PROGRAM_UNDER_USER_MODE?CV8F5025_PROGRAM SEGMENT CODE at 0x7E00    //0x1D00

PUBLIC PROGRAM_UNDER_USER_MODE

//----------------------PROGRAM_UNDER_USER_MODE -----------------------------//
    RSEG  ?PR?_PROGRAM_UNDER_USER_MODE?CV8F5025_PROGRAM
_PROGRAM_UNDER_USER_MODE:
    USING    0

PROGRAM_UNDER_USER_MODE:
    clr     SFRB
    mov     P2PU,               #0x02 ;pull-up _P_DAT

    // set timeout 64mS = 48 (MHz) * 64(ms) * 1000 / 128(div)
    setb    SFRB
    mov     T0PR0,              #0xDC
    mov     T0PR1,              #0x05  
    mov     T0CON,              #0x71
    mov     T0CNT0,             #0x00
    mov     T0CNT1,             #0x00

WAIT_START_BIT:
    clr     SFRB
    jnb     _P_DAT,             PROGRAM_START

    setb    SFRB
    mov     A,                  T0CON
    jnb     A7,                 WAIT_START_BIT

PROGRAM_END:
    clr     A
    clr     SFRB
    mov     P2PU,               A

    setb    SFRB
    mov     T0CON,              A
    ret

//--------------------------------------------------------------------------//
//start recv command                                                        //
//--------------------------------------------------------------------------//
PROGRAM_START:
    jb      _P_CLK,             $               
    jnb     _P_CLK,             $               
    jb      _P_DAT,             PROGRAM_START   

    mov     R0,                 #6
    clr     A
RECV_CMD:
    jb      _P_CLK,             $               
    jnb     _P_CLK,             $               
    mov     C,                  _P_DAT          
    rlc     A
    djnz    R0,                 RECV_CMD
    mov     R1,                 A

    mov     R0,                 #8
RECV_DATA:
    jb      _P_CLK,             $               
    jnb     _P_CLK,             $               
    mov     C,                  _P_DAT          
    rlc     A
    djnz    R0,                 RECV_DATA
    mov     R2,                 A

RECV_CRC:    
    jb      _P_CLK,             $               
    jnb     _P_CLK,             $               
    mov     C,                  _P_DAT   
           
    //mov     P2PU,               #0x02 
    setb    _P_DAT         
    mov     P2OE,               #0x02           
    
    mov     A,                  R1
    rlc     A
    xrl     A,                  R2
    mov     C,                  PSW.0
    jnc     CMD_SET_ADDRESS_L

CRC_ERR:
    mov     R0,                 #0xAE
    mov     R1,                 #0x02
    ljmp    SEND_RPS
                  
CMD_SET_ADDRESS_L:
    mov     A,                  R1

    cjne    A,                  #_CMD_ADDR_L,           CMD_SET_ADDRESS_H
    ljmp    SET_ADDRESS_L

CMD_SET_ADDRESS_H:
    cjne    A,                  #_CMD_ADDR_H,           CMD_WR
    ljmp    SET_ADDRESS_H
  

CMD_WR:
    cjne    A,                  #_CMD_WR_BYTE,          CMD_RD
    ljmp    WR_BYTE
     
CMD_RD:
    cjne    A,                  #_CMD_RD_BYTE,          CMD_ERASE_ALL
    ljmp    RD_BYTE

CMD_ERASE_ALL:
    cjne    A,                  #_CMD_ERASE_ALL,        CMD_ERROR
    ljmp    ERASE_ALL

CMD_ERROR:
    mov     R0,                 #0xAF
    mov     R1,                 #0x01
    ljmp    SEND_RPS


//--------------------------------------------------------------------------//
//set low byte address                                                      //
//--------------------------------------------------------------------------//
SET_ADDRESS_L:
    clr     SFRB
    mov     DPL,                R2

    setb    SFRB
    mov     EFADR0,             R2
    
    clr     A
    mov     R0,                 EFADR0
    mov     R1,                 #0x00
    ljmp    SEND_RPS

//--------------------------------------------------------------------------//
//set high byte address                                                     //
//--------------------------------------------------------------------------//
SET_ADDRESS_H:
    clr     SFRB
    mov     DPH,                R2

    setb    SFRB
    mov     EFADR1,             R2
   
    mov     R0,                 EFADR1
    mov     R1,                 #0x00
    ljmp    SEND_RPS

//--------------------------------------------------------------------------//
//recv one byte data, and wait to flush to flash                            //
//--------------------------------------------------------------------------//
WR_BYTE:
    setb    SFRB

    mov     EFBUF,              R2
    mov     EFCON,              #0x5D 
    mov     EFCON,              #0x74 
WAIT_WR:
    mov     A,                  EFCON
    jnb     A7,                 WAIT_WR
    anl     EFCON,              #~0x80

    inc     EFADR0
    mov     A,                  EFADR0
    jnz     WR_BYTE_END

    inc     EFADR0

WR_BYTE_END:
    mov     PSW,                #0x00
    //clr     SFRB

    mov     R0,                 0x02//EFBUF
    mov     R1,                 #0x00
    ljmp    SEND_RPS

//--------------------------------------------------------------------------//
//read one byte from flash                                                  //
//--------------------------------------------------------------------------//
RD_BYTE:
    clr     SFRB

    clr     A
    movc    A,                  @A+DPTR
    inc     DPTR
    
    mov     R0,                 A
    mov     R1,                 #0x00
    ljmp    SEND_RPS

//--------------------------------------------------------------------------//
//Erase all user data on flash                                              //
//--------------------------------------------------------------------------//
ERASE_ALL:
    setb    SFRB
    
    mov     R1,                 #0x3F
    mov     R0,                 #0x00
ERASE_ALL_LP:
    mov     EFADR1,             R0
    mov     EFADR0,             #0x00
    call    ERASE_SECTOR

    inc     R0
    inc     R0
    djnz    R1,                 ERASE_ALL_LP

    mov     R0,                 #0xA9
    mov     R1,                 #0x00
    ljmp    SEND_RPS

//--------------------------------------------------------------------------//
//Erase all user data on flash                                              //
//--------------------------------------------------------------------------//
ERASE_SECTOR:
    setb    SFRB
    mov     EFCON,              #0x77 
    mov     EFCON,              #0x3B 

WAIT_ERASE:
    mov     A,                  EFCON
    jnb     A7,                 WAIT_ERASE
    anl     EFCON,              #~0x80

    ret


//--------------------------------------------------------------------------//
//respronse programer, and one command end                                  //
//--------------------------------------------------------------------------//
SEND_RPS:
    clr     SFRB

    mov     A,                  R0
    mov     R2,                 PSW

    mov     A,                  R1
    anl     A,                  #0x03
    mov     R1,                 A
    mov     A,                  PSW
    
    xrl     A,                  R2
    anl     A,                  #0x01
    rl      A
    rl      A

    orl     A,                  #0x08
    orl     A,                  R1
    mov     R1,                 A

    //----------------------------------------------------------------------//
    mov     A,                  R0
    mov     R0,                 #0x08

    clr     _P_DAT
    mov     P2OE,               #0x02
    mov     P2PU,               #0x00

SEND_RPS_LP:
    rlc     A
    jnb     _P_CLK,             $               
    jb      _P_CLK,             $               
    mov     _P_DAT,             C               
    djnz    R0,                 SEND_RPS_LP

    mov     A,                  R1
    mov     R0,                 #0x04
SEND_RPS_LP1:
    rrc     A
    jnb     _P_CLK,             $               
    jb      _P_CLK,             $               
    mov     _P_DAT,             C               
    djnz    R0,                 SEND_RPS_LP1
        
    mov     P2OE,               #0x00
    ljmp    PROGRAM_START           



END






