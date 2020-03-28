class Solution {
public:
    int row, col, res, tmp_res;
    int maxAreaOfIsland(vector<vector<int>>& m) {
        row = m.size();
        col = m[0].size();
        res = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(m[i][j] == 1){
                    tmp_res = 1;
                    dfs(i, j, m);
                    res = max(res, tmp_res);
                }
            }
        }
        
        return res;
    }
    
    int dfs(int i, int j, vector<vector<int> >& m){
        if(i < 0 || i >= row || j < 0 || j >= col || m[i][j] != 1){
            return 0;
        }
        
        m[i][j] = 2;
        tmp_res += dfs(i - 1, j, m); // U 
        tmp_res += dfs(i + 1, j, m); // D 
        tmp_res += dfs(i, j - 1, m); // L 
        tmp_res += dfs(i, j + 1, m); // R
        return 1;
    }
};