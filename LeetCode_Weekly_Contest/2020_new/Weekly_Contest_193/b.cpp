#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    static bool cmp(pii& a, pii& b){
        return a.se < b.se;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> u;
        int res = 0;
        for(int x : arr){
            u[x]++;
        }
        
        vector<pii>v;
        for(auto it = u.begin(); it != u.end(); it++){
            v.push_back({it -> first, it -> second});
        }
        sort(v.begin(), v.end(), cmp);
        
        int i = 0;
        while(k--){
            v[i].se--;
            if(v[i].se == 0){
                u.erase(v[i].fi);
                i++;
            }
        }
        return u.size();
    }
};
