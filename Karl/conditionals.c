#include <stdio.h>
#include <stdbool.h>

int main(void) {

    if (true || false && false) {
        printf("True!\n");
    }
    else {
        printf("False\n");
    }
}