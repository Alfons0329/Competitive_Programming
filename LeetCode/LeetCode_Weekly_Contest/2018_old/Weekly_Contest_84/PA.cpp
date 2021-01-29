#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& arr)
    {
        FORI(arr.size())
        {
            reverse(arr[i].begin(), arr[i].end());
        }
        FORI(arr.size())
        {
            for(int j = 0; j < arr[i].size(); ++j)
            {
                arr[i][j] ^= 1;
            }
        }
        return arr;
    }
};
