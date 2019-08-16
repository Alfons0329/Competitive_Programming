ass Solution {
    public:
        int movesToMakeZigzag(vector<int>& nums) 
        {
            int n = nums.size();
            int res1 = 0, res2 = 0;
            vector<int> type(n), nums2 = nums;

            int now = 0; // > < > <
            for(int i = 0; i < n - 1; i++)
            {
                if(nums[i] <= nums[i + 1] && now == 0)
                {
                    res1 += abs(nums[i] - nums[i + 1]) + 1;
                    nums[i + 1] -= abs(nums[i] - nums[i + 1]) + 1;
                }
                else if(nums[i] >= nums[i + 1] && now == 1)
                {
                    res1 += abs(nums[i] - nums[i + 1]) + 1;
                }
                now ^= 1;

            }

            now = 1;
            nums = nums2;
            for(int i = 0; i < n - 1; i++)
            {
                if(nums[i] <= nums[i + 1] && now == 0)
                {
                    res2 += abs(nums[i] - nums[i + 1]) + 1;
                    nums[i + 1] -= abs(nums[i] - nums[i + 1]) + 1;
                }
                else if(nums[i] >= nums[i + 1] && now == 1)
                {
                    res2 += abs(nums[i] - nums[i + 1]) + 1 ;
                }
                now ^= 1;

            }
            for(auto x : nums)
            {
                printf("%d,", x);

            }
            return min(res1, res2);
        }
};
