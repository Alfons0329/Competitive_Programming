#include <stdio.h>
#include <stdlib.h>
#include "extern_practice_include.c"

int main(){
    extern float x;
    printf("Extern float x: %f\n", x);
    x *= 3.14f;
    printf("Extern float x after * 3.14: %f\n", x);

    extern double y;
    printf("Extern float y: %f\n", y);
    y *= 5.00f;
    printf("Extern float y after * 5: %f\n", y);
    return 0;
}
