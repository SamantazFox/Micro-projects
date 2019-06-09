/*
 * asciitables.c
 *
 * A tiny ASCII table generator.
 *
 * Compile with:
 *   $ gcc -std=c11 -o asciitable asciitable.c
 *
 *
 * Copyright 2019 (C) Samantaz Fox
 *
 * This file is in the public domain.
 * Feel free to copy, modify or redistribute it!
 *
*/



#include <stdio.h>


#define SEPARE_TXT "+-----+-----+-----+--------+-------+\n"
#define HEADER_TXT "| Dec | Hex | Oct |  Html  | Char  |\n"

#define DEC_STR	 " %3d "      // Decimal
#define HEX_STR  " %.2Xh "    // Hexadecimal
#define OCT_STR  " %.3o "     // Octal
#define HTM_STR  " &#%.3d; "  // Html
#define CHR_STR  " %-c     "  // Character

#define FULL_STR  "|" DEC_STR "|" HEX_STR "|" OCT_STR "|" HTM_STR "|" CHR_STR "|\n"


#define SPECIAL_CHARS \
	"+-----+-----+-----+-----+----------------------------+\n" \
	"| Dec | Hex | Oct | Chr | Description                |\n" \
	"+-----+-----+-----+-----+----------------------------+\n" \
	"|   0 | 00h | 000 | NUL | Null                       |\n" \
	"|   1 | 01h | 001 | SOH | Start of heading           |\n" \
	"|   2 | 02h | 002 | STX | Start of text              |\n" \
	"|   3 | 03h | 003 | ETX | End of text                |\n" \
	"|   4 | 04h | 004 | EOT | End of transmission        |\n" \
	"|   5 | 05h | 005 | ENQ | Enquiry                    |\n" \
	"|   6 | 06h | 006 | ACK | Acknowledge                |\n" \
	"|   7 | 07h | 007 | BEL | Bell                       |\n" \
	"|   8 | 08h | 010 | BS  | Backspace                  |\n" \
	"|   9 | 09h | 011 | TAB | Horizontal tab             |\n" \
	"|  10 | 0Ah | 012 | LF  | NL line feed, new line     |\n" \
	"|  11 | 0Bh | 013 | VT  | Vertical tab               |\n" \
	"|  12 | 0Ch | 014 | FF  | NP form feed, new page     |\n" \
	"|  13 | 0Dh | 015 | CR  | Carriage return            |\n" \
	"|  14 | 0Eh | 016 | SO  | Shift out                  |\n" \
	"|  15 | 0Fh | 017 | SI  | Shift in                   |\n" \
	"|  16 | 10h | 020 | DLE | Data link escape           |\n" \
	"|  17 | 11h | 021 | DC1 | Device control 1           |\n" \
	"|  18 | 12h | 022 | DC2 | Device control 2           |\n" \
	"|  19 | 13h | 023 | DC3 | Device control 3           |\n" \
	"|  20 | 14h | 024 | DC4 | Device control 4           |\n" \
	"|  21 | 15h | 025 | NAK | Negative acknowledge       |\n" \
	"|  22 | 16h | 026 | SYN | Sychronous idle            |\n" \
	"|  23 | 17h | 027 | ETB | End of transmission block  |\n" \
	"|  24 | 18h | 030 | CAN | Cancel                     |\n" \
	"|  25 | 19h | 031 | EM  | End of Medioum             |\n" \
	"|  26 | 1Ah | 032 | SUB | Substitute                 |\n" \
	"|  27 | 1Bh | 033 | ESC | Escape                     |\n" \
	"|  28 | 1Ch | 034 | FS  | File separator             |\n" \
	"|  29 | 1Dh | 035 | GS  | Group separator            |\n" \
	"|  30 | 1Eh | 036 | RS  | Record separator           |\n" \
	"|  31 | 1Fh | 037 | US  | Unit separator             |\n" \
	"+-----+-----+-----+-----+----------------------------+\n"




void printFormattedRange(FILE* file, int min, int max)
{
	// Header
	fprintf(file, SEPARE_TXT HEADER_TXT SEPARE_TXT);

	for (int i = min; i <= max; i++)
		fprintf(file, FULL_STR, i, i, i, i, i);

	// Footer
	fprintf(file, SEPARE_TXT "\n");
}


int main(int argc, char const *argv[])
{
	FILE* f = fopen(__FILE__ ".txt", "wx");
	if (f == NULL) f = stdout;

	fprintf(f, SPECIAL_CHARS "\n");

	printFormattedRange(f,  32, 127); // Standard ASCII codes
	printFormattedRange(f, 128, 255); // Extended ASCII codes

	if (f != NULL) fclose(f);

	return 0;
}
