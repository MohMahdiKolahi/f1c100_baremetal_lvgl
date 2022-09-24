#ifndef __F1C100S_I2C_H__
#define __F1C100S_I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


typedef unsigned long long		virtual_addr_t;

#define F1C100S_I2C0_BASE (0x01C27000)

#define I2C0 F1C100S_I2C0_BASE

struct i2c_msg_t {
	int addr;
	int flags;
	int len;
	void * buf;
};



enum {
	I2C_ADDR			= 0x000,
	I2C_XADDR			= 0x004,
	I2C_DATA 			= 0x008,
	I2C_CNTR			= 0x00c,
	I2C_STAT			= 0x010,
	I2C_CCR				= 0x014,
	I2C_SRST			= 0x018,
	I2C_EFR				= 0x01c,
	I2C_LCR				= 0x020,
};

enum {
	I2C_STAT_BUS_ERROR	= 0x00,
	I2C_STAT_TX_START	= 0x08,
	I2C_STAT_TX_RSTART	= 0x10,
	I2C_STAT_TX_AW_ACK	= 0x18,
	I2C_STAT_TX_AW_NAK	= 0x20,
	I2C_STAT_TXD_ACK	= 0x28,
	I2C_STAT_TXD_NAK	= 0x30,
	I2C_STAT_LOST_ARB	= 0x38,
	I2C_STAT_TX_AR_ACK	= 0x40,
	I2C_STAT_TX_AR_NAK	= 0x48,
	I2C_STAT_RXD_ACK	= 0x50,
	I2C_STAT_RXD_NAK	= 0x58,
	I2C_STAT_IDLE		= 0xf8,
};


void i2c_init(uint32_t i2c, uint32_t baud);
 int f1c100s_i2c_start();
 int f1c100s_i2c_stop();
 int f1c100s_i2c_send_data( uint8_t dat);
 int f1c100s_i2c_read( struct i2c_msg_t *msg);
 int f1c100s_i2c_wait_status();
 int f1c100s_i2c_write( struct i2c_msg_t * msg);
 void f1c100s_i2c_set_rate(uint64_t rate);




#ifdef __cplusplus
}
#endif

#endif /* __F1C100S_I2C_H__ */
