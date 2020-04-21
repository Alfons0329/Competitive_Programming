/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &bm) {
        vector<int> d = bm.dimensions();
        int row = d[0], col = d[1];
        int i = 0, j = col - 1;
        
        while(i < row && j >= 0){
            if(bm.get(i, j)){
                j--;
            }
            else{
                i++;
            }
        }
        return j == col - 1 ? -1 : j + 1;
    }
};