class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int res = nums[0];
        int tmp_res = nums[0];
        for(int i = 1; i < n; i++){
            tmp_res = max(tmp_res + nums[i], nums[i]);
            res = max(res, tmp_res);
        }
        return res;
    }
};