/*
 * libpitch.c - Public API for the chord transposition library (libpitch)
 *
 * Thin wrapper over the parse -> render pipeline (token.c / parse.c / render.c).
 * The context holds only the detected key and the active i18n table; there is
 * no corm.
 */

#include <pitch/pitch.h>

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "render.h"

struct pitch_ctx {
	int key;           /* chromatic 0-11, or -1 */
	char **i18n_table; /* chromatic_en or chromatic_latin */
};

/* Chromatic scale tables. Encoding is "sharp\0flat" pairs; chord_str() (in
 * render.c) picks the flat half under a FLAT spell decision (PITCH_BEMOL
 * override or a flat spelling family). */
static char *chromatic_en[] = {
	"C\0", "C#\0Db", "D\0", "D#\0Eb", "E\0", "F\0", "F#\0Gb",
	"G\0", "G#\0Ab", "A\0", "A#\0Bb", "B\0", NULL,
};

static char *chromatic_latin[] = {
	"Do\0",  "Do#\0Reb",  "Re\0", "Re#\0Mib", "Mi\0", "Fa\0", "Fa#\0Solb",
	"Sol\0", "Sol#\0Lab", "La\0", "La#\0Sib", "Si\0", NULL,
};

pitch_ctx_t *pitch_init(void)
{
	pitch_ctx_t *ctx = calloc(1, sizeof(*ctx));
	if (!ctx)
		return NULL;

	setlocale(LC_ALL, "en_US.UTF-8");

	ctx->key = -1;
	ctx->i18n_table = chromatic_en;
	return ctx;
}

transp_ctx_t *transp_init(void)
{
	return pitch_init();
}

void pitch_free(pitch_ctx_t *ctx)
{
	free(ctx);
}

void transp_free(transp_ctx_t *ctx)
{
	pitch_free(ctx);
}

char *
pitch_buffer(pitch_ctx_t *ctx, const char *input, int semitones, int flags)
{
	pitch_song_t song;
	char *input_copy;
	char *result;

	if (!ctx || !input)
		return NULL;

	semitones = ((semitones % 12) + 12) % 12;

	ctx->i18n_table =
	        (flags & PITCH_LATIN) ? chromatic_latin : chromatic_en;

	input_copy = strdup(input);
	if (!input_copy)
		return NULL;

	if (pitch_song_parse(input_copy, &song, &ctx->key) < 0) {
		free(input_copy);
		return NULL;
	}

	result = pitch_render(
	        &song, semitones, flags, chromatic_en, chromatic_latin,
	        &ctx->key);
	pitch_song_free(&song);
	free(input_copy);
	return result;
}

char *
transp_buffer(transp_ctx_t *ctx, const char *input, int semitones, int flags)
{
	return pitch_buffer(ctx, input, semitones, flags);
}

int pitch_get_key(pitch_ctx_t *ctx)
{
	if (!ctx)
		return -1;
	return ctx->key;
}

int transp_get_key(transp_ctx_t *ctx)
{
	return pitch_get_key(ctx);
}

void pitch_reset_key(pitch_ctx_t *ctx)
{
	if (!ctx)
		return;
	ctx->key = -1;
}

void transp_reset_key(transp_ctx_t *ctx)
{
	pitch_reset_key(ctx);
}

char *pitch_shift_table(pitch_ctx_t *ctx, int latin)
{
	if (!ctx || ctx->key == -1)
		return NULL;

	char **table = latin ? chromatic_latin : chromatic_en;
	char *result = malloc(512);
	if (!result)
		return NULL;

	result[0] = '\0';
	for (unsigned i = 0; i < 12; i++) {
		char *name = table[i];
		if (pitch_spelling_family(i) == PITCH_SPELL_FAMILY_FLAT &&
		    strchr(name, '#'))
			name += strlen(name) + 1;
		long t = (long)i - ctx->key;
		if (t < 0)
			t += 12;
		char line[64];
		snprintf(line, sizeof(line), "%s %ld\n", name, t);
		strcat(result, line);
	}

	return result;
}

char *transp_shift_table(transp_ctx_t *ctx, int latin)
{
	return pitch_shift_table(ctx, latin);
}
