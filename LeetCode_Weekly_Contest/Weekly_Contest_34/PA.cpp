class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops)
    {
        if(!ops.size())
        {
            return m*n;
        }
        else
        {
            int srow=ops[0][0],scol=ops[0][1];
            for(int i=1;i<ops.size();i++)
            {
                srow=min(srow,ops[i][0]);
                scol=min(scol,ops[i][1]);
            }
            return srow*scol;
        }

    }
};
