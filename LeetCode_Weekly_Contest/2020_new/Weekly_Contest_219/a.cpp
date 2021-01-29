class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while(n > 1){
            res += n >> 1;
            n = (n - (n >> 1));
        }
        return res;
    }
