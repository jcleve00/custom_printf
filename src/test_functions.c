#include "custom_printf.h"

void testChar(){
    char test_char = 'A';
    int chars_printed = customPrintf("Testing customPrintf with char, %%c: %c\n", test_char);
    if (chars_printed == 32){
        customPrintf("Success! Chars printed: %d\n", chars_printed);
    }
    else{
        customPrintf("Failed! Chars printed: %d\n", chars_printed);
    }
    customPrintf("Press enter to continue...\n");
    getchar();
}

void testString(){
    char *test_string = "Hello, World!";
    int chars_printed = customPrintf("Testing customPrintf with string, %%s: %s\n", test_string);
    if (chars_printed == 45){
        customPrintf("Success! Chars printed: %d\n", chars_printed);
    }
    else{
        customPrintf("Failed! Chars printed: %d\n", chars_printed);
    }
    customPrintf("Press enter to continue...\n");
    getchar();
}

void testInt(){
    int test_int = 1972;
    int chars_printed = customPrintf("Testing customPrintf with int, %%d: %d\n", test_int);
    if (chars_printed == 34){
        customPrintf("Success! Chars printed: %d\n", chars_printed);
    }
    else{
        customPrintf("Failed! Chars printed: %d\n", chars_printed);
    }
    customPrintf("Press enter to continue...\n");
    getchar();
}

void testFloat(){
    float test_float = 3.14159265;
    int chars_printed = customPrintf("Testing customPrintf with float, %%f: %f\n", test_float);
    if (chars_printed == 42){
        customPrintf("Success! Chars printed: %d\n", chars_printed);
    }
    else{
        customPrintf("Failed! Chars printed: %d\n", chars_printed);
    }
    customPrintf("Press enter to continue...\n");
    getchar();
}

void testBinary(){
    int test_binary = 12;
    int chars_printed = customPrintf("Testing customPrintf with binary, %%b: %b\n", test_binary);
    if (chars_printed == 37){
        customPrintf("Success! Chars printed: %d\n", chars_printed);
    }
    else{
        customPrintf("Failed! Chars printed: %d\n", chars_printed);
    }
    customPrintf("Press enter to continue...\n");
    getchar();
}

void testMultipleSpecifiers(){
    char *test_string = "Hello, World!";
    char test_char = 'B';
    int test_int = 1972;
    int chars_printed = customPrintf("In %d, %s was used for the first time in documentation for the %c programming language.\n", test_int, test_string, test_char);
    if (chars_printed == 82){
        customPrintf("Success! Chars printed: %d\n", chars_printed);
    }
    else{
        customPrintf("Failed! Chars printed: %d\n", chars_printed);
    }
    customPrintf("Press enter to continue...\n");
    getchar();
}
void quit(){
    customPrintf("Goodbye!!!\n");
}

void clearConsole(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}