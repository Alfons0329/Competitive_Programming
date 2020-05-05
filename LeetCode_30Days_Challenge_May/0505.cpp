class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, pair<int, int>> u; // key: char, val <freq, pos>
        int res = n;
        for(int i = 0; i < n; i++){
            u[s[i]].first++;
            u[s[i]].second = i;
        }
        for(auto it = u.begin(); it != u.end(); it++){
            if(it -> second.first == 1){
                res = min(res, it -> second.second);
            }
        }
        return res == n ? -1 : res;
    }
};
