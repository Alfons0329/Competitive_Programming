#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
void f1(){
    printf("f1\n");
}
void f2(){
    printf("f2\n");
}
void f3(){
    printf("f3\n");
}

char f1_int(int a){
    printf("a: [%d]\n", a);
    return '1';
}
char f2_int(int a){
    printf("a: [%d]\n", a << 1);
    return '2';
}

void f2_intptr(int* a){
    printf("a: [%d]\n", *a);
}

int main(){
    
    // void *f_ptr_void[] = {f1, f2, f3}; // Error, does not compile
    void (*f_ptr_void[])() = {f1, f2, f3}; //
    size_t size_f_ptr_void = sizeof(f_ptr_void) / sizeof(f_ptr_void[0]);
    printf("sizeof(f_ptr_void):[%ld], sizeof(f_ptr_void[0]):[%ld]\n", sizeof(f_ptr_void), sizeof(f_ptr_void[0]));
    for(int i = 0; i < size_f_ptr_void; i++){
        f_ptr_void[i]();
    }
    
    char (*f_ptr_int[])(int) = {f1_int, f2_int}; //
    size_t size_f_ptr_int = sizeof(f_ptr_int) / sizeof(f_ptr_int[0]);
    printf("sizeof(f_ptr_int):[%ld], sizeof(f_ptr_int[0]):[%ld]\n", sizeof(f_ptr_int), sizeof(f_ptr_int[0]));
    for(int i = 0; i < size_f_ptr_int; i++){
        f_ptr_int[i](i);
    }

    return 0;
}
