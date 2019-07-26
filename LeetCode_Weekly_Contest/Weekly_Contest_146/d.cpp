#define all(x) x.begin(), x.end()
class Solution {
    public:
    int maxAbsValExpr(vector<int>& a1, vector<int>& a2) 
    {
        int n = a1.size(), res = 0;
        vector<vector<int>>i_sign = {{1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1}};
        int i_comb[4][40002] = {INT_MIN};
        int j_comb[4][40002] = {INT_MIN};
        
        for(int type = 0; type < 4; type++)
        {
            int op1 = i_sign[type][0], op2 = i_sign[type][1], op3 = i_sign[type][2];
            for(int i = 0; i < n; i++)
            {
                i_comb[type][i] = op1 * a1[i] + op2 * a2[i] + op3 * i;
                j_comb[type][i] = -1 * (op1 * a1[i] + op2 * a2[i] + op3 * i);
            }
        }

        vector<int>type_max(4, INT_MIN);
        for(int i = 0; i < 4; i++)
        {
            type_max[i] = *max_element(i_comb[i], i_comb[i] + n) + *max_element(j_comb[i], j_comb[i] + n);
        }
        return *max_element(all(type_max)); 
    }
};
