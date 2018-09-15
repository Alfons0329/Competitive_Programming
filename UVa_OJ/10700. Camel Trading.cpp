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
#define LL unsigned long long
using namespace std;
void camel(string str)
{
	int  j = 0, cnt, secondstart;
	LL tmp = 0;
	//take the operands and operators first
	char opr[13] = { 0 };
	int num[13] = { 0 };
	//take first num
	for (int i = 0; i < 3; i++)
	{
		if (str[i] == '*' || str[i] == '+')
		{
			cnt = 0;
			opr[0] = str[i];
			for (j = i - 1; j >= 0; j--)
			{
				tmp += (str[j] - '0')*pow(10, cnt);
				cnt++;

				num[0] = tmp;

			}
			secondstart = i + 1;
			break;
		}
	}
	j = 0;
	//take the rest num
	int cnt2 = 0;
	for (int i = secondstart; i < str.size(); i++)
	{
		if (str[i] == '*' || str[i] == '+')
		{
			cnt2++;
			cnt = 0;
			tmp = 0;
			opr[cnt2] = str[i];
			for (j = i - 1; j >= secondstart; j--)
			{
				tmp += (str[j] - '0')*pow(10, cnt);
				cnt++;

				num[cnt2] = tmp;
			}
			secondstart = i + 1;
		}
	}
	//take the last num
	for (int i = str.size() - 1; i >= str.size() - 3; i--)
	{
		if (str[i] == '*' || str[i] == '+')
		{
			cnt2++;
			tmp = 0;
			cnt = 0;
			for (j = str.size() - 1; j > i; j--)
			{
				tmp += (str[j] - '0')*pow(10, cnt);
				cnt++;

				num[cnt2] = tmp;
			}
			break;
		}
	}

	bool flag = false;

	//min

	LL min = 0, max = 1;
	tmp = num[0];
	for (int i = 0; i < 13; i++)
	{
		if (opr[i] ==0)
		{
			break;
		}
		else if (opr[i] == '*')
		{
			tmp *= num[i + 1];
		}
		else
		{
			min += tmp;
			tmp = num[i + 1];
		}
	}
	//lastend
	if (tmp)
		min += tmp;

	//max
	tmp = num[0];
	for (int i = 0; i < 13; i++)
	{
		if (opr[i] ==0)
		{
			break;
		}
		else if (opr[i] == '+')
		{
			tmp += num[i + 1];
		}
		else
		{
			max *= tmp;
			tmp = num[i + 1];
		}
	}
	if (tmp)
		max *= tmp;

	cout << "The maximum and minimum are " << max << " and " << min <<"." <<endl;

}
int main()
{
	int tc;
	string str;
	cin >> tc;
	while (tc--)
	{
		cin >> str;
		camel(str);
	}
	//system("pause");
	return 0;
}