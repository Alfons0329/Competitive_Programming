/*
 * Write a method to replace all spaces in a string with ‘%20’. 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 1000

/*
 * Remember to allocate 2 * len + 1 space for the string as + 1 more space for the null terminated character 
 */
void replace(char* s){
    int len = strlen(s);
    printf("String length: %d\n", len);

    char* res = (char*) calloc(2 * len + 1, sizeof(char)); // 1 more space for the null terminated character
    int j = 0;

    for(int i = 0; i < len; i++){
        if(s[i] == ' '){
            res[j] = '%';
            res[j + 1] = '2';
            res [j + 2] = '0';
            j += 3;
        }
        else{
            res[j] = s[i];
            j++;
        }
    }
    res[j] = '\0'; // NULL string terminator

    printf("%s\n", res);
    free(res);
}

int main(){
    char s[MAX_N] = {0};
    if(scanf("%[^\n]s", s) != EOF){
        replace(s);
    }

    return 0;
}
