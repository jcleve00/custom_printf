#include "custom_printf.h"

int customPrintf(const char *string, ...){
    int i = 0;
    char specifier;
    va_list args;
    va_start(args, string);

    while(string[i] != '\0'){
        if (string[i] == '%'){
            if (string[i+1] == '%'){
                printChar(string[i]);
                i++;
            }
            else{
                specifier = string[i + 1];
                
                i++;
            }
            
        }
        else{
            printChar(string[i]);
        }
        i++;
    }

    va_end(args);

    return 0;
}