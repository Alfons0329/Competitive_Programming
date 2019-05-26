class Solution 
{
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int X) 
    {
        int res = 0, l_sum = 0, r_sum = 0, n = c.size(), interval = 0;
        
        for(int i = 0; i < X; i++)
        {
            interval += c[i];
        }
        
        for(int i = X; i < n; i++)
        {
            if(g[i] == 0)
            {
                r_sum += c[i];
            }
        }
        res = max(res, r_sum + interval);
        
        for(int i = 1; i <= n - X; i++)
        {
            interval = interval - c[i - 1] + c[i + X - 1];
            
            l_sum = 0;
            for(int j = i - 1; j >= 0; j--)
            {
                if(g[j] == 0)
                {
                    l_sum += c[j];
                }
            }
            
            // printf("left  %d ", l_sum);
            r_sum = 0;
            for(int j = i + X; j < n; j++)
            {
                if(g[j] == 0)
                {
                    r_sum += c[j];
                }
            }
            // printf("right  %d ", r_sum);
            // printf("interval  %d \n", interval);
            
            res = max(res,l_sum + interval + r_sum);
        }
        
        return res;
    }
};
