class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // init
        int res = 0, n = nums.size();
        int pfx = 0; // pfx sum
        unordered_map<int, int> m; // store the prefix sum and its frequency
        // traverse the array, check if either s == target k, or m[prefix_sum[i] - target k] exists and its location is before i
        m[0]++;
        for(int i = 0; i < n; i++){
            pfx += nums[i];
            if(m.find(pfx - k) != m.end()){
                res += m[pfx - k];
            }
            m[pfx]++; // accumulate the frequency up to i
        }
        // return answer
        return res;
    }
};