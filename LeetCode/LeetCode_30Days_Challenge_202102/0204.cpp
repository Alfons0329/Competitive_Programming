/*
Approach: Use unorder_map to keep tracking the occurrences of each number, and for each number x, x - 1 and x + 1 is the allowed margin to be defined as harmonious, so just count the occurrence before if any of them (low or high) has occurred before.

Time:O(N)
Space:O(N)
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> um;
        
        for(int x :nums){
            um[x]++;
            int low_cnt = um[x - 1];
            int high_cnt = um[x + 1];
            if(low_cnt || high_cnt){
                res = max(res, max(um[x] + low_cnt, um[x] + high_cnt));
            }
        }
        
        return res;
    }
