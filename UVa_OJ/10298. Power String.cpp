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
string str;
void kmp()
{
	vector<int>fail;
	fail.resize(str.size());
	for (int i = 0; i < fail.size(); i++)
	{
		fail[i] = 0;
	}
	int i=0, j=1;
	while (j < str.size())
	{
		if (str[i] == str[j])
		{
			fail[j] = i + 1;
			i++;
			j++;
		}
		else
		{
			if (i==0)
			{
				fail[j] = 0;
				j++;
			}
			else
			{
				i = fail[i-1];
			}
		}	
	}
	int maxfail=0;
	maxfail = fail.size() - fail[fail.size() - 1];// Tricky
	if (str.size() % (maxfail))
	{
		cout << 1 << endl;
	}
	else
	{
		cout << str.size() / (maxfail) << endl;
	}
}
int main()
{
	
	while (getline(cin, str))
	{
		if (str == ".")
		{
			break;
		}
		else
		{
			kmp();
		}
	}
	return 0;
}
