class Solution
{
public:
    int numMatchingSubseq(string str, vector<string>& words)
    {
        int cnt = 0;
        map<string,int> mymap;
        for(int i=0 ;i<words.size();i++)
        {
            mymap[words[i]]++;
        }
        for(std::map<string,int>::iterator it=mymap.begin() ;it!=mymap.end();it++)
        {
            std::size_t fd = str.find(it->first);
            cout<<it->first<<" , "<<it->second<<endl;
            if(it->first.size()>str.size())
            {
                continue;
            }
            else if(fd != std::string::npos)
            {
                cnt+=it->second;
            }
            else if(issubseq(it->first, str, it->first.size(), str.size()))
            {
                cnt+=it->second;
            }
        }
        return cnt;
    }
    bool issubseq(string str1, string str2, int len1, int len2)
    {
        int same_idx = 0;
        for(int i=0;i<len2 && same_idx<len1;i++)
        {
            if(str1[same_idx] == str2[i])
                same_idx++;
        }
        return (same_idx==len1);
    }
};
