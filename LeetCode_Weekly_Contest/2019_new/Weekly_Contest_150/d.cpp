class Solution 
{
    public:
        string lastSubstring(string_view s) 
        {
            string_view res;
            int sz = s.size();
            for(int i = 0; i < sz; i++)
            {
                if(s.substr(i) > res)
                {
                    res = s.substr(i);

                }

            }
            return string(res);

        }

};
