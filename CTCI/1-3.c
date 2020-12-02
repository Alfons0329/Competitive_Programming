/*
 * Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not. FOLLOW UP Write the test cases for this method.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000

/* 
 * Only allow non-array variable
 * O(N^2) to remove duplicate char with none extra space, simply not print the duplicate character will be fine
 */
void remove_dup_1(char input[]){
    int len = strlen(input);
    printf("Method 1 \n");
    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if(input[i] == input[j]){
                input[j] = 0;
            }
        }
        if(input[i]){
            printf("%c", input[i]);
        }
    }
    if(input[len - 1]){
        printf("%c", input[len - 1]);
    }
    printf("\n");
}

/* 
 * Allow usage of array-length variable but not up to O(N)
 * O(N) to remove  duplicate char with O(256) extra space
 * */
void remove_dup_2(char input[]){
    bool seen[256] = {false}; // Total 256 ASCII characters
    int len = strlen(input);
    for(int i = 0; i < len; i++){
        // Found duplicate, close that character
        if(seen[input[i]]){
            input[i] = 0;
        }
        // Non duplicate, add to seen 
        else{
            seen[input[i]] = true;
        }
    }

    printf("Method 2 \n");
    for(int i = 0; i < len; i++){
        if(input[i]){
            printf("%c", input[i]);
        }
    }
    printf("\n");
}

int main(){
    while(1){
        char input_1[MAX_N] = {0};
        char input_2[MAX_N] = {0};
        if(scanf("%s", input_1) == EOF){
            break;
        }
        strncpy(input_2, input_1, strlen(input_1));
        remove_dup_1(input_1);
        remove_dup_2(input_2);
    }

    return 0;
}
