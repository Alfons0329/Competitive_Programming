#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divandcounq(int start,int endp/*endpoint since end is preserved key*/,vector<int>& nums)
    {
        if(start=endp) //arr.size()=1, kind of special judge
        {
            return nums[start];
        }
        else
        {
            int mid=(start+endp)/2;
            int leftmax=divandcounq(start,mid-1,nums);  //left recursion
            int rightmax=divandcounq(mid,endp,nums);   //right recursion
            int crossmax=getcross(start,mid,endp,nums);  //get cross
            return max(max(leftmax,rightmax),crossmax);  //retrun the max value
        }
    }
    int getcross(int start,int mid,int endp,vector<int>& nums)
    {
        int lefttmpsum=0,leftmax=INT_MIN; //leftcross side accumulation
        for(int i=mid-1;i>=start;i--)
        {
            lefttmpsum+=nums[i];
            leftmax=max(leftmax,lefttmpsum);
        }

        int righttmpsum=0,rightmax=INT_MIN; //rightcross side accumulation
        for(int i=mid;i<=endp;i++)
        {
            righttmpsum+=nums[i];
            rightmax=max(rightmax,righttmpsum);
        }
        return max(max(leftmax,rightmax),leftmax+rightmax);
    }
    int maxSubArray(vector<int>& nums)
    {
        if(nums.size()==1)
            return nums[0];
        else
            return divandcounq(0,nums.size()-1,nums);
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
