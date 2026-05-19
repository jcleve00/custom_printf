#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Struct definition
typedef struct format_specifier {
	char specifier;
	int (*function)(va_list);
} FormatSpec;

	FormatSpec specs[] = {
		{'c', printChar},
		{'s', printString},
		{'d', printInt},
		{'i', printInt},
		{'b', printBinary},
		{'\0', NULL}
	};
    
// Function Prototypes
int customPrintf(const char *string, ...);
int printChar(va_list args);
int printString(va_list args);
int printInt(va_list args);
int printBinary(va_list args);

#endif