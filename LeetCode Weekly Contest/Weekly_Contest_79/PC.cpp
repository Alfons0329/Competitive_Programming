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
                    cout<<" i "<<i <<" j "<<j<<endl;
                    for(int n = j; n >= i; n--) //let's say the slice is zero based, for the i th slice, the smallest group
                    //should contain at least i element ex: 1 2 3 4 for 3 slice then at least in DP 12 [3 4](grouped for current slice) is OK
                    //but for 1 [2 3 4](grouped for current slice) is not right
                    {
                        segment_avg = 0.0f;
                        for(int k = j; k >= n; k--) //forward to accumulate and the average
                        /*
                        let's say the slice is zero based, for the n th slice.
                        ex: for 1 2 3 4 5 and slice for 3 ()as the slice group need to search for the 2-slice of best line(row)
                        we will then check (1 2 3 4)(search for i = slice - 1 for the SUBPROBLEM OF SIZE - 1 and j = 3 (since 1 2 3 4 till 4th element)) [5]
                        which is value = dp[2][3] + avg(5) = 8.5 + 5 = 13.5
                        the same is true for
                        (1 2 3) [4 5] value =  dp[2][2] + avg(4 5) = 6 + 4.5 = 10.5
                        (1 2) [3 4 5] value = dp[2][1] + avg(3,4,5) =
                        (1) [2 3 4 5] //unable to do since the smallest group is less then i - 1 = 3 - 1 = 2
                        then we take the max value of these calculation for dp[i][j]
                        */
                        {
                            segment_avg += arr[k];
                        }
                        //the other part of from 0 to i - 1 there are i elements to search for the previous saved (best value) dp grid
                        cur_val = dp[i - 1][n - 1] + segment_avg / (double)(j - n + 1);
                        cout<<"cur val "<<cur_val<<endl;
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
