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
using namespace std;
int dplcs(string s1, string s2)
{
	vector<vector<int> > dplist(s1.length() + 1, vector<int>(s2.length() + 1));//2d dp array for character matching increase by one for convenience
	//dplist initialization
	for (int i = 0; i < dplist.size(); i++)
		for (int j = 0; j < dplist[i].size(); j++)
			dplist[i][j] = 0;

	for (int i = 0; i < dplist.size(); i++)
		dplist[i][0] = 0;
	for (int i = 0; i < dplist[0].size(); i++)
		dplist[0][i] = 0;

	//dp
	for (int i = 1; i <= s1.length(); i++)
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dplist[i][j] = dplist[i - 1][j - 1] + 1;
			}
			else
			{
				dplist[i][j] = max(dplist[i - 1][j], dplist[i][j - 1]); //from previous step, taking the best case
			}
		}

	return dplist[s1.length()][s2.length()];
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << dplcs(s1, s2)<<endl;
	}
	return 0;
}