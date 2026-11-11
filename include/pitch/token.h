#ifndef PITCH_TOKEN_H
#define PITCH_TOKEN_H

#include <stddef.h>

typedef enum {
	PITCH_TOK_NOT_CHORD = 0,
	PITCH_TOK_CHORD = 1,
	PITCH_TOK_SPECIAL = 2,
	PITCH_TOK_SEP = 3,
	TRANSP_TOK_NOT_CHORD = PITCH_TOK_NOT_CHORD,
	TRANSP_TOK_CHORD = PITCH_TOK_CHORD,
	TRANSP_TOK_SPECIAL = PITCH_TOK_SPECIAL,
	TRANSP_TOK_SEP = PITCH_TOK_SEP,
} pitch_tok_kind_t;

typedef pitch_tok_kind_t transp_tok_kind_t;

typedef enum {
	PITCH_QUAL_MAJOR = 0,
	PITCH_QUAL_MINOR,
	PITCH_QUAL_DIMINISHED,
	PITCH_QUAL_HALF_DIM,
	PITCH_QUAL_AUGMENTED,
	PITCH_QUAL_SUSPENDED,
	PITCH_QUAL_POWER,
	PITCH_QUAL_UNDEFINED,
	TRANSP_QUAL_MAJOR = PITCH_QUAL_MAJOR,
	TRANSP_QUAL_MINOR = PITCH_QUAL_MINOR,
	TRANSP_QUAL_DIMINISHED = PITCH_QUAL_DIMINISHED,
	TRANSP_QUAL_HALF_DIM = PITCH_QUAL_HALF_DIM,
	TRANSP_QUAL_AUGMENTED = PITCH_QUAL_AUGMENTED,
	TRANSP_QUAL_SUSPENDED = PITCH_QUAL_SUSPENDED,
	TRANSP_QUAL_POWER = PITCH_QUAL_POWER,
	TRANSP_QUAL_UNDEFINED = PITCH_QUAL_UNDEFINED,
} pitch_quality_t;

typedef pitch_quality_t transp_quality_t;

typedef struct {
	pitch_tok_kind_t kind;
	int root;
	size_t root_off;
	size_t root_len;
	size_t mod_off;
	size_t mod_len;
	int bass;
	size_t bass_off;
	size_t bass_len;
	pitch_quality_t quality;
} pitch_token_info_t;

typedef pitch_token_info_t transp_token_info_t;

int pitch_token_analyze(const char *tok, size_t len, pitch_token_info_t *out);
int transp_token_analyze(const char *tok, size_t len, transp_token_info_t *out);

#endif /* PITCH_TOKEN_H */
