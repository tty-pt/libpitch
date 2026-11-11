#ifndef PITCH_PARSE_H
#define PITCH_PARSE_H

#include "token.h"
#include <stddef.h>

typedef struct {
	const char *text;
	size_t len;
	size_t lead;
	pitch_token_info_t info;
} pitch_ptoken_t;

typedef pitch_ptoken_t transp_ptoken_t;

typedef struct {
	int is_chord_line;
	int is_comment;
	int is_empty;
	int has_verse;
	size_t verse_len;
	const char *text;
	size_t len;
	pitch_ptoken_t *toks;
	size_t ntok;
} pitch_pline_t;

typedef pitch_pline_t transp_pline_t;

typedef struct {
	pitch_pline_t *lines;
	size_t nlines;
} pitch_song_t;

typedef pitch_song_t transp_song_t;

int pitch_song_parse(const char *input, pitch_song_t *song, int *key);
int transp_song_parse(const char *input, transp_song_t *song, int *key);

void pitch_song_free(pitch_song_t *song);
void transp_song_free(transp_song_t *song);

#endif /* PITCH_PARSE_H */
