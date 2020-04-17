class Solution {
public:
    int row, col;
    int numIslands(vector<vector<char>>& grid) {
      
/*
res = 3
22000
22000
00200
00022
*/
        row = grid.size();
        if(!row){
            return 0;
        }
        col = grid[0].size();
        int res = 0;
        for(int i = 0; i <row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        
        return res;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1'){
            return; 
        }
        
        grid[i][j] = '2';
        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
    }
};