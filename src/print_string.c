#include "custom_printf.h"


int printString(va_list args){
    int chars_printed = 0;
    char *string = va_arg(args, char*);

    // Make sure there is string to loop through
    if (!string){
        string = "(null)";
    }
    // No buffer necessary, so just loop through string and write to console, counting chars_printed along the way. 
    for (int i = 0; string[i] != '\0';i++){
        chars_printed += write(1, &string[i], 1);
    }
    return chars_printed;
}
