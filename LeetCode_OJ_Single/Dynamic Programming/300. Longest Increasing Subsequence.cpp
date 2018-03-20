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
//WA [208,6,2,1,5,7,8,4,3,97]
using namespace std;
vector<int>data;
class Solution {
public:
    vector<int>res;
    int lengthOfLIS(vector<int>& nums)
    {
        if(nums.size()==0)//特判
        {
            return 0;
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                res.push_back(1);
            }
            for(int i=0;i<nums.size();i++)
            {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i])
                {
                    res[j]=max(res[j],res[i]+1);
                }

            }
            }

            sort(res.begin(),res.end());
            return res.back();
        }

    }

};
int main()
{
    Solution sol;
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        int tmp;
        cin>>tmp;
        data.push_back(tmp);
    }
    cout<<sol.lengthOfLIS(data);
    return 0;
}
