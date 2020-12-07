#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 1000

void f_char(char *s){
}

void f_int(int* a){
}

int main(){
    char str[] = "Hel10WorLD";
    char* sp = str;

    printf("%lu\n", strlen(str));
    printf("%c\n", ++*sp);
    printf("%c\n", *sp);
    printf("%c\n", *sp++);
    printf("%c\n", *sp);
    printf("%c\n", *++sp);
    printf("%c\n", *sp);
    printf("%c\n", ++*(sp + 7));
    printf("%s\n", str);

    char str_no_terminate[4] = "Hey\0";
    printf("%s\n", str_no_terminate);

    return 0;
}
