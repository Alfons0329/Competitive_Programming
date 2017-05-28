//reference : http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[32][2];
    void initialize ()
    {
        dp[0][0]=1;
        dp[0][1]=1;
        for (int i=1;i<32;i++) //fibonacci table using dp 2D
        {
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][0];
        }
    }
    int dodp(int len,int num)
    {
        if(len<=0)
            return 1; //only one for 0

        int tmp=1<<(len-1); //sub query of fibonacci sequence

        if(num>=tmp)
            /*length decrement by one of the binstr of length len with # of non consecutive1's*/
            return dp[len-1][0]+dodp(len-2,num-tmp); //keep on tracking down
        else
            return dodp(len-1,num);//bigger just trace down len-1


    }
    int findIntegers(int num)
    {
        initialize();
        int len=0,tmp=num;
        //get the length of bin str representation of num
        while(tmp>0)
        {
            tmp/=2;
            len++;
        }
        return dodp(len,num);
    }
};
int main()
{
    int num;
    cin>>num;
    Solution sol;
    cout<<sol.findIntegers(num)<<endl;
    return 0;
}
