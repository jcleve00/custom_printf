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
                switch(specifier){
                    case 'd':
                        int num = va_arg(args, int);
                        printInt(num);
                    }
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

void printChar(char c){
    write(1, &c, 1);
}
void printInt(int d){
    char digit = d + '0';
    write(1, &digit, 1);
}