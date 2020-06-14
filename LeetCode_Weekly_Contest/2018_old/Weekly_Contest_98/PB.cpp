class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string> res;
        for(auto it: words)
        {
            if(check(it, pattern))
            {
                res.push_back(it);
            }
        }
        return res;
    }
    bool check(string to_chk, string pat)
    {
        if(to_chk.size() != pat.size())
        {
            return false;
        }
        /*check the mapping correspondence*/
        map<char, int> chkmap;
        map<char, int> patmap;
        for(auto it : to_chk)
        {
            chkmap[it]++;
        }
        for(auto it : pat)
        {
            patmap[it]++;
        }
        /*check the changing trend*/
        for(int i = 0; i < to_chk.size() - 1; i++)
        {
            if(to_chk[i] == to_chk[i + 1])
            {
                if(pat[i] != pat[i + 1])
                {
                    return false;
                }
            }
            else
            {
                if(pat[i] == pat[i + 1])
                {
                    return false;
                }
                else if(patmap[pat[i]] != chkmap[to_chk[i]] || patmap[pat[i + 1]] != chkmap[to_chk[i + 1]]) /*such as abc and aba should not be the same, if no this part, will get wrong answer*/
                {
                    return false;
                }
            }
        }


        return true;
    }
};
