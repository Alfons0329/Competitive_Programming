class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                star.push(i);
            }
            else if(s[i] == '('){
                left.push(i);
            }
            else{
                // the precedence of left parenthesis should be higher than star since star is multifunctional
                // nothing to use
                if(left.empty() && star.empty()){
                    return false;
                }
                
                // use (
                if(left.size()){
                    left.pop();
                }
                // use *
                else{
                    star.pop();
                }
            }
        }
        
        // use star (occurred after a left parenthesis to calcelled out the left parenthesis for final check)
        while(left.size() && star.size()){
            if(left.top() > star.top()){
                return false;
            }
            left.pop();
            star.pop();
        }
        
        return left.empty();
    }
};