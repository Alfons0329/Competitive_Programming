class Solution
{
public:
    std::vector<string> res ,res2;
    vector<string> letterCasePermutation(string str)
    {
        dfs(str,0);
        for(int i=0;i<res.size();i++)
        {
            if()
            for(int j=i+1;j<res.size();j++)
            {
                if(res[i]==res[j])
                {
                    res[j]=".";
                }
            }
        }
        for(int i=0;i<res.size();i++)
        {
            if(res[i]!=".")
            {

            }
        }
        return res;
    }
    void dfs(string str,int pos)
    {
        if(pos==str.size())
        {
            res.push_back(str);
            return ;
        }
        str[pos] = toupper(str[pos]);
        dfs(str,pos+1);
        str[pos] = tolower(str[pos]);
        dfs(str,pos+1);
    }
};
