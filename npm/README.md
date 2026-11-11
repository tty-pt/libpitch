# @tty-pt/pitch

[![npm version](https://img.shields.io/badge/npm-v1.0.0-CB3837?logo=npm)](#)
[![License: BSD-2-Clause](https://img.shields.io/badge/License-BSD--2--Clause-blue)](#)
[![TypeScript Ready](https://img.shields.io/badge/TypeScript-Ready-3178C6?logo=typescript)](#)
[![Node.js Native](https://img.shields.io/badge/Node.js-N--API-339933?logo=node.js)](#)
[![Zero Dependencies](https://img.shields.io/badge/dependencies-0-success)](#)

> Universal Node.js and Browser bindings for **`libpitch`**, the pure-C musical chord transposition and lyrics alignment engine.

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

## License

BSD 2-Clause License. Copyright (c) 2026, tty-pt.
