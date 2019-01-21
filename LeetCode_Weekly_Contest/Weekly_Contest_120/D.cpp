class Solution 
{
public:
    // If steps = 0 grid, that is the solution
    int zcnt = 0, res = 0;
    int rt = 0, ct = 0;
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        rt = grid.size(), ct = grid[0].size();
        int sr = 0, sc = 0;
        for(int r = 0; r < rt; r++)
        {
            for(int c = 0; c < ct; c++)
            {
                if(grid[r][c] == 1)
                {
                    sr = r;
                    sc = c;
                }
                else if(grid[r][c] == 0)
                {
                    zcnt++;
                }
            }
        }
        dfs(grid, sr, sc, 0);
        return res;
    }
    void dfs(vector<vector<int>>& grid, int row , int col, int steps)
    {
        if(row < 0 || row >= rt || col < 0 || col >= ct || grid[row][col] < 0) //illegal position
        {
            return;
        }
        
        if(grid[row][col] == 2) //reached the target position with steps = zcnt
        {
            if(steps - 1 == zcnt)
            {
                res++;
            }
            return;
        }
        grid[row][col] = -2; //marked as traversed
        // 4 sides
        dfs(grid, row - 1, col, steps + 1); //U
        dfs(grid, row + 1, col, steps + 1); //D
        dfs(grid, row, col - 1, steps + 1); //L
        dfs(grid, row, col + 1, steps + 1); //R
        
        grid[row][col] = 0; //marked as untraversed, back tracking again
    }
};