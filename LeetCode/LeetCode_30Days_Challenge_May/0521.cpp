class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int res = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i > 0 && j > 0 && matrix[i][j] == 1){
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
};
