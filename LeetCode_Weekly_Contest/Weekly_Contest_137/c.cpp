class Solution 
{
public:
    bool check(string s1, string s2)
    {
        map<char, int>m;
        for(auto i : s1)
        {
            m[i]++;
        }
        
        int cnt = 0;
        for(auto i : s2)
        {   
            if(m[i] == 0)
            {
                cnt++;
            }
            if(cnt > 1)
            {
                return false;
            }
        }
        if(cnt == 1)
        {
            // printf("%s and %s diff by 1 \n", s1.c_str(), s2.c_str());
        }
        return cnt == 1 ? true : false;
    }
    
    static bool cmp(string s1, string s2)
    {
        return s1.size() < s2.size();
    }
    
    void print_v(vector<string>& w)
    {
        printf("word ");
        for(auto i : w)
        {
            cout << i << ' ';
        }
        printf("\n");
    }
    int longestStrChain(vector<string>& w) 
    {
        
        int n = w.size();
        if(n == 1)
        {
            return 1;
        }
        vector<int>dp(1005, 1);
        
        sort(w.begin(), w.end(), cmp);
        print_v(w);
        
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(w[j].size() - w[i].size() == 1 && check(w[i], w[j]))
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            printf("dp ");
            for(int i = 0; i < n; i++)
            {
                printf("%d ", dp[i]);
            }
            printf("\n");
        }
        return *max_element(dp.begin(), dp.end());
    }
};
