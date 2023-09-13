#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

#include "buttons.h"
#include "buzzer.h"
#include "delay.h"
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

song *createSong(char *name, unsigned short pitches[], char beats[], int size, unsigned long duration) {
    if (size <= 0 || duration <= 0) {
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
        notes[i] = createNote(pitches[i], beats[i], duration);

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
    newSong->name = name;
    newSong->size = size;
    newSong->duration = duration;

    return newSong;
}

void tone(note *note_to_play) {
    if (note_to_play->pitch == 0) {
        delay_ms(note_to_play->duration);
        return;
    }
    int pulse = 1000000 / (2 * note_to_play->pitch);
    int repetitions = note_to_play->pitch * note_to_play->duration / 1000;

    for (int i = 0; i < repetitions; i++) {
        set_buzzer();
        delay_us(pulse);
        clear_buzzer();
        delay_us(pulse);
    }
}

void playSong(song *song) {
    // Clear screen
    gfx_mono_draw_filled_rect(0, 0, 128, 32, GFX_PIXEL_CLR);

    // Draw song name
    char str[128];
    sprintf(str, "Tocando: %s", song->name);
    gfx_mono_draw_string(str, 0, 0, &sysfont);

    int update_progress = song->size / 16;

    for (int i = 0; i < song->size; i++) {
        // Pause music
        while (!play_music()) {}

        if (get_selection_status()) {
            // Clear screen
            gfx_mono_draw_filled_rect(0, 0, 128, 32, GFX_PIXEL_CLR);
            return;
        }
        if (i % update_progress == 0) {
            // Update progress bar
            gfx_mono_draw_rect((i / update_progress) * 4, 8, 4, 8, GFX_PIXEL_SET);
        }
        tone(song->notes[i]);
    }
    // Draw full progress bar
    gfx_mono_draw_rect(120, 8, 4, 8, GFX_PIXEL_SET);
}