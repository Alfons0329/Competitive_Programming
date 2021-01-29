class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target){
        int row = matrix.size();
        if(!row){
            return false;
        }
        int col = matrix[0].size();
        
        int search_row = 0;
        int search_col = col - 1;
        
        while(search_row < row && search_col >= 0){
            // searching the matrix, set the search_row as the smallest and search_col as the biggest
            // increment the search_row if the target is greater than the current matrix element
            if(target > matrix[search_row][search_col]){
                search_row++;
            }
            // decrement the search_col if the target is lesser than the current matrix element
            else if(target < matrix[search_row][search_col]){
                search_col--;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};
