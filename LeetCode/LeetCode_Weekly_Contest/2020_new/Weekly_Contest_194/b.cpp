class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int cnt;
        string ans;
        vector<string> res;
        unordered_map<string, int> u; // counter
        unordered_set<string> used; // used
        
        for(string s : names){
            if(used.count(s) == 0){
                used.insert(s);
                res.push_back(s);
            }
            else{
                string ans("");
                do{
                    u[s]++;
                    ans = s + "(" + to_string(u[s]) + ")";
                } while(used.count(ans));
                used.insert(ans);
                res.push_back(ans);
            }
        }
        
        return res;
    }
};
