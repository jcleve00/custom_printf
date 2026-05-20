#include "custom_printf.h"

int printInt(va_list args) {
	int n = va_arg(args, int);
	int charsPrinted = 0;
	unsigned int num; /* use unsigned to safely handle conversion to positive */
	
	/*Edge case 0 */
	if (n < 0) {
		charsPrinted += write(1, "-", 1);
		// Safely make the number positive
		num = (unsigned int)(-n);
	} else {
			num = (unsigned int)n;
	}
	
	/* Dynamic memory: allocate an array to hold our digits*/
	char *buffer = (char *)malloc(12 * sizeof(char));
	if (buffer == NULL) {
		return -1;
	}
	
	int i = 0;
	while (num > 0) {
			/* Get the last digit by finding the remainder of division by 10
			 Adding '0' converts the integer digit (e.g., 5) to the ASCII character ('5') */
			buffer[i] = (num % 10) + '0';
			num = num / 10; // Remove the last digit
			i++;
		}
		
		/* The digits were extracted backwards, so we print them in reverse */
		for (int j = i - 1; j >= 0; j--) {
				charsPrinted += write(1, &buffer[j], 1);
		}
		
		free(buffer);
		
		return charsPrinted;
	}