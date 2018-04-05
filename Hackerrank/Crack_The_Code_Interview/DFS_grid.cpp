#include <bits/stdc++.h>
using namespace std;

void dfs(vector< vector<int> >& grid, int& cnt, int row, int col)
{
    if(grid[row][col] == 1)
    {
        grid[row][col] = 9;
        cnt++;
    }
    else
    {
        return ;
    }
    if(row - 1 >= 0 && grid[row - 1][col] == 1) //dfs up
    {
        dfs(grid, cnt, row - 1, col);
    }
    if(row + 1 < grid.size() && grid[row + 1][col] == 1) //dfs down
    {
        dfs(grid, cnt, row + 1, col);
    }
    if(col - 1 >= 0 && grid[row][col - 1] == 1) //dfs left
    {
        dfs(grid, cnt, row, col - 1);
    }
    if(col + 1 < grid[0].size() && grid[row][col + 1] == 1) //dfs right
    {
        dfs(grid, cnt, row, col + 1);
    }


    if(row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col - 1] == 1) //dfs ul
    {
        dfs(grid, cnt, row - 1, col - 1);
    }
    if(row - 1 >= 0 && col + 1 < grid[0].size() && grid[row - 1][col + 1] == 1) //dfs ur
    {
        dfs(grid, cnt, row - 1, col + 1);
    }
    if(row + 1 < grid.size() && col - 1 >= 0 && grid[row + 1][col  - 1] == 1) //dfs dl
    {
        dfs(grid, cnt, row + 1, col - 1);
    }
    if(row + 1 < grid.size() && col + 1 < grid[0].size() && grid[row + 1][col + 1] == 1) //dfs dr
    {
        dfs(grid, cnt, row + 1, col + 1);
    }
}


int get_biggest_region(vector< vector<int> > grid)
{
    int cnt, max_cnt = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                cnt = 0;
                dfs(grid, cnt, i, j);
                max_cnt = max(max_cnt, cnt);
            }
            else
            {
                continue;
            }
        }
    }
    return max_cnt;
}
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
