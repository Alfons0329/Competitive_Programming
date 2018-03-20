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

int climbStairs(int n)
{
	static vector<unsigned long long int >dplist(n+1,-1);
	if (n == 1)
		return dplist[0]=1;
	else if (n == 2)
		return dplist[1]=2;
	else
	{
		if (dplist[n] != -1)//solved problem
		{
			return dplist[n];
		}
		dplist[n] = climbStairs(n - 1) + climbStairs(n - 2);//dp fibonacci
		return dplist[n];
	}
}
int main()
{
	int tc;
	while (cin >> tc)
	{
		cout << climbStairs(tc);
	}
	return 0;
}