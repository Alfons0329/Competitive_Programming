/*
 * Write a function to determine the number of bits required to convert integer A to integer B.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#define MAX_N 20

int fetch(int a[], int i, int x){
    // Fetch the xth bit of a[i]
    return a[i] >> x & 1;
}

int find_missing(int a[], int n){
    bool* seen = (bool*) malloc(sizeof(bool) * n);
    memset(seen, false, sizeof(bool) * n);
    for(int i = 0; i < n - 1; i++){
        int num = 0;
        int base = 1;
        for(int j = 0; j < 32; j++){
            num |= (base & (a, i, j));
            base <<= 1;
        }
        seen[num] = true;
    }

    for(int i = 0; i < n; i++){
        if(!seen[i]){
            return i; 
        }
    }
    return -1;
}

int main(){
    while(1){
        srand(time(NULL));
        int missing = rand() % MAX_N + 1;
        int* a = (int*) malloc(sizeof(int) * MAX_N);
        for(int i = 0; i < MAX_N; i++){
            a[i] = i;
        }

        int idx_missing;
        for(int i = 0; i < MAX_N; i++){
            if(a[i] == missing){
                idx_missing = i;
                break;
            }
        }

        int* a_missing = (int*) malloc(sizeof(int) * (MAX_N - 1));
        memcpy(a_missing, a, sizeof(int) * (idx_missing));
        memcpy(&a_missing[idx_missing], &a[idx_missing + 1], sizeof(int) * (MAX_N - idx_missing - 1));

        printf("After remove: %d\n", missing);
        /*
         * 
        for(int i = 0; i < MAX_N - 1; i++){
            printf("%d, ", a_missing[i]);
        }
        printf("\n");
         * */

        printf("Missing number: %d", find_missing(a_missing, MAX_N));
        getchar();
    }
    return 0;
}
