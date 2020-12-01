/*
 * Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000

void reverse(char input[]){
    /*
     * Check for A-Z and a-z
     * */
    int len = 0;
    while(input[len++]);
    for(int i = 0; i < len / 2; i++){
        input[i] ^= input[len - i - 1];
        input[len - i - 1] ^= input[i];
        input[i] ^= input[len - i - 1];
    }
    char* ret = (char*)malloc(sizeof(char) * (len + 1));
    memcpy(ret, input, sizeof(char) * (len + 1));
    for(int i = 0; i < len; i++){
        printf("%c", ret[i]);
    }
    printf("\n");;
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
