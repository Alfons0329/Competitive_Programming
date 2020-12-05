/*
 * Explain what the following code does: ((n & (n-1)) == 0). 
 * */
#include <bits/stdc++.h>

using namespace std;


bool check_pow_2(unsigned long num){
    return (num & (num - 1)) == 0;
}

int main(){
    for(unsigned long i = 0; i < 1ULL << 31; i += 2){
        if(check_pow_2(i)){
            cout << i << " is pow of 2 " << endl;
        }
    }
    return 0;
}
