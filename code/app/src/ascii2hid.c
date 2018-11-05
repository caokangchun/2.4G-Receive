
#include "ascii2hid.h"

//---------------------------------------------------
//          USA   ASCII <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_USA[] = 
{
	0, 						0x00, // 0
	0, 						0x00, // 1
	0, 						0x00, // 2
	0, 						0x00, // 3
	0, 						0x00, // 4
	0, 						0x00, // 5
	0, 						0x00, // 6
	0, 						0x00, // 7
	hid_back,				0x00, // 8
	hid_tab,				0x00, // 9
	hid_down,				0x00, // 0A
	0,						0x00, // 0B
	0,						0x00, // 0C
	hid_enter,				0x00, // 0D
	hid_f1,					0x00, // 0E
	hid_f2,					0x00, // 0F
   	hid_f3,			 		0x00, // 10
   	hid_f4,					0x00, // 11
   	hid_f5,					0x00, // 12
   	hid_f6,					0x00, // 13
   	hid_f7,					0x00, // 14
   	hid_f8,					0x00, // 15
   	hid_f9,					0x00, // 16
   	hid_f10,				0x00, // 17
   	hid_f11,				0x00, // 18
   	hid_f12,				0x00, // 19
   	0,						0x00, // 1A
   	hid_esc,				0x00, // 1B
   	0,						0x00, // 1C
   	0,						0x00, // 1D
   	0,						0x00, // 1E
   	0,						0x00, // 1F
   	
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_quotation_mark,		0x20, // 22 "
	hid_3,					0x20, // 23 #
	hid_4,					0x20, // 24 $
	hid_5,					0x20, // 25 %
	hid_7,					0x20, // 26 &
	hid_quotation_mark,		0x00, // 27 '
	hid_9,					0x20, // 28 (
	hid_0,					0x20, // 29 )
	hid_8,					0x20, // 2A *
	hid_equal_mark,			0x20, // 2B +
	hid_comma,				0x00, // 2C ,
	hid_underline,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_solidus_r,			0x00, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_semicolon,			0x20, // 3A :
	hid_semicolon,			0x00, // 3B ;
	hid_comma,				0x20, // 3C <
	hid_equal_mark,			0x00, // 3D =
	hid_full_stop,			0x20, // 3E >
	hid_solidus_r,			0x20, // 3F ?
	hid_2,					0x20, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_y,					0x20, // 59 Y
	hid_z,					0x20, // 5A Z
	
	hid_braces_l,			0x00, // 5B [
	hid_solidus_l,			0x00, // 5C "\"
	hid_braces_r,			0x00, // 5D ]
	hid_6,					0x20, // 5E ^
	hid_underline,			0x20, // 5F _
	hid_wave_line,			0x00, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_y,					0x00, // 79 y
	hid_z,					0x00, // 7A z
	
	hid_braces_l,			0x20, // 7B {
	hid_solidus_l,			0x20, // 7C |
	hid_braces_r,			0x20, // 7D }
	hid_wave_line,			0x20, // 7E ~
	hid_del,				0x00, // 7F DEL

	/* below are not standard ascii */
	hid_f1,					0x00, // 80
	hid_f2, 				0x00, // 81
	hid_f3, 				0x00, // 82
	hid_f4, 				0x00, // 83
	hid_f5, 				0x00, // 84
	hid_f6, 				0x00, // 85
	hid_f7, 				0x00, // 86
	hid_f8, 				0x00, // 87
	hid_f9, 				0x00, // 88
	hid_f10, 				0x00, // 89
	hid_f11, 				0x00, // 8A
	hid_f12, 				0x00, // 8B
	hid_f12, 				0x00, // 8B
	0xF1, 					0x02, // 8C
	0xF8, 					0x02, // 8D
	0xF1, 					0x20, // 8E
	0xF8, 					0x20, // 8F
	0xF1, 					0x04, // 90
	0xF8, 					0x04, // 91
	0xF1, 					0x40, // 92
	0xF8, 					0x40, // 93
	0xF1, 					0x01, // 94
	0xF8, 					0x01, // 95
	0xF1, 					0x10, // 96
	0xF8, 					0x10, // 97
	hid_nk_div,				0x00, // 98
	hid_nk_asterisk,		0x00, // 99
	hid_nk_sub,				0x00, // 9A
	hid_nk_plus,			0x00, // 9B
	hid_nk_del,				0x00, // 9C
	hid_nk_enter,			0x00, // 9D
	hid_nk_0,				0x00, // 9E
	hid_nk_1,				0x00, // 9F
	hid_nk_2,				0x00, // A0
	hid_nk_3,				0x00, // A1
	hid_nk_4,				0x00, // A2
	hid_nk_5,				0x00, // A3
	hid_nk_6,				0x00, // A4
	hid_nk_7,				0x00, // A5
	hid_nk_8,				0x00, // A6
	hid_nk_9,				0x00, // A7
	hid_ins,				0x00, // A8
	hid_del,				0x00, // A9
	hid_home,				0x00, // AA
	hid_end,				0x00, // AB
	hid_page_up,			0x00, // AC
	hid_page_down,			0x00, // AD
	hid_up,					0x00, // AE
	hid_down,				0x00, // AF
	hid_left,				0x00, // B0
	hid_right,				0x00, // B1
	0,						0x00, // B2
	hid_ins,				0x00, // B3
	hid_del,				0x00, // B4
	hid_home,				0x00, // B5
	hid_end,				0x00, // B6
	hid_page_up,			0x00, // B7
	hid_page_down,			0x00, // B8
	hid_up,					0x00, // B9
	hid_down,				0x00, // BA
	hid_left,				0x00, // BB
	hid_right,				0x00, // BC
	0,						0x00, // BD
	hid_nk_num,				0x00, // BE
	hid_caps,				0x00, // BF
	hid_scroll,				0x00, // C0
};

