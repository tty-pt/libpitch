#ifndef PITCH_H
#define PITCH_H

#include "pitch_flags.h"
#include "parse.h"
#include "music.h"
#include "spelling.h"
#include <stddef.h>

typedef struct pitch_ctx pitch_ctx_t;
typedef pitch_ctx_t transp_ctx_t;

pitch_ctx_t *pitch_init(void);
transp_ctx_t *transp_init(void);

char *
pitch_buffer(pitch_ctx_t *ctx, const char *input, int semitones, int flags);
char *
transp_buffer(transp_ctx_t *ctx, const char *input, int semitones, int flags);

int pitch_get_key(pitch_ctx_t *ctx);
int transp_get_key(transp_ctx_t *ctx);

void pitch_reset_key(pitch_ctx_t *ctx);
void transp_reset_key(transp_ctx_t *ctx);

char *pitch_shift_table(pitch_ctx_t *ctx, int latin);
char *transp_shift_table(transp_ctx_t *ctx, int latin);

void pitch_free(pitch_ctx_t *ctx);
void transp_free(transp_ctx_t *ctx);

#endif /* PITCH_H */
