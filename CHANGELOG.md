# Changelog

All notable changes to `libpitch` (`@tty-pt/pitch`) are documented in this file.

## [1.0.1] - 2026-11-13

### Changed
- Upgraded substrate baseline to @tty-pt/stele@^1.6.0 (>=1.6.0).
- Configured WASM module to import Stele linear memory with non-conflicting global base (`--global-base=4194304`).
- Standardized documentation and README logos.

## [1.0.0] - 2026-11-11

### Added
- Canonical `<ttypt/pitch.h>`, `<pitch/pitch.h>`, `<pitch/parse.h>`, `<pitch/token.h>`, `<pitch/music.h>`, `<pitch/spelling.h>`, and `<pitch/pitch_flags.h>` headers with the `pitch_` API prefix (`pitch_ctx_t`, `pitch_init`, `pitch_free`, `pitch_buffer`, `pitch_get_key`, `pitch_reset_key`, `pitch_shift_table`, `pitch_song_parse`, `pitch_song_free`, `PITCH_*` flags).
- Backward-compatible `<transp/transp.h>` and `transp_*` transition headers/aliases.
- Shared library (`libpitch.so`), static archive (`libpitch.a`), WebAssembly module (`pitch.wasm`), and universal `@tty-pt/pitch` Node.js/Browser package.
- Standard `BSD-2-Clause` license (`Copyright (c) 2026, tty-pt`).
