/********************************************/ /**
 * @file f1c100s_adc.c
 * @brief F1C100s ADC module driver
 * @author n.minaylov
 ***********************************************/

#include "f1c100s_adc.h"
#include "io.h"

void adc_init()
{
	/*
	 * Set sample time to 4 ms / 250 Hz. Wait 2 * 4 ms for key to
	 * stabilize on press, wait (1 + 1) * 4 ms for key release
	 */

	write32(F1C100S_ADC_BASE + LRADC_CTRL, FIRST_CONVERT_DLY(2) | LEVELA_B_CNT(1) | HOLD_EN(1) | SAMPLE_RATE(0) | ENABLE(1));
	write32(F1C100S_ADC_BASE + LRADC_INTC, CHAN0_KEYUP_IRQ | CHAN0_KEYDOWN_IRQ);
}

int adc_read()
{
	uint32_t val = read32(F1C100S_ADC_BASE + LRADC_DATA0) & 0x3f;
	int voltage;
	voltage = val * 3000000 / 63;
	return voltage;
}
