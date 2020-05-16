class Solution{
public:
    int singleNonDuplicate(vector<int> &nums){
        int l = 0, r = nums.size() - 1, m = 0;
        while (l < r){
            m = l + (r - l) / 2;
            m = (m & 1) ? m - 1 : m;
            if (nums[m] == nums[m + 1]){
                l = m + 2;
            }
            else{
                r = m;
            }
        }
        return nums[r];
    }
};