
#include "usb_descript.h"
#include "main.h"
#include "usb.h"

unsigned char code uKeyReportTable[] = {
    0X05,0X01,      //usage page            USAGE_PAGE (Generic Desktop)
    0X09,0X06,      //usage                 USAGE (Keyboard)
    0XA1,0X01,      //collection            COLLECTION (Application)
    0X05,0X07,      //usage page            USAGE_PAGE (Keyboard)
    
    0X19,0XE0,      //usage min             USAGE_MINIMUM (Keyboard LeftControl)
    0X29,0XE7,      //usage max             USAGE_MAXIMUM (Keyboard Right GUI)
    0X15,0X00,      //logical min           LOGICAL_MINIMUM (0)
    0X25,0X01,      //logical max           LOGICAL_MAXIMUM (1)
    0X75,0X01,      //report size           REPORT_SIZE (1)
    0X95,0X08,      //report count          REPORT_COUNT (8)
    0X81,0X02,      //input//                 INPUT (Data,Var,Abs)
    
    0X95,0X01,      //report count          REPORT_COUNT (1)
    0X75,0X08,      //report size           REPORT_SIZE (8)
    0X81,0X03,      //input                 INPUT (Cnst,Var,Abs)
    
    0X95,0X06,      //report count          REPORT_COUNT (6)
    0X75,0X08,      //report size           REPORT_SIZE (8)
    0X15,0X00,      //logical min           LOGICAL_MINIMUM (0)
    0X25,0x8F,      //logical max           LOGICAL_MAXIMUM (101)
    0X05,0X07,      //usage page            USAGE_PAGE (Keyboard)
    0X19,0X00,      //usage min             USAGE_MINIMUM (Reserved (no event indicated))
    0X29,0x8F,      //usage max             USAGE_MAXIMUM (Keyboard Application)
    0X81,0X00,      //input                 INPUT (Data,Ary,Abs)

    //led
    0X95,0X05,      //report count          REPORT_COUNT (5)
    0X75,0X01,      //report size           REPORT_SIZE (1)
    0X05,0X08,      //usage page            USAGE_PAGE (LEDs)
    0X19,0X01,      //usage min             USAGE_MINIMUM (Num Lock)
    0X29,0X05,      //usage max             USAGE_MAXIMUM (Kana)
    0X91,0X02,      //output                OUTPUT (Data,Var,Abs)
    
    0X95,0X01,      //report count          REPORT_COUNT (1)
    0X75,0X03,      //report size           REPORT_SIZE (3)
    0X91,0X03,      //output                OUTPUT (Cnst,Var,Abs)
    0xc0,           //end collection      
};

