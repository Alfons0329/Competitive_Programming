class Solution
{
public:
    bool chk(vector<int> &nums, int l, int r)
    {
        if (r - l == 1)
        {
            return true;
        }
        vector<int> v;
        for (int i = l; i <= r; i++)
        {
            v.emplace_back(nums[i]);
        }
        sort(v.begin(), v.end());
        int d = v[1] - v[0];
        for (int i = 1; i < v.size() - 1; i++)
        {
            if (v[i + 1] - v[i] != d)
            {
                return false;
            }
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> res;
        for (int i = 0; i < r.size(); i++)
        {
            if (chk(nums, l[i], r[i]))
            {
                res.emplace_back(true);
            }
            else
            {
                res.emplace_back(false);
            }
        }

        return res;
    }
};