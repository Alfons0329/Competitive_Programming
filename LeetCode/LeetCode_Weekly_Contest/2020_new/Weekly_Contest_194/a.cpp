class Solution {
public:
    int xorOperation(int n, int s) {
        int res = s;
        for(int i = 1; i <= n - 1; i++){
            res ^= (s + 2 * i);
        }
        return res;
    }
