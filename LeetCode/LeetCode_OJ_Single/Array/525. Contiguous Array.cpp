// Time O(N), Space O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // [1,0,1,1,0,0] --> answer will be 6 
        // <key = freq diff, value = position of first time such freq diff occurrs>
        // freq is freq0 - freq1
        // m[0] = 0  --> update result to res = max(res, 6 - 0) = 6
        // m[-1] = 1 --> update tesult to res - max(res, 3 - 1) = 2
        // m[-2] = 4
        // m[]
        // m[]
        
        int n = nums.size();
        int c1 = 0, c0 = 0; // c1 is the freq of 1, and c2 is the freq of 0
        int res = 0;
        unordered_map<int, int>u;
        u[0] = 0; // m[0] = 0  
        
        for(int i = 1; i <= n; i++){
            c1 += nums[i - 1] == 1;
            c0 += nums[i - 1] == 0;
            int d = c0 - c1;
            if(u.count(d)){
                res = max(res, i - u[d]);
            }
            else{
                u[d] = i;
            }
        }
        
        return res;
    }
};