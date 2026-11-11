<p align="center">
  <img src="assets/logo.png" alt="libpitch logo" width="220" />
</p>

# libpitch

[![npm](https://img.shields.io/badge/npm-@tty--pt/pitch-CB3837?logo=npm)](npm/README.md)
[![C99](https://img.shields.io/badge/C-C99-555?logo=c)](#)
[![BSD-2-Clause](https://img.shields.io/badge/License-BSD--2--Clause-blue)](#)
[![chord-transpose](https://img.shields.io/badge/chord-transpose-C4841A)](#)

> Pure-C musical chord detection, key analysis, and transposition library. Canonical header is `<ttypt/pitch.h>`.

Grammar-based chord detection, key-aware enharmonic spelling, and transpose/render pipeline for song charts in native C (`libpitch.so` / `libpitch.a`) and isomorphic WebAssembly (`pitch.wasm` / `@tty-pt/pitch`).

---

## 1. Quickstart

```c
#include <ttypt/pitch.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    pitch_ctx_t *ctx = pitch_init();
    if (!ctx) return 1;
    const char *input =
        "C       G       Am      F\n"
        "Amazing Grace, how sweet the sound\n";
    char *out = pitch_buffer(ctx, input, 2, PITCH_HTML);
    printf("%s\n", out ? out : "(error)");
    /* <div><b>D A Bm G</b></div><div>Amazing Grace, how sweet the sound</div> */
    free(out);
    pitch_free(ctx);
    return 0;
}
```

### Build & Link
```sh
cc transpose.c $(pkg-config --cflags --libs pitch) -o transpose
```

---

## 2. Features

- **Pure-C & Isomorphic WASM**: Zero external runtime dependencies; compiles to native shared/static libraries and `wasm32` modules.
- **Grammar-based detection**: A token is a chord iff a single left-to-right scan consumes it entirely as `root` + suffix atoms — no character whitelists or external chord databases.
- **Typed song model**: Chord / lyric / comment / empty lines become typed tokens with per-token quality (`pitch_quality_t`) and slash-bass spans.
- **Key-aware transpose + render**: Shifts chord roots by semitones and renders plain text or HTML while preserving column alignment.
- **Preference flags**: Flats vs sharps (`PITCH_BEMOL`), Latin solfege (`PITCH_LATIN`), show/hide sections (`PITCH_HIDE_CHORDS`, `PITCH_HIDE_LYRICS`), comment removal (`PITCH_REMOVE_COMMENTS`).

---

## 3. API Overview

```c
typedef struct pitch_ctx pitch_ctx_t;

pitch_ctx_t *pitch_init(void);                        /* NULL on error */
char *pitch_buffer(pitch_ctx_t *ctx, const char *input,
                   int semitones, int flags);         /* malloc'd; caller frees */
int pitch_get_key(pitch_ctx_t *ctx);                  /* 0-11 chromatic, or -1 */
void pitch_reset_key(pitch_ctx_t *ctx);               /* clears detected key */
char *pitch_shift_table(pitch_ctx_t *ctx, int latin); /* malloc'd; caller frees */
void pitch_free(pitch_ctx_t *ctx);                    /* NULL-safe */

pitch_song_t *pitch_song_parse(const char *input, int *detected_key);
void pitch_song_free(pitch_song_t *s);
```

- Flags (`<pitch/pitch_flags.h>`): `PITCH_HIDE_CHORDS (0x01)`, `PITCH_HIDE_LYRICS (0x02)`, `PITCH_HTML (0x04)`, `PITCH_BEMOL (0x08)`, `PITCH_REMOVE_COMMENTS (0x10)`, `PITCH_BREAK_SLASH (0x20)`, `PITCH_SHRINK (0x40)`, `PITCH_LATIN (0x80)`.

---

## 4. Installation & Build

### Prebuilt Packages
Prebuilt packages for Linux (APT / Alpine / Arch / Fedora-RHEL), macOS (Homebrew), Windows (winget / MSYS2), and OpenBSD are distributed via [tty.pt packages](https://github.com/tty-pt/ci/blob/main/docs/install.md). Use **libpitch** as the package name.

### Build from Source
```sh
make              # builds lib/libpitch.so, lib/libpitch.a, and bin/test_pitch
make wasm         # builds npm/dist/pitch.wasm
make test         # builds + runs the 72-test C suite
make npm-test     # builds + runs the Node/WASM test suite
sudo make install # install headers and library to system
```

---

## 5. JavaScript & WebAssembly Bindings (`@tty-pt/pitch`)

For browser, Node.js, and edge runtimes, `libpitch` ships an isomorphic WebAssembly package on npm:

```sh
npm install @tty-pt/pitch
```

See [npm/README.md](npm/README.md) for the full TypeScript and WebAssembly API reference.

---

## License

BSD 2-Clause License. Copyright (c) 2026, tty-pt. See `LICENSE`.
