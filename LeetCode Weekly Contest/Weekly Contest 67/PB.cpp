class Solution
{
public:
    struct stend
    {
        char alpha;
        int start, end;
    };
    bool mycompare(stend s1, stend s2)
    {
        return s1.start < s2.start;
    }

    vector<int> partitionLabels(string str)
    {
        int count = str.size();
        vector<stend> vec;
        vec.resize(26);
        for(int i = 0; i < 26; i++)
        {
            vec[i].start = -1;
            vec[i].end = 0;
            vec[i].alpha = 0;
        }
        vec[str[0]-'a'].start = 0;
        for (size_t i = 1; i < count; i++)
        {
            /* code */
            vec[str[i]-'a'].alpha = str[i];
            if(vec[str[i]-'a'].start == -1)
            {
                vec[str[i]-'a'].start = i;
            }
            if(i > vec[str[i]-'a'].end)
            {
                 vec[str[i]-'a'].end = i;
            }
        }




        int min_start = vec[str[0]-'a'].start;
        int max_end = vec[str[0]-'a'].end;
        //greedy approach
        int partition = 0;
        vector<int>res;
        for (size_t i = 0; i < count; i++)
        {
            if( vec[str[i]-'a'].start > min_start
            && vec[str[i]-'a'].start < max_end
            && vec[str[i]-'a'].end > max_end )
            {
                max_end = vec[str[i]-'a'].end;
            }

            if(i == max_end || i == count - 1)//last will definitely cut over to match. just in case
            {
                if(i != count - 1)
                {
                    res.push_back(max_end - min_start + 1);
                    min_start = vec[str[i + 1]-'a'].start;
                    max_end = vec[str[i + 1]-'a'].end;
                }
                else
                {
                    res.push_back(max_end - min_start + 1); // a special case
                }
            }
        }
        return res;
    }
};
