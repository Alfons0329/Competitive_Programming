#define FORI(n) for(int i = 0; i < n; ++ i)
#define pb push_back
class Solution
{
public:
    int expressiveWords(string str, vector<string>& words)
    {
        int res = 0, can = 0, cnt = 0, total_len = 0, extend_len = 0, group_len;
        for(int i = 0;i < words.size();i++)
        {
            can = 1;
            int k = 0;
            total_len = words[i].size();
            for(int j = 0;j < words[i].size();)
            {
                extend_len = 0;
                group_len = 1;
                if(words[i][j] != str[k])
                {
                    can = 0;
                    break;
                }
                else
                {
                    while(j != words[i].size() - 1 && words[i][j + 1] == words[i][j]) //extend the length of substr to be fond
                    {
                        j++;
                        group_len++;
                    }
                    while(1) //able to extend
                    {
                        if(words[i][j] == str[k])
                        {
                            k++;
                            extend_len++;
                        }
                        else
                        {
                            break;
                        }
                    }

                    //last character extend
                    while(k < str.size() && j == words[i].size()-1)
                    {
                        if(words[i][j] == str[k])
                        {
                            k++;
                            extend_len++;
                        }
                        else
                        {
                            can = 0;
                            break;
                        }
                    }

                    if(extend_len < group_len)
                    {
                        can = 0;
                        break;
                    }

                    if(extend_len >= 3) //if extend, should >=3 (as a group per unit)
                    {
                        total_len += extend_len - group_len ;
                    }
                    j++;
                }
            }
            if(total_len != str.size())
            {
                can = 0;
            }
            if(can)
            {
                res++;
            }
        }
        return res;
    }
};
