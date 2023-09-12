#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

#include "but.h"
#include "buzzer.h"
#include "music.h"
#include "pio.h"
#include "pitches.h"
#include "init.h"

#define TEMPO 200

int main(void) {
    board_init();
    sysclk_init();
    delay_init();

    // Disativa WatchDog Timer
    WDT->WDT_MR = WDT_MR_WDDIS;

    // Inicializa IO
    ioinit();

    /* Insert application code here, after the board has been initialized. */
    while (1) {

        unsigned short marioNotes[] = {NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5, NOTE_G5, REST, NOTE_G4, REST, NOTE_C5, NOTE_G4, REST, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4};
        char marioBeats[] = {8, 8, 8, 8, 8, 8, 8, 4, 4, 8, 4, -4, 8, 4, -4, 4, 4, 8, 4};

        song *mario = createSong(marioNotes, marioBeats, 19, TEMPO);

        if (mario == NULL) {
            return 1;
        }
        for (int i = 0; i < mario->size; i++) {
            tone(mario->notes[i]);
        }
    }
}