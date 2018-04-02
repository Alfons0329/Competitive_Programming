class Solution
{
public:
    double dplist[500][500]= {0.0};
    double soupServings(int all)
    {
        if(all <= 50 && all)
        {
            return 0.625;
        }
        else if(all == 0)
        {
            return 0.5;
        }
        return all > 5000 ? 1.0 : prob((all / 25)+ 1, (all / 25)+ 1);
    }
    double prob(int a,int b)
    {
        if(a <= 0 && b <= 0)
        {
            return 0.5;
        }
        else if(a <= 0)
        {
            return 1.0;
        }
        else if(b <= 0)
        {
            return 0;
        }
        if(dplist[a][b] > 0)
        {
            return dplist[a][b];
        }
        else
        {
            dplist[a][b] = 0.25 * (prob(a-4, b) + prob(a-3, b-1) + prob(a-2, b-2) + prob(a-1, b-3));
            return 0.25 * (prob(a-4, b) + prob(a-3, b-1) + prob(a-2, b-2) + prob(a-1, b-3));
        }
    }
};
