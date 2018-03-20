#include <iostream>
using namespace std;
void smoke(unsigned long long int  n, unsigned long long int  k)
{
	unsigned long long int sum = 0;
	sum += n;
	while (n/k)
	{
		sum += n / k;
		n = n / k + n%k;
	}
	cout << sum << endl;
}
int main()
{
	unsigned long long int  n, k;
	while (cin >> n >> k)
	{
		smoke(n, k);
	}
	return 0;
}
