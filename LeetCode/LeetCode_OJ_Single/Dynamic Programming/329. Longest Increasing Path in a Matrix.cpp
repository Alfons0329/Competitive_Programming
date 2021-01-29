class Solution {
public:
    int res;
    int row, col;
    int dp[500][500];
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};
    
    int longestIncreasingPath(vector<vector<int>>& m) {
        res = 0;
        row = m.size();
        if(!row){
            return 0;
        }
        col = m[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                // search the increasing path from the starting point i, j
                dfs(m, i, j);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int> >& m, int& i, int& j){
        // scan its 4 direction neighbour
        if(dp[i][j]){
            return dp[i][j];
        }
        
        dp[i][j] = 1;
        for(int d = 0; d < 4; d++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if(ni < 0 || ni >= row || nj < 0 || nj >= col){
                continue;
            }
            else if(m[ni][nj] > m[i][j]){
                dp[i][j] = max(dp[i][j], 1 + dfs(m, ni, nj));
            }
        }
        
        return dp[i][j];
    }
};