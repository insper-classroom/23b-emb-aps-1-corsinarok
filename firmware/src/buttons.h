/**
 * @file buttons.h 
 * 
 * @brief Arquivo com as definições dos botoes.
*/

#ifndef BUTTONS_H

/************************************************************************/
/* defines                                                              */
/************************************************************************/

#define BUTTONS_H

/************************************************************************/
/* pause button                                                         */
/************************************************************************/

#define PAUSE_BUT_PIO          PIOA                     // Periferico que controla o botao de pausar/retomar a musica
#define PAUSE_BUT_PIO_ID       ID_PIOA                  // ID do periférico do botao de pausar/retomar a musica
#define PAUSE_BUT_IDX          19                       // NO EXT = 4
#define PAUSE_BUT_IDX_MASK     (1u << PAUSE_BUT_IDX)    // Mascara para CONTROLARMOS o botao de pausar/retomar a musica

/************************************************************************/
/* SELECTION button                                                         */
/************************************************************************/

#define SELECTION_BUT_PIO       PIOD                     // Periferico que controla o botao de selecionar a musica
#define SELECTION_BUT_PIO_ID    ID_PIOD                  // ID do periférico do botao de selecionar a musica
#define SELECTION_BUT_IDX       28                       // NO EXT = 9
#define SELECTION_BUT_IDX_MASK (1u << SELECTION_BUT_IDX) // Mascara para CONTROLARMOS o botao de selecionar a musica

/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

/************************************************************************/
/* funcoes para configurar os botoes                                    */
/************************************************************************/

void init_pause_but(void);
void init_selection_but(void);

/************************************************************************/
/* getters                                                              */
/************************************************************************/

int play_music(void);
int get_selecao(void);

#endif