class Solution 
{
public:
    vector<int> pathInZigZagTree(int label) 
    {
        int log_val = (int)log2(label);
        int sz = 2 << (log_val + 1);
        vector<int> v(sz + 5);
        
        int layer = 0;
        for(; layer <= log_val; layer++)
        {    
            int idx =  1 << layer, idx_lim =  1 << (layer + 1);
            
            if((layer + 1) % 2) // odd
            {
                while(idx < idx_lim)
                {
                    v[idx] = idx;
                    idx++;
                }
            }
            else // even
            {
                int minus = 1;
                while(idx < idx_lim)
                {
                    v[idx] = idx_lim - minus;
                    idx++;
                    minus++;
                }
            }
        }
        
        int start = 0;
        for(int i = 0; i < sz; i++)
        {
            if(v[i] == label)
            {
                start = i;
                break;
            }
        }
        
        vector<int> res;
        while(start >= 1)
        {
            res.push_back(v[start]);
            start /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
