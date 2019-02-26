#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) 
{
    int max_row = arr.size(), max_col = arr[0].size(), tmp_sum = 0, res = INT_MIN;
    for(int row = 1; row < max_row - 1; row++)
    {
        for(int col = 1; col < max_col - 1; col++)
        {
            tmp_sum = 0;
            tmp_sum += (arr[row - 1][col - 1] + arr[row - 1][col] + arr[row - 1][col + 1] + arr[row][col] + arr[row + 1][col - 1] + arr[row + 1][col] + arr[row + 1][col + 1]);
                    res = max(tmp_sum, res);
        }
    }
    printf("res %d\n", res);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

