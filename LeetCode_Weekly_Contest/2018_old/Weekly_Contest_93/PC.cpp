#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<int> advantageCount(vector<int>& va, vector<int>& vb)
    {
        vector<int> res;
        sort(va.begin(), va.end());
        FORI(vb.size())
        {
            int min_val = 1e9, min_pos = 0, find = 0;
            for(int j = 0 ;j < va.size(); j++)
            {
                if(va[j] < min_val && va[j] > vb[i])
                {
                    min_pos = j;
                    min_val = va[j];
                    find = 1;
                }
            }
            if(find)
            {
                // va[min_pos] = -1;, TLE since testcase 64
                va.erase(va.begin() + min_pos); //AC
                res.push_back(min_val);
            }
            else
            {
                min_val = 1e9;
                for(int j = 0 ;j < va.size(); j++)
                {
                    if(va[j] < min_val && va[j] != -1)
                    {
                        min_pos = j;
                        min_val = va[j];
                    }
                }
                // va[min_pos] = -1;, TLE since testcase 64
                va.erase(va.begin() + min_pos); //AC
                res.push_back(min_val);
            }
        }
        return res;
    }
};
