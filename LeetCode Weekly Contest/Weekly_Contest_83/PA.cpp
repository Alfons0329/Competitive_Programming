#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string str)
    {
        vector<pair<int, int>>count_vec;
        vector<vector<int>> res;
        int cnt = 1, start_pos = 0, check = 0;
        FORI(str.size() - 1)
        {
            if(!check)
            {
                start_pos = i;
            }

            if(str[i] == str[i+1])
            {
                cnt++;
                check = 1;
            }
            else if(i != str.size() - 2)
            {
                if(cnt >= 3)
                {
                    count_vec.push_back(make_pair(start_pos, i));
                }
                check = 0;
                cnt = 1;
            }
            if(i == str.size() - 2)
            {
                if(cnt >= 3)
                {
                    if(str[i] == str[i+1])
                        count_vec.push_back(make_pair(start_pos,i + 1));
                    else
                        count_vec.push_back(make_pair(start_pos,i));
                }
                check = 0;
                cnt = 1;
            }
            // printf("spos %d i now %d, char %c, cnt %d \n",start_pos, i, str[i], cnt);
        }
        res.resize(count_vec.size());
        FORI(count_vec.size())
        {
            res[i].push_back(count_vec[i].first);
            res[i].push_back(count_vec[i].second);
        }
        return res;
    }
};
