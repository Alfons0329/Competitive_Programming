class TreeAncestor {
private:
    int dp[50005][26];
public:
    TreeAncestor(int n, vector<int>& p) {
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; i++){
            dp[i][0] = p[i];
        }
        for(int j = 1; j <= 25; j++){
            for(int i = 0; i < n; i++){
                dp[i][j] = dp[i][j - 1] >= 0 ? dp[dp[i][j - 1]][j - 1] : -1;
            }
        }
    }
    
    int getKthAncestor(int val, int k) {
        for(int i = 0; i <= 25; i++){
            if(k & (1 << i)){
                val = dp[val][i];
            }
            if(val == -1){
                return -1;
            }
        }
        
        return val;
    }
};
