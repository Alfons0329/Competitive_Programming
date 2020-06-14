#define FORI(n) for(int i = 0; i < n; ++ i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
class Solution
{
public:
    int numFriendRequests(vector<int>& ages)
    {
        int rq = 0;
        sort(ages.begin(), ages.end());
        map<int, int> mymap;
        FORI(ages.size())
        {
            mymap[ages[i]]++;
        }
        SORT_UNIQUE(ages);
        cout <<"len" << ages.size() <<endl;
        for(int i = ages.size() - 1; i >= 0; --i)
        {
            for(int j = i; j >=0; --j)
            {
                if((ages[j] <= 0.5 * ages[i] + 7)
                ||(ages[j] > ages[i])
                ||(ages[j] > 100 && ages[i] < 100))
                {
                    continue;
                }
                else if(i != j)
                {
                    printf("Request from %d to %d \n",ages[i] , ages[j]);
                    rq += (mymap[ages[i]] ) * (mymap[ages[j]]);
                }
                else if(i == j)
                {
                    rq += mymap[ages[i]] * (mymap[ages[i]]  - 1);
                }
            }
        }
        /*FORI(ages.size()) //A
        {
            for(int j = 0; j < ages.size(); ++j) //B
            {
                if(i == j)
                {
                    continue;
                }
                else if((ages[j] <= 0.5 * ages[i] + 7)
                ||(ages[j] > ages[i])
                ||(ages[j] > 100 && ages[i] < 100))
                {
                    continue;
                }
                else if(i != j)
                {
                    //printf("Request from %d to %d \n",ages[i] , ages[j]);
                    ++rq;
                }
            }
        }*/
        return rq;
    }
};
