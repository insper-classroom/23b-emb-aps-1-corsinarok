/*
 * star_wars.c
 *
 * Created: 12/09/2023 23:14:47
 *  Author: vacbo
 */ 
#include "pitches.h"
#include "music.h"
#include "star_wars.h"

song *get_star_wars_music() {
	
	unsigned short star_wars_notes[] = {NOTE_AS4, NOTE_AS4, NOTE_AS4,
    NOTE_F5, NOTE_C6,
    NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,  
    NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,  
    NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_C5,
    NOTE_F5, NOTE_C6,
    NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,  
    
    NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6, //8  
    NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, 
    NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5,NOTE_C5, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
    
    NOTE_C6, NOTE_G5, NOTE_G5, REST, NOTE_C5,//13
    NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C6, NOTE_C6,
    NOTE_F6, NOTE_DS6, NOTE_CS6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5,
    NOTE_C6};

	char star_wars_beats[] = {8, 8, 8, 2, 2, 8, 8, 8, 2, 4, 8, 8, 8, 2, 4, 8, 8, 8, 2, 8, 8, 8, 2, 2, 8, 8, 8, 2, 4, 8, 8, 8, 2, 4, 8, 8, 8, 2, -8, 16, -4, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 4, -8, 16, -4, 8, 8, 8, 8, 8, -8, 16, 2, 8, 8, -4, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 4, -8, 16, 4, 8, 4, 8, 4, 8, 4, 8, 1};

	int size = sizeof(star_wars_notes) / sizeof(star_wars_beats[0]);

	return createSong(NAME, star_wars_notes, star_wars_beats, size, TEMPO);
}