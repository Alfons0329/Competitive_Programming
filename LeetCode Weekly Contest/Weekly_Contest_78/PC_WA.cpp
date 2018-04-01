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
        vector<vector <double> > dp(serve + 1, vector<double>(serve + 1, 0)); //each grid represent the rest amount(unit) of a and be which comes to here
        //A row, B col
        //dp the used volume
        dp[serve][serve] = 1; //till zero
        for(int i = serve; i >= 0; i--)
        {
            for(int j = serve; j >= 0; j--)
            {
                cout<<"i "<<i<<" j "<<j<<endl;

                if(j - i < 0)
                {
                    continue;
                }

                if(i - 4 > 0)
                {
                    cout<<"case 0"<<endl;
                    dp[i - 4][j] += 0.25 * dp[i][j];
                }
                else // a has been used out, directly set that position to be zero
                {
                    cout<<"case 1"<<endl;
                    dp[0][j] += 0.25 * dp[i][j];
                }

                if(i - 3 > 0 && j - 1 > 0)
                {
                    cout<<"case 2"<<endl;
                    dp[i - 3][j - 1] += 0.25 * dp[i][j];
                }
                else if(i - 3 <= 0)
                {
                    cout<<"case 3"<<endl;
                    dp[0][j] += 0.25 * dp[i][j];
                }

                if(i - 2 > 0 && j - 2 > 0)
                {
                    cout<<"case 4"<<endl;
                    dp[i - 2][j - 2] += 0.25 * dp[i][j];
                }
                else if(i - 2 <= 0)
                {
                    cout<<"case 5"<<endl;
                    dp[0][j] += 0.25 * dp[i][j];
                }

                if(i - 1 > 0 && j - 3 > 0)
                {
                    cout<<"case 6"<<endl;
                    dp[i - 1][j] += 0.25 * dp[i][j];
                }
                else if(i - 1 <= 0)
                {
                    cout<<"case 7"<<endl;
                    dp[0][j] += 0.25 * dp[i][j];
                }
            }
        }
        double ans = 0;
        ans += 0.5 * dp[0][0];


        for(int i = 0 ;i < serve + 1;i++)
        {
            for(int j = 0; j < serve + 1; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"grid end serve"<<serve<<endl;
        for(int i = 1;i< serve + 1;i++)
        {
            ans += dp[0][i];
        }

        return ans;
    }
};
