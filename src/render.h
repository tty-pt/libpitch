/*
 * render.h - Transform the song model into transposed output
 *
 * Walks the parsed model: transposes roots, emits one <b> per chord line with
 * verbatim spacing (diff absorb/add), manages the spacing queue for lyric
 * lines (space/'-' fillers), verse numbers, HTML escaping, comments,
 * PITCH_BREAK_SLASH, hide flags, empty-line and skip_empty handling. Per-song
 * state is local.
 */

#ifndef PITCH_RENDER_H
#define PITCH_RENDER_H

#include <pitch/parse.h>
#include <pitch/pitch_flags.h>

char *pitch_render(
        const pitch_song_t *song, int semitones, int flags, char **en_table,
        char **latin_table, int *key);

char *transp_render(
        const transp_song_t *song, int semitones, int flags, char **en_table,
        char **latin_table, int *key);

#endif /* PITCH_RENDER_H */
