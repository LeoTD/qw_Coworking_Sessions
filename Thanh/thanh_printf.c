#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

//* custom functions
void my_reverse(char str[], int len)
{
    int start, end;
    char temp;
    for(start = 0, end = len-1; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}
char* my_itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
  
    if (num < 0 && base == 10) {
        isNegative = true;
        num *= -1;
    }
  
    while (num != 0) {
        int remainder = num % base;
        if (remainder > 9)
            str[i++] = (remainder-10) + 'A';
        else
            str[i++] = remainder + '0';
        num = num/base;
    }
  
    if (isNegative){
        str[i++] = '-';
    }
  
    str[i] = '\0';
    my_reverse(str, i);

    return str;
}
int my_strlen(char* param_1)
{
    int length = 0;
    int i = 0;
    while(param_1[i] != '\0') {
        length++;
        i++;
    }
    return length;
}
char* my_utoa(long num, char* str, int base) {
    int i = 0;
    bool isNegative = false;

    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
  
    if (num < 0 && base == 10) {
        isNegative = true;
        num *= -1;
    }
  
    while (num != 0) {
        int remainder = num % base;
        if (remainder > 9)
            str[i++] = (remainder-10) + 'A'; // A ASCII value = 65
        else
            str[i++] = remainder + '0'; // 0 ASCII value = 48
        num = num/base;
    }
  
    if (isNegative) { 
        str[i++] = '-';
    }
  
    str[i] = '\0';
    my_reverse(str, i);

    return str;
}
int power(int base,int exp) {
    int total = base;
    for(int i = 0; i < exp; i++) {
        total*=exp;
    }
    return total;
}

int my_printf(char * restrict format, ...) {
    // variables
    char *content;
    unsigned int i;
    char *str;
    char ch;

    va_list arguments;
    va_start(arguments, format);

    // loop through content of parameters
    for(content = format; *content != '\0'; content++) {
        // print string without flag
        while(*content != '%') {
            write(1,(int*)content,1);
            content++;
        }
        content++;

        //* flag handle
        // signed decimal
        if (*content == 'd') {
            i = va_arg(arguments,int); 

            char buffer[500];
            my_itoa(i, buffer, 10);

            int len = my_strlen(buffer);
            write(1,buffer,len);
        }
        // unsigned octal
        else if (*content == 'o') {
            i = va_arg(arguments,int); 

            char buffer[500];
            my_utoa(i, buffer, 8);

            int len = my_strlen(buffer);
            write(1,buffer,len);
        }
        // unsigned decimal
        // TODO - convert signed int to unsigned
        else if (*content == 'u') {

            /*
            i = va_arg(arguments,int);
            // only for negative number
            if ((int) i < 0)
            {
                // store max possible value for *unsign int* in an int array
                int uint32_max[10] = {4,2,9,4,9,6,7,2,9,5};
                // convert i to integer array

                for (int i = 0; i < 10; i++) {
                    char buffer[10];
                    my_itoa(uint32_max[i], buffer, 10);
                    write(1, buffer, 1);
                }
            }
            */
            
            //i = va_arg(arguments,int); 
            long int j = 4294967295;
            char buffer[500];
            my_utoa(j, buffer, 10);
            printf("%s", buffer);
            //int len = my_strlen(buffer);
            //write(1,buffer,len);
            
        }
        // unsigned hexadecimal
        else if (*content == 'x') {
            i = va_arg(arguments,int); 

            char buffer[500];
            my_itoa(i, buffer, 16);

            int len = my_strlen(buffer);
            write(1,buffer,len);
        }
        // character
        else if (*content == 'c') {
            ch = va_arg(arguments, int);
            write(1,(int*)&ch,1);
        }
        // string
        else if (*content == 's') {
            str = va_arg(arguments, char *);

            int len = my_strlen(str);
            write(1,str,len);
        }
        // void * pointer
        else if (*content == 'p') {
            int abcdef;
        }
    }

    va_end(arguments);
}

int main(int argc, char **argv) {
    int integer_1 = -123;
    int integer_2 = 456;
    char ch_1 = 'a';
    char ch_2 = 'b';
    char str_1[6] = "hello\0"; 
    char str_2[6] = "world\0";
    // TODO - process linefeed !!!
    // ! \n on write() will break the compiler
    //my_printf("test string %u %d %c%c %s %s", integer_1, integer_2, ch_1, ch_2, str_1, str_2);
    //printf("\ntest string %u %d %c%c %s %s", integer_1, integer_2, ch_1, ch_2, str_1, str_2);

    my_printf("%u", 1);
    
    return 0;
}

