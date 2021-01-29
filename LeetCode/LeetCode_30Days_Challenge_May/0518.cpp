#define N 26
class Solution {
public:
    bool checkInclusion(string p, string s) {
        if(p.size() > s.size()){
            return false;
        }
        vector<int> us(N);
        vector<int> up(N);
        // vector<int> res;
        
        for(char c : p){
            up[c - 'a']++;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(i >= p.size()){
                us[s[i - p.size()] - 'a']--;
            }
            
            us[s[i] - 'a']++;
            if(us == up){
                // res.push_back(i + 1 - p.size());
                return true;
            }
        }
        
        return false;
    }
