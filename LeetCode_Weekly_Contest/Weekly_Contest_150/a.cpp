class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        map<char, int> m;
        for(auto x : chars)
        {
            m[x]++;
        }
        
        int n = words.size(), res = 0;
        for(int i = 0; i < n; i++)
        {
            map<char, int> m2;
            for(auto x : words[i])
            {
                m2[x]++;
            }
            int ok = 1;
            auto it = m2.begin();
            while(it != m2.end())
            {
                if(it -> second > m[it -> first])
                {
                    ok = 0; 
                    break;
                }
                else
                {
                    it++;
                }
            }
            if(ok)
            {
                res += words[i].size();
            }
        }
        return res;
    }
};