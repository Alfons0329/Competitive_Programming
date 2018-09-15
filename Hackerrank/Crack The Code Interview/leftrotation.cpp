#include <bits/stdc++.h>
using namespace std;

vector<int> array_left_rotation(vector<int> arr, int n, int k)
{
    vector<int> res(arr.size(), 0);
    int pos;
    for(int i = 0 ; i < arr.size(); i++)
    {
        if(i - k >= 0)
        {
            pos = (i - k) % arr.size();
        }
        else
        {
            pos = arr.size() + i - k;
        }
        res[pos] = arr[i];
    }
    return res;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
