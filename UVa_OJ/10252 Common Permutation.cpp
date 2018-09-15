#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;
void cnt(string s1, string s2)
{
	vector<int>s1v(26, 0);
	vector<int>s2v(26, 0);
	vector<char>perm;
	for (int i = 0; i < s1.size(); i++)
	{
		s1v[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		s2v[s2[i] - 'a']++;
	}
	for (int i = 0; i <26; i++)
	{
		if (s1v[i] && s2v[i])
		{
			for (int j = 0; j < min(s1v[i], s2v[i]); j++)
			{
				perm.push_back(i + 'a');
			}
			
		}
	}
	for (int i = 0; i < perm.size(); i++)
	{
		cout << perm[i];
	}
	cout << endl;
}
int main()
{
	string s1, s2;
	while (getline(cin,s1))
	{
		getline(cin,s2);
		cnt(s1, s2);
	}
	return 0;
}