#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_strrev(char *str) {
    char *result;
    int i, j;
    int len;

    len = 0;
    while (str[len] != 0) {
        len += 1;
    }
    result = malloc(len + 1);

    i = 0;
    j = len - 1;
    result[len] = 0;
    while (i < len && j >= 0) {
        result[j] = str[i];
        i += 1;
        j -= 1;
    }
    
    i = 0;
    while (i < len) {
        str[i] = result[i];
        i += 1;
    }

    free(result);
}

char *my_utoa(long num, char *str, int base)
{
    int i = 0;
    bool isNegative = false;

    if (num == 0)
    {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }

    if (num < 0 && base == 10)
    {
        isNegative = true;
        num *= -1;
    }

    while (num != 0)
    {
        int remainder = num % base;
        if (remainder > 9)
            str[i++] = (remainder - 10) + 'A'; // A ASCII value = 65
        else
            str[i++] = remainder + '0'; // 0 ASCII value = 48
        num = num / base;
    }

    if (isNegative)
    {
        str[i++] = '-';
    }

    str[i] = '\0';
    my_strrev(str);

    return str;
}

int main(void)
{
    long int j = 4294967295;
    char buffer[500];

    printf("%u\n", (unsigned int)j);

    my_utoa(j, buffer, 10);

    printf("%s\n", buffer);
}