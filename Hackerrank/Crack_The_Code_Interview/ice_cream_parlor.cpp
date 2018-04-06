#include <bits/stdc++.h>

using namespace std;
void check(vector<int> correspond_cost, int money, int flavor)
{
    vector<int> res;
    int done = 0;
    for(int i = 0; i < correspond_cost.size() - 1; i++)
    {
        if(correspond_cost[i] >= money)
        {
            continue;
        }
        for(int j = i + 1; j < correspond_cost.size(); j++)
        {
            if(correspond_cost[i] + correspond_cost[j] == money)
            {
                printf("%d %d\n",i + 1, j + 1);
                done = 1;
                break;
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
    cin >> trip;
    while(trip--)
    {
        cin>>money>>flavor;
        vector<int> correspond_cost;
        while(flavor--)
        {
            cin>>tmp_cost;
            correspond_cost.push_back(tmp_cost);
        }
        check(correspond_cost, money, flavor);
    }
    return 0;
}
