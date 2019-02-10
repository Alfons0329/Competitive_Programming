#include <bits/stdc++.h>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom)
{
    map<string, int>magmap;
    map<string, int>ranmap;
    for(int i = 0; i < magazine.size(); i++)
    {
        magmap[magazine[i]]++;
    }
    for(int i = 0; i < ransom.size(); i++)
    {
        ranmap[ransom[i]]++;
    }

    for(map<string, int>::iterator it = ranmap.begin(); it != ranmap.end(); ++it)
    {
        if(magmap[it->first] < it->second)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
