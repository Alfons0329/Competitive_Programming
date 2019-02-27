#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below. ie how many pairs of substring anagrams??
int sherlockAndAnagrams(string s) 
{
    int sz = s.size();
    
    for(int i = 1; i < sz - 1; i++) // brute force finding the substring pairds starting from len 1 to len size - 1 
    {


    

    }
}
bool check(string s1, string s2)
{
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    int n = s1.size(), m = str2.size();
    if(n != m)
    {
        return false;
    }

    for(int i = 0; i < s1.size(); i++)
    {
        mp1[s1[i]]++;
        mp2[s2[i]]++;
    }

    //check map composition
    for(auto& it : mp1)
    {
        if(mp2.count(it))
        {
            return false;
        }
    }
    return true;
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

