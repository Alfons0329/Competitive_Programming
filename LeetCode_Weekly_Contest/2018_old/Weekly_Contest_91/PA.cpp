#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    bool lemonadeChange(vector<int>& bl)
    {
        map<int ,int>mymap;
        FORI(bl.size())
        {
            mymap[bl[i]]++;
            if(bl[i] == 10)
            {
                if(mymap[5] == 0)
                {
                    return 0;
                }
                else
                {
                    mymap[5]--;
                }
            }
            else
            {
                if(mymap[5] > 0 && mymap[10] > 0)
                {
                    mymap[5]--;
                    mymap[10]--;
                }
                else if(mymap[5] >=3 && mymap[10] == 0)
                {
                    mymap[5] -= 3;
                }
                else if(mymap[5] == 0 || mymap[10] == 0)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};
