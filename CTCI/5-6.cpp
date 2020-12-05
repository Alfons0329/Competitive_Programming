/*
 * Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc). 
 * */
#include <bits/stdc++.h>
#include <random>

using namespace std;

int swap_odd_even_bits(int num){
    bitset<32> b1(num);

    cout << setw(12) << num << ": " << b1.to_string() << endl;
    // Note, should NOT use signed int
    // Since the left shift will always keep the MSB negative, and for input like 0x80000000, will not work, due to left shift is still larger than INT_MIN, the MSB bit should be 0 for this propblem yet
    unsigned  odd_bits = num & 0x55555555;
    unsigned even_bits = num & 0xAAAAAAAA;

    // return odd_bits >> 1 | even_bits << 1;, wrong since odd_bits lies in 1 3 5 7 9...etc, if shift left then the rightmost bit will gone and for the even bits, shift one more bit to left will make leftmost bit gone
    return odd_bits << 1 | even_bits >> 1;
}

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(INT_MIN, INT_MAX);
    while(1){
        int h = swap_odd_even_bits(gen());
        bitset<32> b(h);
        cout << "After swap:   " << b.to_string() << endl;
        getchar();
    }
    return 0;
}
