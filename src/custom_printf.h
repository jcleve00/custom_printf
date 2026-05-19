#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int customPrintf(const char *string, ...);
void printChar(char c);
void printInt(int d);
#endif