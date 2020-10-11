class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        if(s.empty()){
            return 0;
        }
        
        int tmp = 0;
        for(char c : s){
            if(c == '('){
                tmp++;
            }
            else if(c == ')'){
                tmp--;
            }
            res = max(tmp, res);
        }
        
        return res;
    }
}
