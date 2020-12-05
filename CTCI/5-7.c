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

#define MAX_N 1000
#define TEST_CASES 1000

int fetch(int a[], int i, int x){
    // Fetch the xth bit of a[i]
    return a[i] >> x & 1;
}

int find_missing(int a[], int n){
    bool* seen = (bool*) malloc(sizeof(bool) * n);
    memset(seen, false, sizeof(bool) * n);
    for(int i = 0; i < n - 1; i++){
        int num = 0;
        for(int j = 0; j < 32; j++){
            num |= fetch(a, i, j) << j;
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
    int t = 0;
    srand(time(NULL));
    while(t++ < TEST_CASES){
        int missing = rand() % MAX_N;
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

        int ret = find_missing(a_missing, MAX_N);
        if(ret != missing){
            fprintf(stderr, "Testcase %d\tfailed!, remove %d != find missing %d \n", t, missing, ret);
            return EXIT_FAILURE;
        }
        else{
            fprintf(stdout, "Testcase %d\tpassed!, remove %d == find missing %d \n", t, missing, ret);
        }
    }
    return 0;
}
