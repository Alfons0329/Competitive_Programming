class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // init
        int row = grid.size();
        if(!row){
            return 0;
        }
        int col = grid[0].size();
        for(int i = 0; i < row; i++){
            grid[i][0] = i == 0 ? grid[i][0] : grid[i - 1][0] + grid[i][0];
        }
        for(int j = 0; j < col; j++){
            grid[0][j] = j == 0 ? grid[0][j] : grid[0][j - 1] + grid[0][j];
        }
        // do dp
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
            }
        }
        
        return grid[row - 1][col - 1];
    }
};