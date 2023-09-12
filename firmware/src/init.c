#include "buzzer.h"
#include "pio.h"
#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

void ioinit() {
    // Habilida clock do periferico PIO
    pmc_enable_periph_clk(BUZ_PIN_PIO);

    // Inicializa Buzzer como saida
    pio_set_output(BUZ_PIN_PIO, BUZ_PIN_MASK, 0, 0, 0);

    // Init OLED
    gfx_mono_ssd1306_init();
    gfx_mono_draw_string("teste", 50, 16, &sysfont);
}