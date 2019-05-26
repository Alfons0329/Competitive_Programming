class Solution 
{
    public:
        struct data
        {
            int v;
            int f;
        };

        static bool cmp(data d1, data d2)
        {
            return d1.f > d2.f;
        }

        vector<int> rearrangeBarcodes(vector<int>& b) 
        {
            int n = b.size();
            if(n == 1)
            {
                return b;
            }

            map<int, int> m;
            vector<data> vd;
            for(auto i : b)
            {
                m[i]++;
            }
            auto it = m.begin();
            data d;
            for(; it != m.end(); it++)
            {
                d.v = it -> first;
                d.f = it -> second;
                vd.push_back(d);
            }

            sort(vd.begin(), vd.end(), cmp);
            int sz = vd.size(), idx = 0;
            vector<int>res(n);
            for(int i = 0; i < n; i += 2) // odd pos
            {
                res[i] = vd[idx].v;
                vd[idx].f--;
                if(vd[idx].f == 0)
                {
                    idx++; // use second highest freq
                }
            }
            for(int i = 1; i < n; i += 2)
            {
                res[i] = vd[idx].v;
                vd[idx].f--;
                if(vd[idx].f == 0)
                {
                    idx++; // use second highest freq
                }
            }
            return res;
        }
};
