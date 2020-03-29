class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj_ele = nums[0], maj_cnt = 0;
        
        for(int i = 1; i < n; i++){
            if(maj_ele == nums[i]){
                maj_cnt++;
            }
            else{
                if(maj_cnt){
                    maj_cnt--;
                }
                else{
                    maj_ele = nums[i];
                }
            }
        }
        
        return maj_ele;
    }
};