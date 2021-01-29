class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // O(N) time and O(1) space
        int res = 0, cnt = 0;
        res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == res){
                cnt++;
            }
            else{
                if(cnt){
                    cnt--;
                }
                else{
                    res = nums[i];// new candidate
                }
            }
        }
        
        return res;
    }
