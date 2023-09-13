/*
 * harry_potter.c
 *
 * Created: 12/09/2023 23:26:38
 *  Author: vacbo
 */ 

#include "pitches.h"
#include "music.h"
#include "harry_potter.h"

song *get_harry_potter_music() {
	
	unsigned short harry_potter_notes[] = {REST, NOTE_D4,
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_D5,
    NOTE_C5, 
    NOTE_A4,
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_F4, NOTE_GS4,
    NOTE_D4, 
    NOTE_D4,

    NOTE_G4, NOTE_AS4, NOTE_A4, //10
    NOTE_G4, NOTE_D5,
    NOTE_F5, NOTE_E5,
    NOTE_DS5, NOTE_B4,
    NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_B4,
    NOTE_G4,
    NOTE_AS4,
        
    NOTE_D5, NOTE_AS4,//18
    NOTE_D5, NOTE_AS4,
    NOTE_DS5, NOTE_D5,
    NOTE_CS5, NOTE_A4,
    NOTE_AS4,  NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_D4,
    NOTE_D5, 
    REST, NOTE_AS4,  

    NOTE_D5, NOTE_AS4,//26
    NOTE_D5, NOTE_AS4,
    NOTE_F5, NOTE_E5,
    NOTE_DS5, NOTE_B4,
    NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_AS4,
    NOTE_G4, 
    };

	char harry_potter_beats[] = {2, 4, -4, 8, 4, 2, 4, -2, -2, -4, 8, 4, 2, 4, -1, 4, -4, 8, 4, 2, 4, 2, 4, 2, 4, -4, 8, 4, 2, 4, -1, 4, 2, 4, 2, 4, 2, 4, 2, 4, -4, 8, 4, 2, 4, -1, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4, -4, 8, 4, 2, 4, -1};

	int size = sizeof(harry_potter_notes) / sizeof(harry_potter_beats[0]);

	return createSong(NAME, harry_potter_notes, harry_potter_beats, size, TEMPO);
}
