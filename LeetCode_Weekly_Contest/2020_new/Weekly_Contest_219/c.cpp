class Solution {
public:
    int stoneGameVII(vector<int>& s) {
        int n = s.size(), res = 0;
        vector<int>p(n); // prefix sum
        p[0] = s[0];
        for(int i = 1; i < n; i++){
            p[i] = s[i] + p[i - 1];
        }
        
        int dp[1005][1005];
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j < n; j++){
            for(int i = j; i >= 0; i--){
                int remove_left = p[j] - p[i];
                int remove_right = i - 1 < 0 ? p[j - 1] : p[j - 1] - p[i - 1];
                dp[i][j] = max(remove_left - dp[i + 1][j], remove_right - dp[i][j - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
