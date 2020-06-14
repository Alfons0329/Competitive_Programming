int dir[4][2]  = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // u d l r
class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int res = 0, has_0 = 0;
        int row = grid.size(), col = grid[0].size();
        int dp [100][100] = {0};
        
        queue<pair<int, int>> q;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                }
                else
                {
                    has_0 = 1;
                }
            }
        }
             
        if(has_0 == 0 || q.size() == col * row) // all 1 or all 0
        {
            return -1;
        }
        
        int cur_row, cur_col;
        while(q.size())
        {
            cur_row = q.front().first;
            cur_col = q.front().second;
            res = max(res, dp[cur_row][cur_col]);
            // printf("starting from %d, %d \n", cur_row, cur_col);
            q.pop(); // finish dealing that node
            
            int n_row, n_col;
            for(int i = 0; i < 4; i++) // dir
            {
                n_row = cur_row + dir[i][0];
                n_col = cur_col + dir[i][1];
                if(n_row >= 0 && n_row < row && n_col >= 0 && n_col < col && grid[n_row][n_col] == 0 && dp[n_row][n_col] == 0) // in the grid and is water and unvisited 
                {
                    // printf("update neighbour %d, %d as %d + 1 \n", n_row, n_col, dp[cur_row][cur_col] + 1);
                    dp[n_row][n_col] = dp[cur_row][cur_col] + 1; // update dist for touched part
                    q.push({n_row, n_col}); // push node that can be visited
                }
            }
        }
       
        return res == 0 ? -1 : res;
    }
};