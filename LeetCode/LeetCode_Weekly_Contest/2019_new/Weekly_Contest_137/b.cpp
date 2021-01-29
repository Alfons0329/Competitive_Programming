class Solution 
{
public:
    bool check(string s)
    {
        int n = s.size();
        if(n < 2)
        {
            return true;
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == s[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    string removeDuplicates(string s) 
    {
        while(check(s) == false)
        {
            for(int i = 0; i < s.size() - 1; i++)
            {
                if(s[i + 1] == s[i])
                {
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + i);
                }
                if(s.size() < 2)
                {
                    break;
                }
            }
        }
        return s;
    }    
};
