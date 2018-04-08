/*
Wrong Answer
[1,2,3,4,5,6,7]
4*/
class Solution
{
public:
    double largestSumOfAverages(vector<int>& arr, int kin)
    {
        if(kin == 1)
        {
            double sum = 0.0f;
            for(auto i : arr; i != arr.end(); i++)
            {
                sum += *i;
            }
            return sum / (double) arr.size();
        }
        double dp[105][105] = {0.0f};
        cout<<"kin "<<kin<<" size "<<arr.size()<<endl;
        for(int i = 0; i < arr.size(); i++)
        {
            dp[0][i] = arr[i];
        }
        double cur_val = 0.0f, max_val = 0.0f, segment_avg = 0.0, segment_avg2 = 0.0f;

        for(int i = 1; i < kin; i++)
        {
            for(int j = i; j < arr.size(); j++)
            {
                cout<<"i "<<i<<" j "<<j<<endl;
                cur_val = 0.0f, max_val = 0.0f;
                if(j < i)
                {
                    continue;
                }
                else if(j == i)
                {
                    // cout<<"equal "<<endl;
                    segment_avg = 0.0f;
                    for(int k = 0; k <= j; k++)
                    {
                        segment_avg += arr[k];
                    }
                    dp[i][j] = segment_avg;
                }
                else if(i == 1)
                {
                    // cout<<"j "<<j<<endl;
                    for(int k = 1; k <= j; k++)
                    {
                        segment_avg = 0.0f;
                        segment_avg2 = 0.0f;
                        for(int l = 0; l < k; l++)
                        {
                            // cout<<"l "<<l<<endl;
                            segment_avg += arr[l];
                        }
                        for(int m = k; m <= j; m++)
                        {
                            // cout<<"m "<<m<<endl;
                            segment_avg2 += arr[m];
                        }
                        max_val = max(max_val, segment_avg / k + segment_avg2 / double(j - k + 1));
                        // cout<<"svg1 "<<segment_avg<<" svg2 "<<segment_avg2<<" cur_val "<<cur_val<<" k "<<k<<endl;
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
                            // cout<<"case2 n "<<n<<" k "<<k<<endl;
                            segment_avg += arr[k];
                        }
                        cur_val = dp[i - 1][n - 1] + segment_avg / (double)(j - n + 1);
                        cout<<"cur val "<<cur_val<<" upvalue "<<dp[i - 1][n]<<" segval "<<segment_avg / (double)(j - n + 1)<<endl;
                        max_val = max(max_val, cur_val);
                    }
                    dp[i][j] = max_val;
                    //after choosing the max_val of the dp
                }
            }
        }
        cout<<"Dplist "<<endl;
        for(int i = 0 ;i < kin; i++)
        {
            for(int j = 0;j < arr.size(); j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"i3j6"<<dp[3][6]<<endl;
        return dp[kin - 1][arr.size() - 1];
    }
};
