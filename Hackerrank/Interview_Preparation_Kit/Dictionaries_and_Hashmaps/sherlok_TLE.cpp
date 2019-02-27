#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below. ie how many pairs of substring anagrams??
bool check(string s1, string s2)
{
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    int n = s1.size(), m = s2.size();
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
    
    if(mp1.size() != mp2.size())
    {
        return false;
    }

    for(unordered_map<char, int>::iterator it = mp1.begin(); it != mp1.end(); it++)
    {
        if(mp2.count(it->first)) // if same alphabet, then the amount should be the same too.
        {
            if(mp1[it->first] != mp2[it->first])
            {
                return false;
            }
        }
        else // if not just return false
        {
            return false;
        }
    }
    return true;
}

int sherlockAndAnagrams(string s) 
{
    int sz = s.size(), res = 0;
    string s1, s2;
    for(int i = 1; i <= sz; i++) // brute force finding the substring pairds starting from len 1 to len size - 1 
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
                for(int k = j + 1; k + i - 1 < sz; k++)
                {
                    s2 = s.substr(k, i);
                    // cout << "check " << s1 << " , " << s2 <<endl;
                    if(check(s1, s2))
                    {
                        // cout << " ANAGRAM! \n"; 
                        res++;
                    }
                }
            }
        }
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

