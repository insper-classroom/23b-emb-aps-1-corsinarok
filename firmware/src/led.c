/*
 * led.c
 *
 * Created: 12/09/2023 18:06:48
 *  Author: Peng1104
 */
#include <asf.h>

#include "led.h"

/************************************************************************/
/* funcoes                                                              */
/************************************************************************/

void init_led() {
    pmc_enable_periph_clk(LED_PIO_ID);
    pio_configure(LED_PIO, PIO_OUTPUT_0, LED_IDX_MASK, PIO_DEFAULT);
}

void led_on() {
    pio_clear(LED_PIO, LED_IDX_MASK);
}

void led_off() {
    pio_set(LED_PIO, LED_IDX_MASK);
}