unsigned char code uMouseReportTable[] = {
    0X05,0X01,      //USAGE_PAGE (Generic Desktop)
    0X09,0X02,      //USAGE (Mouse)     
    0XA1,0X01,      //COLLECTION (Application)     
    0X85,0X01,      //mouse id        
    0X09,0X01,      //USAGE_PAGE(pointer)
    0XA1,0X00,      //COLLECTION        
    
    //key           
    0X05,0X09,      //USAGE_PAGE (Button)    
    0X19,0X01,      //USAGE_MINIMUM (Button 1)        
    0X29,0X05,      //USAGE_MAXIMUM (Button 5)        
    0X15,0X00,      //LOGICAL_MINIMUM (0)
    0X25,0X01,      //LOGICAL_MAXIMUM (1)
    0X95,0X05,      //REPORT_COUNT (3)
    0X75,0X01,      //REPORT_SIZE (1)    
    0X81,0X02,      //INPUT (Data,Var,Abs)
    
    //fill
    0X95,0X01,      //REPORT_COUNT (1)    
    0X75,0X03,      //REPORT_SIZE (5)
    0X81,0X03,      //INPUT (Cnst,Var,Abs)

    //X,Y,wheel          
    0X05,0X01,      //USAGE_PAGE (Generic Desktop)         
    0X09,0X30,      //USAGE (X)         
    0X09,0X31,      //USAGE (Y)     
    0X09,0X38,      //usage  wheel    
    0X15,0X80,      //LOGICAL_MINIMUM (-128)     
    0X25,0X7F,      //LOGICAL_MAXIMUM (127) 
    0X75,0X08,      //REPORT_SIZE (8)     
    0X95,0X03,      //REPORT_COUNT (2)
    0X81,0X06,      //input  
    
    0XC0,                  //end collection     
    0XC0,                  //end collection    
    
    //-------------------------------------------------------------//
    //consumer production                                          //
    //-------------------------------------------------------------//
    
    0X05,0X0C,      //usage page     consumer device    
    0X09,0X01,      //usage          consumer control       
                    
    0XA1,0X01,      //collection     application    
    0X85,0X02,      //report id      (2)
                    
    0X15,0X00,      //logical min       
    0X25,0X01,      //logical max 
    0X05,0X0C,      //usage page     consumer device 
    
    //BYTE ONE
    0X09,0Xb5,      //usage          scan next track
    0X09,0XB6,      //usage          scan previous track
    0X09,0XB7,      //usage          stop
    0X09,0XCD,      //usage          play / pause
    0X09,0Xb3,      //usage          fast forward
    0X09,0Xb4,      //usage          rewind
    0X09,0XB8,      //usage          eject
    0X09,0Xb9,      //usage          radom play
    0X75,0X01,      //report size       
    0X95,0X08,      //report count          
    0X81,0X02,      //input//  
    
    //BYTE TWO
    0X09,0Xe2,      //usage          mute
    0X09,0Xe9,      //usage          volume up
    0X09,0Xea,      //usage          volume down
    0X09,0Xb2,      //usage          record
    0X0A,0X2A,0X02, //usage          www bookmarks
    0X0A,0X2b,0X02, //usage          www history
    0X0A,0X83,0X01, //usage          Consumer Control Configuration (music)
    0X0A,0X92,0X01, //usage          calculator
    0X75,0X01,      //report size       
    0X95,0X08,      //report count          
    0X81,0X02,      //input  
    
    //BYTE THREE
    0X0A,0X23,0X02, //usage          www home page
    0X0A,0X24,0X02, //usage          www go back
    0X0A,0X25,0X02, //usage          www go forward
    0X0A,0X26,0X02, //usage          www stop
    0X0A,0X27,0X02, //usage          www fresh
    0X0A,0X8a,0X01, //usage          mail reader
    0X0A,0X96,0X01, //usage          internet browser
    0X0A,0X94,0X01, //usage          local machine browser
    0X75,0X01,      //report size       
    0X95,0X08,      //report count          
    0X81,0X02,      //input//  
    
    0X05,0X01,      //usage page     USAGE_PAGE (Generic Desktop)
    0X15,0X00,      //logical min    LOGICAL_MINIMUM (0)
    0X25,0X01,      //logical max    LOGICAL_MAXIMUM (1)
    
    //BYTE four
    0X09,0X81,      //usage          system power down
    0X09,0X82,      //usage          system sleep
    0X09,0X83,      //usage          system wake up
    
    0X95,0X03,      //report count   REPORT_COUNT (3)
    0X75,0X01,      //report size    REPORT_SIZE (1)
    0X81,0X06,      //input          INPUT (Data,Var,Rel
    
    0X95,0X01,      //REPORT_COUNT   (1)    
    0X75,0X05,      //REPORT_SIZE    (5)
    0X81,0X03,      //INPUT (Data,Var,Rel )
    
    0XC0,           //end collection 

};

unsigned char code uHidReportTable[] = {
    0x06, 0xA0, 0xff,              // USAGE_PAGE (Vendor Defined Page 1)
    0x09, 0x01,                    // USAGE (Vendor Usage 1)
    0xa1, 0x01,                    // COLLECTION (Application)
        0x85, 0x01,                    //   REPORT_ID (1)
        0x09, 0x08,                    //   USAGE (Vendor Usage 3)
        0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
        0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
        0x75, 0x08,                    //   REPORT_SIZE (8)
        0x95, 0xff,                    //   REPORT_COUNT (255)
        0xb1, 0x02,                    //   FEATURE (Data,Ary,Abs,Wrap)
        
        0x85, 0x02,                    //   REPORT_ID (2)
        0x09, 0x08,                    //   USAGE (Vendor Usage 3)
        0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
        0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
        0x75, 0x08,                    //   REPORT_SIZE (8)
        0x95, 0xff,                    //   REPORT_COUNT (255)
        0xb1, 0x02,                    //   FEATURE (Data,Ary,Abs,Wrap)

        0x85, 0x03,                    //   REPORT_ID (3)
        0x09, 0x08,                    //   USAGE (Vendor Usage 3)
        0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
        0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
        0x75, 0x08,                    //   REPORT_SIZE (8)
        0x95, 0xff,                    //   REPORT_COUNT (255)
        0xb1, 0x02,                    //   FEATURE (Data,Ary,Abs,Wrap)
    0xc0,                          //   END_COLLECTION
};

