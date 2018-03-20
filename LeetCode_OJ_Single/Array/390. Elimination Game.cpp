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

using namespace std;
class Solution {
public:
	int lastRemaining(int n)
	{

		vector<int>data;
		vector<bool>alive;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			data.push_back(i + 1);
			alive.push_back(true);
		}
		int border = data.size(), tr_cnt = 0;
		while (border != 1)
		{

			if (!flag)
			{
				for (int i = 0; i < data.size();)
				{
					if (alive[i])
					{
						tr_cnt++;
						if (tr_cnt % 2)
						{
							alive[i] = false;
						}
					}
					i++;
				}
			}
			if (flag)
			{
				for (int i = data.size()-1; i >=0;)
				{
					if (alive[i])
					{
						tr_cnt++;
						if (tr_cnt % 2)
						{
							alive[i] = false;
						}
					}
					i--;
				}
			}
			flag = !flag;
			tr_cnt = 0;
			border /= 2;
		}
		int return_index;
		for (int i = 0; i < data.size(); i++)
		{
			if (alive[i])
				return_index=i;
		}
		return data[return_index];
	}
};

int main()
{
	Solution sol;
	int tmp;
	cin >> tmp;
	cout << sol.lastRemaining(tmp);

	return 0;
}
