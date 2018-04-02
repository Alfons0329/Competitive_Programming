#include <bits/stdc++.h>
using namespace std;

int number_needed(string str_a, string str_b)
{
    vector<int> count_a(26, 0);
    vector<int> count_b(26, 0);
    for(int i = 0;i < str_a.size();i++)
    {
        count_a[str_a[i] - 'a']++;
        count_b[str_b[i] - 'a']++;
    }
    int remain = 0;
    for(int i = 0;i < 26;i++)
    {
        if(count_a[i] == count_b[i])
        {
            remain += count_a[i];
        }
    }
    return 2 * (str_a.size() - remain);
}

int main()
{
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
