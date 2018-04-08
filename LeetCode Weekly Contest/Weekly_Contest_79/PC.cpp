/*
Wrong Answer
[1,2,3,4,5,6,7]
4*/
class Solution
{
public:
    double largestSumOfAverages(vector<int>& arr, int kin)
    {
        double dp[105][105] = {0.0f};
        for(int i = 0; i < arr.size(); i++)
        {
            double sum = 0.0f;
            for(int j = 0; j <= i; j++)
            {
                sum += arr[j];
            }
            dp[0][i] = sum / (double) (i + 1);
        }
        double cur_val = 0.0f, max_val = 0.0f, segment_avg = 0.0, segment_avg2 = 0.0f;

        for(int i = 1; i < kin; i++)
        {
            for(int j = i; j < arr.size(); j++)
            {
                cur_val = 0.0f, max_val = 0.0f;
                if(j < i)
                {
                    continue;
                }
                else if(j == i)
                {
                    segment_avg = 0.0f;
                    for(int k = 0; k <= j; k++)
                    {
                        segment_avg += arr[k];
                    }
                    dp[i][j] = segment_avg;
                }
                else if(i == 1)
                {
                    for(int k = 1; k <= j; k++)
                    {
                        segment_avg = 0.0f;
                        segment_avg2 = 0.0f;
                        for(int l = 0; l < k; l++)
                        {
                            segment_avg += arr[l];
                        }
                        for(int m = k; m <= j; m++)
                        {
                            segment_avg2 += arr[m];
                        }
                        max_val = max(max_val, segment_avg / k + segment_avg2 / double(j - k + 1));
                    }
                    dp[i][j] = max_val;
                }
                else
                {
                    for(int n = j; n >= i - 1; n--)
                    {
                        segment_avg = 0.0f;
                        for(int k = j; k >= n; k--)
                        {
                            segment_avg += arr[k];
                        }
                        cur_val = dp[i - 1][n - 1] + segment_avg / (double)(j - n + 1);
                        max_val = max(max_val, cur_val);
                    }
                    dp[i][j] = max_val;
                    //after choosing the max_val of the dp
                }
            }
        }
        return dp[kin - 1][arr.size() - 1];
    }
};
