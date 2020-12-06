/*
 * Given a double string, convert it to double
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define MAX_N 1000
#define MAX_CASE 5

double str_to_lf(char* str){
    int len = strlen(str), dot_pos = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == '.'){
            dot_pos = i;
            break;
        }
    }

    int part_int = 0, base_int = 1;
    double part_dec = 0.0f, base_dec = 0.1f;
    for(int i = dot_pos - 1; i >= 0; i--){
        assert(str[i] >= '0' && str[i] <= '9');
        part_int += (str[i] - '0') * base_int;
        base_int *= 10;
    }
    for(int i = dot_pos + 1; i < len; i++){
        assert(str[i] >= '0' && str[i] <= '9');
        part_dec += (str[i] - '0') * base_dec;
        base_dec /= 10.0f;
    }

    return (double) part_int + part_dec;
}

int main(){
    while(1){
        char str[MAX_N] = {0};
        scanf("%s", str);
        if(strlen(str) == 0){
            break;
        }
        else{
            printf("Input: %s, convert to double: %.10lf \n", str, str_to_lf(str));
        }
    }
    return 0;
}
