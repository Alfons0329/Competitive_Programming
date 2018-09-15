#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDerangement(int n)
    {
        vector<unsigned long long int> der(n+1,0);
        der[0] = 1;
        der[1] = 0;
        der[2] = 1;
        for (int i=3; i<=n; ++i)
            der[i] = (i-1)*(der[i-1] + der[i-2])%1000000007;//dont forget to mod or it will overflow at testcase n = 21;
        ;
        return der[n]%1000000007;
    }
};
int  main(int argc, char const *argv[])
{
    Solution sol;
    int test;
    cin>>test;
    cout<<sol.findDerangement(test)<<endl;
    return 0;
}
