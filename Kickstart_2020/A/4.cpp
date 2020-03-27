#include <bits/stdc++.h>
const int MAX_N = 2e6 + 5;
const char aa = 'A';

using namespace std;

string s;
int T, n, k, kase;
int tot, res;
int trie[MAX_N][26];
int cnt[MAX_N], len[MAX_N];

void insert(){
    int n = s.size(), root = 0;
    cout << "insert " << s << '\n';
    for(int i = 0; i < n; i++){
        // not exist, insert it
        if(!trie[root][s[i] - aa]){
            trie[root][s[i] - aa] = ++tot;
        }
        // descend trie
        root = trie[root][s[i] - aa];
        cnt[root]++;
        len[root] = i + 1;
    }


    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 26; j++){
            cout << trie[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < 12; i++){
        cout << cnt[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < 12; i++){
        cout << len[i] << ' ';
    }
    cout << '\n';

}

int dfs(int u, int sum){
    printf("u %d sum %d \n", u, sum);
    for(int i = 0; i < 26; i++){
        if(trie[u][i]){
            sum += dfs(trie[u][i], 0);
            trie[u][i] = 0;
        }
    }

    int tmp = (cnt[u] - sum) / k;
    if(tmp){
        printf("tmp %d cntu %d sum %d res %d \n",tmp , cnt[u], sum, res);
        res += tmp * len[u];
        sum += tmp * k;
    }

    cnt[u] = 0;
    len[u] = 0;
    return res;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin >> T;
    while(T--){
        cin >> n >> k;
        tot = 0;
        res = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            insert();
        }
        cout << "Case #" << ++kase << ": " << dfs(0, 0) << endl;
    }
    return 0;
}
