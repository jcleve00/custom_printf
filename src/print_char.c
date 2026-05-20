#include "custom_printf.h"

int printChar(va_list args){
    char c = va_arg(args, int);
    if (!c){
        return -1;
    }
    write(1, &c, 1);
    return 1;
}