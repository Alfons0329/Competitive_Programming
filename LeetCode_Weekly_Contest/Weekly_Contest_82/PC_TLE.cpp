#define ALL(X) (X).begin(), (X).end()
class Solution
{
public:
    bool mycompare(pair<int, int>p1, pair<int, int>p2)
    {
        return p1.first < p2.first;
    }
    int maxProfitAssignment(vector<int>& dif, vector<int>& pf, vector<int>& wk)
    {
        sort(ALL(wk));
        vector<pair<int, int>> vpii;
        for(int i = 0;i < dif.size(); ++i)
        {
            vpii.push_back(make_pair(dif[i], pf[i]));
        }
        sort(ALL(vpii));
        int power = 0, pos = 0, res = 0, cur_max = 0;
        int j = 0;
        for(int i = 0;i < wk.size(); ++i)
        {
            pos = 0;
            cur_max = 0;
            j = 0;
            for(int j = 0; j < vpii.size(); ++j)
            {
                if(wk[i] >= vpii[j].first)
                {
                    cur_max = max(cur_max, vpii[j].second);
                }
                else
                {
                    break;
                }
            }
            res += cur_max;
        }
        return res;
    }
};
