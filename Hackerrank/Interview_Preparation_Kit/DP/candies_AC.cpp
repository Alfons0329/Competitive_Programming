#include <bits/stdc++.h>
#define ull unsigned long long
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
    vector<ull> left_cont_less_cnt(m, 0);
    vector<ull> right_cont_less_cnt(m, 0);

    // init
    for(int i = 0; i < m - 1; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            left_cont_less_cnt[i + 1] = left_cont_less_cnt[i] + 1;
        }
    }

    for(int i = m - 1; i >= 1; i--)
    {
        if(arr[i - 1] > arr[i])
        {
            right_cont_less_cnt[i - 1] = right_cont_less_cnt[i] + 1;
        }
    }

    // dp process
    ull res = 0;

    print_vec(left_cont_less_cnt);
    print_vec(right_cont_less_cnt);

    for(int i = 0; i < m; i++)
    {
        res += max(left_cont_less_cnt[i], right_cont_less_cnt[i]) + 1;
    }
    printf("res %llu\n", res);
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


