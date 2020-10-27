class Solution
{
public:
    char slowestKey(vector<int> &rt, string kp)
    {
        char res;
        int n = rt.size(), d = 0, max_d = INT_MIN;
        rt.insert(rt.begin(), 0);

        for (int i = 1; i <= n; i++)
        {
            d = rt[i] - rt[i - 1];
            max_d = max(max_d, d);
        }

        for (int i = 1; i <= n; i++)
        {
            d = rt[i] - rt[i - 1];
            if (d == max_d)
            {
                res = max(res, kp[i - 1]);
            }
        }
        return res;
    }
};