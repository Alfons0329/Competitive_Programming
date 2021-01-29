class Solution {
public:
    string removeKdigits(string num, int k) {
        string res("");
        for(char c : num){
            while(k && res.size() && c < res.back()){
                k--;
                res.pop_back();
            }
            if(!(c == '0' && res.empty())){
                res.push_back(c); 
            }
        }
        
        // have ensured that the string is in monotonically incresing order
        // MSB[]LSB
        while(res.size() && k--){
            res.pop_back();
        }
        return res.size() ? res : "0";
    }
