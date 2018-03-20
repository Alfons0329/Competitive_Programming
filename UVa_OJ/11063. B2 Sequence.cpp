#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool b2seq(vector<int>nums)
{
    vector<int>res;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i;j<nums.size();j++)
        {
            res.push_back(nums[i]+nums[j]);
        }
    }
    sort(res.begin(),res.end());
    int flag=1;

    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]<=nums[i])
                flag=0;
        }
    }

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<1)
            flag=0;
    }

    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i]==nums[i+1])
            flag=0;
    }

    for(int i=0;i<res.size()-1;i++)
    {
        if(res[i]==res[i+1])
            flag=0;
    }
    return (flag)?1:0;
}
int main()
{
    int tc,tmp,cnt=1;
    vector<int>nums;
    while(cin>>tc)
    {
        while(tc--)
        {
            cin>>tmp;
            nums.push_back(tmp);
        }
        if(b2seq(nums))
            printf("Case #%d: It is a B2-Sequence.\n",cnt);
        else
            printf("Case #%d: It is not a B2-Sequence.\n",cnt);

        cnt++;
        cout<<endl;
        nums.clear();
    }
    return 0;
}
