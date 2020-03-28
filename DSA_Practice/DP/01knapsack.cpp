#include <bits/stdc++.h>

using namespace std;

// solve 0-1 knapsack problem 
// input arguments
// v: the value vector where v[i] is the value of ith object
// w: the value vector where w[i] is the weight of ith object
// limit: the weight limit of backpack 
// 
// dp[i][j] is the maximum value that can be achieved up until i th object and weight j 
int knapsack_01(vector<int> v, vector<int> w, int limit){

    for(auto x : v){
        cout << x << ' ';
    }
    cout << '\n';

    for(auto x : w){
        cout << x << ' ';
    }
    cout << '\n';

    int n = v.size();
    vector<vector<int> > dp(n + 5, vector<int>(limit + 5, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= limit; j++){
            // if current item <= current weight, then use it (or not)
            // if use it, query the alread-solved subproblem ()
            // if not use it, just assign the best value of dp[i - 1][j]
            if(w[i - 1] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
            // otherwise we are not able to use such item
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= limit; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return dp[n][limit];
}

// main driver function
int main(){
    // IO
    int n, limit;
    cin >> n;
    vector<int> v(n, 0);
    vector<int> w(n, 0);

    cout << "value array of size " << n << ":\n";
    for(int& x : v){
        cin >> x;
    }
    cout << "weight array of size " << n << ":\n";
    for(int& x : w){
        cin >> x;
    }

    // solve
    cout << "weight limit: " << '\n'; 
    cin >> limit;
    cout << "dp max value " << knapsack_01(v, w, limit);
    return 0;
}
