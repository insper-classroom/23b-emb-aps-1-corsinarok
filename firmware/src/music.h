/**
 * @file music.h 
 * 
 * @brief Arquivo com as definições das notas musicais e musicas
*/

#ifndef MUSIC_H
#define MUSIC_H

/**
 * @brief Nota musical
 * 
 * @param pitch Frequencia da nota
 * @param duration Duração da nota
*/

typedef struct {
    unsigned short pitch; 
    long duration;
} note;

typedef struct {
    note **notes;
    char *name;
    int size;
    unsigned long duration;
} song;

note* createNote(unsigned short pitch, char beat, unsigned long song_duration);

song* createSong(unsigned short pitches[], char beats[], int size, unsigned long duration);

void tone(note *note);

#endif