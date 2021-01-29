class Solution
{
public:
    int len, sz, cnt;
    int numSpecialEquivGroups(vector<string>& A)
    {
        vector<bool>visit(A.size(), 0);
        vector<vector<string>> res;
        vector<string>tmp;
        len = A[0].size();
        sz = A.size();
        cnt = 0;
        for(int i = 0; i < sz - 1; i++)
        {
            if(visit[i])
            {
                continue;
            }
            else
            {
                tmp.clear();
                tmp.push_back(A[i]);//push itself
                visit[i] = true;
                for(int j = i + 1; j < sz; j ++)
                {
                    if(eqv(A[i], A[j]))
                    {
                        tmp.push_back(A[j]);
                        visit[j] = true;
                    }
                }
                cnt++;
                res.push_back(tmp);
            }
        }
        if(!visit[sz - 1]) //last one
        {
            cnt++;
        }
        return cnt;
    }
    bool eqv(string s1, string s2)
    {
        map<char, int> odd;
        map<char, int> even;
        for(int i = 0; i < len; i++)
        {
            if(i & 1)
            {
                odd[s1[i]]++;
            }
            else
            {
                even[s1[i]]++;
            }
        }

        for(int i = 0; i < len; i++)
        {
            if(i & 1)
            {
                if(odd[s2[i]] == 0)
                {
                    return false;
                }
            }
            else
            {
                if(even[s2[i]] == 0)
                {
                    return false;
                }
            }
        }
        //reverse
        odd.clear();
        even.clear();
        for(int i = 0; i < len; i++)
        {
            if(i & 1)
            {
                odd[s2[i]]++;
            }
            else
            {
                even[s2[i]]++;
            }
        }

        for(int i = 0; i < len; i++)
        {
            if(i & 1)
            {
                if(odd[s1[i]] == 0)
                {
                    return false;
                }
            }
            else
            {
                if(even[s1[i]] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
