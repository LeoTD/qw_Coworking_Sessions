#include <stdio.h>

// This function prints one byte at a time as a hexadecimal value. Takes a pointer to memory, and a number of bytes to print.
void print_memory_representation_hex(char *start, int n) {

    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}

int main () {

    int  var1 = 2189640;
    int* ptr1 = &var1;

    // Address of var1 is the same as the value of ptr1!
    printf("Address of var1 variable:       %p\n",   &var1  );
    printf("Value of ptr1 variable:         %p\n\n", ptr1   );
    // Run it a few times and you'll see these values change.

    // Dereferencing with different types!
    printf("Dereferencing as an integer:    %d\n", *((int*)ptr1) );
    printf("Dereferencing as a char:        %c\n", *((char*)ptr1) );
    printf("Printing as a string:           %s\n\n", (char*)ptr1 );

    // Print bytes in memory (in hex notation):
    printf("Printing integer in hex:        %08x\n", *((int*)ptr1) );
    printf("Printing bytes in memory (hex):");
    print_memory_representation_hex((char*) &var1, sizeof(var1));
    // Notice anything about the memory representation of this integer? (Look up endianness)

    return 0;
}
