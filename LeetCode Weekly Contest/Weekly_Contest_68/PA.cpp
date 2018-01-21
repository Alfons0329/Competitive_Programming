class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int rt=1, ct=1;
        for(int i=matrix.size()-1;i>=0;i--)
        {
            for(int j=0,k=i;j<matrix[0].size();j++,k++)
            {
                // cout<<"Trverse "<<matrix[k][j]<<" "<<matrix[i][0]<<endl;
                if(matrix[i][0]!=matrix[k][j])
                {
                    rt=0;
                    return false;
                }
                if(k==matrix.size()-1)
                {
                    break;
                }
            }
        }
        for(int i=1;i<matrix[0].size();i++)
        {
            for(int j=0,k=i;j<matrix.size();j++,k++)
            {
                // cout<<"Trverse p2 "<<matrix[j][k]<<" "<<matrix[0][i]<<endl;
                if(matrix[0][i]!=matrix[j][k])
                {
                    ct=0;
                    return false;
                }
                if(k==matrix[0].size()-1)
                {
                    break;
                }
            }
        }
        return (ct&&rt)? 1 : 0;
    }
};
