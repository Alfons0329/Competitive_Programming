class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int neww) {
        if(image[sr][sc] == neww){
            return image;
        }
        dfs(image, sr, sc, image[sr][sc], neww);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int start, int neww){
        // check out of bound
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() \
          || image[sr][sc] ^ start || image[sr][sc] == neww){
            return;
        }
        
        image[sr][sc] = neww;
        dfs(image, sr - 1, sc, start, neww);
        dfs(image, sr + 1, sc, start, neww);
        dfs(image, sr, sc + 1, start, neww);
        dfs(image, sr, sc - 1, start, neww);
        
    }
