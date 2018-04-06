#include <bits/stdc++.h>

using namespace std;
struct flavor_and_id
{
    int cost, id;
};
void check(vector<int> correspond_cost, int money, int flavor)
{
    vector<flavor_and_id> mymap;
    flavor_and_id tmp;
    int done = 0;
    for(int i = 0; i < correspond_cost.size() - 1; i++)
    {
        tmp.cost = correspond_cost[i];
        tmp.id = i + 1;
        if(correspond_cost[i] < money)
        {
            mycollection.push_back(tmp);
        }
    }
    for(int i = 0; i < mymap.size() - 1; i++)
    {
        if(mymap[i].cost >= money)
        {
            continue;
        }
        else
        {
            for(int j = i + 1; j < mymap.size(); j++)
            {
                if(mymap[i].cost + mymap[j].cost == money)
                {
                    printf("%d %d\n",mymap[i].id, mymap[j].id);
                    done = 1;
                    break;
                }
            }
        }
        if(done)
        {
            break;
        }
    }
}
int main(int argc, char const *argv[])
{
    int trip, money, flavor, tmp_cost;
    vector<int> correspond_cost;
    cin >> trip;
    while(trip--)
    {
        cin>>money>>flavor;
        while(flavor--)
        {
            cin>>tmp_cost;
            correspond_cost.push_back(tmp_cost);
        }
        check(correspond_cost, money, flavor);
        correspond_cost.clear();
    }
    return 0;
}
