class Solution {
public:
    int search(vector<int>& nums, int target) {
        int bp = 0, n = nums.size();
        if(!n){
            return -1;
        }
        
        // find break point where the sorting rule is violated
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                bp = i;
                break;
            }
        }
        
        // binary search in [0:bp]
        int l = 0, r = bp , m = 0, res = -1;
        while(l <= r){
            m = l + (r - l) / 2; // prevent overflow
            if(nums[m] == target){
                res = m;
                break;
            }
            else if(nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        
        if(res >= 0){
            return res;
        }
        // binary search in [bp:]
        l = bp + 1; 
        r = n - 1;
        while(l <= r){
            m = l + (r - l) / 2; // prevent overflow
            if(nums[m] == target){
                res = m;
                break;
            }
            else if(nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        
        return res >= 0 ? res : -1;
    }
};