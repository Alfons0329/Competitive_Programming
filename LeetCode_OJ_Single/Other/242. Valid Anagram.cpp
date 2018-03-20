#include <stack>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#define MAXN 1010000
#define LL long long
#define ll __int64
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(is_permutation(s1.begin(),s1.end(),s2.begin()))
    {
        cout<<true;
    }
    else
        cout<<false;
    return 0;
}
