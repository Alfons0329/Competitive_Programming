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
    
    char str[] = "ABCDEFG";
    for(int i = 0; i < strlen(str); i++){
        char* ptr_ith = str;
        ptr_ith += i;
        printf("%c\n", *(str + i)); // This print char at str[i]
        printf("%d\n", *ptr_ith); // This does the same as above
        printf("%p\n", ptr_ith); // This print the address of str[i]

        printf("[%s]\n", ptr_ith); // This print str[i:]
        printf("[%s]\n", str + i); // This does the same as above
        print_str(str + i); // This does the same function as 2 lines above
        print_str(&str[i]); // This does the same function as 3 lines above
        
    }
/*
 * */

    char name1[200] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char name2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char name3[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Sizeof name1[200] is %ld with len %ld \n", sizeof(name1), strlen(name1));
    printf("Sizeof name2[] is %ld with len %ld \n", sizeof(name2), strlen(name2));
    printf("Sizeof name3[7] is %ld with len %ld \n", sizeof(name3), strlen(name3));
/*
 * Sizeof name1[200] is 200 with len 26
 * Sizeof name2[] is 27 with len 26
 * Sizeof name3[7] is 27 with len 26
 * */

    char* p1 = &str[2];
    char* p2 = &str[6];
    printf("%d \n", p2 - p1);
    printf("%s \n", p1);
    printf("%c \n", *(p1));
    // printf("%s \n", *(p1));
/*
 * 4
 * CDEFG 
 * C
 * ASAN:DEADLYSIGNAL
 * */
    return 0;
}
