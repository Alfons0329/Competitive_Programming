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
void check_anagram(char s1[], char* s2){
    int m = strlen(s1);
    int n = strlen(s2);
    printf("m %d n %d \n", m, n);
    assert(m == n);
    
    int alphabet_count[256] = {0};
    for(int i = 0; i < m; i++){
       alphabet_count[s1[i]]++;
       alphabet_count[s2[i]]--;
    }

    bool flag = true;
    for(int i = 0; i < 256; i++){
        if(alphabet_count[i] > 0){
            flag = false;
            break;
        }
    }

    printf("Anagram %s \n", flag ? "Yes" : "No");
}

int main(){
    while(1){
        char s1[MAX_N] = {0};
        char s2[MAX_N] = {0};
        if(scanf("%s", s1) == EOF){
            break;
        }
        scanf("%s", s2);
        check_anagram(s1, s2);
    }

    return 0;
}
