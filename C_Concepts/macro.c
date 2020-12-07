#include <stdio.h>
#include <stdlib.h>

#define MAX_TWO(a, b)(a > b ? a : b)

int main(){
    int a = 5, b = 7;
    printf("Max of %d, %d is %d \n", a, b, MAX_TWO(a, b));
    return 0;
}
