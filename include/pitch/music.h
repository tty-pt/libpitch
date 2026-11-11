#ifndef PITCH_MUSIC_H
#define PITCH_MUSIC_H

/**
 * @file music.h
 * @brief Key names for the pitch renderer and key dropdown.
 */

const char *pitch_key_name(int semitones, int orig_key, int latin);
const char *key_name(int semitones, int orig_key, int latin);

const char *pitch_target_key_name(int orig_key, int transpose, int latin);
const char *target_key_name(int orig_key, int transpose, int latin);

#endif /* PITCH_MUSIC_H */
