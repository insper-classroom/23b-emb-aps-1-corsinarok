#include "music.h"

note *createNote(unsigned short pitch, unsigned char beats, unsigned long bpm) {
    note *note = malloc(sizeof(note));

    note->pitch = pitch;
    note->duration = 60000 * beats / bpm;

    if (beats < 0) {
        note->duration *= -1.5;
    }
    return note;
}

song *createSong(unsigned short *pitches, unsigned char *beats, const int size, unsigned long tempo) {
    song *song = malloc(sizeof(song));

    note **notes = malloc(size * sizeof(note*)); 

    for (int i = 0; i < size; i++) {
        notes[i] = createNote(pitches[i], beats[i], tempo);
    }
    song->notes = notes;
    song->size = size;
    song->tempo = tempo;

    return song;
}