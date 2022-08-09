#include <stdio.h>
#include <stdarg.h>


void func(int num, ...) {
    va_list l;
    va_start(l, num);

    int i = 0;
    while (i < num) {
        printf("%x ", va_arg(l, int), 1);
        i += 1;
    }
    printf("\n");
    va_end(l);
}

int main(void) {
    func(3, 1, 2, 3, 4);
}