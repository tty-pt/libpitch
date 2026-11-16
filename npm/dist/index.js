import { loadWasmModule, loadNativeAddon, getSubstrate } from "@tty-pt/stele";

const nativeBinding = loadNativeAddon(import.meta.url, "pitch");
let wasmInstance = null;

export function getPitchWasm() {
  if (wasmInstance) return wasmInstance;
  wasmInstance = loadWasmModule(new URL("./pitch.wasm", import.meta.url));
  return wasmInstance;
}

export const getTranspWasm = getPitchWasm;

export const PITCH_HIDE_CHORDS = 0x01;
export const PITCH_HIDE_LYRICS = 0x02;
export const PITCH_HTML = 0x04;
export const PITCH_BEMOL = 0x08;
export const PITCH_REMOVE_COMMENTS = 0x10;
export const PITCH_BREAK_SLASH = 0x20;
export const PITCH_LATIN = 0x80;

export const TRANSP_HIDE_CHORDS = PITCH_HIDE_CHORDS;
export const TRANSP_HIDE_LYRICS = PITCH_HIDE_LYRICS;
export const TRANSP_HTML = PITCH_HTML;
export const TRANSP_BEMOL = PITCH_BEMOL;
export const TRANSP_REMOVE_COMMENTS = PITCH_REMOVE_COMMENTS;
export const TRANSP_BREAK_SLASH = PITCH_BREAK_SLASH;
export const TRANSP_LATIN = PITCH_LATIN;

/**
 * Transpose chord sheet or chord line by semitones (-11 to +11) strictly via WebAssembly
 */
export function transposeText(text, semitones, flags = 0, options = {}) {
  if (!text) return "";
  if (!options.wasm && nativeBinding && nativeBinding.transpose) {
    return nativeBinding.transpose(text, semitones, flags);
  }

  const wasm = getPitchWasm();
  const substrate = getSubstrate();
  return substrate.withString(text, (inPtr) => {
    const outPtr = wasm.exports.pitch_wasm_transpose(inPtr, semitones, flags);
    if (!outPtr) return text;
    const result = substrate.readString(outPtr);
    wasm.exports.free(outPtr);
    return result;
  });
}

/**
 * Returns chromatic index (0-11) of the detected musical key, or -1
 */
export function getDetectedKey() {
  const wasm = getPitchWasm();
  return wasm.exports.pitch_wasm_get_key();
}

/**
 * Clears detected key for subsequent transposition operations
 */
export function resetKey() {
  const wasm = getPitchWasm();
  wasm.exports.pitch_wasm_reset_key();
}

/**
 * Generates transposition shift table across all 12 musical keys
 */
export function getShiftTable(latin = 0) {
  const wasm = getPitchWasm();
  const substrate = getSubstrate();
  const outPtr = wasm.exports.pitch_wasm_shift_table(latin ? 1 : 0);
  if (!outPtr) return "";
  const result = substrate.readString(outPtr);
  wasm.exports.free(outPtr);
  return result;
}