unsigned char code uLanguageTab[] = { 0x04,0x03,0x09,0x04 };
unsigned char code uMftTab[] = {
    32,         //该描述符的长度为32字节
    0x03,       //字符串描述符的类型编码为0x03
    0x42, 0x00, //B
    0x41, 0x00, //A
    0x52, 0x00, //R
    0x43, 0x00, //C
    0x4f, 0x00, //O
    0x44, 0x00, //D
    0x45, 0x00, //E
    0x20, 0x00, // 
    0x53, 0x00, //S
    0x43, 0x00, //C
    0x41, 0x00, //A
    0x4e, 0x00, //N
    0x4e, 0x00, //N
    0x45, 0x00, //E
    0x52, 0x00, //R
    //注：请将最后一个多余的逗号删除
 };


unsigned char code uProductTab[] = {
    32,         //该描述符的长度为32字节
    0x03,       //字符串描述符的类型编码为0x03
    0x42, 0x00, //B
    0x41, 0x00, //A
    0x52, 0x00, //R
    0x43, 0x00, //C
    0x4f, 0x00, //O
    0x44, 0x00, //D
    0x45, 0x00, //E
    0x20, 0x00, // 
    0x53, 0x00, //S
    0x43, 0x00, //C
    0x41, 0x00, //A
    0x4e, 0x00, //N
    0x4e, 0x00, //N
    0x45, 0x00, //E
    0x52, 0x00, //R
    //注：请将最后一个多余的逗号删除
};


unsigned char code uInterfaceTab0[] = {
    26,         //该描述符的长度为26字节
    0x03,       //字符串描述符的类型编码为0x03
    0x55, 0x00, //U
    0x53, 0x00, //S
    0x42, 0x00, //B
    0x20, 0x00, // 
    0x4b, 0x00, //K
    0x65, 0x00, //e
    0x79, 0x00, //y
    0x62, 0x00, //b
    0x6f, 0x00, //o
    0x61, 0x00, //a
    0x72, 0x00, //r
    0x64, 0x00, //d
    //注：请将最后一个多余的逗号删除
};


unsigned char code uInterfaceTab1[] = {
    30,         //该描述符的长度为30字节
    0x03,       //字符串描述符的类型编码为0x03
    0x55, 0x00, //U
    0x53, 0x00, //S
    0x42, 0x00, //B
    0x20, 0x00, // 
    0x56, 0x00, //V
    0x45, 0x00, //E
    0x4e, 0x00, //N
    0x44, 0x00, //D
    0x45, 0x00, //E
    0x52, 0x00, //R
    0x20, 0x00, // 
    0x48, 0x00, //H
    0x49, 0x00, //I
    0x44, 0x00, //D
    //注：请将最后一个多余的逗号删除
};


unsigned char code uSerialNoTab[] = {
    26,         //该描述符的长度为26字节
    0x03,       //字符串描述符的类型编码为0x03
    0x53, 0x00, //S
    0x4e, 0x00, //N
    0x32, 0x00, //2
    0x30, 0x00, //0
    0x31, 0x00, //1
    0x37, 0x00, //7
    0x30, 0x00, //0
    0x36, 0x00, //6
    0x56, 0x00, //V
    0x45, 0x00, //E
    0x52, 0x00, //R
    0x31, 0x00, //1
    //注：请将最后一个多余的逗号删除
};


unsigned char  code uDevHidTable[] = {
0x12,                           //uint8 b_length
0x01,                           //uint8 b_descriptor_type
0x10,                           //uint8 bcd_usb_l
0x01,                           //uint8 bcd_usb_h
0x00,                           //uint8 b_device_class
0x00,                           //uint8 b_device_sub_class
0x00,                           //uint8 b_device_protocol
_MAX_EP_SIZE_,                  //uint8 b_max_packe_size0
0xFF,                           //uint8 id_vender_l
0xFF,                           //uint8 id_vender_h
0x35,                           //uint8 id_product_l
0x00,                           //uint8 id_product_h
0x01,                           //uint8 bcd_device_l
0x00,                           //uint8 bcd_device_h
#if _DEV_STR_DES_EN
0x01,                           //uint8 i_manufacturer
0x02,                           //uint8 i_product
0x03,                           //uint8 i_serial_number
#else
0x00,                           //uint8 i_manufacturer
0x00,                           //uint8 i_product
0x00,                           //uint8 i_serial_number
#endif
0x01,                           //uint8 b_num_configuration
};

