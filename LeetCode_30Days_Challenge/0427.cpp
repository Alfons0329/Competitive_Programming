class Solution {
    public:
        int dp[1005][1005];
        int maximalSquare(vector<vector<char>>& m) {
            int row = m.size();
            if(!row){
                return 0;

            }
            int col = m[0].size();

            memset(dp, 0, sizeof(dp));
            int res = 0;

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(i == 0 || j == 0){
                        if(m[i][j] == '1'){
                            res = max(1, res);
                            dp[i][j] = 1;
                        }
                        continue;

                    }
                    else if(m[i][j]== '1'){
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                        res = max(res, dp[i][j] * dp[i][j]);
                    }
                }
            }
            return res;
        }
};
