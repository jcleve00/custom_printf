#include "custom_printf.h"

void testChar(){
    char test_char = 'A';
    customPrintf("Testing customPrintf with char, %%c: %c\n", test_char);
}

void testString(){
    char test_string = "Hello, World!";
    customPrintf("Testing customPrintf with string, %%s: %c\n", test_string);
}

void testInt(){
    int test_int = 1972;
    customPrintf("Testing customPrintf with int, %%d: %d\n", test_int);
}

void testFloat(){
    float test_float = 3.14159265;
    customPrintf("Testing customPrintf with float, %%f: %f\n", test_float);
}

void testBinary(){
    int test_binary = 12;
    customPrintf("Testing customPrintf with binary, %%b: %f\n", test_binary);
}

void testMultipleSpecifiers(){
    char test_string = "Hello, World!";
    char test_char = 'B';
    int test_int = 1972;

    customPrintf("In %d, %s was used for the first time in documentation for the %c programming language.\n", test_int, test_string, test_char);
}