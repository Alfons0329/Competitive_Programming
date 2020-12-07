#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
/*
 * This does not swap sincei the function just changes local pointer variables and the changes are not reflected outside the function.
 * */
void swap_no_effect(char* str1, char* str2) { 
    char *tmp = str1; 
    str1 = str2; 
    str2 = tmp; 
}   

void swap_with_strlib(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* tmp = malloc(sizeof(char) * len2);
    
    printf("%d %d \n", len1, len2);
    strncpy(tmp, str2, len2);
    strncpy(str2, str1, len1);
    printf("str2 %s \n", str2);
    strncpy(str1, tmp, len2);
    str2[len1] = '\0'; // Add a terminating null character to cut out the remain character after str2[len1]
    printf("str2 %s \n", str2);
    free(tmp);
}

void swap_with_double_ptr(char** str1, char** str2){
    char **tmp;
    tmp = *str2;
    *str2 = *str1;
    *str1 = tmp;
}

int main() { 
    char str1[] = "geeks"; 
    char str2[] = "BANANABANANABANANABANANA"; 
    swap_no_effect(str1, str2); 
    printf("[ANS]: After swap_no_effect str1 is %s, str2 is %s\n", str1, str2);

    char* p_str1 = str1;
    char* p_str2 = str2;

    swap_with_strlib(str1, str2); 
    printf("[ANS]: After swap_with_strlib(str1, str2) str1 is %s, str2 is %s\n", str1, str2);

    swap_with_strlib(p_str1, p_str2); 
    printf("[ANS]: After swap_with_strlib(p_str1, p_str2) str1 is %s, str2 is %s\n", p_str1, p_str2);

    char* xx = "APPLE";
    char* yy = "CHICKENCHICKEN";
    swap_with_double_ptr(&xx, &yy); 
    printf("[ANS]: After swap_with_double_ptr(xx, yy) str1 is %s, str2 is %s\n", xx, yy);
    return 0; 
} 
