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
            
            set<char> char_cnt;
            for(int j = 0; j < sz; j++)
            {
                bit |= (1 << w[i][j] - 'a');
                char_cnt.insert(w[i][j]);
            }
            if(char_cnt.size() <= 7)
            {
                wb.push_back(bit);
            }
        }
        
        n = wb.size();
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