#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> a){
    int n = a.size();
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]){
            int j = i + 1;
            while(a[j] == a[i] && j < n){
                a[j] = INT_MIN;
                j++;
            }
            i = j;
        }
    }

    for(auto x : a){
        if(x != INT_MIN){
            cout << x << ' ';
        }
    }
}

vector<int> io(){
    int n = 0;
    cin >> n;
    
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    return a;
}

int main(){    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<int>a = io();
    solve(a);
    return 0;
}
