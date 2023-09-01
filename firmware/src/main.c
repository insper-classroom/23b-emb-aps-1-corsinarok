#include <asf.h>

#include "gfx_mono_text.h"
#include "gfx_mono_ug_2832hsweg04.h"
#include "sysfont.h"

#include "music.h"
#include "pitches.h"

#define START_BUT_PIO PIOA
#define START_BUT_PIN 0
#define START_BUT_PIN_MASK (1 << START_BUT_PIN)

#define PAUSE_BUT_PIO PIOA
#define PAUSE_BUT_PIN 0
#define PAUSE_BUT_PIN_MASK (1 << PAUSE_BUT_PIN)

#define BUZ_PIN_PIO PIOA
#define BUZ_PIN 3
#define BUZ_PIN_MASK (1 << BUZ_PIN)

#define TIME 200

void tone(note *note, Pio *pio, const uint32_t ul_mask) {
    int period = 1000000 / note->pitch;
    int pulse = period / 2;

    for (int i = 0; i < note->duration; i++) {
        pio_set(pio, ul_mask);
        delay_us(pulse);
        pio_clear(pio, ul_mask);
        delay_us(pulse);
    }
}

int main(void) {
    board_init();
    sysclk_init();
    delay_init();

    // Disativa WatchDog Timer
    WDT->WDT_MR = WDT_MR_WDDIS;

    // Habilida clock do periferico PIO
    pmc_enable_periph_clk(BUZ_PIN_PIO);

    // Inicializa Buzzer como saida
    pio_set_output(BUZ_PIN_PIO, BUZ_PIN_MASK, 0, 0, 0);

    // Init OLED
    gfx_mono_ssd1306_init();

    gfx_mono_draw_filled_circle(20, 16, 16, GFX_PIXEL_SET, GFX_WHOLE);
    gfx_mono_draw_string("mundo", 50, 16, &sysfont);

    /* Insert application code here, after the board has been initialized. */
    while (1) {

        int marioNotes[] = {NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5, NOTE_G5, REST, NOTE_G4, REST, NOTE_C5, NOTE_G4, REST, NOTE_E4, REST, NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4};
        int marioBeats[] = {8, 8, 8, 8, 8, 8, 8, 4, 4, 8, 4, -4, 8, 4, -4, 4, 4, 8, 4};

        song *mario = createSong(marioNotes, marioBeats, 19, TIME);

        for (int i = 0; i < mario->size; i++) {
            playNextNote(mario->notes[i], BUZ_PIN_PIO, BUZ_PIN_MASK);
        }
    }
}