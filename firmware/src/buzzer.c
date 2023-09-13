#include <asf.h>

#include "buzzer.h"
#include "led.h"

void init_buzzer(void) {
	pmc_enable_periph_clk(BUZ_PIO_ID);
	pio_configure(BUZ_PIO, PIO_OUTPUT_0, BUZ_PIN_MASK, PIO_DEFAULT);
}

void set_buzzer(void) {
	led_on();
	pio_set(BUZ_PIO, BUZ_PIN_MASK);
}

void clear_buzzer(void) {
	led_off();
	pio_clear(BUZ_PIO, BUZ_PIN_MASK);
}