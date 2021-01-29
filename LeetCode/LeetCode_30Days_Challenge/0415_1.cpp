class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), a = 1;
        vector<int> sfx(n, 0);
        vector<int> pfx(n, 0);
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++){
            a *= nums[i];
            pfx[i] = a;
        }
        a = 1;
        for(int i = n - 1; i >= 0; i--){
            a *= nums[i];
            sfx[i] = a;
        }
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                res[i] = sfx[i + 1];
            }
            else if(i == n - 1){
                res[i] = pfx[i - 1];
            }
            else{
                res[i] = pfx[i - 1] * sfx[i + 1];
            }
        }
        
        return res;
    }
};
