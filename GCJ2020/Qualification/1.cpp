#include <bits/stdc++.h>

using namespace std;

int m[100][100];
int T, I, n, k, r, c;

void input(){
    memset(m, 0, sizeof(m));
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> m[i][j];
        }
    }
}

void solve(){
    k = r = c = 0;
    for(int i = 0; i < n; i++){
        set<int> row_ele;
        for(int j = 0; j < n; j++){
            if(i == j){
                k += m[i][j];
            }
            row_ele.insert(m[i][j]);
        }
        r += (row_ele.size() != n);
    }
    for(int j = 0; j < n; j++){
        set<int> col_ele;
        for(int i = 0; i < n; i++){
            col_ele.insert(m[i][j]);
        }
        c += (col_ele.size() != n);
    }
    printf("Case #%d: %d %d %d\n", I, k, r, c);
}

int main(){
    cin >> T;
    while(++I <= T){
        input();
        solve();
    }
    return 0;
}
