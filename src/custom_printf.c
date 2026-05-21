#include "custom_printf.h"

FormatSpec specs[] = {
	{'c', printChar},
	{'s', printString},
	{'f', printFloat},
    {'d', printInt},
	{'i', printInt},
	{'b', printBinary},
	{'\0', NULL}
};

int customPrintf(const char *string, ...){

    /* Adding error handling*/
    if (string == NULL){
        return -1;
    }

    int i = 0;
    char specifier;
    va_list args;
    va_start(args, string);
    int chars_printed = 0; /* declared for testing results */

    while(string[i] != '\0'){
        if (string[i] == '%'){
            if (string[i+1] == '%'){
                /* added chars_printed += */
                chars_printed += write(1, &string[i], 1);
                i++;
            }
            else{
                specifier = string[i + 1];
                for (int j = 0; specs[j].specifier != '\0';j++){
                    if (specifier == specs[j].specifier){
/* added chars_printed */ chars_printed += specs[j].function(&args); // Accept reference to args
                    }
                }
                i++;
            }
        }
        else{
            /* Added chars_printed */
           chars_printed += write(1, &string[i], 1);
        }
        i++;
    }

    va_end(args);

    return chars_printed;
}