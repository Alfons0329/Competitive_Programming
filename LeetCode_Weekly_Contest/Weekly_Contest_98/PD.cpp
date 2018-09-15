#define ll  long long
const ll MOD = 1e9 + 7;
class Solution {
public:
    int sumSubseqWidths(vector<int>& A)
    {
        ll res = 0, sz = A.size();
        sort(A.begin(), A.end());
        ll dp[20001] = {0};
        dp[0] = 1;
        for(int i = 1; i < sz; i++)
        {
            dp[i] = (dp[i - 1] % MOD * 2) % MOD;
        }
        for(int i = 0; i < sz; i++)
        {
            res += A[i] * (dp[i] - dp[sz - i - 1]);
            res %= MOD;
        }
        return res;
    }
};
