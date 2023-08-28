#include "asf.h"

#include "gfx_mono_text.h"
#include "gfx_mono_ug_2832hsweg04.h"
#include "sysfont.h"

#define START_BUT_PIO PIOA
#define START_BUT_PIN 0
#define START_BUT_PIN_MASK (1 << START_BUT_PIN)

#define PAUSE_BUT_PIO PIOA
#define PAUSE_BUT_PIN 0
#define PAUSE_BUT_PIN_MASK (1 << PAUSE_BUT_PIN)

#define BUZ_PIN_PIO PIOA
#define BUZ_PIN 0
#define BUZ_PIN_MASK (1 << BUZ_PIN)

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55

typedef struct {
    uint16_t freq;
    uint16_t time;
} note;

int calculateDuration(int passo, note *note) {
    return passo * 60000 / note->time;
}

void playSound(int passo, note *note) {
    int duration = calculateDuration(passo, note) /2;

    pio_set(BUZ_PIN_PIO, BUZ_PIN_MASK);
    delay_us(duration);
    pio_clear(BUZ_PIN_PIO, BUZ_PIN_MASK);
    delay_us(duration);
}

int main(void) {
    board_init();
    sysclk_init();
    delay_init();

    // Init OLED
    gfx_mono_ssd1306_init();

    // Escreve na tela um circulo e um texto
    gfx_mono_draw_filled_circle(20, 16, 16, GFX_PIXEL_SET, GFX_WHOLE);
    gfx_mono_draw_string("mundo", 50, 16, &sysfont);

    /* Insert application code here, after the board has been initialized. */
    while (1) {
        note _do = {16350, 1000000};
    }
}