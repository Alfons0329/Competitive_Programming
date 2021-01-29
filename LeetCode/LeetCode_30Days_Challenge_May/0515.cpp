class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int mx_nw = kadane(A);
        int mx_w = 0;
        for(int& x : A){
            mx_w += x;
            x *= -1;
        }
        mx_w += kadane(A);
        return mx_w == 0 ? mx_nw : max(mx_w, mx_nw);
    }
    
    int kadane(vector<int>& v){
        int mx = INT_MIN, cur_mx = 0;
        for(int x : v){
            cur_mx = max(cur_mx + x, x);
            mx = max(cur_mx, mx);
        }
        return mx;
    }
