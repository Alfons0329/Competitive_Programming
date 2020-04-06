#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;

const int maxn = 1445;
int T, I, n, st, et, st_min, et_max;
int ok;
int a[maxn];
int who[maxn];
string res;
vector<pair<pii, int> > v;
vector<char> todo;

void io(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
}

bool cmp(pair<pii, int> p1, pair<pii, int> p2){
    return p1.fi.fi < p2.fi.fi;
    // return p1.fi.se - p1.fi.fi > p2.fi.se - p2.fi.fi; 
}

void input(){
    cin >> n;
    memset(a, 0, sizeof(a));
    v.clear();
    ok = 1;

    for(int i = 0; i < n; i++){
        cin >> st >> et;
        v.push_back({{st, et}, i});
        for(int j = st; j < et; j++){
            a[j]++;
            if(a[j] >= 3){
                ok = 0;
            }
        }
    }
}

void solve(){
    int type = 0; // 1 C, 0 J
    memset(who, 0, sizeof(who));
    if(!ok){
        cout << "Case #" << I << ": " << "IMPOSSIBLE" << '\n';
        return;
    }

    sort(v.begin(), v.end(), cmp);
    todo.clear();
    todo.resize(n);
    for(int i = 0; i < n; i++){
        st = v[i].fi.fi, et = v[i].fi.se;
        int clean = 1;
        for(int j = st; j < et; j++){
            if(who[j]){
                clean = who[j];
                break;
            }
        }

        if(clean > 1){
            for(int j = st; j < et; j++){
                who[j] = clean == 'C' ? 'J' : 'C' ;
            }
            todo[v[i].se] = clean == 'C' ? 'J' : 'C';
        }
        else{
            for(int j = st; j < et; j++){
                who[j] = 'J';
            }
            todo[v[i].se] = 'J';
        }
    }

    cout << "Case #" << I << ": ";
    for(char c : todo){
        cout << c;
    }
    cout << '\n';
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
