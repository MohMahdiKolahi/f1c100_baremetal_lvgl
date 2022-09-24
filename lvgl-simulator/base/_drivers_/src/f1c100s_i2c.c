#include "f1c100s_i2c.h"
#include "io.h"

static inline void sdelay(int loops);

void i2c_init(uint32_t i2c, uint32_t baud)
{

	write32(i2c + I2C_SRST, 1 << 0);
	write32(i2c + I2C_SRST, 0 << 0);
	f1c100s_i2c_set_rate(baud);
	write32(i2c + I2C_ADDR, 0);
	write32(i2c + I2C_XADDR, 0);
	write32(i2c + I2C_CNTR, (1 << 6) | (1 << 4));
}

 int f1c100s_i2c_start()
{
	write32(F1C100S_I2C0_BASE + I2C_CNTR, (1 << 7) | (1 << 6) | (1 << 5) | (1 << 2));

	sdelay(200000);
	(read32(F1C100S_I2C0_BASE + I2C_CNTR) & (1 << 5));
		return f1c100s_i2c_wait_status();
}

 int f1c100s_i2c_stop()
{
	write32(F1C100S_I2C0_BASE + I2C_CNTR, (read32(F1C100S_I2C0_BASE + I2C_CNTR) | (1 << 4)) & ~((1 << 7) | (1 << 3)));
	sdelay(200000);
	if (!(read32(F1C100S_I2C0_BASE + I2C_CNTR) & (1 << 4)))
		return 0;

	return -1;
}

 int f1c100s_i2c_send_data(uint8_t dat)
{
	write32(F1C100S_I2C0_BASE + I2C_DATA, dat);
	write32(F1C100S_I2C0_BASE + I2C_CNTR, read32(F1C100S_I2C0_BASE + I2C_CNTR) & (~(1 << 3)));
	return f1c100s_i2c_wait_status();
}

 int f1c100s_i2c_read(struct i2c_msg_t *msg)
{
	uint8_t *p = msg->buf;
	int len = msg->len;

	if ((f1c100s_i2c_send_data((uint8_t)(msg->addr << 1 | 1)) != I2C_STAT_TX_AR_ACK) && 0)
		return -1;

	while (len > 0)
	{
		int ret = f1c100s_i2c_wait_status();
		switch (ret)
		{
		case I2C_STAT_TX_AR_ACK:
			if (len == 1)
				write32(F1C100S_I2C0_BASE + I2C_CNTR, read32(F1C100S_I2C0_BASE + I2C_CNTR) & ~((1 << 3) | (1 << 2)));
			else
				write32(F1C100S_I2C0_BASE + I2C_CNTR, read32(F1C100S_I2C0_BASE + I2C_CNTR) & ~(1 << 3));
			break;
		case I2C_STAT_RXD_ACK:
			*p++ = read32(F1C100S_I2C0_BASE + I2C_DATA);
			len--;
			if (len == 1)
				write32(F1C100S_I2C0_BASE + I2C_CNTR, read32(F1C100S_I2C0_BASE + I2C_CNTR) & ~((1 << 3) | (1 << 2)));
			else
				write32(F1C100S_I2C0_BASE + I2C_CNTR, read32(F1C100S_I2C0_BASE + I2C_CNTR) & ~(1 << 3));
			break;
		case I2C_STAT_RXD_NAK:
			*p++ = read32(F1C100S_I2C0_BASE + I2C_DATA);
			len--;
			break;
		default:
			return ret;
		}
	}
	return 1;
}

 int f1c100s_i2c_wait_status()
{
	sdelay(200000);
	if ((read32(F1C100S_I2C0_BASE + I2C_CNTR) & (1 << 3)))
		return read32(F1C100S_I2C0_BASE + I2C_STAT);
	else
		return I2C_STAT_BUS_ERROR;
}

 int f1c100s_i2c_write(struct i2c_msg_t *msg)
{
	uint8_t *p = msg->buf;
	int len = msg->len;

	if(f1c100s_i2c_send_data( (uint8_t)(msg->addr << 1)) != I2C_STAT_TX_AW_ACK)
		return -1;
	while(len > 0)
	{
		int ret = f1c100s_i2c_send_data(*p++);
		if(ret != I2C_STAT_TXD_ACK)
			return ret;
		len--;
	}
	return 0;
}

 void f1c100s_i2c_set_rate(uint64_t rate)
{
	//uint64_t pclk = clk_get_rate(pdat->clk);
	uint32_t apb_clock = clk_apb_get_freq();
	int64_t freq, delta, best = 0x7fffffffffffffffLL;
	int tm = 5, tn = 0;
	int m, n;

	for (n = 0; n <= 7; n++)
	{
		for (m = 0; m <= 15; m++)
		{
			freq = apb_clock / (10 * (m + 1) * (1 << n));
			delta = rate - freq;
			if (delta >= 0 && delta < best)
			{
				tm = m;
				tn = n;
				best = delta;
			}
			if (best == 0)
				break;
		}
	}
	write32(F1C100S_I2C0_BASE + I2C_CCR, ((tm & 0xf) << 3) | ((tn & 0x7) << 0));
}

static inline void sdelay(int loops)
{
	__asm__ __volatile__("1:\n"
						 "subs %0, %1, #1\n"
						 "bne 1b"
						 : "=r"(loops)
						 : "0"(loops));
}
