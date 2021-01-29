class Solution {
public:
    int row, col;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if(!row){
            return 0;
        }
        col = grid[0].size();
        
        int res = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return res;
    }
    
    void dfs(int i, int j, vector<vector<char> >& grid){
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1'){
            return;
        }
        // mark as visited
        grid[i][j] = '2';
        dfs(i - 1, j, grid); //U
        dfs(i + 1, j, grid); //D
        dfs(i, j - 1, grid); //L
        dfs(i, j + 1, grid); //R
    }
};