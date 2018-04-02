class Solution
{
public:
    double soupServings(int all)
    {
        if(all > 6000) //monotonically increasing since A is always used more than B. (by emperical method)
            return 1.0;
        else if(all && all <= 25) //mathematical testing since all <= 25 ml A will run out first in the probability of 0.25 + 0.5(0.25*3)
        //(latter is A B run out at the same time)
            return 0.625;
        else if(all == 0)
            return 0.5; //special case // already run out at the same time


        int serve = all / 25; //25 ml as a servin unit, chess board as drawing, longest method is always serving 25ml of A till end.
        int asoup = all / 25;
        int bsoup = all / 25;
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

                dp[i][j] = 0.25 * (dir1 + dir2 + dir3 + dir4);
            }
        }
        return dp[serve][serve];
    }
};
