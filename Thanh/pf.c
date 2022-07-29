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
char* my_utoa(uintptr_t num, char* str, int base) {
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
            str[i++] = (remainder-10) + 'a'; // A ASCII value = 65
        else
            str[i++] = remainder + '0'; // 0 ASCII value = 48
        num = num/base;
    }
    str[i] = '\0';
    my_reverse(str, i);
    
    printf("\nmy_utoa: %s\n", str);
    return str;
}

int my_printf(char * restrict format, ...) {
    // variables
    char *content;
    unsigned int i;
    char *str;
    char ch;
    void *ptr;

    va_list arguments;
    va_start(arguments, format);

    // loop through content of parameters
    for(content = format; *content != '\0'; content++) {
        // print string without flag
        while(*content != '%') {
            write(1,(int*)content,1);
            content++;
            if (*content == '\0')
                break;
        }
        content++;

        //* flag handle
        // signed decimal
        if (*content == 'd') {
            i = va_arg(arguments,int); 
            // convert to string
            char buffer[500];
            my_itoa(i, buffer, 10);
            // print
            int len = my_strlen(buffer);
            write(1,buffer,len);
        }
        // unsigned octal
        else if (*content == 'o') {
            i = va_arg(arguments,int); 
            // convert to string
            char buffer[500];
            my_utoa(i, buffer, 8);
            // print
            int len = my_strlen(buffer);
            write(1,buffer,len);
        }
        // unsigned decimal
        else if (*content == 'u') {
            i = va_arg(arguments,int); 
            // convert to string
            char buffer[500];
            my_utoa(i, buffer, 10);
            // print
            int len = my_strlen(buffer);
            write(1,buffer,len);
            
        }
        // unsigned hexadecimal
        else if (*content == 'x') {
            i = va_arg(arguments,int); 
            // convert to string
            char buffer[500];
            my_utoa(i, buffer, 16);
            // print
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
            // print
            int len = my_strlen(str);
            write(1,str,len);
        }
        // void * pointer
        else if (*content == 'p') {
            ptr = va_arg(arguments, void *);
            // convert to string
            char buffer[500];
            my_utoa((uintptr_t)ptr, buffer, 16);
            // print
            int len = my_strlen(buffer);
            write(1,"0x",2);
            write(1,buffer,len);
        }
    }

    va_end(arguments);
}

int main(int argc, char **argv) {
    
    int integer_1 = -123;
    int integer_2 = 456;
    int *ptr_int1 = &integer_1;
    int *ptr_int2 = &integer_2;
    char ch_1 = 'a';
    char ch_2 = 'b';
    char str_1[6] = "hello\0"; 
    char str_2[6] = "world\0";

//    my_printf("test string u:%u d:%d o:%o x:%x c:%c%c s:%s %s p:%p", integer_1, integer_2, integer_1, integer_1, ch_1, ch_2, str_1, str_2, ptr_int1);
//    printf("\ntest string u:%u d:%d o:%o x:%x c:%c%c s:%s %s p:%p\n", integer_1, integer_2, integer_1, integer_1, ch_1, ch_2, str_1, str_2, ptr_int1);

    my_printf("t:%p\n", ptr_int1);
    printf("\np:%p\n", ptr_int1);
    return 0;
}

