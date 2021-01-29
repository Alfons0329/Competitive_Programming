class Solution {
public:
    string reformatNumber(string n) {
        string res, tmp;
        for(char c : n){
            if(c <= '9' && c >= '0'){
                tmp += c;
            }
        }
        
        int i = 0, flg = 0;
        int l = tmp.size();
        if(i + 4 == l){
            flg = 1;
        }
        else{     
            while(i < l - 3){
                if(i + 2 < l){
                    res += tmp.substr(i, 3);
                    res += "-";
                    i += 3;
                }
                if(i + 4 == l){
                    flg = 1;
                    break;
                }
            }
        }
        
        
        if(flg){
            res += tmp.substr(i, 2);
            res += "-";
            res += tmp.substr(i + 2, 2);
        }
        else{
            res += tmp.substr(i, l - i);
        }
        
        if(res.back() == ' ' || res.back() == '-'){
            res.pop_back();
        }
        
        return res;
    }
