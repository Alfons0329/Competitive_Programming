#include <bits/stdc++.h>
using namespace std;

int dp[55][1505];
int a[55][35];
int pfx[55][1505];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, p, k, cnt = 1, tmp;
    cin >> T;
    while (T--) {
        cin >> n >> k >> p;

        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(pfx, 0, sizeof(pfx));
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k; j++){
                cin >> a[i][j];
                pfx[i][j] = pfx[i][j - 1] + a[i][j];
            }
        }
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k; j++){
                for (int l = 0; l + j <= p; l++){
                    dp[i][l + j] = max(dp[i][l + j], max(dp[i - 1][l + j], dp[i - 1][l] + pfx[i][j]));
                }
            }
        }

        cout << "Case #" << cnt++ << ": " << dp[n][p] << '\n';
    }

    return 0;
}
