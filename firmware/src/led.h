/**
 * @file led.h
 *
 * @brief Arquivo com as definições e declarações das funções para o controle do LED.
 */

#include <asf.h>

#ifndef LED_H
#define LED_H

/************************************************************************/
/* defines                                                              */
/************************************************************************/

// Configuracoes do LED
#define LED_PIO       PIOC            // periferico que controla o LED
#define LED_PIO_ID    ID_PIOC         // ID do periférico que controla o LED
#define LED_IDX       30              // NO EXT1 = 8
#define LED_IDX_MASK  (1 << LED_IDX)  // Mascara para CONTROLARMOS o LED

/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

void init_led(void);
void led_on(void);
void led_off(void);

#endif