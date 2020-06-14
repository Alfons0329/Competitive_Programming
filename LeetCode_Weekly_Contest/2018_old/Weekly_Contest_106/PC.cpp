#define LL long long
const int MOD = 1e9 + 7;
class Solution 
{
public:
    int threeSumMulti(vector<int>& A, int target) 
    {
        unordered_map<LL, LL>my;
        LL n = A.size();
        LL res = 0;
        
        for(LL i = 0; i < n; i++)
        {
            my[A[i]]++;    
        }
        
        for(LL it1 = 0; it1 < 101; ++it1)
        {  
            if(my[it1] == 0)
            {
                continue;
            }
            for(LL it2 = it1; it2 < 101; ++it2)
            {
                LL fir = it1;
                LL sec = it2;
                LL thr = target - fir - sec;
                if(my[thr] == 0 || my[it2] == 0) //unable to use
                {
                    continue;
                }
                if(!(fir <= sec && sec <= thr)) //maLLain the order to prevent duplicated
                {
                    continue;
                }
                
                if((fir == sec) && (fir == thr))
                {
                    res +=cnr(my[fir], 3) % MOD;
                }
                else if((fir == sec) && (fir != thr))  //2 and 1
                {
                    res +=( cnr(my[fir], 2) % MOD ) * ( cnr(my[thr], 1) % MOD );
                }
                else if((fir == thr) && (fir != sec)) //2 and 1
                {
                    res +=( cnr(my[fir], 2) % MOD ) * ( cnr(my[sec], 1) % MOD );

                }
                else if((thr == sec) && (fir != thr)) //2 and 1
                {
                    res +=( cnr(my[sec], 2) % MOD ) * ( cnr(my[fir], 1) % MOD );
                }
                else //all different
                {
                    res +=( cnr(my[fir], 1) % MOD ) * ( cnr(my[sec], 1) % MOD ) * ( cnr(my[thr], 1) % MOD );
                }
                res %= MOD;
            }
        }
        return (int)(res % MOD); //test
        
    }
    
    LL cnr( LL n, LL k )
    {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        LL result = n;
        for( LL i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }
};