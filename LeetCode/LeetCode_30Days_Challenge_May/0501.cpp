class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n - 1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(isBadVersion(m + 1)) r = m;
            else l = m + 1;
        }
        return r + 1;
    }
};
