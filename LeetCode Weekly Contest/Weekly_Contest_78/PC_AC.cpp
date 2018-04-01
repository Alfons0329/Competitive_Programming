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
        for(int i = 0; i < serve + 1; i++) // i for usage of A
        {
            for(int j = 0; j < serve + 1; j++) // j for usage of B
            {
                if(i <= 0) //comes from a used of ALL A
                {

                }
                else if(j <= 0) //we want a to be used out rather than B
                {

                }
                else
                {
                    
                }
            }
        }
        return ans;
    }
};