unsigned char code uDevHidCfgTable[] = {
//Configuration 9-byte
0x09,                                          //0--bLength
0x02,                                          //1--bDescriptorType
( 9 + (9 + 9 + 7 ) + ( 9 + 9 )*1 ),            //2--wTotalLength l
0X00,                                          //3--wTotalLength h
0x02,                                          //4--bNumInterFace
0x01,                                          //5--bConfigurationValue
0x00,                                          //6--iConfigration
0xA0,                                          //7--bmAtrributes
0x64,                                          //8--bMaxPower Imax =2*bMaxPower

//-------------------------------------------------------------//
//Interface 0 9-byte for keyboard,(ep1)                        //
//-------------------------------------------------------------//
0x09,                                          //0--bLengh
0x04,                                          //1--bdescriptortpye
0x00,                                          //2--binterfacenumber
0x00,                                          //3--balternatsetting
0x01,                                          //4--bnumendpoints
0x03,                                          //5--binterfaceclass
0x01,                                          //6--binterfacesubclass
0x01,                                          //7--binterfaceprotocol 01=KB// 02=M
#if _DEV_STR_DES_EN
0x04,                                          //8--iconfiguration
#else
0x00,                                          //8--iconfiguration
#endif

//-------------------------------------------------------------//
//HID 0 9-byte                                                 //
//-------------------------------------------------------------//
//USB_HID_KEYBOARD_TABLE:
0x09,                                          //0--blength
0x21,                                          //1--bdescriptortype
0x10,                                          //2--bbcdhidl
0x01,                                          //3--bcdhid
0x00,                                          //4--bcountycode
0x01,                                          //5--bnumdescriptors
0x22,                                          //6--bdescriptortype
_KEY_REPORT_TAB_SIZE_ & 0xFF,                  //7--bdescriptor length, low byte
( _KEY_REPORT_TAB_SIZE_ >>8 ) & 0xFF,          //8--bdescriptor length, high byte

//-------------------------------------------------------------//
//EP1 7-byte  for HID0 (keyboard)                              //
//-------------------------------------------------------------//
0x07,                                          //0--blength
0x05,                                          //1--bdescriptortype
0x81,                                          //2--bendpointaddress
0x03,                                          //3--bmattributes
_MAX_EP_SIZE_/*0x08*/,                         //4--bwmaxpacketlsize
0x00,                                          //5--bwmaxpacketh
0x01,                                          //6--Query interval(ms)

#ifdef _USB_HID
//-------------------------------------------------------------//
//Interface 1 9-byte for HID_VENDER                                 //
//-------------------------------------------------------------//
0x09,                                          //0--bLengh
0x04,                                          //1--bdescriptortpye
0x01,                                          //2--binterfacenumber
0x00,                                          //3--balternatsetting
0x00,                                          //4--bnumendpoints
0x03,                                          //5--binterfaceclass
0x00,                                          //6--binterfacesubclass
0x00,                                          //7--binterfaceprotocol 01=KB// 02=M
#if _DEV_STR_DES_EN
0x05,                                          //8--iconfiguration
#else
0x00,                                          //8--iconfiguration
#endif

//-------------------------------------------------------------//
//HID 1 9-byte                                                 //
//-------------------------------------------------------------//
//USB_HID_TABLE:
0x09,                                          //0--blength
0x21,                                          //1--bdescriptortype
0x10,                                          //2--bbcdhidl
0x01,                                          //3--bcdhid
0x00,                                          //4--bcountycode
0x01,                                          //5--bnumdescriptors
0x22,                                          //6--bdescriptortype
_HID_REPORT_TAB_SIZE_ & 0xFF,                  //7--bdescriptor length low byte 
( _HID_REPORT_TAB_SIZE_ >>8) & 0xFF,           //8--bdescriptor length high byte
#endif /* _USB_HID */
};

