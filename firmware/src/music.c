#include "music.h"

note *createNote(unsigned short pitch, unsigned char beats, unsigned long song_duration) {
    note *note = malloc(sizeof(note));

    note->pitch = pitch;
    note->duration = 60000 * beats / song_duration;

    if (beats < 0) {
        note->duration *= -1.5;
    }
    return note;
}

song *createSong(unsigned short *pitches, unsigned char *beats, const int size, unsigned long duration) {
    song *song = malloc(sizeof(song));

    note **notes = malloc(size * sizeof(note*)); 

    for (int i = 0; i < size; i++) {
        notes[i] = createNote(pitches[i], beats[i], duration);
    }
    song->notes = notes;
    song->size = size;
    song->duration = duration;

    return song;
}