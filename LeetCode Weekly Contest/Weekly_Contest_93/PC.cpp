#define FORI(n) for(int i = 0; i < n; ++ i)

class Solution
{
public:
    vector<int> advantageCount(vector<int>& va, vector<int>& vb)
    {
        vector<int> res;
        vector<bool> used(va.size(), false);
        FORI(vb.size())
        {

            vector<int>::iterator lb = lower_bound(va.begin(), va.end(), vb[i]);
            printf("%d , %d\n",*lb ,vb[i]);
            if(used[lb - va.begin()] == false)
            {
                res.push_back(va[lb - va.begin()]);
                printf("has ub min_val %d\n", va[lb - va.begin()]);
                used[lb - va.begin()] = true;
            }
            else
            {
                int min_val = 100000000, min_pos = 0;
                for(int i = 0; i < va.size(); i++)
                {
                    if(va[i] < min_val && used[i] == false) //just take the smallest to put
                    {
                        min_pos = i;
                        min_val = va[i];
                    }
                }
                used[min_pos] = true;
                res.push_back(min_val);
                printf("no ub min_val %d\n", min_val);
            }
        }
        return res;
    }
};
