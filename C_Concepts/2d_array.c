#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define M 5
#define N M

int main(){
    int arr[M][N] = {0};
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = i * N + j;
        }
    }

    printf("%ld \n", arr); // address of arr
    printf("%p \n", arr); // address of arr, should be the same
    
    printf("%ld \n", *arr); // address of arr[0]
    printf("%ld \n", arr[0]); // address of arr[0]
    printf("%ld \n", arr[4]); // address of arr[4], decremented by 20 bytes since 4 * 5 = 20
    
    printf("%ld \n", *(arr + 4)); 

    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return 0;
}
