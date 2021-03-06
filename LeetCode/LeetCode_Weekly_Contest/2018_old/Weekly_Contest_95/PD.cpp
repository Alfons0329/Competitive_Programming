/* Dynamic programming
dp[i][j][k] = # of schemes has profit j with first i tasks and k people.

transiion --> current dp[i][j][k] : how many schemes can be done has profit j with first i tasks and k people?


cur_k = group[i] = people needed for current mission
cur_p = profit[i] = current profit
dp[i][j][k] = dp[i - 1][j][k] do nothing of the current mission
+ dp[i][j - cur_p][k - cur_k] do this mission, but the schemes will according to the previos stored value
i.e. how much schemes to achieve such condition with the same first i missions but only use j - cur_k and k - cur_p
people, also if k - cur_k < 0 then such mission cannot be done since run out of human resources


*/
#define LL long long
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit)
    {
        int sz = group.size();
        LL dp[sz + 1][P + 1][G + 1]; //use profit for DP, 1 or padding
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1; //doing nothing is 1
        LL cur_k, cur_p;
        for(LL i = 1; i <= sz; i++)
        {
            cur_k = group[i - 1];
            cur_p = profit[i - 1];
            for(LL j = 0; j < P + 1; j++)
            {
                for(LL k = 0; k < G + 1; k++)
                {
                    if(k - cur_k < 0)
                    {
                        dp[i][j][k] = dp[i - 1][j][k] % MOD; //currrent mission cannot be done, use the last mission
                    }
                    else if(j - cur_p < 0)
                    {
                        dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][0][k - cur_k]) % MOD;
                    }
                    else
                    {
                        dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - cur_p][k - cur_k]) % MOD;
                    }
                }
            }
        }
        LL ans = 0;

        for(int k = 0; k < G + 1; k++)
        {
            ans += dp[sz][P][k];
        }

        return ans % MOD;

    }

};
