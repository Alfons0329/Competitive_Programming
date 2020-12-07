#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

void param_1(int arr[]){
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("sizeof(arr) %d, sizeof(arr[0]) %d\n", sizeof(arr), sizeof(arr[0]));
    printf("Array size in param_1 %d \n", arr_size);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("sizeof(arr) %d, sizeof(arr[0]) %d\n", sizeof(arr), sizeof(arr[0]));
    printf("Array size in main %d \n", arr_size);

    param_1(arr);

    return 0;
}
