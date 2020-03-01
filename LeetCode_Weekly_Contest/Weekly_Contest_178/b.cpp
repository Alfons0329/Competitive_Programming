class Solution
{
public:
    struct data
    {
        char a;
        int sum;
        vector<int> rk;
    };
    static bool cmp(data &d1, data &d2)
    {
        sort(d1.rk.begin(), d1.rk.end());
        sort(d2.rk.begin(), d2.rk.end());
        int n = d1.rk.size();
        for (int i = 0; i < n; i++)
        {
            if (d1.rk[i] != d2.rk[i])
            {
                return d1.rk[i] < d2.rk[i];
            }
        }
        return 0;
    }
    string rankTeams(vector<string> &vs)
    {
        int n = vs.size();
        int m = vs[0].size();
        if (n == 1)
        {
            return vs[0];
        }

        int minchar = 0xff;
        vector<data> vd(26);
        vector<data> vd_clean;
        for (char x : vs[0])
        {
            minchar = min(minchar, (int)x);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vd[vs[i][j] - minchar].a = vs[i][j];
                vd[vs[i][j] - minchar].sum += (j + 1);
                vd[vs[i][j] - minchar].rk.push_back(j + 1);
            }
        }
        for (auto x : vd)
        {
            if (x.rk.size())
            {
                vd_clean.push_back(x);
            }
        }

        sort(vd_clean.begin(), vd_clean.end(), cmp);
        string res("");
        for (auto x : vd_clean)
        {
            if (x.a)
            {
                res += x.a;
            }
        }
        return res;
    }
};