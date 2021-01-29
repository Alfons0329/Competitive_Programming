/*
* Analysis:
    * Time complexity: O(len(s)) by iterating through all the element in s
    * Space complexity: O(len(s)) as we pb all the space-separated substring in it
*/
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()){
            return "";
        }
        else{
            // special testcase like "", " ", "    " or " " * n (n in [1, INF))
            int flg = 0;
            for(char c : s){
                if(c != ' '){
                    flg = 1;
                    break;
                }
            }
            if(!flg){
                return "";
            }
        }
        stringstream ss(s);
        string tmp, res("");
        vector<string> v;
        // remove white space by using stringstream
        while(ss >> tmp){
            v.emplace_back(tmp);
        }
        // push back the reversed result
        for(int i = v.size() - 1; i >= 0; i--){
            res += v[i];
            if(i != 0){
                res += " ";
            }
        }
        // return the final answer
        return res;
    }
};