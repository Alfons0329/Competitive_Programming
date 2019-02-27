#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// Complete the makeAnagram function below.
int makeAnagram(string a, string b) 
{
    unordered_map<char, int> map_1; // map for string a
    unordered_map<char, int> map_2; // map for string b
    int m = a.size(), n = b.size(), res = 0, cnt = 0;
    
    for(int i = 0 ; i < m; i++)
    {
        map_1[a[i]]++;
    }

    for(int i = 0 ; i < n; i++)
    {
        map_2[b[i]]++;
    }
    // 26 alphabet characters
    for(int i = 0; i < 26; i++)
    {
        if(map_1.count('a' + i) && map_2.count('a' + i))
        {
            cnt += min(map_1['a' + i], map_2['a' + i]);
        }
    }


    return m + n - cnt * 2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

