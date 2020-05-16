class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        // init
        vector<int> res;        
        int l = 0, r = nums.size() - 1, m = 0;
        // binary search to find find first
        while(l < r){
            m = l + (r - l) / 2;
            if(nums[m] >= target){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        if(nums[l] == target){
            res.emplace_back(l);
        }
        
        l = 0, r = nums.size() - 1;
        while(l < r){
            m = l + (r - l + 1) / 2;
            if(nums[m] <= target){
                l = m;
            }
            else{
                r = m - 1;
            }
        }
        if(nums[l] == target){
            res.emplace_back(l);
        }
        
        if(res.empty()){
            return {-1, -1};
        }
        else{
            return res;
        }
    }
};