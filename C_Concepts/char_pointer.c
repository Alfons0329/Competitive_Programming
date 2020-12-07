#include <stdio.h>

int main(){
    const char* c1 = "ABCDE";
    printf("%s\n", c1); // Prints ABCDE
    c1++;
    printf("%s\n", c1); // Prints BCDE
    // c[0] = 'Z'; Undefined behaviour, segfault
    
    char* const c2 = "VWXYZ";
    // c2++; // Compiler error, since c2 is CONST POINTER to char
    return 0;
}
