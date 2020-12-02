/*
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 4

void swap(int* a, int* b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void transpose(int m[][MAX_N]){
    for(int i = 0; i < MAX_N; i++){
        for(int j = i + 1; j < MAX_N; j++){
            swap(&m[i][j], &m[j][i]);
        }
    }
}

void flip(int m[][MAX_N]){
    for(int i = 0; i < MAX_N / 2; i++){
        for(int j = 0; j < MAX_N; j++){
            swap(&m[MAX_N - i - 1][j], &m[i][j]);
        }
    }
}

int main(){
    while(1){
        int m[MAX_N][MAX_N] = {0};
        int n;
        printf("Rotate N times of 90 degree, input N: ");
        scanf("%d", &n);
        for(int i = 0; i < MAX_N; i++){
            for(int j = 0; j < MAX_N; j++){
                m[i][j] = i * MAX_N + j + 1;
            }
        }

        switch(n){
            case 1:
                transpose(m);
                flip(m);
                break;
            case 2:
                flip(m);
                break;
            case 3:
                flip(m);
                transpose(m);
                break;
            case 4:
                break;
            default:
                return 0;
        }

        for(int i = 0; i < MAX_N; i++){
            for(int j = 0; j < MAX_N; j++){
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
