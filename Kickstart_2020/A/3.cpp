#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

using namespace std;

int T, n, m, kase, res; 
int a[maxn];

int solve(){
    int res = INT_MIN;
    priority_queue<int, vector<int>>pq;
    for(int i = 0; i < n - 1; i++){
        pq.push(a[i + 1] - a[i]);
    }

    while(m--){
        int mxm = pq.top();
        if(mxm == 1){
            break;
        }
        int p1 = mxm / 2, p2 = mxm - p1;
        // printf("mxm %d p1 %d p2 %d \n", mxm, p1, p2);
        pq.pop();
        pq.push(p1);
        pq.push(p2);
    }

    return pq.top();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(a, 0 , sizeof(a));
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << "Case #" << ++kase << ": " << solve() << endl;
    }

    return 0;
}
