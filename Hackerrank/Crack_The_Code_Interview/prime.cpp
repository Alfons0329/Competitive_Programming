#include <bits/stdc++.h>
using namespace std;

bool is_prime(long int num)
{
    if(num == 1)
        return false;
    for(int i = 2;i <= sqrt(num);i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tc;
    long int tmp;
    cin >> tc;
    while(tc--)
    {
        cin >> tmp;
        printf("%s\n",(is_prime(tmp) ? "Prime" : "Not prime"));
    }
    return 0;
}
