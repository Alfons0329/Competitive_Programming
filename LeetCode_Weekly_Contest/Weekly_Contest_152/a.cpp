#define ll unsigned long long 
class Solution 
{
    public:
        ll MOD = 1e9+7;
        ll f(ll n)
        {
            ll res = 1;
            for(ll i = 1; i <= n; i++)
            {
                res *= i;
                res %= MOD;
            }
            return res;
        }
        int numPrimeArrangements(int n) 
        {
            vector<int> p = {0, 2, 3, 5, 7 ,11 ,13 ,17 ,19 ,23 ,29 ,31 ,37 ,41 ,43 ,47 ,53 ,59 ,61 ,67 ,71 ,73 ,79 ,83 ,89 ,97};
            int pos = 0;
            while(pos < 26 && p[pos] <= n)
            {
                pos++;
            }
            if(pos >= 26)
            {
                pos = 25;
            }
            else if(p[pos] > n)
            {
                pos--;
            }
            ll res = (f(pos) % MOD * f(n - pos) % MOD) % MOD;
            return res;            
        }
};
