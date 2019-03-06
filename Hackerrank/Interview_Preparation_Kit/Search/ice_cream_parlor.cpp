#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
struct cost_data
{
    int pos;
    int cnt;
};
// Complete the whatFlavors function below. This question is equivalent to whether 2 numbers add up to certain number K
void whatFlavors(vector<int> cost, int money) 
{
    // init
    unordered_map<int, cost_data> mymap; // for statistical purpose of cost and its occurance
    int n = cost.size();
    for(int i = 0; i < n ; i++)
    {
        mymap[cost[i]].pos = i + 1;
        mymap[cost[i]].cnt++;
    }

    // iterate map process
    int cost_1 = 0, cost_2 = 0;
    for(int i = 0; i < n ; i++)
    {
        cost_1 = cost[i];
        cost_2 = money - cost_1;
        if(cost_2 == cost_1) // should be exisiting at least 2
        {
            if(mymap[cost_1].cnt == 2) // due to unique solution, print second
            {
                printf("%d %d\n", i + 1, mymap[cost_1].pos); // 1-base
                return;
            }
        }
        else
        {
            if(mymap[cost_2].cnt == 1) //exists for the other cost
            {
                printf("%d %d\n", i + 1, mymap[cost_2].pos);  // 1-base
                return;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
