#define N 100
class Solution 
{
public:
    int find_sq(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ver[N][N] = {0};
        int hor[N][N] = {0};
        hor[0][0] = ver[0][0] = (grid[0][0] == 1);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    ver[i][j] = hor[i][j] = 0; 
                }
                else
                { 
                    hor[i][j] = (j == 0) ? 1 : hor[i][j-1] + 1; 
                    ver[i][j] = (i == 0) ? 1 : ver[i-1][j] + 1; 
                }
            }
        }
        
        int res = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                int small = min (hor[i][j], ver[i][j]);
                while (small > res) 
                { 
                    if (ver[i][j - small + 1] >= small && hor[i - small + 1][j] >= small) 
                    { 
                        res = small;
                    }
                    small--; 
                } 
            }
        }
        return res;
    }
    int largest1BorderedSquare(vector<vector<int>>& grid) 
    {
        int res = find_sq(grid);
        return res == 0 ? 0 : res * res;
    }
};
