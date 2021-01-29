/*
* Step 1: DFS all the object from border, marked as '*', i.e. things from border
* Step 2: the rest 0 will be marked as surrounded
*/
class Solution {
public:
    int row, col;
    void solve(vector<vector<char>>& m) {
        row = m.size();
        if(row == 0){
            return;
        }
        col = m[0].size();
        
        // U
        for(int j = 0; j < col; j++){
            dfs(0, j, m, '*');
        }
        // D
        for(int j = 0; j < col; j++){
            dfs(row - 1, j, m, '*');
        }
        // L
        for(int i = 0; i < row; i++){
            dfs(i, 0, m, '*');
        }
        // R
        for(int i = 0; i < row; i++){
            dfs(i, col - 1, m, '*');
        }
        // other
        for(int i = 0; i < row ; i++){
            for(int j = 0; j < col; j++){
                dfs(i, j, m, 'X');
                if(m[i][j] == '*'){
                    m[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(int i, int j, vector<vector<char>>& m, char c){
        if(i < 0 || i >= row || j < 0 || j >= col || m[i][j] != 'O'){
            return;
        }
        
        m[i][j] = c;
        dfs(i - 1, j, m, c); // U
        dfs(i + 1, j, m, c); // D
        dfs(i, j - 1, m, c); // L
        dfs(i, j + 1, m, c); // R
    }
};