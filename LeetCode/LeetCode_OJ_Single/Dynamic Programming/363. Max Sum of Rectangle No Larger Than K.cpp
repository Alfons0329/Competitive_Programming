class Solution {
public:
    int max_subarray_sum_no_larger_than_k(vector<int>& arr, int k){
        // Cumulative sumset
        set<int> cum_set;
        cum_set.insert(0);
        
        int res = INT_MIN;
        int cum = 0;
        
        // Interval sum in arr[i: j] = cum[j] - cum[i - 1]
        for(int i = 0; i < arr.size(); i++){
            cum += arr[i];
            auto sit = cum_set.lower_bound(cum - k);
            // If the lower_bound of cum - k  has appeared before, then it means 
// it is possible to construct the possible cumulative sum less than k
            // Max possible will be cum - lower_bound for possible cumulative sum happened before
            if(sit != cum_set.end()){
                res = max(res, cum - *sit);
            }
            cum_set.insert(cum);
        }
        
        return res;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        int res = INT_MIN;
        for(int c_L = 0; c_L < col; c_L++){
            vector<int> row_sum(row, 0);
            for(int c_R = c_L; c_R < col; c_R++){
                for(int r = 0; r < row; r++){
                    row_sum[r] += mat[r][c_R];
                }
                int tmp_res = max_subarray_sum_no_larger_than_k(row_sum, k);
                res = max(res, tmp_res);
            }
        }
        return res;
    }
};