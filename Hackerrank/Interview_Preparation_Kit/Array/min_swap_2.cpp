#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int dfs_circle(const vector<int>& arr_padded, int cur_pos, int arrow_cnt, int start_num, vector<bool>& visited)
{
    visited[cur_pos] = true;// mark current node as traversed
    
    cur_pos = arr_padded[cur_pos]; // move to the next one
    if(visited[cur_pos] == false)
    {
        arrow_cnt = dfs_circle(arr_padded, cur_pos, arrow_cnt + 1, start_num, visited); // keep dfs-ing
    }
    return arrow_cnt;

}
int minimumSwaps(vector<int> arr) 
{
    int n = arr.size(), res = 0;
    vector<int> arr_padded(arr.begin(), arr.end());
    arr_padded.insert(arr_padded.begin(), INT_MAX);

    vector<bool> visited(n + 1, false);
    bool finished_all = true;
    for(int i = 1; i < n + 1;)
    {
        if(arr_padded[i] == i) // already in the right position, no need for dfs, to avoid stackoverflow
        {
            i++;
            continue;
        }
        else
        {
            finished_all = true; // search for the untraversed node
            for(int j = 1; j < n + 1; j++)
            {
                if(visited[j] == false)
                {
                    i = j;
                    finished_all = false;
                    break;
                }
            }

            if(finished_all == false) // and traverse such node
            {

                res += dfs_circle(arr_padded, i, 0, arr_padded[i], visited);
            }
        }
        if(finished_all) // break if all the nodes have been traversed
        {
            break;
        }
    }
    printf("final res %d\n", res);
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
            return x == y and x == ' ';
            });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


