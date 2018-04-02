class Solution
{
public:
    double soupServings(int all)
    {
        if(all > 6000) //monotonically increasing since A is always used more than B. (by emperical method)
            return 1.0;

        int serve = all / 25; //25 ml as a servin unit, chess board as drawing, longest method is always serving 25ml of A till end.
        vector<vector <double> > dp(serve + 1, vector<double>(serve + 1, 0)); //each grid represent the rest amount(unit) of a and be which comes to here
        //A row, B col
        double dir1, dir2, dir3, dir4;
        for(int i = 0; i <= serve; i++)
        {
            for(int j = 0; j <= serve; j++)
            {
                if(i - 4 <= 0 && j <=0)
                {
                    dir1 = 0.5;
                }
                else if(i - 4 <= 0)
                {
                    dir1 = 1;
                }
                else if(j <= 0)
                {
                    dir1 = 0;
                }
                else
                {
                    dir1 = dp[i - 4][j];
                }

                if(i - 3 <= 0 && j - 1 <= 0)
                {
                    dir2 = 0.5;
                }
                else if(i - 3 <= 0)
                {
                    dir2 = 1;
                }
                else if(j - 1 <= 0)
                {
                    dir2 = 0;
                }
                else
                {
                    dir2 = dp[i - 3][j - 1];
                }


                if(i - 2 <= 0 && j - 2 <= 0)
                {
                    dir3 = 0.5;
                }
                else if(i - 2 <= 0)
                {
                    dir3 = 1;
                }
                else if(j - 2 <= 0)
                {
                    dir3 = 0;
                }
                else
                {
                    dir3 = dp[i - 2][j - 2];
                }


                if(i - 1 <= 0 && j - 3 <= 0)
                {
                    dir4 = 0.5;
                }
                else if(i - 1 <= 0)
                {
                    dir4 = 1;
                }
                else if(j - 3 <= 0)
                {
                    dir4 = 0;
                }
                else
                {
                    dir4 = dp[i - 1][j - 3];
                }
                cout<<"Dir 1__"<<dir1<<" dir 2__"<<dir2<<"dir 3 __"<<dir3<<" dir4___"<<dir4<<endl;
                dp[i][j] = 0.25 * (dir1 + dir2 + dir3 + dir4);
            }
        }
        return dp[serve][serve];
    }
};
