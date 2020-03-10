/*
* Step 1: construct a prefix sum
* Step 2: the dp[i][j] means the min of the max sum among j splits in arr[0 to i], 0 and i are inclusive
* Step 3: init dp, init all dp[i][1] to prefix sum, since it does not split (only one group together)
* Step 4: iterating all the dp[i][j] 
for i in [0, n - 1]:
    for j in [2, m]:
        for k in all possible splitting point in (this time we split only once, since the subproblem has been solved)
            [ 0 <- k -> (splitted with j - 1times)| (altogether, so not split)   ]
        max(dp[k][j - 1],                         |prefix_sum[i] - prefix_sum[k]))

* Analysis:
    * Time complexity: O(m * n * n)
    * Space complexoty: O(m * n)
*/
class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();

        vector<unsigned int> prefix_sum(n, 0);
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, INT_MAX));
        prefix_sum[0] = nums[0];
        // Step 1:
        for (int i = 1; i < n; i++){
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        // Step 2, 3:
        for (int i = 0; i < n; i++){
            dp[i][1] = prefix_sum[i];
        }

        dp[0][0] = 0;
        // Step 4
        for (int i = 0; i < n; i++){
            // check all the possible splitting mechanism
            for (int j = 2; j <= m; j++){
                // from 0 to i,
                for (int k = 0; k < i; k++){
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefix_sum[i] - prefix_sum[k]));
                }
            }
        }

        return dp[n - 1][m];
    }
};