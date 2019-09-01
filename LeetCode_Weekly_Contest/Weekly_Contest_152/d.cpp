class Solution 
{
public:
    vector<int> findNumOfValidWords(vector<string>& w, vector<string>& p) 
    {
        vector<int> res;
        int n = w.size(), m = p.size();
        int bit = 0, sz = 0;
        vector<bitset<26>> pb;
        vector<bitset<26>> wb;
        
        for(int i = 0; i < m; i++)
        {
            sz = p[i].size();
            bit = 0;
            for(int j = 0; j < sz; j++)
            {
                bit |= (1 << p[i][j] - 'a');
            }
            bitset<26> tmp(bit);
            pb.push_back(tmp);
        }
        
        for(int i = 0; i < n; i++)
        {
            sz = w[i].size();
            bit = 0;
            for(int j = 0; j < sz; j++)
            {
                bit |= (1 << w[i][j] - 'a');
            }
            bitset<26> tmp(bit);
            wb.push_back(tmp);
        }
        
        
        for(int i = 0; i < m; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                int flg1 = 1, flg2 = 0, idx = 0;
                while(idx < 26)
                {
                    if(pb[i][idx] < wb[j][idx])
                    {
                        flg1 = 0;
                        break;
                    }
                    idx++;
                }

                if(wb[j][p[i][0] - 'a'])
                {
                    flg2 = 1;
                }
                if(flg1 && flg2)
                {
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};