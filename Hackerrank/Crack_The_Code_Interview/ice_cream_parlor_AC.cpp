#include <bits/stdc++.h>
/*
Algorithm: run through the list of data from head till end, check if hash[money - current_searched_money] exists
then we have a solution and we are good to print out
*/
using namespace std;
inline void check(vector<int>& flavor_cost, int money, int flavor)
{
    unordered_map<int, int> cost_to_id_hash;
    for(int i = 0; i < flavor_cost.size(); i++)
    {
        if(cost_to_id_hash[money - flavor_cost[i]])
        {
            printf("%d %d\n",cost_to_id_hash[money - flavor_cost[i]] , i + 1);
        }
        cost_to_id_hash[flavor_cost[i]] = i + 1;
    }
}
int main()
{
    int trip, money, flavor, tmp_cost, id = 1, need = 1;
    vector<int> flavor_cost;
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
            flavor_cost.push_back(tmp_cost);
        }
        check(flavor_cost, money, flavor);
        flavor_cost.clear();
    }
    return 0;
}
