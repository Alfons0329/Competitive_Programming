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
    
    map<int, int> freq_cnt; // order matters
    for(unordered_map<char, int>::iterator it = map_1.begin() ;it != map_1.end(); it++)
    {
        freq_cnt[it -> second]++;
    }
    if(freq_cnt.size() > 2)
    {
        return "NO";
    }
    else if(freq_cnt.size() == 1) // all the same frequency, ex aabbccddee, we only have 2 : 5
    {
        return "YES";
    }

    map<int, int>::iterator it = freq_cnt.begin();
    int f1 = it -> first;
    int lower_freq_cnt = it -> second; 

    map<int, int>::iterator it2 = ++it;
    int f2 = it2 -> first;
    int higher_freq_cnt = it2 -> second;
    
    int lower_freq = min(f1, f2), higher_freq = max(f1, f2);

    if(lower_freq == 1 && lower_freq_cnt == 1)
    {
        return "YES";
    }
    else if(higher_freq - lower_freq == 1 && higher_freq_cnt == 1) // remove the only 1 freq to satisfy thr string such as aaaab 4 : 1 and 1 : 1 or aabbbcc 2 : 2 3 : 1
    {
        return "YES";
    }
    else if(higher_freq - lower_freq > 1) // things like aabbcccc 2 : 2 and 4 : 1 where, lower_freq = 2, higher_freq = 4 should remove 2
    {
        return "NO";
    }
    
    return "NO";
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

