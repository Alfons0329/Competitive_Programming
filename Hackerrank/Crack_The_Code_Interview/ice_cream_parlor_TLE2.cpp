#include <bits/stdc++.h>
/*
Algorithm: run through the list of data from head till end, check if hash[money - current_searched_money] exists
then we have a solution and we are good to print out
*/
using namespace std;
inline void check(map<int ,int>& cost_to_id_hash, int money, int flavor)
{
    map<int ,int>::iterator it;
    int small_id = 0, large_id = 0;
    for(it = cost_to_id_hash.begin(); it != cost_to_id_hash.end(); it++)
    {
        // cout<<"It first (cost) "<<it->first<<" it second (correspond id) "<<it->second<<" relating to "<<cost_to_id_hash[money - it->first]<<endl;
        if(cost_to_id_hash[money - it->first] && (cost_to_id_hash[money - it->first] != it->second))//exists in another pair of the
        {
            small_id = min(it->second, cost_to_id_hash[money - it->first]);
            large_id = max(it->second, cost_to_id_hash[money - it->first]);
            printf("%d %d\n", small_id, large_id);
            break;
        }
    }
}
int main()
{
    int trip, money, flavor, tmp_cost, id = 1, need = 1;
    map<int, int> cost_to_id_hash;
    cin >> trip;
    while(trip--)
    {
        cin>>money>>flavor;
        id = 1;
        need = 1; //need do further check
        // cout<<"--------------------------"<<endl;
        while(flavor--)
        {
            cin>>tmp_cost;
            if(tmp_cost < money)
            {
                if(cost_to_id_hash[tmp_cost])
                {
                    if(tmp_cost == money / 2)
                    {
                        printf("%d %d\n", cost_to_id_hash[tmp_cost] ,id);
                        need = 0;
                        break;
                    }
                }
                else
                {
                    cost_to_id_hash[tmp_cost] = id;
                }
            }
            id++;
        }
        if(need)
        {
            check(cost_to_id_hash, money, flavor);
        }
        cost_to_id_hash.clear();
    }
    return 0;
}
