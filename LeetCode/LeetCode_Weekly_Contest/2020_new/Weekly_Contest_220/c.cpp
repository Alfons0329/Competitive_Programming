class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int dp[100005] = {0};
        int n = nums.size();
        dp[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            int cnt = 1, mxm = dp[i + 1];
            dp[i] = nums[i];
            while(i + cnt < n && cnt <= k){
                mxm = max(mxm, dp[i + cnt]);
                // We can do an early stopping here once we reach the first (and also closest) positive number 
                // Since it will give us the optimial answer that current point can reach to (the farther the point, less optimial it is) 
                if(nums[i + cnt] > 0){
                    break;
                }
                else{
                    cnt++;
                }
            }
            dp[i] = dp[i] + mxm;
        }
        return dp[0];
    }
