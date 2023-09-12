/**
 * @file buzzer.h 
 * 
 * @brief Arquivo com as definições dos botoes.
*/

#ifndef BUT_H
#define BUT_H

/**
 * @file buzzer.h
 * 
 * @brief This file contains the button constants.
*/

#define START_BUT_PIO PIOA
#define START_BUT_PIN 0
#define START_BUT_PIN_MASK (1 << START_BUT_PIN)

#define PAUSE_BUT_PIO PIOA
#define PAUSE_BUT_PIN 0
#define PAUSE_BUT_PIN_MASK (1 << PAUSE_BUT_PIN)

#endif