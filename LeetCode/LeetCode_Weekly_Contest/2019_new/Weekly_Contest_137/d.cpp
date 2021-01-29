class Solution {
    public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int n = stones.size();
        if(n == 1)
        {
            return stones[0];
        }
        
        bool dp[102][30002] = {0}; // combination of sum (col) up of stones from 0...i (row)
        int res = INT_MAX, sum = 0;
        for(int i = 0; i <= n; i++) // sum to be 0, the combinations definitely match
        {
            dp[i][0] = 1;
            if(i < n)
            {
                sum += stones[i];
            }
        }
        
        for(int i = 1; i <= n; i++) // all combination for problem input
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j < stones[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]];
                }
            }
        }
        
        
        for(int j = sum / 2; j <= sum; j++)
        {
            if(2 * j - sum >= 0 && dp[n][j])
            {
                res = min(res, 2 * j - sum);
                break;
            }
        }
        return res;
    }
};
