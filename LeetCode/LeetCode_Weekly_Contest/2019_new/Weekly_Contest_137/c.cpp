class Solution 
{
public:
    bool check(string s1, string s2) // s2 should be a predecessor of s1, i.e. s2 is longer
    {
        int m = s1.size(), n = s2.size(), i = 0, j = 0;
        int cnt = 0;
        while(i < m && j < n)
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                while(j < n && s1[i] != s2[j])
                {
                    j++;
                    cnt++;
                    if(cnt > 1)
                    {
                        return false;
                    }
                }
            }
        }
        
        return cnt <= 1 ? true : false;
    }
    
    static bool cmp(string s1, string s2)
    {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& w) 
    {
        int n = w.size();
        vector<int> dp(1005, 1);
        sort(w.begin(), w.end(), cmp);
        
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(w[j].size() - w[i].size() == 1 && check(w[i], w[j]))
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
