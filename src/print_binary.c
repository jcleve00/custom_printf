#include "custom_printf.h"

int printBinary(va_list args){
    int n = va_arg(args, int);
    int binaryNum[32]; /* Array to store binary digits assuming 32 bits */
    int i = 0;
    int charsPrinted = 0;

    char *buffer = (char *)malloc(32 * sizeof(char)); /* Dynamically allocate memory to array */
    if (buffer == NULL){
        return -1;
    }

    /* if number is 0 no conversion necessary */
    if (n == 0){
        write(1, "0", 1);
        free(buffer);
        return 1;
    }
    /* Convert integer to binary and store in binaryNum */
    while (n > 0){
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    int digitCount = i;

    /* Loop through binaryNum, converting digits to chars and store in buffer in reverse order */
    int bufferIndex = 0;

    for (int j = digitCount - 1; j >= 0; j--){
        buffer[bufferIndex] = binaryNum[j] + '0';
        bufferIndex++;
    }
    
    /* Get length of buffer. Print and count digits */
    for (i = 0; i < bufferIndex;i++){
        write(1, &buffer[i], 1);
        charsPrinted++;
    }

    free(buffer);
    return charsPrinted;
}