class Solution 
{
public:
    int tribonacci(int n) 
    {
        int a[6] = {0, 1, 1, 2, 4, 7};
        if(n < 6)
        {
            return a[n];
        }
        
        int t0 = 2, t1 = 4, t2 = 7;
        int t3 = t0 + t1 + t2;
        for(int i = 6; i <= n; i++)
        {
            t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        return t3;
    }
};