#ifdef _USB_VCOM
unsigned char  code uDevCdcTable[] = {
0x12,                           //uint8 b_length
0x01,                           //uint8 b_descriptor_type
0x10,                           //uint8 bcd_usb_l
0x01,                           //uint8 bcd_usb_h
0x02,                           //uint8 b_device_class
0x00,                           //uint8 b_device_sub_class
0x00,                           //uint8 b_device_protocol
_MAX_EP_SIZE_,                  //uint8 b_max_packe_size0
0x4A,                           //uint8 id_vender_l
0x29,                           //uint8 id_vender_h
0x00,                           //uint8 id_product_l
0x01,                           //uint8 id_product_h
0x01,                           //uint8 bcd_device_l
0x00,                           //uint8 bcd_device_h
#if _DEV_STR_DES_EN
0x01,                           //uint8 i_manufacturer
0x02,                           //uint8 i_product
0x03,                           //uint8 i_serial_number
#else
0x00,                           //uint8 i_manufacturer
0x00,                           //uint8 i_product
0x00,                           //uint8 i_serial_number
#endif
0x01,                           //uint8 b_num_configuration
};

unsigned char code uDevCdcCfgTable[] = {
//Configuration 9-byte
0x09,                                          //0--bLength
0x02,                                          //1--bDescriptorType
( 9 + ( 9 + 19 + 7 ) + ( 9 + 7 + 7 ) ),        //2--wTotalLength l
0X00,                                          //3--wTotalLength h
0x02,                                          //4--bNumInterFace
0x01,                                          //5--bConfigurationValue
0x00,                                          //6--iConfigration
0xA0,                                          //7--bmAtrributes
0x64,                                          //8--bMaxPower Imax =2*bMaxPower

/* CIC INTERFACE DESCRIPTOR */
0x09,
0x04,
0,                          /* bInterfaceNumber */
0x00,                       /* bAlternateSetting */
0x01,                       /* management and notification(optional)element present */
0x02,                       /* Communication Interface Class */
0x02,
0x01,
0x00,                       /* Interface Description String Index*/

/* CDC Class-Specific descriptor */
0x05,                       /* size of Functional Desc in bytes */
0x24,                       /* descriptor type*/
0x00,
0x10,
0x01,                       /* USB Class Definitions for CDC spec release number in BCD */

0x05,                       /* Size of this descriptor */
0x24,                       /* descriptor type*/
0x01,
0x01,/*may use 0x03 */      /* device handales call management itself(D0 set)
                            and will process commands multiplexed over the data interface */
0x01,                       /* Indicates multiplexed commands are
                            handled via data interface */

0x04,                       /* Size of this descriptor */
0x24,                       /* descriptor type*/
0x02,
0x02, /*may use 0x0F */     /* Device Supports all commands for ACM - CDC
                            PSTN SubClass bmCapabilities */

0x05,                       /* size of Functional Desc in bytes */
0x24,                       /* descriptor type*/
0x06,
0x00,                       /* Interface Number of Control */
0x01,                       /* Interface Number of Subordinate (Data Class) Interface */

/*Endpoint descriptor */
0x07,
0x05,
0x81,
0x03,
_MAX_EP_SIZE_,
0x00,
0x0A,

/* DATA CLASS INTERFACE DESCRIPTOR */
0x09,
0x04,
1,                          /* bInterfaceNumber */
0x00,                       /* bAlternateSetting */
0x02,                       /* notification element included */
0x0A,                       /* DATA Interface Class */
0x00,                       /* Data Interface SubClass Code */
0x00,
0x00,                       /* Interface Description String Index*/

/*Endpoint descriptor */
0x07,
0x05,
0x82,
0x02,
_MAX_EP_SIZE_,
0x00,
0x00,                       /* This value is ignored for Bulk ENDPOINT */

/*Endpoint descriptor */
0x07,
0x05,
0x03,
0x02,
_MAX_EP_SIZE_,
0x00,
0x00                        /* This value is ignored for Bulk ENDPOINT */
};
#endif /* _USB_VCOM */

unsigned char* GetHid0Des()
{
    unsigned char* lpszBuf = uDevHidCfgTable;
    lpszBuf += 18;
    return lpszBuf;
}

unsigned char* GetHid1Des()
{
    unsigned char* lpszBuf = uDevHidCfgTable;
    lpszBuf += 43;
    return lpszBuf;
}



