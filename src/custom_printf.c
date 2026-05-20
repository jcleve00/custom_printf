#include "custom_printf.h"

FormatSpec specs[] = {
	{'c', printChar},
	{'s', printString},
	{'d', printInt},
	{'i', printInt},
	{'b', printBinary},
	{'\0', NULL}
};

int customPrintf(const char *string, ...){
    int i = 0;
    char specifier;
    va_list args;
    va_start(args, string);

    while(string[i] != '\0'){
        if (string[i] == '%'){
            if (string[i+1] == '%'){
                write(1, &string[i], 1);
                i++;
            }
            else{
                specifier = string[i + 1];
                for (int j = 0; specs[j].specifier != '\0';j++){
                    if (specifier == specs[j].specifier){
                        specs[j].function(args);
                    }
                }
                i++;
            }
        }
        else{
            write(1, &string[i], 1);
        }
        i++;
    }

    va_end(args);

    return 0;
}