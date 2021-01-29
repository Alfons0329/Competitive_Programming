class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>u;
        u[0]++;
        int pfx = 0;
        int res = 0;
        
        
        for(int x : nums){
            pfx += x;
            if(u.count(pfx - k)){
                res += u[pfx - k];
            }
            u[pfx]++;
        }
        
        return res;
    }
};