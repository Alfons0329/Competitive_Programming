/*
 * Bit Rotation: A rotation (or circular shift) is an operation similar to shift except that the bits that fall off at one end are put back to the other end.
 * In left rotation, the bits that fall off at left end are put back at right end.
 * In right rotation, the bits that fall off at right end are put back at left end
 * */
#include <bits/stdc++.h>
#define MAX_BITS 32

using namespace std;

int left_rotate(int num, int x){
    return (num << x) | (num >> (MAX_BITS - x));
}
int right_rotate(int num, int x){
    return (num >> x) | (num << (MAX_BITS - x));
}

int main(){
    int num;
    while(cin >> num){
        for(int i = 0; i <= 32; i++){
            bitset<32> b1(num);
            cout << "Num: " << num << b1.to_string() << endl;
            bitset<32> b2(left_rotate(num, i));
            cout << "After left_rotate " << i << " bits:  " << b2.to_string() << endl; 
            bitset<32> b3(right_rotate(num, i));
            cout << "After right_rotate " << i << " bits: " << b3.to_string() << endl; 
        }
    }
    return 0;
}
