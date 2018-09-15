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
using namespace std;
unsigned long long int lastdigit(unsigned long long int num)
{
	vector<int>table;
	table.resize(21);//hash like method base on number theory
	table[0] = 0;
	table[1] = 1;
	table[2] = 4;
	table[3] = 7;
	table[4] = 6;
	table[5] = 5;
	table[6] = 6;
	table[7] = 3;
	table[8] = 6;
	table[9] = 9;
	table[10] = 0;
	table[11] = 1;
	table[12] = 6;
	table[13] = 3;
	table[14] = 6;
	table[15] = 5;
	table[16] = 6;
	table[17] = 7;
	table[18] = 4;
	table[19] = 9;
	table[20] = 0;
	return table[(num % 20)];
}
int main()
{
	unsigned long long int ans , ten, one, last2=0;
	string lastdig, num;
	while (cin >> num)
	{
		if (num == "0")
			break;

		ans = 0;
		ten = 0;
		one = 0;
		if(num.size()>=2)
			ten = (num[num.size() - 2] - '0') * 10;
		
		one = (num[num.size() - 1] - '0');
		last2 = ten + one;
		for (int i = 1; i <= last2; i++)
		{
			ans += lastdigit(i);
		}
		cout<< ans % 10 << endl;

	}
	return 0;
}