class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        // find out the shortest length
        int min_len = INT_MAX;
        for(string s : strs){
            min_len = min(min_len, (int)s.size());
        }
        // extend the prefix as long as possible
        string res = "";
        for(int j = 0; j < min_len; j++){
            char c = strs[0][j];
            bool end = false;
            for(int i = 1; i < strs.size(); i++){
                if(c != strs[i][j]){
                    end = true;
                }
            }
            if(end){
                break;
            }
            else{
                res += strs[0][j];
            }
        }
        // return the result
        return res;
    }
};