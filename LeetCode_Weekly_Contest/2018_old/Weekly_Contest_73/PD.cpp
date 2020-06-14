class Solution
{
public:
    int numTilings(int N)
    {
        unsigned long long int fir = 2 , sec = 5, thr = 7;
        for(int i = 4 ; i < 5 ; i++)
        {
            fir = sec;
            sec = thr;
            thr = fir + sec;
        }
        cout<<thr<<endl;
        return thr % 1000000007;
    }
};
