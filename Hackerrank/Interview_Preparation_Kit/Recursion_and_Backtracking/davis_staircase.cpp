#include <bits/stdc++.h>
#define MAX_N 37
using namespace std;

// Complete the stepPerms function below.
int dp[MAX_N] = {0}; // cache
int stepPerms(int n) 
{
    if(n == 1)
    {
        dp[1] = 1;
        return 1;
    }
    else if(n == 2) // 1 1, 2
    {
        dp[2] = 2;
        return 2;
    }
    else if(n == 3) // 1 1 1, 1 2, 2 1, 3
    {
        dp[3] = 4;
        return 4;
    }
    else
    {
        if(dp[n - 1] != 0 && dp[n - 2] != 0 && dp[n - 3] != 0) // cached before
        {
            dp[n] = dp[n - 1] + dp [n - 2] + dp[n - 3];
        }
        else
        {
            dp[n] = stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
        }
    }
    printf("dp %d is %d\n", n, dp[n]);
    return dp[n];
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
