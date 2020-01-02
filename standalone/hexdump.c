/*
 * hexdump.c
 *
 * Prints, as text, the content of a binary file to stdout,
 * in both HEX and ASCII forms.
 *
 * Compile with:
 *   $ gcc -Ofast -o hexdump[.exe] hexdump.c
 *
 *
 * Copyright 2019-2020 (C) Samantaz Fox
 *
 * This file is in the public domain.
 * Feel free to copy, modify or redistribute it!
 *
*/


#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <time.h>


# define MAX_BUFFER_SIZE (1024 * 1024 * 32)  // 32 MiB


static void row2hex(char* data, size_t len)
{
  /* String length:   1    2    3    4    5    6    7    8 */
	char string_1[] = "   ""   ""   ""   ""   ""   ""   ""   ";
	char string_2[] = "   ""   ""   ""   ""   ""   ""   ""   ";

	#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
	switch(len)
	{
		/* High 8 bytes */
		case 16: snprintf(string_2 + 21, 3, "%.2X", (char) data[15] ); string_2[23] = ' ';
		case 15: snprintf(string_2 + 18, 3, "%.2X", (char) data[14] ); string_2[20] = ' ';
		case 14: snprintf(string_2 + 15, 3, "%.2X", (char) data[13] ); string_2[17] = ' ';
		case 13: snprintf(string_2 + 12, 3, "%.2X", (char) data[12] ); string_2[14] = ' ';
		case 12: snprintf(string_2 +  9, 3, "%.2X", (char) data[11] ); string_2[11] = ' ';
		case 11: snprintf(string_2 +  6, 3, "%.2X", (char) data[10] ); string_2[ 8] = ' ';
		case 10: snprintf(string_2 +  3, 3, "%.2X", (char) data[ 9] ); string_2[ 5] = ' ';
		case  9: snprintf(string_2 +  0, 3, "%.2X", (char) data[ 8] ); string_2[ 2] = ' ';
		/* Low 8 bytes */
		case  8: snprintf(string_1 + 21, 3, "%.2X", (char) data[ 7] ); string_1[23] = ' ';
		case  7: snprintf(string_1 + 18, 3, "%.2X", (char) data[ 6] ); string_1[20] = ' ';
		case  6: snprintf(string_1 + 15, 3, "%.2X", (char) data[ 5] ); string_1[17] = ' ';
		case  5: snprintf(string_1 + 12, 3, "%.2X", (char) data[ 4] ); string_1[14] = ' ';
		case  4: snprintf(string_1 +  9, 3, "%.2X", (char) data[ 3] ); string_1[11] = ' ';
		case  3: snprintf(string_1 +  6, 3, "%.2X", (char) data[ 2] ); string_1[ 8] = ' ';
		case  2: snprintf(string_1 +  3, 3, "%.2X", (char) data[ 1] ); string_1[ 5] = ' ';
		case  1: snprintf(string_1 +  0, 3, "%.2X", (char) data[ 0] ); string_1[ 2] = ' ';
	}

	printf("[ %s %s] ", string_1, string_2 );
}

static void row2ascii(char* data, size_t len)
{
	#define bin2ascii(b)  ( (char) ((b) >= 32 && (b) <= 126) ? (b) : '.' )

	char str[17] ="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
	switch(len)
	{
		/* High 8 bytes */
		case 16: str[15] = bin2ascii(data[15]);
		case 15: str[14] = bin2ascii(data[14]);
		case 14: str[13] = bin2ascii(data[13]);
		case 13: str[12] = bin2ascii(data[12]);
		case 12: str[11] = bin2ascii(data[11]);
		case 11: str[10] = bin2ascii(data[10]);
		case 10: str[ 9] = bin2ascii(data[ 9]);
		case  9: str[ 8] = bin2ascii(data[ 8]);
		/* Low 8 bytes */
		case  8: str[ 7] = bin2ascii(data[ 7]);
		case  7: str[ 6] = bin2ascii(data[ 6]);
		case  6: str[ 5] = bin2ascii(data[ 5]);
		case  5: str[ 4] = bin2ascii(data[ 4]);
		case  4: str[ 3] = bin2ascii(data[ 3]);
		case  3: str[ 2] = bin2ascii(data[ 2]);
		case  2: str[ 1] = bin2ascii(data[ 1]);
		case  1: str[ 0] = bin2ascii(data[ 0]);
	}

	printf("%s\n", str);
}

/**
* Application for printing file to console as hexadecimal.
*/

static void printUsage(void)
{
	printf("usage: hexdump.exe <filename>\n");
}


void dump(char* buffer, long unsigned int size)
{
	for (long unsigned int done = 0; done <= size; done += 16)
	{
		char* data_current = (char*) (buffer + done);
		long int todo = (size - done);

		if (todo <= 0) { printf("\n"); return; }
		int line = (todo > 16) ? 16 : (todo);

		// Print address + data as HEX + data as ASCII
		printf("\t\t0x%.8lx: ", done);
		row2hex  (data_current, line);
		row2ascii(data_current, line);
	}
}


int main(int argc, char* argv[])
{
	if (argc != 2) { printUsage(); return 0; }

	// Open file as a binary stream
	const char* filename = argv[1];
	FILE* fd = fopen(filename, "rb");
	if (fd == NULL)
	{
		fprintf(stderr, "Can't open file '%s'\n", filename);
		return 1;
	}


	// Allocate a buffer (see #define above for size)
	uint8_t* buffer = calloc(MAX_BUFFER_SIZE, 1);
	if (buffer == NULL)
	{
		fprintf(stderr, "Failed to allocate buffer\n");
		return 1;
	}


	// Copy file's data to buffer.
	size_t filesize = fread(buffer, 1, MAX_BUFFER_SIZE, fd);
	if (!filesize)
	{
		fprintf(stderr, "Error: File is too large\n");
		free(buffer);
		return 1;
	}
	fclose(fd);


	// Generate dump
	dump(buffer, filesize);

	fprintf(stderr, "\nDump Done\n");
	fprintf(stderr,
		"Parsed %ld bytes in %ld ms\n",
		filesize, (clock() / (CLOCKS_PER_SEC/1000))
	);


	free(buffer);
	return 0;
}
