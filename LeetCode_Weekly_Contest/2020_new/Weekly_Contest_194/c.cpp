class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> dry; // dry days
        unordered_map<int, int> lake_full; // key: full lake ID, val: which day
            
        vector<int> res(n, -1);
        
        for(int i = 0; i < n; i++){
            // rainy day
            if(rains[i] > 0){
                if(lake_full.count(rains[i])){ // the lake already full
                    auto found = dry.lower_bound(lake_full[rains[i]]);
                    
                    // unable to dry beforehand
                    if(found == dry.end()){
                        return {};
                    }
                    else{
                        res[*found] = rains[i];
                        dry.erase(*found); // use such day
                    }
                }
                lake_full[rains[i]] = i; // update the day when lake is full
            }
            else{
                dry.insert(i);
                res[i] = 1;
            }
        }
        return res;
    }
