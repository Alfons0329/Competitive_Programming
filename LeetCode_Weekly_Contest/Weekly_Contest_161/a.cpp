class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int res = 0, n = s1.size(), m = s2.size();
        if (n != m)
        {
            return -1;
        }

        int type1 = 0, type2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] == 'x') // xy -> xy 1swap
                {
                    type1++;
                }
                else // yx -> yx 1swap
                {
                    type2++;
                }
            }
        }

        if ((type1 + type2) % 2)
        {
            return -1;
        }

        return (type1 / 2 + type2 / 2) + (type1 % 2) * 2;
    }
};