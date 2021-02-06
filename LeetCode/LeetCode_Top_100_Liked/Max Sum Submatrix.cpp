/*
Approach: Inspired by https://www.youtube.com/watch?v=-FgseNO-6Gk
Time: O(col * col (due to the combination of L R bound pair ) * row (Kadanes'algorithm from the top to bottom row))
Space: O(row)
*/

#include <bits/stdc++.h>

using namespace std;

pair<int, pair<int, int>> kadane(vector<int> array){
    int res = INT_MIN;
    int tmp_res = 0;
    int n = array.size();

    // To print the bound of row
    int r_begin = 0;
    int r_end = 0;
    pair<int, pair<int, int>> ret;
    for(int i = 0; i < n; i++){
        if(tmp_res + array[i] > array[i]){
            r_end = i;
        }
        else if(tmp_res + array[i] < array[i]){
            r_begin = i;
        }
        tmp_res = max(tmp_res + array[i], array[i]);
        res = max(res, tmp_res);
        ret = {res, {r_begin, r_end}};
    }
    return ret;
}

int find_max_submatrix(const vector<vector<int>> mat){
    int row = mat.size();
    int col = mat[0].size();
    int res = 0;

    // The four bounds of the result rectangle
    int r_begin = 0;
    int r_end = 0;
    int c_begin = 0;
    int c_end = 0;

    for(int c_L = 0; c_L < col; c_L++){
        // Init the subarray running sum from left to right, with size being # of rows
        vector<int> row_sum(row, 0);
        for(int c_R = c_L; c_R < col; c_R++){
            for(int r = 0; r < row; r++){
                row_sum[r] += mat[r][c_R];
            }
            pair<int, pair<int, int>> ret = kadane(row_sum);
            if(ret.first > res){
                res = ret.first;
                r_begin = ret.second.first;
                r_end = ret.second.second;
                c_begin = c_L;
                c_end = c_R;
            }
        }
    }

    printf("Result rectangle, r_begin %d r_end %d, c_begin %d c_end %d\n", r_begin, r_end, c_begin, c_end);
    return res;
}

int main(){
    vector<vector<int>> mat = 
    {{1, 2, -1, -4, -20},
    {-8, -3, 4, 2, 1},
    {3, 8, 10, 1, 3},
    {-4, -1, 1, 7, -6}};
    int ret = find_max_submatrix(mat);
    printf("Ans: %d\n", ret);

    mat = 
    {{6, -5, 7, 4, -4},
    {-9, 3, -6, 5, 2},
    {-10, 4, 7, -6, 3},
    {-8, 9, -3, 3, -7}};
    ret = find_max_submatrix(mat);
    printf("Ans: %d\n", ret);

    mat = 
    {{1, 2, -3},
    {3, 4, -5},
    {-5, -6, -7}},
    ret = find_max_submatrix(mat);
    printf("Ans: %d\n", ret);

    mat = 
    {{2, 1, -3, -4, 5},
    {0, 6, 3, 4, 1},
    {2, -2, -1, 4, -5},
    {-3, 3, 1, 0, 3}};
    ret = find_max_submatrix(mat);
    printf("Ans: %d\n", ret);
    return 0;
}