#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(int* a){
    *a *= 2;
    static int x = 0;
    x = x + 3;
    return x;
}

int ff(int a){
    a *= 2;
    return a;
}

int main(){
    for(int i = 0; i < 10; i++){
        int k = i;
        printf("fx %d \n", f(&k));
        printf("fk: %d \n", k);
        printf("ffx %d \n", ff(k));
        printf("ffk: %d \n", k);
        printf("----\n");
    }

    return 0;
}
