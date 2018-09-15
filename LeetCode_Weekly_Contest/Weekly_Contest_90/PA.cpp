class Solution
{
public:
    bool buddyStrings(string str_a, string str_b)
    {
        if(str_a.size() != str_b.size() || str_a.size() == 0 || str_b.size() == 0)
        {
            return false;
        }
        if(str_a == str_b) //swap two same
        {
            map<char, int> alphabet_cnt;
            for(int i = 0; i < str_a.size(); i++)
            {
                alphabet_cnt[str_a[i]]++;
                if(alphabet_cnt[str_a[i]] >= 2)
                {
                    return true;
                }
            }
        }

        int cnt = 0, dif_1, dif_2;
        for(int i = 0; i < str_a.size(); i++)
        {
            if(str_a[i] != str_b[i] && cnt == 0)
            {
                cnt++;
                dif_1 = i;
            }
            else if(str_a[i] != str_b[i] && cnt == 1)
            {
                cnt++;
                dif_2 = i;
            }
            else if(str_a[i] != str_b[i])
            {
                return false;
            }
        }
        swap(str_a[dif_1], str_a[dif_2]);
        return str_a == str_b ? true : false;
    }
};
