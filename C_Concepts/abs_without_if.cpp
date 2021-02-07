#include <bits/stdc++.h>

int abs_no_if(int num){
    return num * ((num > 0)  - (num < 0));
}

int main(){
    int num;
    while(scanf("%d", &num)){
       printf("abs of %d is %d \n", num, abs_no_if(num)); 
    }
    
    return 0;
}
