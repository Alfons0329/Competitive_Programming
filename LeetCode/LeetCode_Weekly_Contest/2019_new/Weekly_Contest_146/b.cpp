class Solution 
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) 
    {
        vector<int>res;
        int rn = red.size(), bn = blue.size();
        res.push_back(0); 
        
        for(int i = 1; i < n; i++)
        {
            int r_len = INT_MAX, b_len = INT_MAX, find = 0;
            for(int j = 0; j < rn; j++)
            {
                vector<bool>vis(n, 0);
                if(red[j][0] == 0)
                {
                    int cr_len = bfs(1, 0, red[j][1], i ,vis, red, blue);
                    if(cr_len > 0)
                    {
                        find = 1;
                        r_len = min(cr_len, r_len);
                    }
                }
            }
            
            for(int j = 0; j < bn; j++)
            {
                vector<bool>vis(n, 0);
                if(blue[j][0] == 0)
                {
                    int cb_len = bfs(1, 1, blue[j][1], i, vis, red, blue);
                    if(cb_len > 0)
                    {
                        b_len = min(cb_len, b_len);
                        find = 1;
                    }
                }
            }
            
            if(find)
            {
                res.push_back(min(b_len, r_len));
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
    }
    
    int bfs(int len, int color_now, int start, int target, vector<bool>& vis, vector<vector<int>>& red, vector<vector<int>>& blue)
    {
        if(start == target)
        {
            return len;
        }
        
        vis[start] = 1;
        
        int rn = red.size(), bn = blue.size(), has = 0;
        if(color_now == 0)
        {
            for(int i = 0; i < bn; i++)
            {
                if(blue[vis[i]][1] == 0)
                {
                    dfs(len + 1, 1, blue[i][1], target, vis, red, blue);
                    has = 1;
                }
            }
        }
        else
        {
            for(int i = 0; i < rn; i++)
            {
                if(red[vis[i]][1] == 0)
                {
                    dfs(len + 1, 0, red[i][1], target, vis, red, blue);
                    has = 1;
                }
            }
        }
        return -1;
    }
};
