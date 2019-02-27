#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Complete the isValid function below.
string isValid(string s) 
{
    unordered_map<char, int> map_1; // stat data for character occurance
    string res;
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        map_1[s[i]]++;
    }

    cout << "kk" << endl;
    unordered_map<int, int> map_2; // stat data for occurance of character occurance
    for(unordered_map<char, int>:: iterator it = map_1.begin(); it != map_1.end(); it++)
    {
        map_2[it -> second]++;
    }

    cout << "kk" << endl;
    if(map_2.size() > 2)
    {
        res = "NO";
        return res;
    }

    cout << "kk" << endl;
    // compare the remain 2 elemet
    unordered_map<int, int>:: iterator it1 = map_2.begin();
    unordered_map<int, int>:: iterator it2 = map_2.end();
    cout << "it1sec " << it1 -> second << "  it2sec   " << it2 -> second << endl;
    res = (abs(it1 -> second - it2 -> second) > 1) ? "NO" : "YES";
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

