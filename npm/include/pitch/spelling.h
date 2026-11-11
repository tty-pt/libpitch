#ifndef PITCH_SPELLING_H
#define PITCH_SPELLING_H

/**
 * @file spelling.h
 * @brief Spelling-family decisions shared by the renderer and key dropdown.
 *
 * Single source of truth for the circle-of-fifths family rule.
 */

enum {
	/** Key spelled with sharps. */
	PITCH_SPELL_FAMILY_SHARP = 0,
	/** Key spelled with flats. */
	PITCH_SPELL_FAMILY_FLAT = 1,
	SPELL_FAMILY_SHARP = PITCH_SPELL_FAMILY_SHARP,
	SPELL_FAMILY_FLAT = PITCH_SPELL_FAMILY_FLAT,
};

enum {
	/** Spell chord names with sharps. */
	PITCH_SPELL_SHARP = 0,
	/** Spell chord names with flats. */
	PITCH_SPELL_FLAT = 1,
	SPELL_SHARP = PITCH_SPELL_SHARP,
	SPELL_FLAT = PITCH_SPELL_FLAT,
};

static inline int pitch_spelling_family(int chrom)
{
	static const int table[12] = {
		PITCH_SPELL_FAMILY_SHARP, /* 0  C  */
		PITCH_SPELL_FAMILY_FLAT,  /* 1  Db */
		PITCH_SPELL_FAMILY_SHARP, /* 2  D  */
		PITCH_SPELL_FAMILY_FLAT,  /* 3  Eb */
		PITCH_SPELL_FAMILY_SHARP, /* 4  E  */
		PITCH_SPELL_FAMILY_FLAT,  /* 5  F  */
		PITCH_SPELL_FAMILY_SHARP, /* 6  F# */
		PITCH_SPELL_FAMILY_SHARP, /* 7  G  */
		PITCH_SPELL_FAMILY_FLAT,  /* 8  Ab */
		PITCH_SPELL_FAMILY_SHARP, /* 9  A  */
		PITCH_SPELL_FAMILY_FLAT,  /* 10 Bb */
		PITCH_SPELL_FAMILY_SHARP, /* 11 B  */
	};
	if (chrom >= 0 && chrom < 12)
		return table[chrom];
	return PITCH_SPELL_FAMILY_SHARP;
}

static inline int spelling_family(int chrom)
{
	return pitch_spelling_family(chrom);
}

#endif /* PITCH_SPELLING_H */
