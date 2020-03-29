class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), a = 1;
        int right = 1;
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++){
            a *= nums[i];
            res[i] = a;
        }
        
        
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1){
                res[i] = res[i - 1];
                right *= nums[i];
            }
            else if(i == 0){
                res[i] = right;
            }
            else{
                res[i] = res[i - 1] * right;
                right *= nums[i];
            }
        }
        
        return res;
    }
};