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
            // cur_max = 0;
            // j = 0;
            while(j < vpii.size() && wk[i] >= vpii[j].first) /*update the new job only when the higher ability worker is encountered
            otherwise the duplicated will remain the same(iteratr through the end of same difficulty but get the highest amng the interval)
            ex dif[1,2,3,3] profit[2,5,3,1] worker[3,3,3] throught the iteration the j will reach the end but get max profit of 5 and result in 15
            in short this will get the max profit with corresponding difficulty below the ability of current worker thus save time*/
            {
                cur_max = max(cur_max, vpii[j].second);
                // printf("Cur max %d \n", cur_max);
                ++j;
            }
            // printf("Final j %d \n", j);
            res += cur_max;
        }
        return res;
    }
};
