class Solution 
{
public:
        int dietPlanPerformance(vector<int>& c, int k, int l, int h) 
        {
            int res = 0, n = c.size();
            if(n == 1)
            {
                return 1 * (c[0] > h) - 1 * (c[0] < l); 
            }

            int prefix[MAX_N] = {0};
            prefix[1] = c[0];
            for(int i = 1; i < n; i++)
            {
                prefix[i + 1] = prefix[i] + c[i];
            }

            int sum = 0;
            for(int i = k; i <= n; i++)
            {
                sum = prefix[i] - prefix[i - k];
                if(sum < l)
                {
                    res -= 1;
                }
                else if(sum > h)
                {
                    res += 1;
                }
            }
            return res;
        }
};
