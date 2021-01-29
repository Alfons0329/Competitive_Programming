class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int max_endhere = nums[0], max_endhere_bk = 0;
        int min_endhere = nums[0];
        
        for(int i = 1; i < n; i++){
            res = max(nums[i], max(res, max(max_endhere * nums[i], min_endhere * nums[i])));
            max_endhere_bk = max_endhere;
            max_endhere = max(nums[i], max(max_endhere * nums[i], min_endhere * nums[i]));
            min_endhere = min(nums[i], min(max_endhere_bk * nums[i], min_endhere * nums[i]));
        }
        
        return res;
    }
};
