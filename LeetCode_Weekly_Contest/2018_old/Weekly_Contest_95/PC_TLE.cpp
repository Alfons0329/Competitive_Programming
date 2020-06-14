#include <stdint.h>
const uint64_t MOD = 1e9 + 7;
class Solution
{
public:
    int nthMagicalNumber(int N, int A, int B)
    {
        int cnt = 0;
        cnt = min(A, B);
        cnt--;
        while(1)
        {
            if(cnt % A == 0 && cnt % B == 0)
            {
                cnt += LCM(A, B);
                N--;
            }
            else if(cnt % A == 0)
            {
                cnt += A;
                N--;
            }
            else if(cnt % B == 0)
            {
                cnt += B;
                N--;
            }
            if(!N)
            {
                break;
            }
        }
        return cnt % MOD;
    }
    unsigned long long int LCM(int A, int B)
    {
        unsigned long long int mxm = max(A, B);
        do
        {
            if (mxm % A == 0 && mxm % B == 0)
            {
                break;
            }
            else
            {
                mxm++;
            }
        } while(1);
        return mxm;
    }
};
