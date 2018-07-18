class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        if(startFuel >= target)
        {
            return 0;
        }
        else if(stations.size() == 0)
        {
            return (startFuel >= target) ? 0 : -1;
        }
        int dp[500][500] = {0}, cur_fuel = startFuel, car_pos = 0, refuel = 0;

        int best_choice = 0, max_refuel = 0, stations_pos = 0, can_reach_next = 1;
        int closest_next_pos = 0, closest_next_dist = INT_MAX;
        while (1)
        {
            if(car_pos + cur_fuel >= target || car_pos >= target) //should have the highest priority
            {
                printf("reach target!\n");
                break;
            }
            can_reach_next = 0;//search the next, closest stations to go, reachable or not (check the requirement of break if unreachable)
            closest_next_pos = 0;
            closest_next_dist = INT_MAX;
            for(int i = 0; i < stations.size(); i++)
            {
                if(stations[i][0] - car_pos < closest_next_dist && stations[i][1] > 0 /*still useable*/)
                {
                    closest_next_dist = stations[i][0];
                    closest_next_pos = i;
                }
            }
            printf("car_pos %d fuel_now closest_next_pos is %d with dist %d\n",car_pos,  closest_next_pos, closest_next_dist);

            if(stations[closest_next_pos][0] - car_pos > cur_fuel || closest_next_dist == INT_MAX)//unracehable with current fuel
            {
                printf("unreachable to all\n");
                return -1;
            }

            max_refuel = stations_pos = 0;
            for(int i = 0; i < stations.size(); i++) //find all reachable stations with max fuel to refill
            {
                printf("i %d i0 %d i1 %d ok \n", i, stations[i][0], stations[i][1]);
                if(stations[i][0] - car_pos >= 0 && cur_fuel >= stations[i][0] - car_pos/*reachable with current fuel*/&& stations[i][1] > max_refuel /*bigger fuel slot*/)
                {
                    max_refuel = stations[i][1];
                    stations_pos = i;
                }
            }
            cur_fuel -= (stations[stations_pos][0] - car_pos); //drive
            car_pos = stations[stations_pos][0]; //reach
            cur_fuel += stations[stations_pos][1]; //refill
            // stations[stations_pos][0] = INT_MAX; //marked such station as used to prevent duplicate using
            stations[stations_pos][1] = 0; //used out such fuel
            refuel++;
            printf("select stations_pos %d, car_pos is now %d, car_fuel is now %d \n",stations_pos, car_pos, cur_fuel);
        }
        return refuel;
    }
};
