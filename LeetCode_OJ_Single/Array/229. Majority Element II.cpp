const int k = 3;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return nums;
        }
        int maj1 = INT_MAX, maj2 = INT_MAX; 
        int cnt1 = 0, cnt2 = 0;
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == maj1){
                cnt1++;
            }
            else if(nums[i] == maj2){
                cnt2++;
            }
            else if(cnt1 == 0){
                maj1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){
                maj2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0; 
        cnt2 = 0;
        for(int x : nums){
            if(x == maj1){
                cnt1++;
            }
            else if(x == maj2){
                cnt2++;
            }
        }
        
        if(cnt1 > n / 3){
            res.emplace_back(maj1);
        }
        
        if(maj1 != maj2){
            if(cnt2 > n / 3){
                res.emplace_back(maj2);
            }
        }
        
        return res;
    }
};