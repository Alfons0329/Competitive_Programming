/*
 * Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation. 
 * */
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int count_one(int x){
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
}

/*
 * Slow, brute force solutions
 * */
int next_bigger_same_one_slow(int num){
    if(num == 0 || num == -1 || num == INT_MAX){
        cerr << "Exception 1" << endl;
        return -1; // 0 does not have 1 and -1 contains all 1 in binary representation
    }

    int cnt = count_one(num);
    bitset<32> a(num);
    while(count_one(++num) != cnt && num < INT_MAX);
    bitset<32> b(num);
    cout << "Original: " << a.to_string() << endl;
    cout << "Next bigger: " << num << ", bin representation: " << b.to_string() << endl;
}

int next_smaller_same_one_slow(int num){
    if(num == 0 || num == -1 || num == INT_MIN){
        cerr << "Exception 2" << endl;
        return -1; // 0 does not have 1 and -1 contains all 1 in binary representation
    }
    
    int cnt = count_one(num);
    bitset<32> a(num);
    while(count_one(--num) != cnt && num > INT_MIN);
    bitset<32> b(num);
    cout << "Original: " << a.to_string() << endl;
    cout << "Next smaller: " << num << ", bin representation: " << b.to_string() << endl;
}

/*
 * Faster solution according to: https://www.geeksforgeeks.org/closest-next-smaller-greater-numbers-number-set-bits/
 * */

int main(){
    while(1){
        int num;
        cin >> num;
        next_bigger_same_one_slow(num);
        next_smaller_same_one_slow(num);
    }
    return 0;
}
