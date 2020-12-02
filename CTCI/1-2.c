/*
 * Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000

void reverse(char input[]){
    int len = strlen(input);
    for(int i = 0; i < len / 2; i++){
        input[i] ^= input[len - i - 1];
        input[len - i - 1] ^= input[i];
        input[i] ^= input[len - i - 1];
    }

    char* ret = (char*)malloc(sizeof(char) * (len + 1));
    memcpy(ret, input, sizeof(char) * (len + 1));
    ret[len] = '\0';
    printf("%s\n", ret);
    free(ret);
}

int main(){
    while(1){
        char input[MAX_N] = {0};
        if(scanf("%s", input) == EOF){
            break;
        }
        reverse(input);
    }

    return 0;
}
