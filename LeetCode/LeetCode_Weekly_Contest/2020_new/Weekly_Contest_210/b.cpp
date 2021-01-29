#define N 105
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int m[N][N] = {0};
        int deg[N] = {0}; // degree for node i
        
        for(auto vii : roads){
            m[vii[0]][vii[1]] = 1;
            m[vii[1]][vii[0]] = 1;
            deg[vii[0]]++;
            deg[vii[1]]++;
        }
        
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                res = max(res, deg[i] + deg[j] - m[i][j]);
            }
        }
        
        return res;
    }
};
