// explanation atricle: https://leetcode.com/problems/number-of-distinct-islands/discuss/553846/Concise-and-short-C%2B%2B-setlessvectorlessintgreater-greater-track-relative-coordinate-solution-with-explanation 
class Solution {
public:
    int row, col, start;
    set<vector<int> > coor_all;
    vector<int> coor_one;
    
    int numDistinctIslands(vector<vector<int>>& m) {
        row = m.size();
        col = m[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                start = i * col + j;
                if(m[i][j] == 1){
                    dfs(i, j ,m);
                    coor_all.insert(coor_one);
                    coor_one.clear();
                }
            }
        }
        
        return coor_all.size();
    }
    
    void dfs(int i, int j, vector<vector<int> >& m){
        if(i < 0 || i >= row || j < 0 || j >= col || m[i][j] != 1){
            return;
        }
        
        m[i][j] = 2; // mark as traversed
        coor_one.emplace_back(i * col + j - start);// insert the relative coordinate to the set
        printf("emp %d \n", i * col + j - start);
        dfs(i - 1, j, m); // U
        dfs(i + 1, j, m); // D
        dfs(i, j - 1, m); // L
        dfs(i, j + 1, m); // R
    }
};