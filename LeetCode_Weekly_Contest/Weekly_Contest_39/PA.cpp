#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c)
    {
        int s=sqrt(c);
        for(int i=0;i<=s;i++)
        {
            int remain=c-i*i;
            if(remain>=0) //keep substracting
            {
                int s2=sqrt(remain);
                if(s2*s2+i*i==c)//check for a^2+b^2=c
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
int  main(int argc, char const *argv[])
{
    Solution sol;
    int test;
    cin>>test;
    cout<<sol.judgeSquareSum(test)<<endl;
    return 0;
}
