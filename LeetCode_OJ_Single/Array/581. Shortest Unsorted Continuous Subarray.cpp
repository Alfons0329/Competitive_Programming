class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        unsigned int cnt = 1;
        vector<int>res,res2;
        res = nums;
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++)
        {
            if(res[i] != nums[i])
            {
                res2.push_back(i);
            }
        }
        return (res2.size()) ? (res2.back()-res2[0]+1) : 0;

    }
};
