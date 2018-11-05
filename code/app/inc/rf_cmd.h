
#ifndef __RF_CMD__
#define __RF_CMD__

#define HEAD_LEN	4
#define CMD_NO		4

#define LEN1		8
#define LEN2		5
#define LEN3		10
#define LEN4		11
#define LEN5		12

#define CMD_LEN1	LEN1+HEAD_LEN
#define CMD_LEN2	LEN2+HEAD_LEN
#define CMD_LEN3	LEN3+HEAD_LEN
#define CMD_LEN4	LEN4+HEAD_LEN
#define CMD_LEN5	LEN5+HEAD_LEN

#define SET_BUF		3
typedef struct
{
	UINT8 ch;			// set ch
	UINT8 id;			// set id
	UINT8 host  : 1;	// host set
	UINT8 slave : 1;	// slave set
	UINT8 type  : 2;	// set type
	UINT8 len   : 3;	// data len
	UINT8 dat[SET_BUF];	// data buffer
}MENU_SET;

typedef enum
{
	SET_NONE = 0,
	SET_CH,
	SET_ID,
	SET_BUZZ,
	//SET_RX_ID,
}SET_TYPE;


BOOL rf_host_cmd(UINT8 *cmd_dat);
BOOL rf_slave_cmd(UINT8 *cmd_dat);


#endif /* end of __RF_CMD__ */

