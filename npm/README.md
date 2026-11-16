# @tty-pt/pitch

[![npm version](https://img.shields.io/badge/npm-v1.0.1-CB3837?logo=npm)](#)
[![License: BSD-2-Clause](https://img.shields.io/badge/License-BSD--2--Clause-blue)](#)
[![TypeScript Ready](https://img.shields.io/badge/TypeScript-Ready-3178C6?logo=typescript)](#)
[![Node.js Native](https://img.shields.io/badge/Node.js-N--API-339933?logo=node.js)](#)
[![WebAssembly](https://img.shields.io/badge/WebAssembly-Reactor-654FF0?logo=webassembly)](#)
[![Zero Dependencies](https://img.shields.io/badge/dependencies-0-success)](#)

> Universal Node.js and Browser bindings for **`libpitch`**, the pure-C musical chord detection, key analysis, transposition, and lyrics alignment engine.

## Quickstart

```bash
npm install @tty-pt/pitch
```

```typescript
import { pitchText, PITCH_HTML, PITCH_BEMOL } from "@tty-pt/pitch";

const input = "C G Am F\nSinging in the morning sun";
const html = pitchText(input, 2, PITCH_HTML);
console.log(html);
// <div><b>D A Bm G</b></div><div>Singing in the morning sun</div>
```

## API Reference

- `pitchText(input: string, semitones?: number, flags?: number): string`: Transposes and renders a song chord chart by `semitones` using the native C (`pitch_node.node`) or shared-memory WebAssembly (`pitch.wasm` on `@tty-pt/stele`) engine.
- **Formatting Flags**: `PITCH_HIDE_CHORDS (0x01)`, `PITCH_HIDE_LYRICS (0x02)`, `PITCH_HTML (0x04)`, `PITCH_BEMOL (0x08)`, `PITCH_REMOVE_COMMENTS (0x10)`, `PITCH_BREAK_SLASH (0x20)`, `PITCH_SHRINK (0x40)`, `PITCH_LATIN (0x80)`.
- `getPitchWasm(): WebAssembly.Instance`: Returns the `pitch.wasm` instance on the Stele shared-memory substrate.

## C Development Headers via NPM

```makefile
CFLAGS += -I./node_modules/@tty-pt/pitch/include
LDLIBS += -lpitch
```

## License

BSD 2-Clause License. Copyright (c) 2026, tty-pt.
