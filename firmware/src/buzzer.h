/**
 * @file buzzer.h 
 * 
 * @brief Arquivo com as definições e declarações das funções do buzzer.
*/

#ifndef BUZZER_H
#define BUZZER_H

/**
 * @file buzzer.h
 * 
 * @brief This file contains the buzzer constants and functions prototypes.
*/

#define BUZ_PIN_PIO PIOA
#define BUZ_PIN 3
#define BUZ_PIN_MASK (1 << BUZ_PIN)

void set_buzzer();

void clear_buzzer();

#endif