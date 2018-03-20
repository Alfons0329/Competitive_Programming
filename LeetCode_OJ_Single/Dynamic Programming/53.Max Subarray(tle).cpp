#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        vector<int>res(nums.size(),-99999999);

        for(int i=0;i<nums.size();i++)
            res[i]=nums[i];
        for(int i=0;i<nums.size();i++)
        {
            int tempsum=nums[i];

            for(int j=i+1;j<nums.size();j++)
            {
                tempsum+=nums[j]; //accumulate
                res[j]=max(tempsum,res[j]); //dynamic programming
            }
        }
        sort(res.begin(),res.end());
        return res.back();
    }
};
int main()
{
    Solution sol;
    vector<int> nums;
    int tmp;
    while(scanf("%d",&tmp)!=EOF)
    {
        nums.push_back(tmp);

    }
    cout<<sol.maxSubArray(nums)<<endl;
    nums.clear();
    return 0;
}
