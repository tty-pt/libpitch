# Changelog

All notable changes to `libpitch` (`@tty-pt/pitch`) are documented in this file.

## [1.0.1] - 2026-11-16

### Added
- Added `.github/workflows/ci.yml` publishing `libpitch` across all 7 OS package formats (`deb,apk,rpm,pacman,brew,openbsd,winget`) and `@tty-pt/pitch` to npm with `linux-x64`, `darwin-arm64`, `darwin-x64`, `win32-x64` N-API prebuilds and `pitch.wasm`.

### Changed
- Routed all `pitch.wasm` heap allocations through `@tty-pt/stele` (`>=1.7.0` / `^1.7.0`) via `--wrap=malloc/free/calloc/realloc` and non-conflicting `--global-base=1245184`.
- Made `Makefile` library symlink (`SONAME-libpitch := libtransp`) portable across Unix `.so`/`.dylib` and Windows `.dll`.
- Standardized documentation and README logos.

## [1.0.0] - 2026-11-11

### Added
- Canonical `<ttypt/pitch.h>`, `<pitch/pitch.h>`, `<pitch/parse.h>`, `<pitch/token.h>`, `<pitch/music.h>`, `<pitch/spelling.h>`, and `<pitch/pitch_flags.h>` headers with the `pitch_` API prefix (`pitch_ctx_t`, `pitch_init`, `pitch_free`, `pitch_buffer`, `pitch_get_key`, `pitch_reset_key`, `pitch_shift_table`, `pitch_song_parse`, `pitch_song_free`, `PITCH_*` flags).
- Backward-compatible `<transp/transp.h>` and `transp_*` transition headers/aliases.
- Shared library (`libpitch.so`), static archive (`libpitch.a`), WebAssembly module (`pitch.wasm`), and universal `@tty-pt/pitch` Node.js/Browser package.
- Standard `BSD-2-Clause` license (`Copyright (c) 2026, tty-pt`).
