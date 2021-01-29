class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), a = 1;
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++){
            a *= nums[i];
            left[i] = a;
        }
        a = 1;
        for(int i = n - 1; i >= 0; i--){
            a *= nums[i];
            right[i] = a;
        }
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                res[i] = right[i + 1];
            }
            else if(i == n - 1){
                res[i] = left[i - 1];
            }
            else{
                res[i] = left[i - 1] * right[i + 1];
            }
        }
        
        return res;
    }
};