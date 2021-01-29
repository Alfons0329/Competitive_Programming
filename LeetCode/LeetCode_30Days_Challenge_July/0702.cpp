class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {      
        vector<int> prev = cells;
        vector<int> cur(8, 0);
        N = (N % 14 == 0) ? 14 : N % 14;
        while(N--){
            for(int i = 1; i < 7; i++){
                cur[i] = prev[i - 1] ^ prev[i + 1] == 0 ? 1 : 0;
            }
            prev = cur;
        }
        return cur;
    }
};
