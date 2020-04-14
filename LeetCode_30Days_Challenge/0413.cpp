class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        if(!n){
            return 0;
        }
        
        int cnt0 = 0, cnt1 = 0, d = 0;
        int res = INT_MIN;
        unordered_map<int, int> dm;
        dm[0] = 0;
        
        for(int i = 1; i <= n; i++){
            cnt0 += nums[i - 1] == 0;
            cnt1 += nums[i - 1] == 1;
            d = cnt0 - cnt1;
            if(dm.count(d)){
                res = max(res, i - dm[d]);
            }
            else{
                dm[d] = i;
            }
        }
        
        return res == INT_MIN ? 0 : res;
    }
};