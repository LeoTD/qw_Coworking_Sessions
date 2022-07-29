#include <stdio.h>
#include <stdint.h>

int main(void) {
    int thing = 42;
    int *ptr = &thing;
    printf("%p\n", ptr);
}