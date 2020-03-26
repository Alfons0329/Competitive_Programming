#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, p, k, cnt = 1, tmp;
    cin >> T;
    while (T--) {
        cin >> n >> k >> p;
        int dp[55][1505] = {0};                            // answer
        vector<vector<int>> pfx(55, vector<int>(1505, 0)); // prefix sum

        for (int i = 0; i < n; i++){
            for (int j = 1; j <= k; j++){
                cin >> tmp;
                pfx[i][j] = pfx[i][j - 1] + tmp;
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 1; j <= k; j++){
                for (int l = 0; l + j <= p; l++){
                    dp[i][l + j] = max(dp[i][l + j], max(dp[i - 1][l + j], dp[i - 1][l] + pfx[i][j]));
                }
            }
        }
        cout << "Case #" << cnt++ << ": " << dp[n - 1][p] << '\n';
    }

    return 0;
}
