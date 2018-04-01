class Solution
{
public:
    double soupServings(int all)
    {
        if(all > 4000)
            return 1.0;
        int serve = all / 25; //25 ml as a servin unit, chess board as drawing, longest method is always serving 25ml of A till end.
        int asoup = all / 25;
        int bsoup = all / 25;
        vector<vector <double> > dp(serve, vector<double>(serve, 0)); //each grid represent the rest amount(unit) of a and be which comes to here
        //A row, B col
        //dp the used volume
        dp[serve - 1][serve - 1] = 1;
        for(int i = serve - 1; i >= 0; i--)
        {
            for(int j = serve - 1; j >= 0; j--)
            {
                cout<<"i "<<i<<" j "<<j<<endl;
                if(i - 4 >= 0)
                {
                    dp[i - 4][j] = 0.25 * dp[i][j];
                }
                if(i - 3 >= 0 && j - 1 >= 0)
                {
                    dp[i - 3][j - 1] = 0.25 * dp[i][j];
                }

                if(i - 2 >= 0 && j - 2 >= 0)
                {
                    dp[i - 2][j - 2] = 0.25 * dp[i][j];
                }

                if(i - 1 >= 0 && j - 3 >= 0)
                {
                    dp[i - 1][j - 3] = 0.25 * dp[i][j];
                }
            }
        }
        double ans = 0;
        ans += 0.5*dp[0][0];

        for(int i = 0 ; i < serve; i++)
        {
            for(int j = 0; j < serve; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"grid end ";
        for(int i = 1; i < serve; i++)
        {
            ans+= 0.5 * dp[0][i];
        }
        return ans;
    }
};
