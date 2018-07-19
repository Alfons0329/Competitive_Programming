/*
AC version, try using the priority queue. we keep traversing through the stations without refuling, that means try our best with current fuel.
Once we traverse to a gas station with the negative fuel,
we refill the tank with the gas station we have visited before(pushed in to the traversed_stations priority queue)
to check if we can reach even further if we refueled before using the retroactive method.
----------------------------------------------------------------------------------------------------------------
Please try the following testcases for understanding how the code runs
1000
299
[[13,21],[26,115],[100,47],[225,99],[299,141],[444,198],[608,190],[636,157],[647,255],[841,123]]
*/
class Solution
{
public:
    struct mycompare
    {
        bool operator()(pair<int ,int>&p1, pair<int ,int>&p2) //pair first for station position and second for how much gas does a staion hace
        {
            return p1.second < p2.second; //sort descending to get the largest element first
        }
    };
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        if(stations.size() == 0)
        {
            return (startFuel >= target) ? 0 : -1;
        }
        priority_queue<pair<int ,int>, vector<pair<int ,int>>, mycompare> traversed_stations; //logN query
        int cur_fuel = startFuel, car_pos = 0, refuel = 0;
        for(int i = 0; i < stations.size(); i++)
        {
            cur_fuel -= (stations[i][0] - car_pos);
            if(car_pos + cur_fuel >= target)
            {
                break;
            }
            while(!traversed_stations.empty() && cur_fuel < 0) //traverse to certain gas station but we ran out of fuel, that we have to trace back to see if we can refuel before
            {
                cur_fuel += traversed_stations.top().second;
                refuel++;
                traversed_stations.pop();
            }
            if(cur_fuel < 0)
            {
                return -1;
            }
            car_pos = stations[i][0];
            traversed_stations.push(make_pair(stations[i][0], stations[i][1]));;
            has_chance_to_refuel = 0;
        }
        //if hasn't reach the target yet
        while(!traversed_stations.empty() && car_pos + cur_fuel < target) //traverse to certain gas station but we ran out of fuel, that we have to trace back to see if we can refuel before
        {
            cur_fuel += traversed_stations.top().second;
            // car_pos = traversed_stations.top().first;
            refuel++;
            traversed_stations.pop();
        }

        return (car_pos + cur_fuel >= target) ? refuel : -1; //able to reach the target destination or not
    }

};
