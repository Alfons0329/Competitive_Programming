#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& arr)
    {
        vector<vector<int>>trans, res;
        int big = max(arr[0].size(), arr.size());
        trans.resize(big);
        FORI(trans.size())
        {
            trans[i].resize(big);
        }
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = 0; j < arr[0].size(); j++)
            {
                trans[i][j] = arr[j][i];
            }
        }

        res.resize(arr[0].size());
        FORI(res.size())
        {
            res[i].resize(arr.size());
        }
        for(int i = 0; i < trans.size(); i++)
        {
            for(int j = 0; j < trans[0].size(); j++)
            {
                res[i][j] = trans[i][j];
            }
        }
        return trans;
    }
};
