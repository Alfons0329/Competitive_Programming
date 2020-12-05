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
        int res = ((N >> (j + 1)) << (j + 1)) | M << i | tmp;
        bitset<32> b(res);
        cout << "Result: "<< b << '\n';
    }
    return 0;
}
