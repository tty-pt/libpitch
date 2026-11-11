#ifndef PITCH_FLAGS_H
#define PITCH_FLAGS_H

/**
 * @file pitch_flags.h
 * @brief Bitwise transpose output flags for libpitch.
 */

/* Flags (bitwise OR together) */

/** @brief Emit HTML markup (div per line, b per chord line, escaped text). */
#define PITCH_HTML 0x04
/** @brief Spell accidentals as flats (Db instead of C#). */
#define PITCH_BEMOL 0x08
/** @brief Break lyric lines at a '/' followed by a space. */
#define PITCH_BREAK_SLASH 0x20
/** @brief Drop '%' comment lines and skip a following empty line. */
#define PITCH_REMOVE_COMMENTS 0x10
/** @brief Omit chord symbols from the output. */
#define PITCH_HIDE_CHORDS 0x01
/** @brief Omit lyric lines from the output. */
#define PITCH_HIDE_LYRICS 0x02
/** @brief Use Latin solfege root names; minor suffix 'm' renders as '-'. */
#define PITCH_LATIN 0x80

/* Backward-compatible TRANSP_* aliases */
#define TRANSP_HTML            PITCH_HTML
#define TRANSP_BEMOL           PITCH_BEMOL
#define TRANSP_BREAK_SLASH     PITCH_BREAK_SLASH
#define TRANSP_REMOVE_COMMENTS PITCH_REMOVE_COMMENTS
#define TRANSP_HIDE_CHORDS     PITCH_HIDE_CHORDS
#define TRANSP_HIDE_LYRICS     PITCH_HIDE_LYRICS
#define TRANSP_LATIN           PITCH_LATIN

#endif /* PITCH_FLAGS_H */
