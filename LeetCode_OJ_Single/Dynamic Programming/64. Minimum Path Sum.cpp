#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include <string>
#define MAXN 1010000
#define LL long long
#define ll __int64
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
using namespace std;
int dpgrid(vector<vector<int> > &grid)
{
	vector<vector<int> >dplist(grid.size(), vector<int>(grid[0].size()));//2d vector initialization
	dplist[0][0] = grid[0][0]; //very first initialization value
	for (int row = 1; row < grid.size(); row++) //row dplist value initialization for left
	{
		dplist[row][0] = dplist[row - 1][0] + grid[row][0];//last+current
	}

	for (int col = 1; col < grid[0].size(); col++) //col dplist value initialization for up
	{
		dplist[0][col] = dplist[0][col-1] + grid[0][col];//last+current
	}

	for (int row = 1; row < grid.size(); row++) //travelling and dp
		for (int col = 1; col < grid[0].size(); col++)
			dplist[row][col] = min(dplist[row - 1][col], dplist[row][col - 1]) + grid[row][col]; //last(subproblem)+current

	return dplist[grid.size() - 1][grid[0].size() - 1];//destination dp result
}
int main()
{
	int tc,row,col,tmp; 
	cin >> tc;
	while (tc--)
	{
		cin >> row >> col;
		vector<vector<int> >grid(row,vector<int>(col));
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				cin >> tmp;
				grid[i][j] = tmp;
			}
		
		cout << dpgrid(grid)<<endl;
	}
	return 0; 
}