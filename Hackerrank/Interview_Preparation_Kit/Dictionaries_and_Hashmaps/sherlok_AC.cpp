#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) 
{
    int sz = s.size(), res = 0;
    string s1;
    unordered_map<char, int> map_1;
    unordered_map<string, int> map_2;

    for(int i = 0; i < sz; i++) // calculate len = 1 first and use n * (n - 1) / 2 to save time
    {
        map_1[s[i]]++;
    }

    for(unordered_map<char, int>::iterator it = map_1.begin(); it != map_1.end(); it++)
    {
        res += it -> second * (it -> second  - 1) / 2;
    }

    for(int i = 2; i <= sz; i++)
    {
        for(int j = 0; j < sz; j++)
        {
            if(j + i - 1 >= sz)
            {
                break;
            }
            else
            {
                s1 = s.substr(j, i); // master string
                sort(s1.begin(), s1.end());
                map_2[s1]++;
            }
        }
    }
    printf("slen %llu, map size %d\n", s.length(), map_2.size());
    for(unordered_map<string, int>::iterator it = map_2.begin(); it != map_2.end(); it++)
    {
        res += it -> second * (it -> second  - 1) / 2;
    }

    printf("res %d\n", res);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) 
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

