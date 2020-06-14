class Solution {
public:
    bool possible(vector<int>& bd, int m, int k, int mid){
        int n = bd.size();
        int cnt = 0, res = 0;
        for(int i = 0; i < n; i++){
            if(bd[i] <= mid){
                cnt++;
            }
            else{
                cnt = 0;
            }
            if(cnt == k){
                cnt = 0;
                res++;
            }
        }
        return res >= m;
    }
    int minDays(vector<int>& bd, int m, int k) {
        int l = 1, r = INT_MIN, mid = 0;
        for(int x : bd){
            r = max(x, r);
        }
        while(l < r){
            mid = l + (r - l) / 2;
            if(possible(bd, m, k, mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        
        // opt to return l, so give l a final check
        return possible(bd, m, k, l) ? l : -1;
    }
