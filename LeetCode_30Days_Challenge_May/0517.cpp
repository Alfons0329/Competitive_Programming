#define N 26
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> us(N);
        vector<int> up(N);
        vector<int> res;
        
        for(char c : p){
            up[c - 'a']++;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(i >= p.size()){
                us[s[i - p.size()] - 'a']--;
            }
            
            us[s[i] - 'a']++;
            if(us == up){
                res.push_back(i + 1 - p.size());
            }
        }
        
        return res;
        
    }
