#define ULL unsigned long long
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit)
    {
        int sz = group.size();
        ULL dp[sz][P + 1][G + 1] = {0}; //use profit for DP, 1 or padding
        /* Dynamic programming
        dp[i][j][k] = # of schemes has profit j with first i tasks and k people.

        transiion --> current dp[i][j][k] : how many schemes can be done has profit j with first i tasks and k people?


        cur_k = group[i] = people needed for current mission
        cur_p = profit[i] = current profit
        dp[i][j][k] = dp[i - 1][j][k] do nothing of the current mission
                    + dp[i][j - cur_k][k - cur_p] do this mission, but the schemes will according to the previos stored value
                    i.e. how much schemes to achieve such condition with the same first i missions but only use j - cur_k and k - cur_p
                    people, also if k - cur_k < 0 then such mission cannot be done since run out of human resources


        */
        dp[0][0][0] = 1; //doing nothing is 1
        int cur_k, cur_p;
        for(int i = 1; i < group.size(); i++)
        {
            cur_k = group[i];
            cur_p = profit[i];
            for(int j = 1; j < P + 1; j++)
            {
                for(int k = 1; k < G + 1; k++)
                {
                    if(k - cur_k < 0)
                    {
                        dp[i][j][k] = dp[i - 1][j][k]; //currrent mission cannot be done, use the last mission
                    }
                    else
                    {
                        dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - cur_k][k - cur_p];
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < G + 1; j++)
            {
                ans += dp[i][P][j] % MOD;
            }
        }
        return ans;

    }
};
