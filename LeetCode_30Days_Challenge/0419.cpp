class Solution {
public:
    int search(vector<int>& nums, int target) {
        // init some required var
        int n = nums.size();
        if(!n){
            return -1;
        }
        // find the break point which is not ascending
        int bp = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                bp = i;
                break;
            }
        }
        // BS the left part [0 : bp + 1)
        int l = 0, r = bp, m = 0, res = -1;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] == target){
                res = m;
                break;
            }
            else if(target > nums[m]){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        // if found
        if(res >= 0){
            return res;
        }
        // BS the right part [bp + 1 : )
        l = bp + 1;
        r = n - 1;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] == target){
                res = m;
                break;
            }
            else if(target > nums[m]){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return res;
    }
};