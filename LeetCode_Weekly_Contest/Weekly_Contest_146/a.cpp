class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) 
    {
        int res = 0, n = d.size();
        map<pair<int, int>, int> m;
        
        for(int i = 0; i < n; i++)
        {
            if(d[i][0] > d[i][1])
            {
                m[make_pair(d[i][1], d[i][0])]++;                
            }
            else
            {
                m[make_pair(d[i][0], d[i][1])]++;                
            }
        }
        
        auto it = m.begin();
        while(it != m.end())
        {
            if(it -> second > 1)
            {
                res += (it -> second) * (it -> second - 1) / 2 ;
            }
            it++;
        }
        return res;
        
    }
};
