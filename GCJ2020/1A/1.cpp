#include <bits/stdc++.h>

using namespace std;

int T, I, n;
string res;
vector<string> v;
vector<pair<string, string> > ps; // prefix suffix

void input(){
    cin >> n;
    v.clear();
    v.resize(n);
    ps.clear();
    ps.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
}

void solve(){
    string pfx = "", sfx = "";
    for(int i = 0; i < n; i++){
        int k = 0;
        while(k <= v[i].size() && v[i][k] != '*'){
            k++;
        }
        pair<string, string> p;
        p.first = v[i].substr(0, k);
        if(p.first.size() > pfx.size()){
            pfx = p.first;
        }

        k = v[i].size();
        while(k >= 0 && v[i][k - 1] != '*'){
            k--;
        }
        p.second = v[i].substr(k, v[i].size() - k);
        if(p.second.size() > sfx.size()){
            sfx = p.second;
        }
        ps[i] = p;
        // cout << "pfx " << pfx << " sfx " << sfx << '\n';
    }

    for(int i = 0; i < n; i++){
        // prefix mismatch
        // cout << "maxpfx " << pfx << " max suffix " << sfx << " psif " << ps[i].first << " psis " << ps[i].second << '\n';
        if(ps[i].first.size() && pfx.substr(0, ps[i].first.size()) != ps[i].first){
            // cout << "pfx mismatch " << pfx.substr(0, ps[i].first.size()) << " , " << ps[i].first << '\n';
            cout << "Case #" << I << ": *" << '\n';
            return;
        }
        // suffix mismatch
        if(ps[i].second.size() && sfx.substr(sfx.size() - ps[i].second.size(), ps[i].second.size()) != ps[i].second){
            // cout << "sfx mismatch " << sfx.substr(sfx.size() - ps[i].second.size(), ps[i].second.size()) << " , " << ps[i].second << '\n';
            cout << "Case #" << I << ": *" << '\n';
            return;
        }
    }

    res = pfx;

    for(string s : v){
        for(char c : s){
            if(c != '*'){
                res += c;
            }
        }
    }

    for(char c : sfx){
        res += c;
    }

    cout << "Case #" << I << ": " << res << '\n';
}

int main(){
    cin >> T;
    while(++I <= T){
        input();
        solve();
    }
    return 0;
}
