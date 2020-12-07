#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

void param_1(int arr[]){
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("sizeof(arr) %lu, sizeof(arr[0]) %lu\n", sizeof(arr), sizeof(arr[0]));
    printf("Array size in param_1 %d \n", arr_size);
/*
 sizeof(arr) 8, sizeof(arr[0]) 4
 Array size in param_1 2 
 * */
}

void print_str(char* p_str){
    printf("print_str print[%s]\n", p_str);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("sizeof(arr) %lu, sizeof(arr[0]) %lu\n", sizeof(arr), sizeof(arr[0]));
    printf("Array size in main %d \n", arr_size);

    param_1(arr);

/*
 sizeof(arr) 20, sizeof(arr[0]) 4
 Array size in main 5 
 * */
    
    char str[] = "HELLO WORLD";
    for(int i = 0; i < strlen(str); i++){
        printf("Start from: %c\n", *(str + i));
        printf("[%s]\n", str + i);
        print_str(str + i); // This has the same function as above line
        print_str(&str[i]); // This has the same function as above, above line
    }
/*
Start from: H
HELLO WORLD
Start from: E
ELLO WORLD
Start from: L
LLO WORLD
Start from: L
LO WORLD
Start from: O
O WORLD
Start from:  
 WORLD
Start from: W
WORLD
Start from: O
ORLD
Start from: R
RLD
Start from: L
LD
Start from: D
D
 * */

    char* p1 = &str[2];
    char* p2 = &str[6];
    printf("%d \n", p2 - p1);
    printf("%s \n", p1);
    printf("%c \n", *(p1));
    printf("%s \n", *(p1));
/*
 * 4
 * LLO WORLD
 * LLO WORLD
 * <<<SegFault>>>
 * */
    return 0;
}
