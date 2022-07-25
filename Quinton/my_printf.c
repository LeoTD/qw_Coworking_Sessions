#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define CONV_CHAR 37 // '%' functionally equivalent. 37 is the ASCII value of %.

int my_printf(char *fmt, ...) {
    // To work with the variadic function construct in C, we need to know how many variables were passed in.
    // In the case of printf and variants, this number is encoded in the format string.
    int i = 0;
    int count = 0;
    // simple count, needs refining! "%%"? Is this memory safe?
    while (fmt[i] != '\0') {
        if (fmt[i] == CONV_CHAR) {
            count += 1;
        }
        i += 1;
    }

    // Here we initialize the va_list which will contain our arguments.
    va_list args_list;           // va_list is an instance of an argument list.
    va_start(args_list, fmt);    // va_start takes the list and the last named parameter before the variable parameters.

    i = 0;
    int arg = 0;
    while (i < count + 1) {
        // Starting with the first, va_arg gets the next variable in the list, and returns it as the type you specify. 
        // NOTE: va_arg is NOT MAGIC. If you mismatch the type you ask for compared to the type that was given, you *will*
        //      get weird results that may crash your program.

        // Only recieves integers!
        arg = va_arg(args_list, int);

        // Print what we recieved to prove we received it.
        printf("%d\n", arg);

        i += 1;
    }

    // Stop traversing the argument list.
    va_end(args_list);

    return 0;
}

int main(void) {
    int bytes_printed;
    bytes_printed = my_printf("Hell%d, World!\n", 0);
    return 0;
}