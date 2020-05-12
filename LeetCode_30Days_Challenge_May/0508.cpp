class Solution {
public:
    double get_slope(int x1, int y1, int x0, int y0){
        if(x1 - x0 == 0){
            return INT_MAX;
        }
        else{
            return (double)(y1 - y0) / (double)(x1 - x0);
        }
    }
    bool checkStraightLine(vector<vector<int>>& c) {
        double slope = get_slope(c[1][0], c[1][1], c[0][0], c[0][1]);
        double check = 0.0f;
        for(int i = 2; i < c.size(); i++){
            check = get_slope(c[i][0], c[i][1], c[0][0], c[0][1]);
            if(check != slope){
                return false;
            }
        }
        return true;
    }
};
