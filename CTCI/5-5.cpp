/*
 * Write a function to determine the number of bits required to convert integer A to integer B.
 * */
#include <bits/stdc++.h>
#include <random>

using namespace std;

int hamming_distance(int a, int b){
    bitset<32> b1(a);
    bitset<32> b2(b);

    cout << setw(12) << a << "\tin bin " << b1.to_string() << endl;
    cout << setw(12) << b << "\tin bin " << b2.to_string() << endl;

    a ^= b;
    bitset<32> b3(a);
    cout << setw(12) << a << "\tin bin " << b3.to_string() << endl;
    int ret = 0;
    for(int i = 0; i < 32; i++){
        ret += a & 1;
        a >>= 1;
    }

    return ret;
}

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(INT_MIN, INT_MAX);
    while(1){
        int h = hamming_distance(gen(), gen());
        cout << "Hamming distance: " << h << endl;
        getchar();
    }
    return 0;
}
