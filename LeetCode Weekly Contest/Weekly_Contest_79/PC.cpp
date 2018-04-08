class Solution
{
public:
    double largestSumOfAverages(vector<int>& arr, int kin)
    {
        double dp[kin][arr.size()] = {0.0f};
        cout<<"kin "<<kin<<" size "<<arr.size()<<endl;
        for(int i = 0; i < arr.size(); i++)
        {
            dp[0][i] = arr[i];
        }
        double cur_val = 0.0f, max_val = 0.0f, segment_avg = 0.0;

        for(int i = 1; i < arr.size() - 1; i++)
        {
            cur_val = 0.0f;
            for(int j = i + 1; j < arr.size(); j++)
            {
                cout<<"i "<<i<<" j "<<j<<endl;
                if(j < i)
                {
                    continue;
                }
                else if(j == i)
                {
                    for(int k = 0; k <= j; k++)
                    {
                        segment_avg += arr[k];
                    }
                    dp[i][j] = segment_avg / (j + 1);
                }
                else
                {
                    cout<<"else"<<endl;
                    for(int n = j; n >= i; n--)
                    {
                        segment_avg = 0.0f;
                        cout<<"haha "<<endl;
                        for(int k = j; k >= n; k--)
                        {
                            cout<<"case2 n "<<n<<" k "<<k<<endl;
                            segment_avg += arr[k];
                        }
                        cur_val = dp[i - 1][n - 1] + segment_avg / (j - n + 1);
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
