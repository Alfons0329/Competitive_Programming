
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //a pascal triangle, like structure, *4 for better understanding
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector <double > > cups;
        cups.resize(100);
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cups[i].push_back(0.0);
            }
        }
        int row=0,col=0;
        for(int i=1;i<=poured;i++)
        {
            if(i == 1) //initial condition
            {
                cups[row][col] = 1.0;
            }
            else
            {
                for(int j=0;j<cups[row].size();j++)
                {
                    if(cups[row][j] >= 1.0)//boundary safe
                    {
                        row++;
                        break;
                    }
                }
                //pour from the top most of the champagneTower
                cout<<"row "<<row<<endl;
                if(row >= 100) //process over since we've done row 99
                    break;

                cups[0][0] += 1.0;
                for(int j=0;j<=row;j++)
                {
                    for(int k=0;k<=j;k++)
                    {
                        cout<<" j "<<j<<" , "<<k<<"  val   "<<cups[j][k]<<endl;
                        if(cups[j][k] >= 1.0 && j < 99)//boundary safe
                        {
                            cups[j+1][k] += (cups[j][k] - 1.0) / 2.0 ;
                            cups[j+1][k+1] += (cups[j][k] - 1.0) / 2.0 ;
                            cups[j][k] = 1.0;
                        }
                    }
                }
            }
            if(row >= 100) //process over since we've done row 99
                break;
        }
        cout<<"My tower ";
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
                cout<<cups[i][j]<<" ";
            cout<<endl;
        }
        return cups[query_row][query_glass];
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    int a,b,c;
    cin>>a>>b>>c;
    cout<<sol.champagneTower(a,b,c)<<endl;
    return 0;
}
