#include "music.h"
#include "stdlib.h"

note *createNote(unsigned short pitch, char beats, unsigned long bpm) {
    if (bpm <= 0) {
        // Use serial comunications to print error (invalid parameters)
        return NULL;
    }
    note *newNote = malloc(sizeof(note));

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

song *createSong(unsigned short pitches[], char beats[], int size, unsigned long tempo) {
    if (size <= 0 || tempo <= 0) {
        // Use serial comunications to print error (invalid parameters)
        return NULL;
    }
    song *newSong = malloc(sizeof(song));
    
    if (newSong == NULL) {
        // Use serial comunications to print error (malloc failed)
        return NULL;
    }
    note **notes = malloc(size * sizeof(note *));

    if (notes == NULL) {
        // Use serial comunications to print error (malloc failed)
        free(newSong);
        return NULL;
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

void tone(note *note) {
    if (note->pitch == 0) {
        delay_ms(note->duration);
        return;
    }
    int period = 1000000 / note->pitch;
    int pulse = period / 2;
    int repetitions = note->pitch * note->duration / 1000;

    for (int i = 0; i < repetitions; i++) {
        set_buzzer();
        delay_us(pulse);
        clear_buzzer();
        delay_us(pulse);
    }
}