/**
 * @file buzzer.h 
 * 
 * @brief Arquivo com as definições e declarações da musica do Super Mario Bros theme by Koji Kondo
*/

#include "pitches.h"
#include "music.h"

#ifndef MARIO_H
#define MARIO_H

#define TEMPO 200
#define NAME "Mario Theme"

song* get_mario_music(void);

#endif