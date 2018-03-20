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
#include<string>
#define MAXN 1010000
#define LL long long
#define ll __int64
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
using namespace std;

int dpchange(vector<int>& coins, int amount)
{

	vector<int>dplist(amount+1, 0xfffffff);
	dplist[0] = 0;

	for (int i = 0; i < coins.size(); i++)//dp loop
	{
		for (int j = coins[i]; j <= amount; j++)
		{	//solveABLE
			dplist[j] = min(dplist[j], dplist[j - coins[i]] + 1 /*use 1 coin*/);//money change count for current amount (dplist ,take the min to do or not to include
		}
	}
	return dplist[amount] == 0xfffffff/*unable to match*/ ? -1 : dplist[amount];

}
int main()
{
	int coin, amount;
	vector<int> coins;
	cin >> amount;
	while (cin >> coin)
	{
		coins.push_back(coin);
	}
	cout << dpchange(coins, amount);
	//system("pause");
	return 0;
}