#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll inf = 1e13;
int T, I, n;
ll q; // query
ll p[555][555]; // pascal triangle
ll s[555][555]; // sum
string res;

void build(){
    p[1][1] = 1;
    s[1][1] = 1;
    for(int i = 2; i < 555; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1 || j == 1){
                p[i][j] = 1;
            }
            else{
                p[i][j] = min(p[i - 1][j - 1] + p[i - 1][j], inf);
            }
            if(j == 1){
                s[i][j] = 1;
            }
            else{
                s[i][j] = s[i][j - 1] + p[i][j];
            }
        }
    }
}


void solve(){
    printf("Case #%d:\n", I);
    int i = 1, j = 1, step = 0, dir = 0;
    while(1){
        printf("%d %d\n", i, j); 
        q -= p[i][j];
        if(q == 0){
            break;
        }
        else if(q < 0){
            throw;
        }
        if(q >= s[i + 1][j + 1]){
            i++;
            j++;
        }
        else if(q >= s[i + 1][j]){
            i++;
        }
        else if(j > 0 && q >= s[i][j - 1]){
            // remove at once if such row's binary sum is greater
            j--;
        }
    }
}

int main(){
    cin >> T;
    build();
    while(++I <= T){
        cin >> q;
        solve();
    }
    return 0;
}
