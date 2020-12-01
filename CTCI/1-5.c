/*
 * Write a method to decide if two strings are anagrams or not.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 1000

/*
 * Count each alphabet (ASCII char), doing the statistics with alphabet_count[256], and iterate again, if alphabet_count[i] is greater then zero, then it means there exists at least one char has not been cancelled out, so non anagram.
 */
void replace(char* s){
    int len = strlen(s);
    printf("String length: %d\n", len);
    getchar();
    
    char* res = (char*) calloc(2 * len + 1, sizeof(char));// 1 more space for the null terminated character
    int j = 0;

    for(int i = 0; i < len; i++){
        if(s[i] == ' '){
            res[j] = '%';
            res[j + 1] = '2';
            res [j + 2] = '0';
            j += 3;
        }
        else{
            res[j] = s[i];
            j++;
        }
    }
    res[j] = '\0'; // NULL string terminator
    
    printf("%s\n", res);
}

int main(){
    while(1){
        char s[MAX_N] = {0};
        if(scanf("%[^\n]s", s) == EOF){
            break;
        }
        replace(s);
    }
    return 0;
}
