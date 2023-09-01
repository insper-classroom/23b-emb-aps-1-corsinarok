/**
 * @file music.h 
 * 
 * @brief Arquivo com as definições das notas musicais e musicas
 */

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#ifndef MUSIC_H

/************************************************************************/
/* defines                                                              */
/************************************************************************/

#define MUSIC_H

/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

/**
 * @brief Nota musical
 * 
 * @param pitch Frequencia da nota
 * @param duration Duração da nota
 */

typedef struct {
    unsigned short pitch; 
    unsigned long duration;
} note;

typedef struct {
    note **notes;
    int size;
    unsigned long duration;
} song;

note* createNote(unsigned short pitch, unsigned char beat, unsigned long song_duration);

song* createSong(unsigned short *pitches, unsigned char *beats, int size, unsigned long duration);

void tone(note *note, Pio *pio, const uint32_t ul_mask);

#endif