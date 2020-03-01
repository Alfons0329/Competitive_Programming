class Solution
{
public:
    string rankTeams(vector<string> &vs)
    {
        int n = vs.size();
        int m = vs[0].size();
        if (n == 1)
        {
            return vs[0];
        }

        // vii is the original data, and vii_clean is cleaned (i.e. remove all unused alphabets)
        vector<vector<int>> vii(26, vector<int>(m + 1, 0));
        vector<vector<int>> vii_clean;
        int alph = 0;
        for (auto s : vs[0])
        {
            vii[s - 'A'][0] = s;
        }
        for (auto s : vs)
        {
            int sz = s.size();
            for (int i = 0; i < sz; i++)
            {
                vii[s[i] - 'A'][i + 1]++;
            }
        }

        // make 0 away, clean
        for (auto vi : vii)
        {
            if (vi[0])
            {
                vii_clean.push_back(vi);
            }
        }

        // custom sort
        sort(vii_clean.begin(), vii_clean.end(), [](auto &a, auto &b) {
            int m = a.size();
            for (int i = 1; i < m; i++)
            {
                if (a[i] > b[i])
                {
                    return true;
                }
                else if (a[i] < b[i])
                {
                    return false;
                }
            }
            return a[0] < b[0]; // all tie, rank by ID
        });

        // concatenate the result
        string res("");
        for (auto vi : vii_clean)
        {
            res += (char)vi[0];
        }

        return res;
    }
};