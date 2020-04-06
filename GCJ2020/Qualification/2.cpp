#include <bits/stdc++.h>

using namespace std;

int T, I, n;
int cnt;
string s, res, l, r, tmp;
vector<string> v;

void io(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
}

void input(){
    cin >> s;
    s += 'Z';
}

void solve(){
    string tmp;
    res = tmp = "";
    cnt = 0;    
    v.clear();
    n = s.size();

    v.emplace_back("0");
    for(int i = 0; i < n - 1; i++){
        tmp += s[i]; 
        if(s[i] ^ s[i + 1]){
           v.emplace_back(tmp); 
           tmp = "";
        }
    }
    v.emplace_back("0");

    for(int i = 0;i < v.size() - 1; i++){
        int l = v[i][0] - '0', r = v[i + 1][0] - '0';
        int diff = l - r;
        string ls = (i) ? v[i] : "", rs = v[i + 1];
        for(int i = 0; i < abs(diff); i++){
            if(diff > 0){
                ls = ls + ")";
            }
            else if(diff < 0){
                ls = ls + "(";
            }
        }
        res += ls;
    }

    cout << "Case #" << I << ": " << res << '\n';
}

int main(){
    io();

    cin >> T;
    while(++I <= T){
        input();
        solve();
    }

    return 0;
}
