class Solution 
{
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int x) 
    {
        int res = 0, l_sum = 0, r_sum = 0, x_sum = 0, n = c.size(), x2 = x;
        c.insert(c.begin(), 0); //padding
        g.insert(g.begin(), 0); //padding
        vector<int> prefix_sum(n + 2, 0);
        
        for(int i = 1; i <= n; i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + (g[i] == 0 ? c[i] : 0);
            if(x2 >= 1)
            {
                x_sum += c[i - 1];
            }
            x2--;
        }
        prefix_sum[n + 1] = prefix_sum[n];
        
        for(int i = 1; i <= n - x + 1; i++)
        {
            l_sum = prefix_sum[i - 1];
            x_sum = x_sum + c[i + x - 1] - c[i - 1];
            r_sum = prefix_sum[n] - prefix_sum[i + x - 1];
            
            res = max(res, l_sum + x_sum + r_sum);
        }
        
        return res;
    }
};