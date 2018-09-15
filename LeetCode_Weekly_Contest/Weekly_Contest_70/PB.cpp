#define FORI(n) for(int i = 0; i < n; ++ i)
/*
Use greedy algorithm to approach.
e.g. [2,2,2,2,2] --> [2,2,2]   [2,2] total of six rabbits
[3,3,3,3,3,3,3,3,3,3] there are count 10 of 3
so the combination could be [3,3,3,3] (4rabbits) [3,3,3,3] (4rabbits)
check the note for more detail information
*/
class Solution
{
public:
    int numRabbits(vector<int>& answers)
    {
        map<int ,int> hash_map;
        if(answers.size())
        {
            int rabbit_ans=0;
            FORI(answers.size()) //statistical analysis
            {
                hash_map[answers[i]]++;
            }
            std::map<int, int>::iterator it=hash_map.begin();
            for(it=hash_map.begin();it!=hash_map.end();++it)
            {
                if(it->second)
                {
                    rabbit_ans+=(it->first+1)*ceil((double)it->second/(double)(it->first+1));
                }
                else
                {
                    rabbit_ans++;
                }
            }
            cout<<rabbit_ans<<endl;
            return rabbit_ans;
        }
    }
};
