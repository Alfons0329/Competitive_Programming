/*
 * Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000

bool check(char input[]){
    /*
     * Check for A-Z and a-z
     * */
    unsigned long long hash = 0;
    for(int i = 0; input[i]; i++){
        int shift = input[i] - 'A';
        int hash_shift = hash >> shift;
        if(hash_shift & 1){
            return false;
        } 
        else{
            hash |= (unsigned long long)(1ULL << shift);
        }
    }
    return true;
}

int main(){
    while(1){
        char input[MAX_N] = {0};
        scanf("%s", input);
        if(input[0] == 0){
            break;
        }
        printf("All unique?: %d\n", check(input));
    }

    return 0;
}
