
# Custom printf Implementation

In this project, we created a custom implementation of printf() to handle format specifiers c, s, d, i, f, b, %, and nonspecifier. It utilizes variadic functions, custom memory management, and function pointer-based dispatching to format and print data to standard output. The goal is to provide a deeper understanding of how system level I/O and variable argument handling function in C.

## Authors

- Josh Cleveland [@jcleve](https://github.com/jcleve00)
- Wynoami Glasser [@wynoami](https://github.com/wynoami)


## Flowchart 

Here is a flowchart of how we designed the program to run crafted in Canva.
![Flowchart of customPrintf logic](./images/CustomPrintf-Flowchart.png)


## Description of Project

This project invloves the development of a custom C library function, `customPrintf()`, which replicates the functionality of the standard `printf()` library function. The objectice was to build a variadic function capable of parsing a format string and dynamically formatting various data types, including characters, strings, integers, binary integers, and floating-point numbers.

Some of the key challenges we addressed are:
- Memory Management:Implementing dynamic memory allocation `malloc` and deallocation `free` to safely handle data types that lack a fixed string representation.
- Systems Programming: Bypassing the standard library's buffered output by leveraging the `write()` system call for direct interaction with the standard output file descriptor.
- Architecture: Moving away from standard `switch` chains in favor of a dispatch table, utilizing an array of `FormatSpec` structures and function pointers for fast lookups.

By completing this project, we have gained a functional understanding of how C interprets variable argument lists, how data is represented at the binary level, and how to maintain strict memory hygiene in C. 

## How to Run project

To compile the project with the required srict standards, use the following GCC command: 
    `gcc -Wall -Werror -Wextra -pedantic -std=c11 -o main main.c custom_printf.c`

## Project structure breakdown

The project is organized for modularity and maintainability:

- custom_printf.h: Contains the FormatSpec struct, library imports, and global function prototypes.
- custom_printf.c: The core engine; handles the variadic argument loop and the dispatch logic for specifiers, as well as the logic for printing characters, strings, integers, binary numbers, and floating-point values.
- main.c: Contains the menu display for the user's selection

## Explanations

- Dispatch Table: Instead of using complex `switch` statements, we mapped format specifiers to their respective functions using an array of `FormatSpec` structs. This provides an efficient, readable way to look up and execute printing logic. 
- Variadic Functions: We utilized `<stdarg.h>` to access the variadic function argument list (`va_list`). By iterating through the format string, we call the appropriate helper function only when a `%` specifier is encountered. 
- Low-Level I/O: The `write()` system call is used to send data directly to file descriptor `1` (stdout), which ensures high performance and precise control over the character count returned by our function.
- Dynamic Memory: For complex types like floats, `malloc` is used to allocate temporary buffers, which are subsequently freed to keep the heap clean. 

## What was not completed or what would we run?

- We have not implemented precision handling for floats (e.g., `.2f`).
- Flag support is not included in this build (e.g., `+`, `#`, `0`).

## Error, Run, & Build issues

- Character Count: Whitespace was not accounted for and it threw of the total character count.
- Strict Flags: Because we are using `-Werror`, ay unused variables or type mismatches will trigger a build failure. All code is currently sanitized to pass these warnings.

## Environment

- Compiler: GCC 13.x or higher
- Standard: C11
- Development Host: Windows 11 (VS Code)
- Development Runtime: Linux (via Dev Containers)
- Version Control: GitHub
- Repository: https://github.com/jcleve00/custom_printf.git
