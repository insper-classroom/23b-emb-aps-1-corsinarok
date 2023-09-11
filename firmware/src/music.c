#include "music.h"
#include "stdlib.h"

note *createNote(unsigned short pitch, unsigned char beats, unsigned long bpm) {
    if (bpm <= 0) {
        // Use serial comunications to print error (invalid parameters)
        return NULL;
    }

    note *newNote = (note *)malloc(sizeof(note));
    if (newNote == NULL) {
        // Use serial comunications to print error (malloc failed)
        return NULL;
    }

    newNote->pitch = pitch;
    newNote->duration = (60000 * 4) / (bpm * beats);

    if (beats < 0) {
        newNote->duration *= -1.5;
    }

    return newNote;
}

song *createSong(unsigned short *pitches, unsigned char *beats, int size, unsigned long tempo) {
    if (size <= 0 || tempo <= 0) {
        // Use serial comunications to print error (invalid parameters)
        return NULL;
    }

    song *newSong = (song *)malloc(sizeof(song));
    if (newSong == NULL) {
        // Use serial comunications to print error (malloc failed)
        return NULL;
    }

    note **notes = (note **)malloc(size * sizeof(note *));

    if (notes == NULL) {
        // Use serial comunications to print error (malloc failed)
        free(newSong);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        notes[i] = createNote(pitches[i], beats[i], tempo);
    }

    for (int i = 0; i < size; i++) {
        notes[i] = createNote(pitches[i], beats[i], tempo);
        // Use serial comunications to print error (malloc failed)
        if (notes[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(notes[j]);
            }
            free(notes);
            free(newSong);
            return NULL;
        }
    }

    newSong->notes = notes;
    newSong->size = size;
    newSong->tempo = tempo;

    return newSong;
}