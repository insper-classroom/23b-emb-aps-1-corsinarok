/*
 * buttons.c
 *
 * Created: 12/09/2023 19:21:48
 *  Author: lucas
 */

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include <asf.h>

#include "buttons.h"

/************************************************************************/
/* variaveis globais                                                    */
/************************************************************************/

volatile char _play_music_status = 1;
volatile char _selection_status = 0;
volatile int _selection_value = 0;

/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

/************************************************************************/
/* callbacks dos botoes                                                 */
/************************************************************************/

void _pause_but_callback(void);
void _selection_but_callback(void);

void init_pause_but(void) {
    pmc_enable_periph_clk(PAUSE_BUT_PIO_ID);

    pio_configure(PAUSE_BUT_PIO, PIO_INPUT, PAUSE_BUT_IDX_MASK, PIO_PULLUP);

    pio_handler_set(PAUSE_BUT_PIO,
                    PAUSE_BUT_PIO_ID,
                    PAUSE_BUT_IDX_MASK,
                    PIO_IT_RISE_EDGE,
                    _pause_but_callback);

    pio_enable_interrupt(PAUSE_BUT_PIO, PAUSE_BUT_IDX_MASK);
    pio_get_interrupt_status(PAUSE_BUT_PIO);

    NVIC_EnableIRQ(PAUSE_BUT_PIO_ID);
    NVIC_SetPriority(PAUSE_BUT_PIO_ID, 5); // Prioridade 5
}

void init_selection_but(void) {
    pmc_enable_periph_clk(SELECTION_BUT_PIO_ID);

    pio_configure(SELECTION_BUT_PIO, PIO_INPUT, SELECTION_BUT_IDX_MASK, PIO_PULLUP);

    pio_handler_set(SELECTION_BUT_PIO,
                    SELECTION_BUT_PIO_ID,
                    SELECTION_BUT_IDX_MASK,
                    PIO_IT_RISE_EDGE,
                    _selection_but_callback);

    pio_enable_interrupt(SELECTION_BUT_PIO, SELECTION_BUT_IDX_MASK);
    pio_get_interrupt_status(SELECTION_BUT_PIO);

    NVIC_EnableIRQ(SELECTION_BUT_PIO_ID);
    NVIC_SetPriority(SELECTION_BUT_PIO_ID, 5); // Prioridade 5
}

void _pause_but_callback(void) {
    _play_music_status = !_play_music_status;
}

void _selection_but_callback(void) {
    _selection_status = 1;
    _selection_value++;

    // Limite e a quantidade de musicas - 1

    if (_selection_value > 2) {
        _selection_value = 0;
    }
}

int play_music(void) {
    return _play_music_status;
}

int get_selecao(void) {
    return _selection_value;
}

int get_selection_status(void) {
    if (_selection_status) {
        _selection_status = 0;
        return 1;
    }
    return 0;
}