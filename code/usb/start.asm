$NOMOD51

NAME CV8F5025_VECTOR_TAB

#include "../system/inc/CV8F5025.H"


?PR?_USB_BUS_INT?CV8F5025_VECTOR_TAB SEGMENT CODE at 0x1883

;PUBLIC USB_BUS_INT

//----------------------USB_BUS_INT -----------------------------//
    RSEG  ?PR?_USB_BUS_INT?CV8F5025_VECTOR_TAB
_USB_BUS_INT:
    USING    0

USB_BUS_INT:
    ljmp    0x188B

?PR?_USB_EP1_OUT_INT?CV8F5025_VECTOR_TAB SEGMENT CODE at 0x189B

;PUBLIC USB_EP1_OUT_INT

//------------------USB_EP1_OUT_INT -----------------------------//
    RSEG  ?PR?_USB_EP1_OUT_INT?CV8F5025_VECTOR_TAB
_USB_EP1_OUT_INT:
    USING    0

USB_EP1_OUT_INT:
    ljmp    0x188B

?PR?_USB_EP2_OUT_INT?CV8F5025_VECTOR_TAB SEGMENT CODE at 0x18AB

;PUBLIC USB_EP2_OUT_INT

//------------------USB_EP2_OUT_INT -----------------------------//
    RSEG  ?PR?_USB_EP2_OUT_INT?CV8F5025_VECTOR_TAB
_USB_EP2_OUT_INT:
    USING    0

USB_EP2_OUT_INT:
    ljmp    0x188B
	
?PR?_USB_EP3_OUT_INT?CV8F5025_VECTOR_TAB SEGMENT CODE at 0x18BB

;PUBLIC USB_EP3_OUT_INT

//------------------USB_EP3_OUT_INT -----------------------------//
    RSEG  ?PR?_USB_EP3_OUT_INT?CV8F5025_VECTOR_TAB
_USB_EP3_OUT_INT:
    USING    0

USB_EP3_OUT_INT:
    ljmp    0x188B

END