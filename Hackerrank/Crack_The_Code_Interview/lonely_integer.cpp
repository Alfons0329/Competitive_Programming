#include <bits/stdc++.h>
using namespace std;

int lonely_integer(vector < int > arr)
{
    if(arr.size() == 1)
    {
        return arr[0];
    }
    sort(arr.begin(), arr.end());
    map<int ,int>mymap;
    for(int i = 0; i < arr.size(); i++)
    {
        mymap[arr[i]]++;
    }
    int res;
    for(map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
    {
        if(it->second == 1)
        {
            res = it->first;
            break;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << lonely_integer(a) << endl;
    return 0;
}
