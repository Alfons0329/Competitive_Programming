class Solution
{
public:
    double size;
    double soupServings(int all)
    {
        int serve = ceil(all / 25.0) ; //25 ml as a servin unit, if a unit is less than 25 it still have to be procesed since the integer division will do floor, so we need to change to ceiling
        vector<vector <double> > dp(serve + 1, vector<double>(serve + 1, 0));
        return all > 5000 ? 1.0 : prob(serve, serve, dp);
    }
    double prob(int a,int b,vector<vector <double> > dp)
    {
        cout<<"a is "<<a <<" b is "<<b<<endl;
        if(a <= 0 && b <= 0)
        {
            return 0.5;
        }
        if(a <= 0)
        {
            return 1.0;
        }
        if(b <= 0)
        {
            return 0;
        }
        if(dp[a][b] > 0)
        {
            return dp[a][b];
        }
        dp[a][b] = 0.25 * (prob(a-4, b, dp) + prob(a-3, b-1, dp) + prob(a-2, b-2, dp) + prob(a-1, b-3, dp));
        return dp[a][b];
    }
};
