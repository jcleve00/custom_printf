#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function Prototypes
int customPrintf(const char *string, ...);
int printChar(va_list args);
int printString(va_list args);
int printInt(va_list args);
int printBinary(va_list args);
int printFloat(va_list args);

// Struct definition
typedef struct format_specifier {
	char specifier;
	int (*function)(va_list);
} FormatSpec;

extern FormatSpec specs[];

// Test Function Prototypes
void testChar();
void testString();
void testInt();
void testFloat();
void testBinary();
void testMultipleSpecifiers();
void quit();

// Clear Console prototype
void clearConsole();

#endif