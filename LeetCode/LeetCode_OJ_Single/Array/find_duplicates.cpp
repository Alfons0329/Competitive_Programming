#include <bits/stdc++.h>

using namespace std;
vector<int> v;

void check_method_1(){
    unordered_map<int, int>m;
    for(int x : v){
        m[x]++;
    }
    cout << "duplicates: ";
    for(auto it = m.begin(); it != m.end(); it++){
        if(it -> second >= 2){
            cout << it -> first << " ";
        }
    }
}

// this only works if all the element are in [0 to arr.size() - 1]
void check_method_2(){
    // assertion
    int n = v.size();
    for(int x : v){
        assert(x >= 0 && x <= n - 1);
    }
    for(int x : v){
        v[x % n] += n;
    }

    cout << "\nduplicates: ";
    for(int i = 0; i < n; i++){
        if(v[i] >= n * 2){
            cout << i << " ";
        }
    }
}

int main(){
    int tmp;
    while(cin >> tmp){
        v.emplace_back(tmp);
    }
    check_method_1();
    check_method_2();
    return 0;
}
