class Solution {
    public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        
        if(n == 1)
        {
            return nums[0] == abs(target) ? 1 : 0;
        }
        
        int dp[21][1001] = {0};
        int res = 0, sum = 0;
        sort(nums.begin(), nums.end());
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) // sum to be 0, the combinations definitely match
        {
            dp[i][0] = nums[i - 1] == 0 ? 1 << i : dp[i - 1][0];
            sum += nums[i - 1];
        }

        for(int i = 1; i <= n; i++) // all combination for problem input
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j < nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
        for(int j = 0; j <= sum; j++)
        {
            if(j * 2 - sum == target && dp[n][j])
            {
                res = dp[n][j];
            }
        }
        return res;
    }
};
