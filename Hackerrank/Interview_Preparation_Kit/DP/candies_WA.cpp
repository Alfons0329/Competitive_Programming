#include <bits/stdc++.h>

using namespace std;
template <typename T>
void print_vec(vector<T> vec)
{
    int n = vec.size();
    for(int i = 0; i < n; i++)
    {
        cout << vec[i] <<' ';
    }
    cout << endl;
}
 
// Complete the candies function below.
long candies(int n, vector<int> arr) 
{
    int m = arr.size();
    vector<char> trend(m, 0);

    // init
    for(int i = 0; i < m - 1; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            trend[i + 1] = 'u';
        }
        else if(arr[i] == arr[i + 1])
        {
            trend[i + 1] = 'e';
        }
        else
        {
            trend[i + 1] = 'd';
        }
    }
    vector<int> dp(m, 0);
    vector<int> d_behind(m, 0);
    dp[0] = arr[0] < arr[1] ? 1 : 2;

    int cnt = 0;
    for(int i = 1; i < m - 1; i++)
    {
        if(trend[i] == 'd')
        {
            cnt = 0;
            for(int j = i + 1; j < m; j++)
            {
                if(trend[j] != 'd')
                {
                    break;
                }
                else if(trend[j] == 'd')
                {
                    cnt++;
                }
            }
            d_behind[i] = cnt;
        }
    }
    cout << 0 << " ";
    print_vec(trend); 
    print_vec(d_behind); 
    // dp process
    for(int i = 1; i < m; i++)
    {
        if(trend[i] == 'u')
        {
           dp[i] = dp[i - 1] + 1;
        }
        else if(trend[i] == 'e')
        {
            dp[i] = min(dp[i - 1] - 1 > 1 ? dp[i - 1] - 1 : 1, d_behind[i + 1] + 1);
        }
        else
        {
            dp[i] = min(dp[i - 1] - 1 > 1 ? dp[i - 1] - 1 : 1, d_behind[i] + 1);
        }
    }
    
    print_vec(dp);

    int res = 0;
    for(int i = 0; i < m; i++)
    {
        res += dp[i];
    }
    printf("res %d\n", res);
    return res;

}
   
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

