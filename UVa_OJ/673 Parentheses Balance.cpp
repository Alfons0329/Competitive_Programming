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
int main()
{
	int tc,fail;
	cin >> tc;
	string tmp;
	stack<char>st;
	while (tc--)
	{
		char topele;
		fflush(stdin);
		getline(cin, tmp);
		fail = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == '(' || tmp[i] == '[')
			{
				st.push(tmp[i]);
			}
			else if (tmp[i] == ')' || tmp[i] == ']')
			{
				if (st.size() >= 1)
				{
					topele = st.top();
					if (topele == '('&&tmp[i] == ']')
					{
						fail = 1;
					}
					if (topele == '['&&tmp[i] == ')')
					{
						fail = 1;
					}
					st.pop();
				}
				else
				{
					fail = 1;
				}
			}
		}
		if (!st.empty())
			fail = 1;

		if (fail)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}