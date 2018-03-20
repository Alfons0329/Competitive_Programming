#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxval=INT_MIN,tmpsum=0;
        for(int i=0;i<nums.size();i++)// Kanede's algorithm
        {
            //Two types of accumulation during the loop
            //If tempsum+current iterated number is smaller then the current iterated number
            //, then we restart from here
            //otherwise just keep accumulation
            tmpsum=max(tmpsum+nums[i],nums[i]);

            //Update the maxvalue (Either restart or accumulated)
            maxval=max(maxval,tmpsum);
        }

        return maxval;
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
