class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, int> sumdeg; // in + 1, out - 1
        for(auto vi : trust){
            int u = vi[0];
            int v = vi[1];
            sumdeg[u]--;
            sumdeg[v]++;
        }
        
        for(int i = 1; i <= N; i++){
            if(sumdeg[i] == N - 1){
                return i;
            }
        }
        return -1;
    }
}
