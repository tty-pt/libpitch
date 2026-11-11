#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ttypt/pitch.h>
#include <ttypt/iso.h>

static pitch_ctx_t *s_ctx = NULL;

ISO_EXPORT(char *, pitch_wasm_transpose, const char *input, int semitones, int flags) {
    if (!s_ctx) {
        s_ctx = pitch_init();
    }
    if (!s_ctx || !input) return NULL;
    return pitch_buffer(s_ctx, input, semitones, flags);
}

ISO_EXPORT(int, pitch_wasm_get_key, void) {
    if (!s_ctx) return -1;
    return pitch_get_key(s_ctx);
}

ISO_EXPORT(void, pitch_wasm_reset_key, void) {
    if (s_ctx) pitch_reset_key(s_ctx);
}

ISO_EXPORT(char *, pitch_wasm_shift_table, int latin) {
    if (!s_ctx) s_ctx = pitch_init();
    if (!s_ctx) return NULL;
    return pitch_shift_table(s_ctx, latin);
}

ISO_EXPORT(char *, transp_wasm_transpose, const char *input, int semitones, int flags) {
    return pitch_wasm_transpose(input, semitones, flags);
}

ISO_EXPORT(int, transp_wasm_get_key, void) {
    return pitch_wasm_get_key();
}

ISO_EXPORT(void, transp_wasm_reset_key, void) {
    pitch_wasm_reset_key();
}

ISO_EXPORT(char *, transp_wasm_shift_table, int latin) {
    return pitch_wasm_shift_table(latin);
}
