/*
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j). EXAMPLE: Input: N = 10000000000, M = 10101, i = 2, j = 6 Output: N = 10001010100
 * */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int M, N, i, j;
    while(cin >> M >> N){
        cin >> i >> j;
        int tmp = (1 << i) - 1;
        tmp &= N;
        int res1 = ((N >> (j + 1)) << (j + 1)) | M << i | tmp;
        // int res2 = (N & 1 << (j + 1)) | M << i | tmp; this is absolutely wrong since the bits higher than j will be set to zero due to & 1 << (j + 1)
        bitset<32> b1(res1);
        bitset<32> b2(res2);
        cout << "Result1: "<< b1 << '\n';
        // cout << "Result1: "<< b2 << '\n';
        // assert(res1 == res2);
    }
    return 0;
}
