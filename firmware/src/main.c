#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

#include "led.h"
#include "buzzer.h"
#include "buttons.h"
#include "music.h"
#include "pitches.h"

/************************************************************************/
/* includes musicas                                                     */
/************************************************************************/

#include "mario.h"
#include "harrypotter.h"
#include "starwars.h"

void init(void);

void init(void) {
	init_led();
	init_buzzer();
	init_pause_but();
	init_selection_but();
	gfx_mono_ssd1306_init();
}

int main(void) {
	board_init();
	sysclk_init();
	delay_init();

	// Disativa WatchDog Timer
	WDT->WDT_MR = WDT_MR_WDDIS;

	// Inicializa os IOs
	init();
	
	// Turn off led on init
	led_off();
	
	gfx_mono_draw_string("teste", 50, 16, &sysfont);

    song *songs[3] = {get_mario_music(), get_harry_potter_music(), get_star_wars_music()};

    /* Insert application code here, after the board has been initialized. */
	while (1) {

		while (!play_music()) {}
		
		song *music = songs[get_selecao()];

        if (music == NULL) {
            return 1; // error music not found
        }
        playSong(music);
	}
}