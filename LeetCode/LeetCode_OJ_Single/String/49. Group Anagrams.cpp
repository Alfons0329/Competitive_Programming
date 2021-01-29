class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // init
        unordered_map<string, vector<string> > m;
        vector<vector<string> > res;
        vector<string> tmp_res;
        // iterate through all the strings in strs and hash((s)) as key, and push_back if there is already such key, else new map element
        string tmp;
        for(string s : strs){
            tmp = s;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(s);
        }
        // finally iterate through the map to get the final answer
        for(auto it = m.begin(); it != m.end(); it++){
            tmp_res.clear();
            for(string s : it -> second){
                // cout << "emp s " << s << " from " << it -> first << '\n';
                tmp_res.emplace_back(s);
            }
            res.emplace_back(tmp_res);
        }
        // return the answer
        return res;        
    }
};