#include <bits/stdc++.h>
const int maxn = 2e6 + 5;
const char aa = 'A';

using namespace std;

string s;
int T, n, k, kase;
int tot, res;
int trie[maxn][26];
int cnt[maxn], len[maxn];

void insert(){
    int n = s.size(), root = 0;
    for(int i = 0; i < n; i++){
        // not exist, insert it
        if(!trie[root][s[i] - aa]){
            trie[root][s[i] - aa] = ++tot;
        }
        // descend trie
        root = trie[root][s[i] - aa];
        // calculate the matched occurrence
        cnt[root]++;
        // calculate the matched length
        len[root] = i + 1;
    }
}

int dfs(int u, int sum){
    for(int i = 0; i < 26; i++){
        if(trie[u][i]){
            sum += dfs(trie[u][i], 0);
            trie[u][i] = 0;
        }
    }

    // check how many group we can have a match
    int tmp = (cnt[u] - sum) / k;
    if(tmp){
        // matched prefix len for all member string in group at the same time
        res += tmp * len[u];
        // at the same time, use such amount of inserted string
        sum += tmp * k;
    }
    cnt[u] = 0;
    len[u] = 0;

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> n >> k;
        tot = 0;
        res = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            insert();
        }
        dfs(0, 0);
        cout << "Case #" << ++kase << ": " << res << endl;
    }

    return 0;
}
