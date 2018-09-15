class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector <double > > cups;
        cups.resize(101); //padding
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cups[i].push_back(0.0);
            }
        }
        cups[0][0] = poured;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(cups[i][j] >= 1.0)
                {
                    cups[i+1][j] += (cups[i][j] - 1.0) / 2.0 ;
                    cups[i+1][j+1] += (cups[i][j] - 1.0) / 2.0 ;
                    cups[i][j] = 1.0;
                }
            }
        }
        return cups[query_row][query_glass];
    }
};
