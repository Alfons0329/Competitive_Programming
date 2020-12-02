/*
 * Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring ( i.e., “waterbottle” is a rotation of “erbottlewat” ). 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 1000

bool is_substr(char* s, char *sub){
    int m = strlen(s);
    int n = strlen(sub);
    assert(n < m);

    for(int i = 0; i < m; i++){
        int offset = 0;
        while(offset < n && s[i + offset] == sub[offset]){
            offset++;
        }
        if(offset == n){
            printf("%s is substr of %s \n", sub, s);
            return true;
        }
    }
    return false;
}

/*
 * If s2 is the rotate of s1, then is_substr(s1 + s1, s2) must be true since s2 will definitely contain in the concatenation of s1
 * */
void is_rotate(char* s1, char* s2){
    int m = strlen(s1);
    int n = strlen(s2);
    assert(m == n);

    char* concat = (char*) malloc(sizeof(char) * (2 * m + 1));
    strncpy(concat, s1, m);
    strncat(concat, s1, m);

    if(is_substr(concat, s2)){
        printf("%s is the rotation of %s \n", s1, s2);
    }
    else{
        printf("%s is NOT the rotation of %s \n", s1, s2);
    }
}

int main(){
    while(1){
        char s1[MAX_N] = {0};
        char s2[MAX_N] = {0};

        scanf("%s", s1);
        scanf("%s", s2);

        is_rotate(s1, s2);
    }
    return 0;
}