//---------------------------------------------------
//          TURKEY   ASCII  <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_TurkeyF[] = 
{	
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_2,			        0x20, // 22 "
	hid_quotation_mark,		0x40, // 23 #
	hid_4,					0x20, // 24 $
	hid_5,					0x20, // 25 %
	hid_6,					0x20, // 26 &
	hid_7,					0x20, // 27 '
	hid_8,					0x20, // 28 (
	hid_9,					0x20, // 29 )
	hid_wave_line,			0x20, // 2A *
	hid_wave_line,			0x00, // 2B +
	hid_solidus_r,			0x00, // 2C ,
	hid_equal_mark,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_underline,			0x00, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_full_stop,			0x20, // 3A :
	hid_solidus_r,			0x20, // 3B ;
	hid_k45,			    0x00, // 3C <
	hid_0,					0x20, // 3D =
	hid_k45,				0x20, // 3E >
	hid_underline,			0x20, // 3F ?
	hid_q,					0x40, // 40 @
	
	hid_f,					0x20, // 41 A
	hid_comma,				0x20, // 42 B
	hid_v,					0x20, // 43 C
	hid_y,					0x20, // 44 D
	hid_d,					0x20, // 45 E
	hid_q,					0x20, // 46 F
	hid_w,					0x20, // 47 G
	hid_o,					0x20, // 48 H
	hid_r,					0x20, // 49 I
	hid_z,					0x20, // 4A J
	hid_j,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_k,					0x20, // 4D M
	hid_i,					0x20, // 4E N
	hid_t,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_braces_l,			0x20, // 51 Q
	hid_u,					0x20, // 52 R
	hid_m,					0x20, // 53 S
	hid_h,					0x20, // 54 T
	hid_a,					0x20, // 55 U
	hid_c,					0x20, // 56 V
	hid_braces_r,			0x20, // 57 W
	hid_solidus_l,			0x20, // 58 X
	hid_semicolon,			0x20, // 59 Y
	hid_n,					0x20, // 5A Z
	
	hid_8,					0x40, // 5B [
	hid_underline,			0x40, // 5C "\"
	hid_9,					0x40, // 5D ]
	hid_3,					0x20, // 5E ^
	hid_equal_mark,			0x20, // 5F _
	hid_solidus_l,			0x40, // 60 `
	
	hid_f,				    0x00, // 61 a
	hid_comma,			    0x00, // 62 b
	hid_v,				    0x00, // 63 c
	hid_y,				    0x00, // 64 d
	hid_d,				    0x00, // 65 e
	hid_q,				    0x00, // 66 f
	hid_w,				    0x00, // 67 g
	hid_o,				    0x00, // 68 h
	hid_s,					0x00, // 69 i
	hid_z,				    0x00, // 6A j
	hid_j,				    0x00, // 6B k
	hid_l,				    0x00, // 6C l
	hid_k,				    0x00, // 6D m
	hid_i,				    0x00, // 6E n
	hid_t,				    0x00, // 6F o
	hid_p,				    0x00, // 70 p
	hid_braces_l,	        0x00, // 71 q
	hid_u,				    0x00, // 72 r
	hid_m,				    0x00, // 73 s
	hid_h,				    0x00, // 74 t
	hid_a,				    0x00, // 75 u
	hid_c,				    0x00, // 76 v
	hid_braces_r,	        0x00, // 77 w
	hid_solidus_l,	        0x00, // 78 x
	hid_semicolon,	        0x00, // 79 y
	hid_n,				    0x00, // 7A z
	
	hid_7,					0x40, // 7B {
	hid_k45,			    0x40, // 7C |
	hid_0,					0x40, // 7D }
	hid_braces_r,			0x40, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          TURKEY   ASCII  <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_TurkeyQ[] = 
{	
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_wave_line,			0x00, // 22 "
	hid_3,					0x40, // 23 #
	hid_4,					0x40, // 24 $
	hid_5,					0x20, // 25 %
	hid_6,					0x20, // 26 &
	hid_2,					0x20, // 27 '
	hid_8,					0x20, // 28 (
	hid_9,					0x20, // 29 )
	hid_underline,			0x00, // 2A *
	hid_4,					0x20, // 2B +
	hid_solidus_l,			0x00, // 2C ,
	hid_equal_mark,			0x00, // 2D -
	hid_solidus_r,			0x00, // 2E .
	hid_7,					0x20, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_solidus_r,			0x20, // 3A :
	hid_solidus_l,			0x20, // 3B ;
	hid_wave_line,			0x40, // 3C <
	hid_0,					0x20, // 3D =
	hid_1,					0x40, // 3E >
	hid_underline,			0x20, // 3F ?
	hid_q,					0x40, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_y,					0x20, // 59 Y
	hid_z,					0x20, // 5A Z
	
	hid_8,					0x40, // 5B [
	hid_underline,			0x40, // 5C "\"
	hid_9,					0x40, // 5D ]
	hid_3,					0x20, // 5E ^
	hid_equal_mark,			0x20, // 5F _
	hid_solidus_l,			0x40, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_quotation_mark,		0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_y,					0x00, // 79 y
	hid_z,					0x00, // 7A z
	
	hid_7,					0x40, // 7B {
	hid_equal_mark,			0x40, // 7C |
	hid_0,					0x40, // 7D }
	hid_braces_r,			0x40, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          SPAIN   ASCII  <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_Spain[] = 
{	
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_2,			        0x20, // 22 "
	hid_3,					0x40, // 23 #
	hid_4,					0x20, // 24 $
	hid_5,					0x20, // 25 %
	hid_6,					0x20, // 26 &
	hid_quotation_mark,		0x00, // 27 '
	hid_8,					0x20, // 28 (
	hid_9,					0x20, // 29 )
	hid_braces_r,			0x20, // 2A *
	hid_braces_r,			0x00, // 2B +
	hid_comma,			    0x00, // 2C ,
	hid_solidus_r,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_7,					0x20, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_full_stop,			0x20, // 3A :
	hid_comma,			    0x20, // 3B ;
	hid_k45,			    0x00, // 3C <
	hid_0,					0x20, // 3D =
	hid_k45,				0x20, // 3E >
	hid_underline,			0x20, // 3F ?
	hid_2,					0x40, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_y,					0x20, // 59 Y
	hid_z,					0x20, // 5A Z
	
	hid_braces_l,			0x40, // 5B [
	hid_wave_line,			0x40, // 5C "\"
	hid_braces_r,			0x40, // 5D ]
	hid_braces_l,			0x20, // 5E ^
	hid_solidus_r,			0x20, // 5F _
	hid_braces_l,			0x00, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_y,					0x00, // 79 y
	hid_z,					0x00, // 7A z
	
	hid_quotation_mark,		0x40, // 7B {
	hid_1,			        0x40, // 7C |
	hid_solidus_l,			0x40, // 7D }
	hid_4,			        0x40, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          PORTUGAL   ASCII  <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_Portugal[] = 
{	
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_2,			        0x20, // 22 "
	hid_3,					0x20, // 23 #
	hid_4,					0x20, // 24 $
	hid_5,					0x20, // 25 %
	hid_6,					0x20, // 26 &
	hid_underline,		    0x00, // 27 '
	hid_8,					0x20, // 28 (
	hid_9,					0x20, // 29 )
	hid_braces_l,			0x20, // 2A *
	hid_braces_l,			0x00, // 2B +
	hid_comma,			    0x00, // 2C ,
	hid_solidus_r,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_7,					0x20, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_full_stop,			0x20, // 3A :
	hid_comma,			    0x20, // 3B ;
	hid_k45,			    0x00, // 3C <
	hid_0,					0x20, // 3D =
	hid_k45,				0x20, // 3E >
	hid_underline,			0x20, // 3F ?
	hid_2,					0x40, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_y,					0x20, // 59 Y
	hid_z,					0x20, // 5A Z
	
	hid_8,			        0x40, // 5B [
	hid_wave_line,			0x00, // 5C "\"
	hid_9,			        0x40, // 5D ]
	hid_solidus_l,			0x20, // 5E ^
	hid_solidus_r,			0x20, // 5F _
	hid_braces_r,			0x20, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_y,					0x00, // 79 y
	hid_z,					0x00, // 7A z
	
	hid_7,		            0x40, // 7B {
	hid_wave_line,		    0x20, // 7C |
	hid_0,			        0x40, // 7D }
	hid_solidus_l,			0x00, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          FRANCE   ASCII  <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_France[] = 
{  	
   	hid_space,				0x00, // 20 SPACE
   	hid_solidus_r,			0x00, // 21 !
	hid_3,			        0x00, // 22 "
	hid_3,					0x40, // 23 #
	hid_braces_r,			0x00, // 24 $
	hid_quotation_mark,		0x20, // 25 %
	hid_1,					0x00, // 26 &
	hid_4,		            0x00, // 27 '
	hid_5,					0x00, // 28 (
	hid_underline,			0x00, // 29 )
	hid_k42,			    0x00, // 2A *
	hid_equal_mark,			0x20, // 2B +
	hid_m,			        0x00, // 2C ,
	hid_6,			        0x00, // 2D -
	hid_comma,			    0x20, // 2E .
	hid_full_stop,			0x20, // 2F /
	
	hid_0,					0x20, // 30 0
	hid_1,					0x20, // 31 1
	hid_2,					0x20, // 32 2
	hid_3,					0x20, // 33 3
	hid_4,					0x20, // 34 4
	hid_5,					0x20, // 35 5
	hid_6,					0x20, // 36 6
	hid_7,					0x20, // 37 7
	hid_8,					0x20, // 38 8
	hid_9,					0x20, // 39 9
	
	hid_full_stop,			0x00, // 3A :
	hid_comma,			    0x00, // 3B ;
	hid_k45,			    0x00, // 3C <
	hid_equal_mark,			0x00, // 3D =
	hid_k45,				0x20, // 3E >
	hid_m,			        0x20, // 3F ?
	hid_0,					0x40, // 40 @
	
	hid_q,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_semicolon,			0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_a,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_z,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_y,					0x20, // 59 Y
	hid_w,					0x20, // 5A Z
	
	hid_5,			        0x40, // 5B [
	hid_8,			        0x40, // 5C "\"
	hid_underline,			0x40, // 5D ]
	hid_9,			        0x40, // 5E ^
	hid_8,			        0x00, // 5F _
	hid_7,			        0x40, // 60 `
	
	hid_q,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_semicolon,			0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_a,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_z,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_y,					0x00, // 79 y
	hid_w,					0x00, // 7A z
	
	hid_4,		            0x40, // 7B {
	hid_6,		            0x40, // 7C |
	hid_equal_mark,			0x40, // 7D }
	hid_2,			        0x40, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          GERMANY   ASCII  <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_Germany[] = 
{	
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_2,			        0x20, // 22 "
	hid_k42,				0x00, // 23 #
	hid_4,					0x20, // 24 $
	hid_5,					0x20, // 25 %
	hid_6,					0x20, // 26 &
	hid_k42,		        0x20, // 27 '
	hid_8,					0x20, // 28 (
	hid_9,					0x20, // 29 )
	hid_braces_r,			0x20, // 2A *
	hid_braces_r,			0x00, // 2B +
	hid_comma,			    0x00, // 2C ,
	hid_solidus_r,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_7,					0x20, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_full_stop,			0x20, // 3A :
	hid_comma,			    0x20, // 3B ;
	hid_k45,			    0x00, // 3C <
	hid_0,					0x20, // 3D =
	hid_k45,				0x20, // 3E >
	hid_underline,			0x20, // 3F ?
	hid_q,					0x40, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_z,					0x20, // 59 Y
	hid_y,					0x20, // 5A Z
	
	hid_8,			        0x40, // 5B [
	hid_underline,			0x40, // 5C "\"
	hid_9,			        0x40, // 5D ]
	hid_wave_line,			0x00, // 5E ^
	hid_solidus_r,			0x20, // 5F _
	hid_equal_mark,			0x20, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_z,					0x00, // 79 y
	hid_y,					0x00, // 7A z
	
	hid_7,		            0x40, // 7B {
	hid_k45,		        0x40, // 7C |
	hid_0,			        0x40, // 7D }
	hid_braces_r,			0x40, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          ITALY   ASCII  <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_Italy[] = 
{	
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_2,			        0x20, // 22 "
	hid_quotation_mark,		0x40, // 23 #
	hid_4,					0x20, // 24 $
	hid_5,					0x20, // 25 %
	hid_6,					0x20, // 26 &
	hid_underline,		    0x00, // 27 '
	hid_8,					0x20, // 28 (
	hid_9,					0x20, // 29 )
	hid_braces_r,			0x20, // 2A *
	hid_braces_r,			0x00, // 2B +
	hid_comma,			    0x00, // 2C ,
	hid_solidus_r,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_7,					0x20, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_full_stop,			0x20, // 3A :
	hid_comma,			    0x20, // 3B ;
	hid_k45,			    0x00, // 3C <
	hid_0,					0x20, // 3D =
	hid_k45,				0x20, // 3E >
	hid_underline,			0x20, // 3F ?
	hid_semicolon,			0x40, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_y,					0x20, // 59 Y
	hid_z,					0x20, // 5A Z
	
	hid_braces_l,			0x40, // 5B [
	hid_wave_line,			0x00, // 5C "\"
	hid_braces_r,			0x40, // 5D ]
	hid_equal_mark,			0x20, // 5E ^
	hid_solidus_r,			0x20, // 5F _
	0,			            0x00, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_y,					0x00, // 79 y
	hid_z,					0x00, // 7A z
	
	0,		                0x00, // 7B {
	hid_wave_line,		    0x20, // 7C |
	0,			            0x00, // 7D }
	0,			            0x00, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          UK   ASCII <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_UK[] = 
{   	
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_2,		            0x20, // 22 "
	hid_solidus_l,			0x00, // 23 #
	hid_4,					0x20, // 24 $
	hid_5,					0x20, // 25 %
	hid_7,					0x20, // 26 &
	hid_quotation_mark,		0x00, // 27 '
	hid_9,					0x20, // 28 (
	hid_0,					0x20, // 29 )
	hid_8,					0x20, // 2A *
	hid_equal_mark,			0x20, // 2B +
	hid_comma,				0x00, // 2C ,
	hid_underline,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_solidus_r,			0x00, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_semicolon,			0x20, // 3A :
	hid_semicolon,			0x00, // 3B ;
	hid_comma,				0x20, // 3C <
	hid_equal_mark,			0x00, // 3D =
	hid_full_stop,			0x20, // 3E >
	hid_solidus_r,			0x20, // 3F ?
	hid_quotation_mark,		0x20, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_y,					0x20, // 59 Y
	hid_z,					0x20, // 5A Z
	
	hid_braces_l,			0x00, // 5B [
	hid_k45,			    0x00, // 5C "\"
	hid_braces_r,			0x00, // 5D ]
	hid_6,					0x20, // 5E ^
	hid_underline,			0x20, // 5F _
	hid_wave_line,			0x00, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_y,					0x00, // 79 y
	hid_z,					0x00, // 7A z
	
	hid_braces_l,			0x20, // 7B {
	hid_k45,			    0x20, // 7C |
	hid_braces_r,			0x20, // 7D }
	hid_solidus_l,			0x20, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          CZECH   ASCII  <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_Czech[] = 
{	
   	hid_space,				0x00, // 20 SPACE
   	hid_quotation_mark,		0x20, // 21 !
	hid_semicolon,			0x20, // 22 "
	hid_x,					0x40, // 23 #
	hid_semicolon,			0x40, // 24 $
	hid_underline,			0x20, // 25 %
	hid_c,					0x40, // 26 &
	hid_solidus_l,		    0x20, // 27 '
	hid_braces_r,			0x20, // 28 (
	hid_braces_r,			0x00, // 29 )
	hid_solidus_r,			0x40, // 2A *
	hid_1,					0x00, // 2B +
	hid_comma,			    0x00, // 2C ,
	hid_solidus_r,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_braces_l,			0x20, // 2F /
	
	hid_0,					0x20, // 30 0
	hid_1,					0x20, // 31 1
	hid_2,					0x20, // 32 2
	hid_3,					0x20, // 33 3
	hid_4,					0x20, // 34 4
	hid_5,					0x20, // 35 5
	hid_6,					0x20, // 36 6
	hid_7,					0x20, // 37 7
	hid_8,					0x20, // 38 8
	hid_9,					0x20, // 39 9
	
	hid_full_stop,			0x20, // 3A :
	hid_wave_line,			0x00, // 3B ;
	hid_comma,			    0x40, // 3C <
	hid_underline,			0x00, // 3D =
	hid_full_stop,			0x40, // 3E >
	hid_comma,				0x20, // 3F ?
	hid_v,					0x40, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_z,					0x20, // 59 Y
	hid_y,					0x20, // 5A Z
	
	hid_f,					0x40, // 5B [
	hid_q,					0x40, // 5C "\"
	hid_g,					0x40, // 5D ]
	hid_3,					0x40, // 5E ^
	hid_solidus_r,			0x20, // 5F _
	hid_7,			        0x40, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_z,					0x00, // 79 y
	hid_y,					0x00, // 7A z
	
	hid_b,		            0x40, // 7B {
	hid_w,		    	    0x40, // 7C |
	hid_n,			        0x40, // 7D }
	hid_1,			        0x40, // 7E ~
	hid_del,				0x00, // 7F DEL
};

//---------------------------------------------------
//          JANPAN   ASCII <-> HID   TABLE
//---------------------------------------------------
code CONVERT lang_Japan[] = 
{
   	hid_space,				0x00, // 20 SPACE
   	hid_1,					0x20, // 21 !
	hid_2,					0x20, // 22 "
	hid_3,					0x20, // 23 #
	hid_4,					0x20, // 24 $
	hid_5,					0x20, // 25 %
	hid_6,					0x20, // 26 &
	hid_7,					0x20, // 27 '
	hid_8,					0x20, // 28 (
	hid_9,					0x20, // 29 )
	hid_quotation_mark,		0x20, // 2A *
	hid_semicolon,			0x20, // 2B +
	hid_comma,				0x00, // 2C ,
	hid_underline,			0x00, // 2D -
	hid_full_stop,			0x00, // 2E .
	hid_solidus_r,			0x00, // 2F /
	
	hid_0,					0x00, // 30 0
	hid_1,					0x00, // 31 1
	hid_2,					0x00, // 32 2
	hid_3,					0x00, // 33 3
	hid_4,					0x00, // 34 4
	hid_5,					0x00, // 35 5
	hid_6,					0x00, // 36 6
	hid_7,					0x00, // 37 7
	hid_8,					0x00, // 38 8
	hid_9,					0x00, // 39 9
	
	hid_quotation_mark,		0x00, // 3A :
	hid_semicolon,			0x00, // 3B ;
	hid_comma,				0x20, // 3C <
	hid_underline,			0x20, // 3D =
	hid_full_stop,			0x20, // 3E >
	hid_solidus_r,			0x20, // 3F ?
	hid_braces_l,			0x00, // 40 @
	
	hid_a,					0x20, // 41 A
	hid_b,					0x20, // 42 B
	hid_c,					0x20, // 43 C
	hid_d,					0x20, // 44 D
	hid_e,					0x20, // 45 E
	hid_f,					0x20, // 46 F
	hid_g,					0x20, // 47 G
	hid_h,					0x20, // 48 H
	hid_i,					0x20, // 49 I
	hid_j,					0x20, // 4A J
	hid_k,					0x20, // 4B K
	hid_l,					0x20, // 4C L
	hid_m,					0x20, // 4D M
	hid_n,					0x20, // 4E N
	hid_o,					0x20, // 4F O
	hid_p,					0x20, // 50 P
	hid_q,					0x20, // 51 Q
	hid_r,					0x20, // 52 R
	hid_s,					0x20, // 53 S
	hid_t,					0x20, // 54 T
	hid_u,					0x20, // 55 U
	hid_v,					0x20, // 56 V
	hid_w,					0x20, // 57 W
	hid_x,					0x20, // 58 X
	hid_y,					0x20, // 59 Y
	hid_z,					0x20, // 5A Z
	
	hid_braces_r,			0x00, // 5B [
	0x87,					0x00, // 5C "\"
	hid_solidus_l,			0x00, // 5D ]
	hid_equal_mark,			0x00, // 5E ^
	0x87,					0x20, // 5F _
	hid_braces_l,			0x20, // 60 `
	
	hid_a,					0x00, // 61 a
	hid_b,					0x00, // 62 b
	hid_c,					0x00, // 63 c
	hid_d,					0x00, // 64 d
	hid_e,					0x00, // 65 e
	hid_f,					0x00, // 66 f
	hid_g,					0x00, // 67 g
	hid_h,					0x00, // 68 h
	hid_i,					0x00, // 69 i
	hid_j,					0x00, // 6A j
	hid_k,					0x00, // 6B k
	hid_l,					0x00, // 6C l
	hid_m,					0x00, // 6D m
	hid_n,					0x00, // 6E n
	hid_o,					0x00, // 6F o
	hid_p,					0x00, // 70 p
	hid_q,					0x00, // 71 q
	hid_r,					0x00, // 72 r
	hid_s,					0x00, // 73 s
	hid_t,					0x00, // 74 t
	hid_u,					0x00, // 75 u
	hid_v,					0x00, // 76 v
	hid_w,					0x00, // 77 w
	hid_x,					0x00, // 78 x
	hid_y,					0x00, // 79 y
	hid_z,					0x00, // 7A z
	
	hid_braces_r,			0x20, // 7B {
	0x89,					0x20, // 7C |
	hid_solidus_l,			0x20, // 7D }
	hid_equal_mark,			0x20, // 7E ~
	hid_del,				0x00, // 7F DEL
};

#ifdef __KEIL_C51__
//---------------------------------------------------
//          LANGUAGE   ASCII  <-> HID   TABLE PTR
//---------------------------------------------------
code CONVERT *lang_ptr[] = 
{
    lang_USA,
    lang_TurkeyQ,
    lang_Spain,
    lang_Portugal,
    lang_France,
    lang_Germany,
    lang_Italy,
    lang_UK,
    lang_Czech,
    lang_Japan,
};
#else
void language(UINT8 type, UINT8 index, LANG *lang)
{
    switch(type)
    {
        case 0:
            lang->hid = lang_USA[index].hid;
            lang->func = lang_USA[index].func;
            break;
        case 1:
            lang->hid = lang_TurkeyF[index].hid;
            lang->func = lang_TurkeyF[index].func;
            break;
        case 2:
            lang->hid = lang_Spain[index].hid;
            lang->func = lang_Spain[index].func;
            break;
        case 3:
            lang->hid = lang_Portugal[index].hid;
            lang->func = lang_Portugal[index].func;
            break;
        case 4:
            lang->hid = lang_France[index].hid;
            lang->func = lang_France[index].func;
            break;
        case 5:
            lang->hid = lang_Germany[index].hid;
            lang->func = lang_Germany[index].func;
            break;
        case 6:
            lang->hid = lang_Italy[index].hid;
            lang->func = lang_Italy[index].func;
            break;
        case 7:
            lang->hid = lang_UK[index].hid;
            lang->func = lang_UK[index].func;
        case 8:
            lang->hid = lang_Czech[index].hid;
            lang->func = lang_Czech[index].func;
        case 9:
            lang->hid = lang_Japan[index].hid;
            lang->func = lang_Japan[index].func;
            break;
    }
}
#endif /* __KEIL_C51__ */

