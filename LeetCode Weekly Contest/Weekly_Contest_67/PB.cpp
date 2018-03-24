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
            cout<<"cast val "<<(int) str[i]-'a'<<endl;
            if(vec[str[i]-'a'].start == -1)
            {
                vec[str[i]-'a'].start = i;
            }
            if(i > vec[str[i]-'a'].end)
            {
                 vec[str[i]-'a'].end = i;
            }
            cout<<"Char "<<str[i]<<" From" <<vec[str[i]-'a'].start <<" to "<<vec[str[i]-'a'].end<<endl;
        }
        int max_start = vec[str[0]-'a'].start;
        int max_end = vec[str[0]-'a'].end;
        //greedy approach
        int partition = 0;
        vector<int>res;
        for (size_t i = 1; i < count; i++)
        {
            cout<<" From" <<max_start <<" to "<<max_end<<endl;
            if( vec[str[i]-'a'].start > max_start
            && vec[str[i]-'a'].start < max_end
            && vec[str[i]-'a'].end > max_end )
            {
                max_end = vec[str[i]-'a'].end;
            }
            if( i == max_end)
            {
                res.push_back(max_end - max_start + 1);
                if(i != count - 1)
                {
                    max_start = vec[str[i + 1]-'a'].start;
                    max_end = vec[str[i + 1]-'a'].end;
                }
            }
        }
        return res;
    }
};
