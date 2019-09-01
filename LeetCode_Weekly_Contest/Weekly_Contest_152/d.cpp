class Solution 
{
public:
    vector<int> findNumOfValidWords(vector<string>& w, vector<string>& p) 
    {
        vector<int> res;
        int n = w.size(), m = p.size();
        int bit = 0, sz = 0;
        vector<int> pb;
        vector<int> wb;
        
        for(int i = 0; i < m; i++)
        {
            sz = p[i].size();
            bit = 0;
            for(int j = 0; j < sz; j++)
            {
                bit |= (1 << p[i][j] - 'a');
            }
            pb.push_back(bit);
        }
        
        for(int i = 0; i < n; i++)
        {
            sz = w[i].size();
            bit = 0;
            for(int j = 0; j < sz; j++)
            {
                bit |= (1 << w[i][j] - 'a');
            }
            wb.push_back(bit);
        }
        
        
        for(int i = 0; i < m; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                int fir = p[i][0] - 'a';
                
                if(((wb[j] >> fir) & 1) &&(wb[j] & pb[i]) == wb[j])
                {
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};