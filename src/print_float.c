#include "custom_printf.h"

int printFloat(va_list *args){
    /* Float are promoted to double in variadic arguments */
    double num = va_arg(*args, double);
    int chars_printed = 0;

    /* Handle negative numbers */
    if (num < 0) {
        chars_printed += write(1, "-", 1);
        num = -num; /* Make it positive for easier math */
    }

    /* Split into integer and fractional parts */
    long int_part = (long)num;                  /* e.g., 3.141592 -> 3 */
    double frac_part = num - (double)int_part;  /* e.g., 3.141592 - 3.0 = 0.141592 */

    /* Print integer part */
    if (int_part == 0) {
        chars_printed += write(1, "0", 1);
    } else {
        /* Allocate buffer for integer digits */
        char *int_buffer = (char *)malloc(20 * sizeof(char));
        if (int_buffer == NULL) return -1;

        int i = 0;
        while (int_part > 0) {
            int_buffer[i] = (int_part % 10) + '0';
            int_part /= 10;
            i++;
        }

        /* Print in reverse */
        for (int j = i - 1; j >= 0; j--) {
            chars_printed += write(1, &int_buffer[j], 1);
        }
        free(int_buffer);
    }

    /* Print fractional part (default 6 decimal places)
    We multiply by 10 and peel off one digit at a time to catch trailing zeros safely */
    /* Print the decimal point */
    chars_printed += write(1, ".", 1);
    
    for (int i = 0; i < 6; i++) {   /* Shift the next decimal digit to the left*/
        frac_part *= 10;            /* Shift the decimal over by 1 place */
        int digit = (int)frac_part; /* Extract the digit */

        char c = digit + '0';       /* Convert to ASCII character */
        chars_printed += write(1, &c, 1);
        frac_part -= digit;         /* Remove the digit to prep for next loop*/
    }

    return chars_printed;
}