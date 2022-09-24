#ifndef __F1C100S_ADC_H__
#define __F1C100S_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef unsigned long long		virtual_addr_t;

#define F1C100S_ADC_BASE (0x01c23400)


enum {
	LRADC_CTRL	= 0x00,
	LRADC_INTC	= 0x04,
	LRADC_INTS	= 0x08,
	LRADC_DATA0	= 0x0c,
};

/* LRADC_CTRL bits */
#define FIRST_CONVERT_DLY(x)	((x) << 24) /* 8 bits */
#define CHAN_SELECT(x)			((x) << 22) /* 2 bits */
#define CONTINUE_TIME_SEL(x)	((x) << 16) /* 4 bits */
#define KEY_MODE_SEL(x)			((x) << 12) /* 2 bits */
#define LEVELA_B_CNT(x)			((x) << 8)  /* 4 bits */
#define HOLD_EN(x)				((x) << 6)
#define LEVELB_VOL(x)			((x) << 4)  /* 2 bits */
#define SAMPLE_RATE(x)			((x) << 2)  /* 2 bits */
#define ENABLE(x)				((x) << 0)

/* LRADC_INTC and LRADC_INTS bits */
#define CHAN1_KEYUP_IRQ			(1 << 12)
#define CHAN1_ALRDY_HOLD_IRQ	(1 << 11)
#define CHAN1_HOLD_IRQ			(1 << 10)
#define	CHAN1_KEYDOWN_IRQ		(1 << 9)
#define CHAN1_DATA_IRQ			(1 << 8)
#define CHAN0_KEYUP_IRQ			(1 << 4)
#define CHAN0_ALRDY_HOLD_IRQ	(1 << 3)
#define CHAN0_HOLD_IRQ			(1 << 2)
#define	CHAN0_KEYDOWN_IRQ		(1 << 1)
#define CHAN0_DATA_IRQ			(1 << 0)

struct adc_key_t {
	int min;
	int max;
	int keycode;
};

struct key_f1c100s_lradc_pdata_t {
	virtual_addr_t virt;
	int irq;
	int vref;
	struct adc_key_t * keys;
	int nkeys;
	int keycode;
};


void adc_init();
 int adc_read();
//static int key_f1c100s_lradc_get_keycode(struct key_f1c100s_lradc_pdata_t * pdat, int voltage);
//static void key_f1c100s_lradc_interrupt(void * data);
//static int key_f1c100s_lradc_ioctl(struct input_t * input, const char * cmd, void * arg);
//static struct device_t * key_f1c100s_lradc_probe(struct driver_t * drv, struct dtnode_t * n);
//static void key_f1c100s_lradc_remove(struct device_t * dev)


//void adc_init(uint8_t ch, pwm_mode_e mode, uint8_t active_level, pwm_prescaller_e psc);
//
//void pwm_set_period(uint8_t ch, uint16_t val);
//void pwm_set_pulse_len(uint8_t ch, uint16_t val);
//
//void pwm_enable(uint8_t ch);
//void pwm_disable(uint8_t ch);
//
//void pwm_pulse_start(uint8_t ch);








#ifdef __cplusplus
}
#endif

#endif /* __F1C100S_ADC_H__ */
